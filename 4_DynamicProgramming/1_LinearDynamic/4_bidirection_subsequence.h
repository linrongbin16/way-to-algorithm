#ifndef DYNAMICPROGRAMMING_BIDIRECTION_SUBSEQUENCE_H
#define DYNAMICPROGRAMMING_BIDIRECTION_SUBSEQUENCE_H 1
//双向子序列
//bidirection subsequence

//考虑一个序列s和其中某一个元素p
//从s的起点(左端点)到p存在一个最长递增子序列s1
//从p到s的终点(右端点)存在一个最长递减子序列s2
//找出一个p 使得它的s1和s2长度之和最长

//枚举s中的每个元素 对其向前向后分别求最长递增和递减子序列的长度
//然后找出最长的那个即可


#include <algorithm>
using std::max;
#ifndef MAX
#define MAX 60
#endif

int longest_increasing_subsequence(int s[MAX], int beg, int end)
{
    //[beg,end]是左闭右闭区间 序列s从beg到end
    //返回序列s在区间[beg,end]中的最长递增子序列的长度
	int f[MAX + 1];
	for(int i = beg; i <= end; ++i)
		f[i] = 1;
	for(int i = beg; i <= end; ++i)
		for(int j = beg; j < i; ++j)
			if(s[i] > s[j])
				f[i] = max(f[i], f[j] + 1);
	return(f[end]);
}
int longest_decreasing_subsequence(int s[MAX], int beg, int end)
{
    //[beg, end]是左闭右闭区间，序列s从beg到end
    //返回序列s在区间[beg, end]中的最长递减子序列的长度
	int f[MAX + 1];
	for(int i = beg; i <= end; ++i)
		f[i] = 1;
	for(int i = beg; i <= end; ++i)
		for(int j = beg; j < i; ++j)
			if(s[i] < s[j])
				f[i] = max(f[i], f[j] + 1);
	return(f[end]);
}

int bidirection_subsequence(int s[MAX], int n, int& idx)
{
    //序列s长度为n+1，下标从1到n，空出0位置
    //返回序列s的最长双向子序列的长度，以及这个元素的下标idx
	int length = 0;
	for(int i = 1; i <= n; ++i){
		int lft = longest_increasing_subsequence(s, 1, i);
		int rgt = longest_decreasing_subsequence(s, i, n);
		if(length < lft + rgt)
			length = lft + rgt - 1, idx = i;
	}
	return(length);
}


#endif
