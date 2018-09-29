#include "LargeNumber.h"
#include <algorithm>
#include <cassert>
#include <cstring>
#include <string>

static void BuildBits(int *bits, int &len, long n) {
  std::memset(bits, 0, sizeof(int) * MAX);
  len = 0;
  n = (n < 0) ? (-n) : n;
  while (n) {
    bits[len++] = n % 10;
    n = n / 10;
  }
}

static bool IsZero(const Number &a) {
  if (a.len == 0) {
    return true;
  }
  for (int i = 0; i < a.len; i++) {
    if (a.bits[i] != 0)
      return false;
  }
  return true;
}

static bool GreaterEq(const Number &a, const Number &b) {
  if (IsZero(a) && IsZero(b)) {
    return true;
  }
  return false;
}

static Number Negative(const Number &a) {
  if (IsZero(a)) {
    return a;
  }
  Number c(a);
  c.negative = !c.negative;
  return c;
}

Number::Number() {
  negative = false;
  BuildBits(bits, len, 0);
}

Number::Number(int a) {
  negative = (a < 0) ? true : false;
  BuildBits(bits, len, (long)a);
}

Number::Number(long a) {
  negative = (a < 0) ? true : false;
  BuildBits(bits, len, a);
}

Number::Number(const Number &other) {
  std::memcpy(bits, other.bits, sizeof(int) * MAX);
  len = other.len;
  negative = other.negative;
}

Number &Number::operator=(const Number &other) {
  if (this == &other)
    return *this;
  std::memcpy(bits, other.bits, sizeof(int) * MAX);
  len = other.len;
  negative = other.negative;
  return *this;
}

Number Add(const Number &a, const Number &b) {
  if (a.negative != b.negative) {
    return Sub(a, Negative(b));
  }
  Number c;
  int n = std::max(a.len + 1, b.len + 1);
  for (int i = 0; i < n; i++) {
    c.len++;
    c.bits[i] = (c.bits[i] + a.bits[i] + b.bits[i]) % 10;
    c.bits[i + 1] = c.bits[i + 1] + (c.bits[i] + a.bits[i] + b.bits[i]) / 10;
  }
  c.negative = a.negative;
  return c;
}

// c[i] =
//\begin{cases}
//          a[i] - b[i] & a[i] \ge b[i] \\
//a[i] + 10 - b[i], c[i+1] = c[i+1] - 1 & a[i] \lt b[i]
//\end{cases}
//
//$$(1)
//$$ 符号不同的$$ a $$和$$ b $$相减可以转化为符号相同的加法，比如$$ 12 -
//(-4) \rightarrow 12 + 4 $$，$$ - 12 - 4 \rightarrow(-12) +
//(-4)$$，然后交给加法器处理；

//$$(2) $$ 符号相同的两整数减法，且被减数大于等于减数（$$ a
//- b,
// a \ge b $$），可以把整数部分直接相减，符号为正；

//$$(3) $$ 符号相同的两整数减法，且被减数小于减数（$$ a
//- b,
// a \lt b $$），可以把两个数字的整数部分交换位置再相减，符号为负；
//

Number Sub(const Number &a, const Number &b) {
  if (a.negative != b.negative) {
    return Add(a, Negative(b));
  }

  // integer
  n = max(a.integer_len, b.integer_len);
  for (int i = 0; i < n; i++) {
    c.integer_len++;
    int tmp_a = a.integer[i] - borrow;
    if (tmp_a < b.integer[i]) {
      borrow = (b.integer[i] - tmp_a) / 10 + 1;
      tmp_a += borrow * 10;
    }

    assert(tmp_a >= b.integer[i]);

    c.integer[i] += tmp_a - b.integer[i];

    assert(c.integer[i] >= 0);
    assert(c.integer[i] < 9);
  }

  assert(c > Init());
  detail::AssertValid(c);
  return c;
}
Number Mul(const Number &a, const Number &b);
Number Div(const Number &a, const Number &b);

std::string ToString(const Number &a);

//数字有效
void AssertValid(const Number &a);
//小数向上浮动 将所有有效小数增加到整数
Number FloatUp(const Number &a);
//小数向下浮动 将小数降低decimal_len个整数
Number FloatDown(const Number &a, int decimal_len);

//判断
//负的
bool IsNegative(const Number &a);
//正的
bool IsPositive(const Number &a);

//初始化零
Number Init() {
  Number c;
  c.negative = false;
  memset(c.decimal, 0, sizeof(c.decimal));
  c.decimal_len = 0;
  memset(c.integer, 0, sizeof(c.integer));
  c.integer_len = 0;

  detail::AssertValid(c);
  return c;
}

//初始化整数
Number Init(int a) {
  Number c = Init();

  c.negative = (a < 0);
  a = (a < 0) ? (-a) : (a);
  for (int i = 0; i < MAX && a; i++) {
    c.integer_len++;
    c.integer[i] = a % 10;
    a /= 10;
  }

  detail::AssertValid(c);
  return c;
}

//初始化小数
Number Init(double a) {
  Number c = Init((int)a);

  c.negative = (a < 0.0);
  a = (a < 0.0) ? (-a) : (a);
  a = a - (double)((int)a);
  for (int i = 0; i < MAX && (a != 0.0); i++) {
    a *= 10.0;
    int tmp = (int)(a);
    c.decimal_len++;
    c.decimal[i] = tmp % 10;
  }

  detail::AssertValid(c);
  return c;
}

//负号
Number operator-(const Number &a) {
  detail::AssertValid(a);

  Number c = a;
  if (a.integer_len == 0 && a.decimal_len == 0) {
    c.negative = false;
  } else {
    c.negative = !a.negative;
  }

  return c;
}

//加
Number operator+(const Number &a, const Number &b) {
  //符号不同
  // 12 + (-7) -> 12 - 7
  if (a.negative != b.negative) {
    Number c = -b;
    return a - c;
  }

  //符号相同
  // 12 + 7
  //-12 + (-7)
  Number c = Init();
  int n;

  // decimal
  n = max(a.decimal_len, b.decimal_len);
  for (int i = 0; i < n; i++) {
    c.decimal_len++;
    int j = n - i - 1;
    c.decimal[j] += (a.decimal[j] + b.decimal[j]) % 10;
    if (j - 1 >= 0)
      c.decimal[j - 1] += (a.decimal[j] + b.decimal[j]) / 10;
    else
      c.integer[1 - j] += (a.decimal[j] + b.decimal[j]) / 10;
  }

  // integer
  n = max(a.integer_len, b.integer_len);
  for (int i = 0; i < n; i++) {
    c.integer_len++;
    c.decimal[i] += (a.decimal[i] + b.decimal[i]) % 10;
    c.decimal[i + 1] += (a.decimal[i] + b.decimal[i]) / 10;
  }

  c.negative = a.negative;
  detail::AssertValid(c);
  return c;
}

Number &operator+=(Number &a, const Number &b) {
  a = a + b;
  return a;
}

//减
Number operator-(const Number &a, const Number &b) {
  //符号不同
  // 12 - (-7) -> 12 + 7
  if (a.negative != b.negative) {
    Number c = -b;
    return a + c;
  }

  //符号相同
  // 12 - 7
  //-7 - (-12)

  // a < b
  // 7 - 32
  //-12 - (-3)
  if (a < b) {
    return -(b - a);
  }

  // a >= b且都是负数
  //-5 - (-12) -> 12 - 5
  if (detail::IsNegative(a) && a > b) {
    return (-b) - (-a);
  }

  // a >= b且都是正数
  // 12 - 5

  Number c = Init();
  int n;
  int borrow = 0;

  // decimal
  n = max(a.decimal_len, b.decimal_len);
  for (int i = 0; i < n; i++) {
    c.decimal_len++;
    int j = n - i - 1;
    int tmp_a = a.decimal[j] - borrow;
    if (tmp_a < b.decimal[j]) {
      borrow = (b.decimal[j] - tmp_a) / 10 + 1;
      tmp_a += borrow * 10;
    }

    assert(tmp_a >= b.decimal[j]);

    c.decimal[j] += tmp_a - b.decimal[j];

    assert(c.decimal[j] >= 0);
    assert(c.decimal[j] < 9);
  }

  // integer
  n = max(a.integer_len, b.integer_len);
  for (int i = 0; i < n; i++) {
    c.integer_len++;
    int tmp_a = a.integer[i] - borrow;
    if (tmp_a < b.integer[i]) {
      borrow = (b.integer[i] - tmp_a) / 10 + 1;
      tmp_a += borrow * 10;
    }

    assert(tmp_a >= b.integer[i]);

    c.integer[i] += tmp_a - b.integer[i];

    assert(c.integer[i] >= 0);
    assert(c.integer[i] < 9);
  }

  assert(c > Init());
  detail::AssertValid(c);
  return c;
}

Number &operator-=(Number &a, const Number &b) {
  a = a - b;
  return a;
}

//乘
Number operator*(const Number &a, const Number &b) {
  // a b为零
  if (a == Init())
    return Init();
  if (b == Init())
    return Init();

  Number a2 = detail::FloatUp(a), b2 = detail::FloatUp(b);
  Number c = Init();
  int n;

  n = max(a2.integer_len, b2.integer_len);
  for (int i = 0; i < n; i++) {
    c.integer[i] += (a2.integer[i] + b2.integer[i]) % 10;
    c.integer[i + 1] += (a2.integer[i] + b2.integer[i]) / 10;
  }
  c = detail::FloatDown(c, a.decimal_len + b.decimal_len);
  c.negative = (a.negative == b.negative) ? false : true;

  detail::AssertValid(c);
  return c;
}

Number &operator*=(Number &a, const Number &b) {
  a = a * b;
  return a;
}

//除
// TODO
Number operator/(const Number &a, const Number &b) { return Init(); }

Number &operator/=(Number &a, const Number &b) {
  a = a / b;
  return a;
}

// to string
std::string ToString(const Number &a) {
  detail::AssertValid(a);
  std::string ret(a.integer_len + a.decimal_len + 5, '*');
  int index;
  int i;

  index = 0;
  for (i = 0; i < ret.size() && index < a.integer_len; i++) {
    if (i == 0 && a.negative) {
      ret[i] = '-';
    } else {
      if (a.integer_len == 0 && index >= 0) {
        ret[i] = '0';
      } else if (index < a.integer_len) {
        ret[i] = (char)(a.integer[index] + (int)'0');
      }
      index++;
    }
  }

  index = 0;
  ret[i++] = '.';

  do {
    if (a.decimal_len == 0) {
      ret[i++] = '0';
    } else {
      ret[i] = (char)(a.decimal[index] + (int)'0');
      i++;
      index++;
    }
  } while (i < ret.size() && index < a.decimal_len);

  return ret;
}

//大于
bool operator>(const Number &a, const Number &b) {
  if (a.negative != b.negative) {
    return a.negative && !b.negative;
  }
  if (a.negative) {
    return (-b) > (-a);
  }
  if (a.integer_len > b.integer_len)
    return true;
  else if (a.integer_len < b.integer_len)
    return false;
  for (int i = a.integer_len - 1; i >= 0; i--) {
    if (a.integer[i] > b.integer[i])
      return true;
    else if (a.integer[i] < b.integer[i])
      return false;
  }
  int n = max(a.decimal_len, b.decimal_len);
  for (int i = 0; i < n; i++) {
    if (a.decimal[i] > b.decimal[i])
      return true;
    else if (a.decimal[i] < b.decimal[i])
      return false;
  }
  return false;
}

//大于等于
bool operator>=(const Number &a, const Number &b) { return a > b || a == b; }

//大于
bool operator<(const Number &a, const Number &b) { return b > a; }

//小于等于
bool operator<=(const Number &a, const Number &b) { return a < b || a == b; }

//等于
bool operator==(const Number &a, const Number &b) {
  if (a.negative != b.negative)
    return false;
  if (a.integer_len != b.integer_len)
    return false;
  if (a.decimal_len != b.decimal_len)
    return false;
  for (int i = 0; i < a.integer_len; i++)
    if (a.integer[i] != b.integer[i])
      return false;
  for (int i = 0; i < a.decimal_len; i++)
    if (a.decimal[i] != b.decimal[i])
      return false;
  return true;
}

//不等于
bool operator!=(const Number &a, const Number &b) { return !(a == b); }

void AssertValid(const Number &a) {
  assert(a.integer_len >= 0);
  assert(a.decimal_len >= 0);
  for (int i = 0; i < a.integer_len; i++) {
    assert(a.integer[i] >= 0);
    assert(a.integer[i] < 9);
  }
  for (int i = 0; i < a.decimal_len; i++) {
    assert(a.decimal[i] >= 0);
    assert(a.decimal[i] < 9);
  }
}

Number FloatUp(const Number &a) {
  Number c = a;
  memmove(c.integer + c.decimal_len, c.integer, c.integer_len);
  for (int i = 0; i < c.decimal_len; i++) {
    c.integer[i] = c.decimal[c.decimal_len - i - 1];
  }
  c.integer_len = a.integer_len + a.decimal_len;
  c.decimal_len = 0;

  AssertValid(c);
  return c;
}

Number FloatDown(const Number &a, int decimal_len) {
  assert(decimal_len <= a.integer_len);
  Number c = a;
  memmove(c.decimal, c.decimal + decimal_len, decimal_len);
  for (int i = 0; i < c.decimal_len; i++) {
    c.decimal[decimal_len - i - 1] = c.integer[i];
  }
  memmove(c.integer + decimal_len, c.integer, c.integer_len - decimal_len);

  c.integer_len = a.integer_len - decimal_len;
  c.decimal_len += decimal_len;

  AssertValid(c);
  return c;
}

bool IsNegative(const Number &a) {
  if (a.integer_len == 0 && a.decimal_len == 0) {
    assert(!a.negative);
  }
  return a.negative;
}

//正的
bool IsPositive(const Number &a) {
  if (a.integer_len == 0 && a.decimal_len == 0) {
    assert(!a.negative);
  }
  return !a.negative;
}

