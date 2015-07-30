//Floyd算法
//floyd

//在无向简单图G上求出所有节点到其他任意节点的最短路径长度

//1)传递闭包原理的应用
//集合S上有一二元关系R 它的传递闭包是包含R的S上的最小传递关系
//比如: 
//集合S为人 关系R为父子 则传递闭包为关系"x是y的祖先"
//集合S为车站 关系R为车次 则传递闭包为关系"x经过若干车次到达y"
//可以看出集合S是图的点集 关系R是图的有向边集
//而x与y的传递闭包关系是节点x到节点y的最短路径
//传递闭包的典型应用即为Floyd-Warshall算法
//
//2)具体步骤: 
//在任意两点i和j间 考察所有其他节点 若某节点k有这样的性质:
//dist(i,j) > dist(i,k) + dist(k,j)即i_k加k_j的距离大于原本估计的距离
//则更新i_j距离 对每对节点i和j做这样的循环 最终可以得到所有节点的最短路径矩阵


#include "general_head.h"
#include "graph.h"

void floyd(graph_matrix& g)
{//图G有g_cnt个节点 下标从0到g_cnt-1 直接操作图G中各节点距离
 //同一节点的g.g_m值为0 不相连的节点g.g_m值为INF
	for (int k = 0; k < g.g_cnt; ++ k)
		for (int i = 0; i < g.g_cnt; ++ i)
			for (int j = 0; j < g.g_cnt; ++ j)
				g.g_m[i][j] = min(g.g_m[i][j], g.g_m[i][k] + g.g_m[k][j]);
}
