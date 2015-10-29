#ifndef DYNAMICPROGRAMMING_LONGEST_INCREASING_SUBSEQUENCE_H
#define DYNAMICPROGRAMMING_LONGEST_INCREASING_SUBSEQUENCE_H 1
//最长递增子序列
//longest increasing subsequence

//求序列s中最长递增子序列的长度

//本问题有两种解法
//
//1)时间复杂度为O(N^2)的原始解法
//设f[i]是第i个元素之前的最长递增子序列的长度
//状态转移方程:
//f[i] = max(f[k]+1, 1) 其中1<=k<=i-1
//初始条件: f[i]为0 其中1<=i<=n
//即对于元素i 对于1到i-1这i个元素的长度f[k]都需要进行比较
//他们的长度再加上元素i自己就是f[k]+1
//也可能是单独一个元素构成序列 即1


#include <algorithm>
using std::max;
#ifndef MAX
#define MAX 60
#endif

int longest_increasing_subsequence1(int s[MAX], int n)
{//序列s的长度为n+1 下标从1到n 空出0位置
 //返回s的最长递增子序列的长度
	int f[MAX + 1];
	for (int i = 1; i <= n; ++i)
		f[i] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j)
			if (s[i] > s[j])
				f[i] = max(f[i], f[j] + 1);
	return(f[n]);
}

//2)时间复杂度为O(N*lgK)的优化解法
//使用二分查找返回已排序列s在[beg,end)范围中值为x的下标
//设f[i]指代若干个长度为i的递增子序列中的最大元素
//顺序依次考察序列s中的每个成员
//当考察s[i]时 将s[i]与f中当前最长长度的最大元素f[len-1]比较
//若s[i]大于f[len] 则对当前f增加1
//若不大于 则在f数组中找出那个k使得f[k]<s[i]<=f[k+1]
//即第i个元素s[i]更新f[k]的值
//题目所求即找出s[n]为结尾的序列的递增子序列的长度


#include "../../1_Sort/1_binary_search.h"

int longest_increasing_subsequence2(int s[MAX], int n)
{
	int f[MAX + 1], len = 1;
	f[1] = s[1];
	for (int i = 2; i <= n; ++i) {
		if(s[i] > f[len]) {
			//若s[i]大于f[len]，则s[i]使子序列增加1
			f[len + 1] = s[i];
			++len;
		}
		else {
			//若不大于，则在之前0到len中更新f[pos]
			//使f[pos]是多个长度相同的子序列中最大元素最大的那个
			//f数组在[0,len)的范围中自然是不递减的
			int pos;
			binary_search(f, 1, len + 1, s[i], pos);
			f[pos] = s[i];
		}
	}
	return(len);
}


#endif
