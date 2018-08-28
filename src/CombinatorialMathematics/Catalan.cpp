#include "Catalan.h"
#include <algorithm>
#include <cassert>
#include "../Calculation/LargeNumber.hpp"

Number* Catalan(const Number& a) {
    int i, j, len, carry, temp;
    a[1][0] = b[1] = 1;
    len = 1;
    for (i = 2; i <= 100; i++) {
        //乘法
        for (j = 0; j < len; j++)
            a[i][j] = a[i - 1][j] * (4 * (i - 1) + 2);
        carry = 0;
        //处理相乘结果
        for (j = 0; j < len; j++) {
            temp = a[i][j] + carry;
            a[i][j] = temp % 10;
            carry = temp / 10;
        }
        //进位处理
        while (carry) {
            a[i][len++] = carry % 10;
            carry /= 10;
        }
        carry = 0;
        //除法
        for (j = len - 1; j >= 0; j--) {
            temp = carry * 10 + a[i][j];
            a[i][j] = temp / (i + 1);
            carry = temp % (i + 1);
        }
        //高位零处理
        while (!a[i][len - 1])
            len--;
        b[i] = len;
    }
}

