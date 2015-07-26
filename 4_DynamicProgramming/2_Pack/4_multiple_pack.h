#ifndef DYNAMICPROGRAMMING_MULTIPLE_PACK_H
#define DYNAMICPROGRAMMING_MULTIPLE_PACK_H 1
//多重背包
//multiple pack

//给定背包承重w 集合s上有n种物品 物品s[i]的价值为v[i] 重量为w[i]
//每种物品最多可选cnt[i]个 最少可选0个 总重量不能超过w 求背包可以装载的最大价值

//与完全背包类似 但每种物品的可选个数最大值由当前重量和该物品数量两者一起决定
//状态转移方程也与完全背包一样:
//f[i][j] = max(f[i-1][ j - k * w[i] ] + k * v[i])
//其中k的取值与完全背包不同: 0<=k<=min(j / w[i], cnt[i])
//w[i]是物品s[i]的重量 v[i]是物品价值 cnt[i]是物品数量
//初始条件与完全背包一样: f[i][j]为0 其中0<=i<=n 0<=j<=w


#include <algorithm>
using std::min;
#include "1_01_pack.h"

int multiple_pack(_01_pack_object *t, int n, int w) 
{//物品序列t的数量为n 下标从0到n 空出0位置 背包承重为w
	int f[OBJECT_MAX + 1][WEIGHT_MAX + 1];
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= w; ++j)
			f[i][j] = 0; 
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= w; ++j) {
			int object_cnt = min((j / t[i].m_weight), t[i].m_count);
			for (int k = 0; k <= object_cnt; ++k)
				f[i][j] = max(f[i][j],
					f[i - 1][j - k * t[i].m_weight] + k * t[i].m_value);
		}
	return(f[n][w]);
}

#endif
