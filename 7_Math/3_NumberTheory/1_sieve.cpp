//筛选算法
//sieve.cpp

//素数是除了1和它自身没有其他数能够整除的数字，从2开始
//素数是数论学科中的基础概念，关于素数的最为著名的问题就是哥德巴赫猜想
//求素数

//1)埃拉托斯特尼(Eratosthenes)筛选法
//从2开始，2为素数，以2为筛子，留下2，删去所有2的倍数
//2之后第一个未被删除的数是3，则3为素数，以3为筛子，留下3，删去所有3的倍数
//3之后第一个未被删除的数是5，则5为素数，以5为筛子，留下5，删除所有5的倍数
//以此类推...
//当求解的数字范围较大时可以使用long long这样的数据类型

#include "general_head.h"

void sieve1(int n, int *prime)
{//求从2到n-1中的所有素数，返回prime数组，prime[i]指代数字i是否为素数
	memset(prime, 1, MAX * sizeof(int));
	for(int i = 2; i < n; ++ i)
		if(prime[i])
			for(int j = i * 2; j < n; j += i)
				prime[j] = 0;
}

//2)对埃拉托斯特尼筛选法的优化
//因为素数中只有2是偶数，故可以只筛选奇数，将循环的速度加快

void sieve2(int n, int *prime)
{
	memset(prime, 1, MAX * sizeof(int));
	//prime数组中偶数位置仍然是1，输出结果时需要注意
	for(int i = 3; i < n; i += 2)
		if(prime[i])
			for(int j = i * i; j < n; j += i)
				prime[j] = 0;
}

//3)快速筛选法

void sieve3(int n, int *prime)
{//prime数组的使用方法与之前不同，prime[i]指代一个素数数字的值，下标从0到n-1
	int not_prime[MAX], cnt(0);
	memset(not_prime, 0, MAX * sizeof(int));
	memset(prime, 0, MAX * sizeof(int));
	for(int i = 2; i < n; ++ i){
		if(!not_prime[i])
			prime[cnt ++] = i;
		for(int j = 0; j < cnt && i * prime[j] < n; ++ j){
			not_prime[i * prime[j]] = 1;
			if(!(i % prime[j]))
				break;
		}
	}
}
