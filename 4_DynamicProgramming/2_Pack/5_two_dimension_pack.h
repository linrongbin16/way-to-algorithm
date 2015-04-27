#ifndef DYNAMICPROGRAMMING_TWO_DIMENSION_PACK_H
#define DYNAMICPROGRAMMING_TWO_DIMENSION_PACK_H 1
//二维背包
//two_dimension_pack.cpp

//给定背包的两种费用w1和w2，选择集s上有n种物品
//物品s[i]的价值为v[i]，费用1为w1[i]，费用2为w2[i]，可选1个或0个，不能切割
//求背包可以装载的最大价值

//对之前使用的二维数组f[i][j]增加一维，多的一维表示第二种费用k
//设f[i][j][k]表示前i种物品，费用1不大于j，费用2不大于k时的最大价值
//状态转移方程：
//f[i][j][k] = max(f[i-1][j][k], f[i-1][j - w1[i]][k - w2[i]] + v[i])
//w1[i]为物品s[i]的费用1，w2[i]为物品费用2，v[i]为物品价值
//初始条件：f[0][j][k]为0，其中0 <= j <= w1，0 <= k <= w2
//
//由此我们也可以联想到多维背包是使用了更多维度的数组f


#include <algorithm>
using std::swap;
#ifndef OBJECT_MAX
#define OBJECT_MAX 100	//物品最大数量
#endif
#ifndef WEIGHT_MAX
#define WEIGHT_MAX 100	//物品最大重量(费用)
#endif
struct two_dimension_pack_object
{
	int _value;
	int _weight;
	int _count;
	int _weight2;

	two_dimension_pack_object()
	{
		_value = 0;
		_weight = 0;
		_count = 0;
		_weight2 = 0;
	}
	two_dimension_pack_object(const two_dimension_pack_object& obj)
	{
		_value = obj._value;
		_weight = obj._weight;
		_count = obj._count;
		_weight2 = obj._weight2;
	}
	two_dimension_pack_object& operator=(const two_dimension_pack_object& obj)
	{
		_value = obj._value;
		_weight = obj._weight;
		_count = obj._count;
		_weight2 = obj._weight2;
		return(*this);
	}
};

int two_dimension_pack(two_dimension_pack_object *t, int n, int w1, int w2) 
{//物品序列t的数量为n，下标从1到n，空出0位置，背包承重1为w1，承重2为w2
	int f[OBJECT_MAX + 1][WEIGHT_MAX + 1][WEIGHT_MAX + 1];
	for(int i = 0; i <= w1; ++i)
		for(int j = 0; j <= w2; ++j)
			f[0][i][j] = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= w1; ++j)
			for(int k = 0; k <= w2; ++k){
				int object_cnt = ((j / t[i]._weight) && (k / t[i]._weight2)) ? 1 : 0;
				f[i][j][k] = max(f[i - 1][j][k],
						f[i - 1][j - object_cnt * t[i]._weight][k - object_cnt * t[i]._weight2] + object_cnt * t[i]._value);
			}
	return(f[n][w1][w2]);
}

#endif
