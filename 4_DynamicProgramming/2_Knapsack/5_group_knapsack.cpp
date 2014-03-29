//分组背包
//group_knapsack.cpp

//给定背包承重w，选择集s上有n种物品，物品s[i]的重量为w[i]，价值为v[i]
//这些物品被划分为grpcnt个组，每组中有objcnt个物品，同一组中物品相互冲突
//即只能在一组中选择一种物品，每种物品选择1个或0个不能切割，求背包可以装载的最大价值

//在每一组中尽量选择最优的那个物品
//在每一组的物品中做一次01背包即可为组间的动态选择提供每一组中选择的依据
//设f[k][j]表示前k组，重量不大于j的最大价值
//状态转移方程：
//f[k][j] = max(f[k - 1][j], f[k - 1][j - w[i]] + v[i])
//其中i表示第k组中的某个物品, 1 <= i <= g[k].objcnt
//初始条件：f[k][j]为0，其中0 <= k <= grpcnt，0 <= j <= w

#include "general_head.h"
#include "knapsack.h"
bool compare(object a, object b);

int group_knapsack(group_object t, int w) 
{//物品分组t的组数量为g_grpcnt，下标从1到g_grpcnt
 //每个分组中的物品数量为g_objcnt，下标从1到g_objcnt，物品总数为g_totalcnt
 //背包承重为w
	int f[OMAX + 1][WMAX + 1];
	for(int k = 0; k <= t.g_grpcnt; ++ k)
		for(int j = 0; j <= w; ++ j)
			f[k][j] = 0;
	for(int i = 1; i <= t.g_grpcnt; ++ i)
		//对分组i中物品进行排序
		//该分组中的1到g_objcnt+1
		//先将单位价值最大的放在前面
		//同样单位价值的物品，重量较小的在前
		sort((object*)(t.g + i) + 1, 
				(object*)(t.g + i) + t.g_objcnt + 1, 
				compare);
	for(int k = 1; k <= t.g_grpcnt; ++ k)
		//将每个分组中的同一组物品当做一次01背包
		//j的循环从w到0，这是在只考虑第二维数组的空间优化的01背包
		for(int j = w; j >= 0; -- j)
			for(int i = 1; i <= t.g_objcnt; ++ i){
				int object_cnt = (j / t.g[k][i].o_weigh) ? 1 : 0;
				f[k][j] = max(f[k][j],
						f[k - 1][j - object_cnt * t.g[k][i].o_weigh] +
						 object_cnt * t.g[k][i].o_value);
			}
	return(f[t.g_grpcnt][w]);
}
bool compare(object a, object b) 
{
	//先比较物品单位价值
	if(((double)a.o_value / a.o_weigh) != 
			((double)b.o_value / b.o_weigh))
		return(((double)a.o_value / a.o_weigh) > 
				((double)b.o_value / b.o_weigh));
	//再比较物品重量
	if(a.o_weigh != b.o_weigh)
		return(a.o_weigh < b.o_weigh);
	return(false);
}









