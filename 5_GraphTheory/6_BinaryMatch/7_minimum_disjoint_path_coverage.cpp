//最小不相交路径覆盖
//minimum_disjoint_path_covering.cpp

//求简单有向图中的最小不相交路径覆盖数

//在图G=<V,E>中，V是节点集合，E是边集合
//路径覆盖：
//边集E的一个子集，该子集组成一个路径集合，每条路径可以从任意节点开始和结束
//使得V中所有节点都属于该子集中边的端点，当图中只有一个节点时路径长度为0
//一个节点只能属于一条路经，不能重复
//最小路径覆盖：
//路径数量最少的路径覆盖
//路径覆盖定理：
//原有向图的最小路径覆盖数 = 原有向图的节点数量 - 对应二分图的最大匹配数
//路径覆盖转化为二分图，拆点法：
//将图G中的每个节点i都拆分成两个节点xi和yi
//设原图G中的一条有向边e从节点i指向节点j，将该边变为从新节点xi与yj之间的无向边
//即得到原图对应的二分图

#include "general_head.h"
#include "graph.h"
//hopcroft_karp.cpp
extern int hopcroft_karp(bipartite b, int *xmatch, int *ymatch);
void construct_b(graph_matrix g, bipartite& b);

int minimum_disjoint_path_covering(graph_matrix g)
{//简单有向图G有g_cnt个节点，下标从0到g_cnt-1
 //若从节点i指向节点j存在有向边则g_m[i][j]为1
 //同一节点的g_m值为0，不相连节点的g_m值为INF
 //返回最小不相交路径覆盖数
	bipartite b;
	int xmatch[MAX], ymatch[MAX];
	memset(xmatch, -1, MAX * sizeof(int));
	memset(ymatch, -1, MAX * sizeof(int));
	construct_b(g, b);
	return(g.g_cnt - hopcroft_karp(b, xmatch, ymatch));
}
void construct_b(graph_matrix g, bipartite& b)
{
	b.b_xn = b.b_yn = g.g_cnt;
	for(int i = 0; i < g.g_cnt; ++ i)
		for(int j = 0; j < g.g_cnt; ++ j)
			if(i != j && g.g_m[i][j] != INF)
				b.b_g[i][j] = g.g_m[i][j];
}
