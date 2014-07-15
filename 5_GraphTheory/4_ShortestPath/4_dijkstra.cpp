//Dijkstra算法
//dijkstra.cpp

//给定无向简单图G和起点beg，求出起点到各点的最短路径及长度
//应用Dijkstra算法的条件：
//该图为有向无回路图，可以进行拓扑排序，不能存在负权值的边

//Dijkstra算法和Prim生成树算法的思路相同，从beg开始向所有邻节点进行扩展
//在Prim算法中，将已加入生成树的节点到beg的距离看做0
//即当节点i已加入生成树中，则distance[i] == 0
//但Dijkstra中用distance数组记录beg到各节点的距离，即使节点已加入生成树也不会置0
//因此又设置了visited数组来标记节点是否已加入生成树
//对于未加入生成树中的节点，每一次按照到beg的距离由小到大重复以下步骤：
//每次从distance中找出未加入生成树中的，到beg距离最小的节点u
//将u加入生成树中，并对u及其邻点进行松弛操作
//重复上述步骤直到所有节点都加入生成树中
//
//我忠实的实现了算法导论中关于Dijkstra算法的伪语言描述

#include "general_head.h"
#include "graph.h"
int min_distance(int *distance, int *visited, int beg, int end);

void dijkstra(graph_matrix g, int beg, int *distance, int *path)
{//distance存储起点beg到各节点的最短路径长度，path[i]指代节点i在最短路径上的父节点
 //图G有g_cnt个节点，下标从0到g_cnt-1，起点为beg，返回distance和path数组
	//使用visited指代该节点已被访问，已加入生成树
	int visited[MAX];
	memset(visited, 0, MAX * sizeof(int));
	for(int i = 0; i < g.g_cnt; ++ i)
		path[i] = beg;
	//不直接连接点beg的节点距离视作INF无穷大
	for(int i = 0; i < g.g_cnt; ++ i)
		distance[i] = g.g_m[beg][i];
	distance[beg] = 0;

	visited[beg] = 1;
	for(int i = 0; i < g.g_cnt - 1; ++ i){
		//生成树有g_cnt个节点，g_cnt-1条边，故循环g_cnt-1次
		//k是未加入生成树，且到生成树距离最近的节点的下标号
		int k = min_distance(distance, visited, 0, g.g_cnt);
		//该节点加入生成树
		visited[k] = 1;
		for(int j = 0; j < g.g_cnt; ++ j)
			//对节点k的所有出弧边进行判断
			if(distance[k] + g.g_m[k][j] < distance[j]){
				//松弛操作
				distance[j] = distance[k] + g.g_m[k][j];
				path[j] = k;
			}
	}
}
int min_distance(int *distance, int *visited, int beg, int end)
{//[beg, end)是左闭右开区间
	int dist(INF), index(0);
	for(int i = beg; i < end; ++ i)
		if(dist > distance[i] && !visited[i]){
			//除过distance[i]为0，或者已经遍历过的节点
			//找出距离最短的新节点
			dist = distance[i];
			index = i;
		}
	return(index);
}
