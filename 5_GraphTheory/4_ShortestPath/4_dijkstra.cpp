//Dijkstra算法
//dijkstra

//给定无向简单图G和起点beg 求出起点到各点的最短路径及长度
//应用Dijkstra算法的条件:
//该图为有向无回路图 可以进行拓扑排序 不能存在负权值的边

//Dijkstra算法和Prim生成树算法的思路相同 从beg开始向所有邻节点进行扩展
//在Prim算法中 将已加入生成树的节点到beg的距离看做0
//即当节点i已加入生成树中 则distance[i] == 0
//但Dijkstra中用distance数组记录beg到各节点的距离 即使节点已加入生成树也不会置0
//因此又设置visited数组来标记节点是否已加入生成树
//或者查看distance数组的值是否为INF极值 也可以判断该节点是否已经加入生成树
//对于未加入生成树中的节点 每一次按照到beg的距离由小到大重复以下步骤:
//每次从distance中找出未加入生成树中的 到beg距离最小的节点u
//将u加入生成树中 并对u及其邻点进行松弛操作
//重复上述步骤直到所有节点都加入生成树中



#include "general_head.h"
#include "graph.h"
int min_distance(int *distance, int *visited, int beg, int end)
{//[beg, end)是左闭右开区间
	int dist = INF, index = 0;
	for (int i = beg; i < end; ++ i)
		if (dist > distance[i] && !visited[i]) {
			//除过distance[i]为0 或者已经遍历过的节点
			//找出距离最短的新节点
			dist = distance[i];
			index = i;
		}
	return(index);
}

void dijkstra(graph_matrix g, int beg, int *distance, int *path)
{//distance存储起点beg到各节点的最短路径长度 path[i]指代节点i在最短路径上的父节点
 //图G有g_cnt个节点 下标从0到g_cnt-1 起点为beg 返回distance和path数组
	//使用visited指代该节点已被访问 已加入生成树
	int visited[MAX];
	memset(visited, 0, MAX * sizeof(int));
	memset(path, -1, MAX * sizeof(int));
	//节点beg到其他所有节点距离初始化为INF
	for (int i = 0; i < g.g_cnt; ++ i)
		distance[i] = INF;
	distance[beg] = 0;

	//专门不设置visited[beg] = 1
	//在第一次调用min_distance时自然会设置beg的邻节点
	for (int i = 0; i < g.g_cnt - 1; ++ i) {
		//生成树有g_cnt个节点 g_cnt-1条边 故循环g_cnt-1次
		//k是未加入生成树 且到生成树距离最近的节点的下标号
		int k = min_distance(distance, visited, 0, g.g_cnt);
		//该节点加入生成树
		visited[k] = 1;
		for (int j = 0; j < g.g_cnt; ++ j)
			//对节点k的所有出弧边进行判断
			if (distance[k] + g.g_m[k][j] < distance[j]) {
				//松弛操作
				distance[j] = distance[k] + g.g_m[k][j];
				path[j] = k;
			}
	}
}
