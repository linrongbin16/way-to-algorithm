# Sieve - 筛选算法

--------

#### 问题

素数是除了$$ 1 $$和它自身没有其他数能够整除的正整数，最小的素数是$$ 2 $$。而不符合该特性的正整数是合数。素数是数论学科中的基础概念，关于素数的最为著名的问题就是哥德巴赫猜想。

判断$$ 1 - n $$中见的任意一个整数是不是素数。常见的素数有$$ 2, 3, 5, 7, 9, 11, 13, 17, 19, 23 $$等等。

#### 解法1

基本判断

判断一个正整数$$ x $$是否为素数，按照素数的定理，只要不断计算$$ result = x \times i $$（$$ 1 \le  i \le  x $$），累加得到result


埃拉托斯特尼（Eratosthenes）筛选法

设置一个数组$$ s = [1...n] $$，每个位置$$ s[i] $$为$$ true $$表示它是素数，否则为合数。

$$ (1) $$ 从$$ 2 $$开始，$$ 2 $$为素数，以$$ 2 $$为筛子，留下2，删去所有2的倍数
//2之后第一个未被删除的数是3，则3为素数，以3为筛子，留下3，删去所有3的倍数
//3之后第一个未被删除的数是5，则5为素数，以5为筛子，留下5，删除所有5的倍数
//以此类推...
//当求解的数字范围较大时可以使用long long这样的数据类型


![PrefixTree1.svg](../res/PrefixTree1.svg)

这样每次查找单词时，按照前缀从根节点开始向下匹配每个孩子节点的字符即可。前缀树查找一个长度为$$ n $$的单词的时间复杂度为$$ O(n) $$。

--------

#### 源码

[import, lang:"c_cpp"](../../../src/DataStructure/PrefixTree.hpp)

#### 测试

[import, lang:"c_cpp"](../../../src/DataStructure/PrefixTree.cpp)

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
		for(int j = 0; j < cnt and i * prime[j] < n; ++ j){
			not_prime[i * prime[j]] = 1;
			if(!(i % prime[j]))
				break;
		}
	}
}
