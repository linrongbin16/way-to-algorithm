#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include <cassert>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <cmath>
#include "../Calculation/LargeNumber.hpp"
using namespace std;
#ifndef MAX
#define MAX 1024
#endif


Number *Catalan(const Number &a) {
    int i,j,len,carry,temp;
    a[1][0]=b[1]=1;
    len=1;
    for(i=2;i<=100;i++)
    {
        for(j=0;j<len;j++)    //乘法
            a[i][j]=a[i-1][j]*(4*(i-1)+2);
        carry=0;
        for(j=0;j<len;j++)    //处理相乘结果
        {
            temp=a[i][j]+carry;
            a[i][j]=temp%10;
            carry=temp/10;
        }
        while(carry)    //进位处理
        {
            a[i][len++]=carry%10;
            carry/=10;
        }
        carry=0;
        for(j=len-1;j>=0;j--) //除法
        {
            temp=carry*10+a[i][j];
            a[i][j]=temp/(i+1);
            carry=temp%(i+1);
        }
        while(!a[i][len-1])     //高位零处理
            len--;
        b[i]=len;
    }
}

#endif
