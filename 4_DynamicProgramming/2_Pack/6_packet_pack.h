#ifndef DYNAMICPROGRAMMING_PACKET_PACK_H
#define DYNAMICPROGRAMMING_PACKET_PACK_H 1
//分组背包
//packet_pack.cpp

//给定背包承重w，选择集s上有n种物品，物品s[i]的重量为w[i]，价值为v[i]
//这些物品被划分为group_number个组，每组中有_object_number个物品，同一组中物品相互冲突
//即只能在一组中选择一种物品，每种物品选择1个或0个不能切割，求背包可以装载的最大价值

//在每一组中尽量选择最优的那个物品
//在每一组的物品中做一次01背包即可为组间的动态选择提供每一组中选择的依据
//设f[k][j]表示前k组，重量不大于j的最大价值
//状态转移方程：
//f[k][j] = max(f[k - 1][j], f[k - 1][j - w[i]] + v[i])
//其中i表示第k组中的某个物品, 1 <= i <= g[k]._object_number
//初始条件：f[k][j]为0，其中0 <= k <= group_number，0 <= j <= w


#include <algorithm>
using std::sort;
#include "1_01_pack.h"
#ifndef GROUP_MAX
#define GROUP_MAX 100
#endif
struct packet_object
{
	//分组的物品
	//第一维表示分组号，从1到_group_number组
	//第二维表示一组中的物品号，从1到_object_number号
	_01_pack_object _objects[GROUP_MAX][OBJECT_MAX];
	int _group_number;	//物品分组数量
	int _object_number;	//每个分组下的物品数量
	int _total;			//所有物品总数 _total = _group_number * _object_number

	packet_object()
	{
		for (int i = 0; i < GROUP_MAX; ++i)
			for (int j = 0; j < OBJECT_MAX; ++j) {
				_objects[i][j]._value = 0;
				_objects[i][j]._weight = 0;
				_objects[i][j]._count = 0;
			}
		_group_number = 0;
		_object_number = 0;
		_total = 0;
	}
	packet_object(const packet_object& packet)
	{
		for (int i = 0; i < GROUP_MAX; ++i)
			for (int j = 0; j < OBJECT_MAX; ++j)
				_objects[i][j] = packet._objects[i][j];
		_group_number = packet._group_number;
		_object_number = packet._object_number;
		_total = packet._total;
	}
	packet_object& operator=(const packet_object& packet)
	{
		for (int i = 0; i < GROUP_MAX; ++i)
			for (int j = 0; j < OBJECT_MAX; ++j)
				_objects[i][j] = packet._objects[i][j];
		_group_number = packet._group_number;
		_object_number = packet._object_number;
		_total = packet._total;
		return(*this);
	}
};
bool compare(_01_pack_object a, _01_pack_object b) 
{
	//先比较物品单位价值
	if(((double)a._value / a._weight) != ((double)b._value / b._weight))
		return(((double)a._value / a._weight) > ((double)b._value / b._weight));
	//再比较物品重量
	if(a._weight != b._weight)
		return(a._weight < b._weight);
	return(false);
}

int packet_pack(packet_object t, int w) 
{//背包承重为w
	int f[OBJECT_MAX + 1][WEIGHT_MAX + 1];
	for(int k = 0; k <= t._group_number; ++k)
		for(int j = 0; j <= w; ++j)
			f[k][j] = 0;
	for(int i = 1; i <= t._group_number; ++i)
		//对分组i中物品进行排序
		//该分组中的1到_object_number+1
		//先将单位价值最大的放在前面
		//同样单位价值的物品，重量较小的在前
		sort((_01_pack_object*)(t._objects + i) + 1, (_01_pack_object*)(t._objects + i) + t._object_number + 1, compare);
	for(int k = 1; k <= t._group_number; ++k)
		//将每个分组中的同一组物品当做一次01背包
		//j的循环从w到0，这是在只考虑第二维数组的空间优化的01背包
		for(int j = w; j >= 0; --j)
			for(int i = 1; i <= t._object_number; ++i){
				int object_cnt = (j / t._objects[k][i]._weight) ? 1 : 0;
				f[k][j] = max(f[k][j],
						f[k - 1][j - object_cnt * t._objects[k][i]._weight] + object_cnt * t._objects[k][i]._value);
			}
	return(f[t._group_number][w]);
}


#endif
