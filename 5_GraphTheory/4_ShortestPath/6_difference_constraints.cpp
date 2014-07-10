//差分约束
//difference_constraints.cpp

//求出差分约束系统的一个可行解

//1)差分约束是这样一类线性约束 Ax <= b
//线性矩阵A中每一行包含一个1和一个-1，其余所有值都是0
//在n个未知元x上，有m个差分约束集合，第k个约数型为：xj - xi <= bk
//其中 1<=i,j<=n，1<=k<=m
//例如这样的矩阵：|  1 -1  0  0  0 |           | 0 |
//                |  1  0  0  0 -1 |           |-1 |
//                |  0  1  0  0 -1 | | x1 |    | 1 |
//                | -1  0  1  0  0 | | x2 |    | 5 |
//                | -1  0  0  1  0 | | x3 | <= | 4 |
//                |  0  0 -1  1  0 | | x4 |    |-1 |
//                |  0  0 -1  0  1 | | x5 |    |-3 |
//                |  0  0  0 -1  1 |           |-3 |
//这个差分约束中，未知元x有5个，有8个约束条件，也可以转化为如下的8个不等式：
//	x1 - x2 <= 0
//	x1 - x5 <= -1
//	x2 - x5 <= 1
//	-x1 + x3 <= 5
//	-x1 + x4 <= 4
//	-x3 + x4 <= -1
//	-x3 + x5 <= -3
//	-x4 + x5 <= -3
//存在x=(-5, -3, 0, -1, -4)是差分约束的一个解
//则对于任意常数d，都有：x+d=(-5+d, -3+d, 0+d, -1+d, -4+d)也是这个差分约束的解
//引理：对于一个m*n(m个不等式n个未知量)的差分约束Ax<=b，设x=(x1,x2,...,xn)是一个解
//则对于任意常数d，x+d=(x1+d,x2+d,...,xn+d)也是该差分约束的解
//
//2)差分约束的约束图
//将这样的Ax<=b表现为图，每个未知量xi是一个节点vi
//有趣的是，需要再加一个节点v0，增加的节点v0是为了让原图必为一个连通图
//这样图中共n+1个节点
//对每个约束 xj-xi<=bk 转化为：边 vi->vj 的权值为 bk
//图中增加 m 条边，不需要考虑那些 0
//而新增v0节点对其他n个节点都有边 v0->vi ，权值为0
//图中增加 n 条边，共 n+m 条边，即只有v0这个节点向外有权值为0的边
//使用Bellman-Ford算法求出构造图中，以v0为源点到其余各节点的最短路径distance数组
//原差分约束中未知量有n个，从1到n，新增节点为v0
//则distance数组中从1到n元素即为未知量从x1到xn的一个可行解
//若返回false则图中含有负权回路，不存在最短路径
//若返回true则最短路径权值给出了差分系统的一个解
//
//我忠实的实现了算法导论中关于差分约束的描述

#include "general_head.h"
#include "graph.h"
//bellman_ford.cpp
extern bool bellman_ford(graph_matrix g, edge_list e, 
		int beg, int *distance, int *path);

bool difference_constraints(int **s, int m, int n, int *b, int *distance)
{//矩阵s有m行n列，b是矩阵右边一列，s和b之间为<=号
 //返回差分约束是否存在可行解
 //若存在则返回数组distance，下标从1到n为差分约束中未知量x1到xn的一个可行解
	graph_matrix g;
	edge_list e;
	//g_m中同一节点距离为0，不直接相连节点为INF
	//edge_list中存储m个不等式，每个不等式都是一条边，再加n个权值为0的边
	for(int i = 0; i <= n; ++ i)
		for(int j = 0; j <= n; ++ j)
			//初始化g的所有距离，同一节点为0，不直接相连节点为INF
			g.g_m[i][j] = ((i == j) ? 0 : INF);
	for(int i = 0; i < n; ++ i){
		//v0节点对其他n个节点都有边 v0->vi
		//权值为0，增加n条边，这里是有向图的边
		g.g_m[0][i + 1] = 0;
		edge p;
		p.e_beg = 0; p.e_end = i + 1; p.e_value = 0;
		e.e_l.push_back(p);
	}
	for(int i = 0; i < m; ++ i){
		//增加所有m个约束，矩阵s中的下标对应到图G中都要+1
		int idx1, idx2;
		for(int j = 0; j < n; ++ j){
			if(s[i][j] == 1)
				idx1 = j;
			else if(s[i][j] == -1)
				idx2 = j;
		}
		//对每个约束 xj-xi<=bk 转化为：
		//边 vi->vj 的权值为 bk ，共m条边
		g.g_m[idx2 + 1][idx1 + 1] = b[i];
		edge p;
		p.e_beg = idx2 + 1; p.e_end = idx1 + 1; p.e_value = b[i];
		e.e_l.push_back(p);
	}
	g.g_cnt = n + 1;
	int *path = new int[MAX];
	//若Bellman-Ford算法存在最短路径则存在可行解，否则不存在
	if(bellman_ford(g, e, 0, distance, path))
		return(true);
	else
		return(false);
}
