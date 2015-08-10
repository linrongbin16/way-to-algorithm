//最小合并扩展
//minimum merge extension

//与最小合并代价一样 唯一不同是序列s的首尾相接
//题目的原型是石子合并

//与最小合并代价的原理一样 但在循环处增加一点改动
//对所有循环增加一倍的长度 重复存储一遍序列
//这样在循环至结尾时 序列可以直接和后面重复的序列连接起来 模仿首尾相接

#include <climits>
#include <algorithm>
using std::min;
#ifndef MAX
#define MAX 60
#endif
#ifndef INF
#define INF INT_MAX
#endif


int minimum_merge_extension(int *s, int n)
{//序列s的数量为n 下标从1到n 首尾相接 返回最小合并代价
	int f[MAX + 1][2 * MAX + 1], sum[2 * MAX + 1][2 * MAX + 1];
	int ss[2 * MAX + 1], min_cost(INF);
	//用ss数组存储两倍的s
	for(int i = 1; i <= 2 * n; ++i)
		ss[i] = (i > n) ? s[i - n] : s[i];
	//初始化f和sum数组
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= 2 * n; ++j)
			//f的j列需要初始化两倍长度 增加的一倍内存重复一遍
			//而i只需要一倍 在后面的遍历过程中i只需要遍历从1到n的位置
			f[i][j] = (j > n) ? ((i == j - n) ? 0 : INF) : ((i == j) ? 0 : INF);
	for(int i = 1; i <= 2 * n; ++i)
		for(int j = 1; j <= 2 * n; ++j)
			//sum则两个维度都要存储两倍长度
			//支持后面的计算
			sum[i][j] = 0;
	for(int i = 1; i <= 2 * n; ++i)
		for(int j = 1; j <= 2 * n; ++j)
			for(int k = i; k <= j; ++k)
				sum[i][j] += ss[k];
	for(int i = 1; i <= n; ++i)
		//遍历i从1到n 作为合并的左边界
		for(int j = i + 1; j <= 2 * n; ++j)
			//遍历j从i+1到2n 作为合并的右边界
			//当j超过n之后 就可以看做是首尾相接的从左边重新开始
			for(int k = i; k < j; ++k)
				f[i][j] = min(f[i][j],
						f[i][k] + f[k + 1][j] + sum[i][k] + sum[k + 1][j]);
	for(int i = 1; i <= n; ++i)
		//合并从i到i+n-1 枚举所有合并的情况
		//找出最小的代价
		min_cost = min(min_cost, f[i][i + n - 1]);
	return(min_cost);
}
