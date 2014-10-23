//求幂运算
//exponentiation.cpp

//求整数x的n次方

//显然用一个循环来暴力的作n-1次乘法是很慢的算法

#include "general_head.h"
//1)原始算法
//基于下面的观察，再应用递归方式可以得到简单的原始算法
//x^n = | x*(x^2)^((n-1)/2)		x是奇数
//      | (x^2)(n/2)			x是偶数
//
//一般情况下求x的n次方，给出的x和n总是看起来无法直接计算的
//比如124235的23943次方，答案一定会超出计算机内置变量的数位，因此一般题目只求最低几位
//比如题目求124235的23943次方的最低5位数字，则加入模运算100000，使得数位不至于过长
//本文中取结果的最低8位
#define MOD 100000000

long long exponentiation1(long long x, long long n)
{//求x^n
	if(n < 0)
		return(exponentiation1(x % MOD, -n) % MOD);
	else if(n == 0)
		return(1);
	else if(n == 1)
		return(x % MOD);
	else if(n % 2)
		//n是奇数
		return(x * exponentiation1(x * x % MOD, (n - 1) / 2) % MOD);
	else
		//n是偶数
		return(exponentiation1(x * x % MOD, n / 2) % MOD);
}

//2)二进制非递归算法
//利用二进制可以将原始算法改写为非递归的形式
//可以将指数(Exponent)n写作二进制形式，例如n = 487 = 256 + 128 + 64 + 32 + 4 + 2 + 1
//二进制形式为n = 111100111
//从n的二进制最低位开始，若n % 2 = 1则乘入答案，后则不乘
//该算法一般称为快速求幂算法
//
//3)其他算法
//2k-ary算法，Sliding-Window算法(滑动窗口算法)，Montgomery's ladder技术(M的阶梯算法)
//更多内容请参考“Exponentiation by squaring(Wikipedia)”，无作者
//
//本文引用了“Exponentiation by squaring(Wikpedia)”，无作者
//“利用二进制非递归求幂，转载”，作者“wayleynam”

long long exponentiation2(long long x, long long n)
{
	long long power(1);
	while(n > 0){
		if(n & 1)
			power = (power * x) % MOD;
		x = (x * x) % MOD;
		n >>= 1;	//n /= 2
	}
	return(power);
}
