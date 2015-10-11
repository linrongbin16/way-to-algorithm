#ifndef DYNAMICPROMGRAMMING_LONGEST_INCREASING_SUBSEQUENCE_EXTENSION_H
#define DYNAMICPROMGRAMMING_LONGEST_INCREASING_SUBSEQUENCE_EXTENSION_H 1
//最长递增子序列扩展
//longest increasing subsequence extension

//对最长递增子序列的扩展问题
//1)求出序列s中的最长递增子序列长度
//2)求出这样的最长序列有多少个
//
//本文的原型是usaco上buy low buy lower但本文中不考虑子序列相同的情况
//即有这样的多个子序列 它们长度最长(长度相等) 且元素完全相同
//但在原序列中的元素位置不一样 本文中认为它们是不同的子序列
//而原题目buy low buy lower中认为它们是相同的子序列 而要求不累加这样相同的子序列
//本文省去了这样的相同子列相同的考虑 认为它们是不同的子列 代码处理比较方便
//buy low buy lower题中为了排除这样相同的子列 还需要设置next数组

//1)求最长递增子序列长度的解法与前一篇最长递增子序列中的原始方法是一样的
//设f[i]为序列s中第i个元素之前最长子列的长度
//状态转移方程:
//f[i] = max(f[j]+1, 1) 其中1<=j<i 
//初始条件: f[i]为1 其中1<=i<=n
//
//2)求多个最长(长度相等的)子序列的个数的方法
//设c[i]为第i个元素之前最长子序列的个数
//状态转移方程:
//若s[j]>s[i] && f[j]+1>f[i] 则c[i]=c[j]
//否则若f[j]+1==f[i] 则c[i]=c[i]+c[j]
//其中1<=j<i
//初始条件: c[i]为1 其中1<=i<=n
//
//3)补注
//上面的算法是很多网站上的写法 在实际测试的过程中我发现有点小小的问题
//我对c[i]所指代的含义有些异议
//我认为c[i]实际是指代以第i个元素做最后一个元素的最长子列长度为f[i]的个数
//即比如在i==5时 f[5]=4 c[5]=2 即第5元素之前最长子列长度为4
//以第5元素为子列结尾的长度为4的子列有2个
//而i==7时 f[7]=4 c[7]=3 即第7元素之前最长子列长度为4
//以第7元素为子列结尾的长度为4的子列有3个
//所以在动规结束之后 最后需要遍历一次c数组找出f最大值对应的c
//全部加起来才是最长子列的个数


#include <algorithm>
using std::max;
#ifndef MAX
#define MAX 60
#endif

int longest_increasing_subsequence_extension(int s[MAX], int n, int& m)
{
    //序列s长为n+1 下标从1到n 空出0位置
    //返回序列s的最长子列的长度 和这样的子列的个数m
	int f[MAX + 1], c[MAX + 1];
	for(int i = 1; i <= n; ++i)
		f[i] = 1, c[i] = 1;
	for(int i = 2; i <= n; ++i)
		//对于每个i元素 考虑前面的所有元素j
		for(int j = 1; j < i; ++j)
			if(s[j] < s[i]){
				//当s[j]<s[i]时 j与i两元素可以组成一个递增子列
				if(f[j] + 1 > f[i]){
					//若f[j]>=f[i]
					//新组成的子列长度会是i元素之前最长的
					//c[i]更新为c[j]
					//即以i为结尾的子列 这样子列的个数和c[j]相等
					f[i] = f[j] + 1;
					c[i] = c[j];
				}
				else if(f[j] + 1 == f[i])
					//若f[j]比f[i]小1
					//前面已有新组成的子列的长度
					c[i] += c[j];
			}
	int cnt(0);
	for(int i = 0; i <= n; ++i)
		if(f[i] == f[n])
			cnt += c[i];
	m = cnt;
	return(f[n]);
}


#endif
