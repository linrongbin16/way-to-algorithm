//区域最大值查询
//range_max_query.cpp

//查询一个序列中某个范围中的最大或最小值

//原始的方法是当给出一个范围[beg, end]时，遍历序列中这个范围的所有元素得到最值
//但时间复杂度太高
//区域最值查询问题也可以用本书第2章中的线段树，区域树这样的数据结构来求解
//但本文介绍的Sparse Table算法(ST算法)是一种最为合适和流行的在线算法
//在经过预处理过程后，读取一个查询之后可以立刻求出区域的最值
//为了方便序列中各个元素的值都是整数，且只查询最大值
//
//Sparse Table算法是一种基于动态规划的算法，需要预先进行一次动态规划作为预处理
//设f[i][j]指代从s[i]起连续2^j个元素，到s[i+(2^j)-1]为止，该范围中的最大值
//其中i >= 1，序列下标从1开始，j >= 0
//当j = 0时，f[i][j] = s[i]，即从s[i]开始连续2^0 = 1个元素，即只有s[i]自己
//状态转移方程：
//f[i][j] = max(f[i][j-1], f[i + 2^(j-1)][j-1])
//其中i >= 1，j >= 1
//初始条件：f[i][0] = s[i]，其中1 <= i <= n
//
//本文引用了“poj 3264 RMQ算法”，作者“品味&兴趣”

#include "general_head.h"

void range_max_query(int *s, int n, map<pair<int, int>, int>& query)
{//序列s有n个元素，下标从1到n
 //查询query中的所有区域的最大值，存储于pair对应的位置
	int f[MAX + 1][MAX + 1];
	for(int i = 1; i <= n; ++ i)
		f[i][0] = s[i];
	for(int j = 1; j <= (int)(log((double)n + 1) / log(2.0)); ++ j)
		//外侧循环j从1到以2为底n的对数即可
		//因为序列s只有n个元素，而j是2的指数
		//但实际计算时由于编程中计算特性需要计算n+1的对数值取整
		for(int i = 1; i + (1 << j) - 1 <= n; ++ i)
			//内存循环i从1开始，且i+(2^j)-1 <= n
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
	for(map<pair<int, int>, int>::iterator it = query.begin();
			it != query.end(); ++ it){
		int beg = min(it->first.first, it->first.second);
		int end = max(it->first.first, it->first.second);
		int k = (int)(log((double)end - beg + 1) / log(2.0));
		it->second = max(f[beg][k], f[end - (1 << k) + 1][k]);
	}
}



