#pragma once
#ifndef MAX
#define MAX 1024
#endif
#include <algorithm>
#include <cassert>
#include <cstring>
#include <string>

struct Number {
  //整数部分 integer_[0]存储个位, integer_[1]存储十位...
  //输出时从后向前反向输出
  int integer[MAX];
  //有效数字的个数
  int integer_len;

  //小数部分 decimal_[0]存储十分之一位, decimal_[1]存储百分之一位...
  //输出时从前向后正向输出
  int decimal[MAX];
  //有效数字的个数
  int decimal_len;

  //正负号
  bool negative;
};

//初始化
Number Init();
Number Init(int a);
Number Init(double a);

//负号
Number operator-(const Number &a);
//加法
Number operator+(const Number &a, const Number &b);
Number &operator+=(Number &a, const Number &b);
//减法
Number operator-(const Number &a, const Number &b);
Number &operator-=(Number &a, const Number &b);
//乘法
Number operator*(const Number &a, const Number &b);
Number &operator*=(Number &a, const Number &b);
//除法
Number operator/(const Number &a, const Number &b);
Number &operator/=(Number &a, const Number &b);
//大于
bool operator>(const Number &a, const Number &b);
//大于等于
bool operator>=(const Number &a, const Number &b);
//大于
bool operator<(const Number &a, const Number &b);
//小于等于
bool operator<=(const Number &a, const Number &b);
//等于
bool operator==(const Number &a, const Number &b);
//不等于
bool operator!=(const Number &a, const Number &b);

//输出字符串
std::string ToString(const Number &a);

