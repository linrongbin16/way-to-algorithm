#ifndef DYNAMICPROGRAMMING_01_PACK_PATH_H
#define DYNAMICPROGRAMMING_01_PACK_PATH_H 1
//01背包路径
//01 pack path

//给定背包最大承重w 集合s有n个物品 s[i]物品的价值是v[i] 重量(费用)是w[i]
//每种物品只能选1个或0个 总重量不能超过w 求出背包可以装载的最大价值
//以及背包装载最大价值时选择了哪些物品 即解决方案 也称动规路径
//为了求出动规路径题目额外给出一个条件 所有物品的价值总和为x

//设f[i][j]表示背包中放入前i件物品 重量不大于j的最大价值
//状态转移方程:
//f[i][j] = max(f[i-1][j], f[i-1][ j - w[i] ] + v[i])
//初始条件: f[0][j]为0 其中0<=j<=w
//这些都与本文前一篇完全一样 但为了求出动规路径 需要额外的增加一个数组path
//设path[i][j][k]=true表示选中了第i件物品时 重量不大于j 最大价值为k
//而path[i][j][k]=false表示未选中第j件物品时 重量不大于j 最大价值为k
//通过这个数组来获得最终某件物品是否被选中


#include <cstring>
#include "1_01_pack.h"
#ifndef VALUE_MAX
#define VALUE_MAX 500
#endif

int _01_pack_path(_01_pack_object *t, int n, int w, bool *choose)
{//物品序列t的数量为n 下标从1到n 空出0位置 背包承重为w
 //返回背包能装载的最大价值以及物品被选的结果 存储在choose数组
	int f[OBJECT_MAX + 1][WEIGHT_MAX + 1];
	//VALUE_MAX是所有物品的价值总和最大值
	bool path[OBJECT_MAX + 1][WEIGHT_MAX + 1][VALUE_MAX + 1];
	for (int i = 0; i <= w; ++i)
		f[0][i] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= w; ++j) {
			int object_cnt = (j / t[i].m_weight) ? 1 : 0;
			int oldf = f[i - 1][j];
			int newf = f[i - 1][j - object_cnt * t[i].m_weight] + object_cnt * t[i].m_value;
			//对f数组的操作与前一篇中相同
			//但增加了path数组的判断
			if(oldf >= newf){
				//只有当出现更高价值的选择时才更新
				f[i][j] = oldf;
				//没有选择第i件物品 重量为j 价值为oldf
				path[i][j][oldf] = false;
			}
			else{
				f[i][j] = newf;
				//选择了第i件物品 重量为j 价值为newf
				path[i][j][newf] = true;
			}
		}
	//通过path求出动规路径
    for (int i = 0; i < OBJECT_MAX + 1; ++i)
        choose[i] = false;
	int value = f[n][w], weight = w;
	for (int i = n; i >= 1; --i) {
		//若第i件物品被选中 重量不大于weight 价值为value
		//则置choose[i]为true 由于最终动规的最大价值为f[n][w]
		//因此将weight置为w value置为f[n][w] 从最后一个物品n开始倒着向前
		if(path[i][weight][value]){
			choose[i] = true;
			//总重量和总价值都减去第i件物品
			weight -= t[i].m_weight;
			value -= t[i].m_value;
		}
	}
	//第n个物品 第w的重量时的最大价值即为所求
	return(f[n][w]);
}


#endif
