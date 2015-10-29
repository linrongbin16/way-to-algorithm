//最小可相交路径覆盖
//minimum_joint_path_covering.cpp

//求简单有向图的最小可相交路径覆盖

//最小可相交路径覆盖问题可以转化为最小不相交路径覆盖
//原始的最小路径覆盖是不可相交的，只需要将图中所有相互能到达的节点都连接起来
//即向任意两存在路径的节点直接添加一条有向边
//用Floyd算法求出任意节点间距离
//对于任意节点i和j，若i到j的距离不是INF，即i到j存在一条路经
//则在图G中添加一条从i指向j的有向边，构造出新的简单有向图G'
//求G'的最小不相交路径覆盖即为原图G的最小可相交路径覆盖
//
//本文引用了“PKU 2594 Treasure Exploration 可相交的最小路径覆盖:传递闭包Floyd+最小路径覆盖”，作者“爱尔兰KEN”

#include "general_head.h"
#include "graph.h"
//floyd.cpp
extern void floyd(graph_matrix& g);
//minimum_disjoint_path_covering.cpp
extern int minimum_disjoint_path_covering(graph_matrix g);

int minimum_joint_path_covering(graph_matrix g)
{//简单有向图G有g_cnt个节点，下标从0到g_cnt-1
 //若从节点i指向节点j存在有向边则g_m[i][j]为1
 //同一节点g_m[i][i]为0，不相连节点g_m[i][j]为INF
 //返回最小可相交路径覆盖数
	graph_matrix f(g);
	floyd(f);
	for(int i = 0; i < f.g_cnt; ++ i)
		for(int j = 0; j < f.g_cnt; ++ j)
			if(i != j && f.g_m[i][j] != INF)
				g.g_m[i][j] = 1;
	return(minimum_disjoint_path_covering(g));
}
