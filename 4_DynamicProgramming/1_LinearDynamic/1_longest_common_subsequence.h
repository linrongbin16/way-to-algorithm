#ifndef DYNAMICPROGRAMMING_LONGEST_COMMON_SUBSEQUENCE_H
#define DYNAMICPROGRAMMING_LONGEST_COMMON_SUBSEQUENCE_H 1
//最长公共子序列
//longest common subsequence

//求两长度相同的序列s1和s2的最长公共子序列的长度
//子序列中相邻的两个成员在原序列中可以是不相邻的 但在原序列中的相对顺序不变

//子序列中相邻的两个成员在原序列中可以是不相邻的 但在原序列中的相对顺序不变
//这意味着可以出现这样的情况，对于序列s1(1 2 3 4 5)和s2(1 4 0 7 8)
//它们的最长公共子序列是(1 4) 其中成员1和4在原序列s1中不相邻 但相对顺序不变
//
//设置f[i][j]表示s1中前i个元素 s2中前j个元素的最长公共子列长度
//本章中的所有动态规划在解题时都会使用f数组来存储决策结果
//状态转移方程:
//f[i][j] =	| 0							    i==0 || j==0
//			| f[i-1][j-1]+1			        i>0 && j>0 && s1[i]==s2[j]
//			| max(f[i][j-1], f[i-1][j])	    i>0 && j>0 && s1[i]!=s2[j]
//初始条件:f[i][0]和f[0][i]为0 其中0<=i<=n
//
//本章中使用数组的方式与其他章节不太一样
//一般情况下我会将一个数组长度设为n 其中成员设为从0到n-1
//但在本章的所有算法中 数组的长度都被设置为n+1 成员都是从1到n 而把0空出来
//这是为了给状态转移方程中的初始状态留出一个位置 请留意这个细节
//本章的所有算法都会这样处理数组 以后不再特别说明

#include <algorithm>
using std::max;
#ifndef MAX
#define MAX 60
#endif

int longest_common_subsequence(int s1[MAX], int *s2, int n)
{//序列s1和s2的长度都为n+1 下标从1到n 空出0位置
 //返回s1和s2的最长公共子序列的长度
	int f[MAX + 1][MAX + 1];
	for (int i = 0; i <= n; ++i) {
		f[0][i] = 0;
        f[i][0] = 0;
    }
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			if (s1[i] == s2[j])
				f[i][j] = f[i - 1][j - 1] + 1;
			else
				f[i][j] = max(f[i][j - 1], f[i - 1][j]);
		}
	return(f[n][n]);
}

#endif
