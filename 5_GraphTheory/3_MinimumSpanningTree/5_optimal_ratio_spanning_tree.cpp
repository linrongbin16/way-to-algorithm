//最优比率生成树
//optimal_ratio_spanning_tree.cpp

//在无向简单图G中，边i有两个参数长度dist[i]和花销cost[i]，均为正整数
//求一棵生成树使得比率ratio = (sum(cost[i])) / (sum(dist[i])) 最小
//其中i是生成树中的边，sum(dist[i])或sum(cost[i])即为生成树所有边的长度或花销之和
//给定这个比率的最大值和最小值
//求生成树中边的花销之和除以长度之和的比率ratio最小的生成树
//
//典故：2005年ACM地区赛赛场上的经典题目最优比率生成树，传说中楼爷1A的G题

//最有比率生成树问题是一个01分数规划问题
//比较流行的算法有Dinkelbach算法和二分法，本文讲二分法
//无向简单图G的所有边的长度dist和花销cost的值都是正整数
//设Cmax是所有边中花销最大的，n是图G的边数量
//则比率ratio的取值范围是[-Cmax*n, Cmax*n]
//
//设x[i] = | 1	边e[i]属于生成树
//		   | 0	边e[i]不属于生成树
//所求比率转化为ratio = (sum(x[i] * cost[i])) / (sum(x[i] * dist[i]))
//其中i是图G中所有边，将该式简写做 ratio = Cost / Dist
//显然可以将比率变化为 ratio * Dist = Cost
//既有 Cost - ratio * Dist = 0，设ratio的最小值为ratio_min，则易有下列结论：
//ratio > ratio_min时，Cost - ratio * Dist < 0
//ratio == ratio_min时，Cost - ratio * Dist == 0
//ratio < ratio_min时，Cost - ratio * Dist > 0
//
//对于图G中的边i，设d[i] = cost[i] - ratio * dist[i]，将d[i]作为边i的权值
//则图G可以得到一个最小生成树，该生成树权值之和即为 Cost - ratio * Dist
//比率ratio的取值范围[-Cmax*n, Cmax*n]即为二分法起始时的最大最小边界
//然后用二分法枚举ratio值，判断Cost - ratio * Dist结果与 0 的关系
//最终求出当该式等于 0 时 ratio 的值即为 ratio 的最小值 ratio_min

#include "general_head.h"
#include "graph.h"
//kruskal.cpp
extern void kruskal(edge_list& e);
void clear_tree_status(edge_list& e);

double optimal_ratio_spanning_tree(edge_list& e, double low, double high)
{//边集e有e_l.size()条边，下标从0到e_l.size()-1
 //low为ratio最小值，high为最大值，返回最小比率ratio
	double ratio;
	//二分查找ratio
	while(low <= high){
		ratio = (low + high) / 2;
		//将边集中的边i的e_value设置为d[i] = cost[i] - ratio * dist[i]
		//在kruskal算法中将e_value作为边的权值进行生成树的生成
		for(int i = 0; i < (int)e.e_l.size(); ++ i)
			e.e_l[i].e_value = e.e_l[i].e_cost - ratio * e.e_l[i].e_dist;	
		//清除边集e中生成树的状态e_join
		clear_tree_status(e);
		kruskal(e);
		double answer(0);
		//计算Cost - ratio * Dist的值
		for(int i = 0; i < (int)e.e_l.size(); ++ i)
			answer += e.e_l[i].e_join * e.e_l[i].e_cost -
				ratio * e.e_l[i].e_join * e.e_l[i].e_dist;
		if(answer == 0)
			return(ratio);
		else if(answer > 0)
			low = ratio;
		else
			high = ratio;
	}
	return(0);
}
void clear_tree_status(edge_list& e)
{
	for(int i = 0; i < (int)e.e_l.size(); ++ i)
		e.e_l[i].e_join = 0;
}
