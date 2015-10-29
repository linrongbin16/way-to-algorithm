#ifndef DYNAMICPROGRAMMING_COMPLETE_PACK_H
#define DYNAMICPROGRAMMING_COMPLETE_PACK_H 1
//完全背包
//complete pack

//给定背包承重w 选择集s中有n个物品可以选择 物品s[i]的价值为v 重量为w[i]
//每种物品可以选择0个或无限多个 总重量不能超过w 求出背包可以装载的最大价值

//类似01背包 在选择每种物品时 枚举当时重量为j的所有可能
//设f[i][j]指代背包中有前i个物品 重量不大于j时的最大价值
//状态转移方程:
//f[i][j] = max(f[i][j], f[i-1][ j - k * w[i] ] + k * v[i])
//其中k为当前物品可以选择的个数 0<=k<=j/w[i]
//w[i]是物品i的重量 v[i]是物品i的价值
//初始条件: f[i][j]为0 其中0<=i<=n 0<=j<=w


#include "1_01_pack.h"

int complete_pack(_01_pack_object *t, int n, int w) 
{//物品序列t的数量为n 下标从1到n 空出0位置 背包承重为w
	int f[OBJECT_MAX + 1][WEIGHT_MAX + 1];
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= w; ++j)
			f[i][j] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= w; ++j){
			int object_cnt = j / t[i].m_weight;
			for (int k = 0; k <= object_cnt; ++k)
                f[i][j] = max(f[i][j],
					f[i - 1][j - k * t[i].m_weight] + k * t[i].m_value);
		}
	return(f[n][w]);
}

#endif
