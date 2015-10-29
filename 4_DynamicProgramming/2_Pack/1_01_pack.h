#ifndef DYNAMICPROGRAMMING_01_PACK_H
#define DYNAMICPROGRAMMING_01_PACK_H 1
//01背包
//01 pack

//给定背包最大承重w 集合s有n个物品 s[i]物品的价值是v[i] 重量(费用)是w[i]
//每种物品只能选1个或0个(选或不选) 总重量不能超过w 求出背包可以装载的最大价值

//设f[i][j]表示背包中放入前i件物品 重量不大于j的最大价值
//f[i-1][j]在选择第i件物品时 可以选择放入或者不放 对自己的重量j状态也有影响
//状态转移方程:
//f[i][j] = max(f[i-1][j], f[i-1][ j- w[i] ] + v[i])
//其中w[i]是物品i的重量 v[i]是物品i的价值 注意j-w[i]是第二维数组的下标值
//初始条件: f[0][j]为0 其中0<=j<=w
//请注意状态转移方程中f中下标的计算 这是所有背包问题的核心技术
//
//本节引用了"背包九讲" 作者"DD"


#include <algorithm>
using std::swap;
using std::max;
#ifndef OBJECT_MAX
#define OBJECT_MAX 100	//物品最大数量
#endif
#ifndef WEIGHT_MAX
#define WEIGHT_MAX 100	//物品最大重量(费用)
#endif
struct _01_pack_object
{
	int m_value;
	int m_weight;
	int m_count;

	_01_pack_object()
	{
		m_value = 0;
		m_weight = 0;
		m_count = 0;
	}
	_01_pack_object(const _01_pack_object& obj)
	{
		m_value = obj.m_value;
		m_weight = obj.m_weight;
		m_count = obj.m_count;
	}
	_01_pack_object& operator=(const _01_pack_object& obj)
	{
		m_value = obj.m_value;
		m_weight = obj.m_weight;
		m_count = obj.m_count;
		return(*this);
	}
};

//1)求最大价值的原始方法
int _01_pack1(_01_pack_object *t, int n, int w) 
{//物品序列t的数量为n 下标从1到n 空出0位置 背包承重为w
 //返回背包能装载的最大价值
	int f[OBJECT_MAX + 1][WEIGHT_MAX + 1];
	for(int i = 0; i <= w; ++i)
		f[0][i] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= w; ++j) {
			//01背包中每个物品最多被选中1个
			//并且重量小于该物品重量时不能选择
			//在完全背包问题中，物品数量会被扩展为
			//object_cnt = w / t[i].weight
			int object_cnt = (j / t[i].m_weight) ? 1 : 0;
			f[i][j] = max(f[i - 1][j],
                    f[i - 1][j - object_cnt * t[i].m_weight] + object_cnt * t[i].m_value);
		}
	//第n个物品 第w的重量时的最大价值即为所求
	return(f[n][w]);
}

//2)求最大价值的优化空间方法
int _01_pack2(_01_pack_object *t, int n, int w)
{
	int f[WEIGHT_MAX + 1];
	for (int i = 0; i <= w; ++i)
		f[i] = 0;
	for (int i = 1; i <= n; ++i)
		//使用一维数组存储时，重量循环从最大值开始
		//该优化技术在本节的分组背包中也使用到了
		for (int j = w; j >= 0; --j) {
			int object_cnt = (j / t[i].m_weight) ? 1 : 0;
			f[j] = max(f[j],
                    f[j - object_cnt * t[i].m_weight] + object_cnt * t[i].m_value);
		}
	return(f[w]);
}


#endif
