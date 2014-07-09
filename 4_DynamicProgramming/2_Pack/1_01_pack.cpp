//01背包
//_01_pack.cpp

//给定背包最大承重w，选择集s有n个物品，s[i]物品的价值是v[i]，重量(费用)是w[i]
//每种物品只能选1个或0个，不能切割，求出背包可以装载的最大价值
//以及背包装载最大价值时选择了哪些物品，即解决方案，也称动规路径

//设f[i][j]表示背包中放入前i件物品，重量不大于j的最大价值
//f[i-1][j]在选择第i件物品时，可以选择放入或者不放，对自己的重量j状态也有影响
//状态转移方程：
//f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i])
//其中w[i]是物品i的重量，v[i]是物品i的价值
//初始条件：f[0][j]为0，其中0 <= j <= w
//请注意状态转移方程中f中下标的计算，这是所有背包问题的核心技术
//
//本节引用了“背包九讲”，作者“DD”

//1)求最大价值的原始方法

#include "general_head.h"
#include "pack.h"

int _01_pack1(object *t, int n, int w) 
{//物品序列t的数量为n，下标从1到n，空出0位置，背包承重为w
 //返回背包能装载的最大价值
	int f[OMAX + 1][WMAX + 1];
	for(int i = 0; i <= w; ++ i)
		f[0][i] = 0;
	for(int i = 1; i <= n; ++ i)
		for(int j = 0; j <= w; ++ j){
			//01背包中每个物品最多被选中1个
			//并且重量小于该物品重量时不能选择
			//在完全背包问题中，物品数量会被扩展为
			//object_cnt = w / t[i].weight
			int object_cnt = (j / t[i].o_weigh) ? 1 : 0;
			f[i][j] = max(f[i - 1][j], 
					f[i - 1][j - object_cnt * t[i].o_weigh] + 
					object_cnt * t[i].o_value);
		}
	//第n个物品，第w的重量时的最大价值即为所求
	return(f[n][w]);
}

//2)求最大价值的优化空间方法

int _01_pack2(object *t, int n, int w)
{
	int f[WMAX + 1];
	for(int i = 0; i <= w; ++ i)
		f[i] = 0;
	for(int i = 1; i <= n; ++ i)
		//使用一维数组存储时，重量循环从最大值开始
		//该优化技术在本节的分组背包中也使用到了
		for(int j = w; j >= 0; -- j){
			int object_cnt = (j / t[i].o_weigh) ? 1 : 0;
			f[j] = max(f[j], 
				f[j - object_cnt * t[i].o_weigh] + 
				object_cnt * t[i].o_value);
		}
	return(f[w]);
}

//3)求最大价值以及解决方案

int _01_pack3(object *t, int n, int w, int *choose)
{//物品序列t的数量为n，下标从1到n，空出0位置
 //背包承重为w，choose数组标记某个物品是否被选中，选中为1，未选中为0
 //返回背包能装载的最大价值以及解决方案
	
}





