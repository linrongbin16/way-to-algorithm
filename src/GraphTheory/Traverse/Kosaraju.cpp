//Kosaraju算法
//kosaraju.cp

//用Kosaraju算法求有向图的强联通分支

//1)基础概念
//在无向图中
//连通图：
//若对于无向图中任意一个节点i都存在一条路径到达其他所有节点j，则该图是一个连通图
//连通分量：
//在无向图G=<V,E>中，若存在一个V的子集V'
//其中任意一个节点i都存在一条路径到达该子集V'中其他所有节点
//则称V'是无向图G的连通分量，连通图自身是一个连通分量
//
//在有向图中
//强连通图：
//若对于有向图中任意一个结点i都存在一条路径到达其他所有节点j，则该图是一个强连通图
//强连通分量，强连通分支(Strongerst Connected Component，SCC)：
//在有向图G=<V,E>中，若存在一个V的子集V'
//其中任意一个节点i都存在一条路径到达该子集V'中其他所有节点
//则称V'是有向图G的强连通分量，强连通图自身是一个强连通分量
//考虑一个这样的有向图G有节点1，2，3和4
//有边e(1, 2)，e(2, 3)，e(3, 1)使123节点形成环，因此123节点是一个强连通分支
//又有边e(2, 4)，e(4, 3)，e(3, 2)使243节点形成环，因此243节点是一个强连通分支
//上面6条边中e(1, 2)，e(2, 4)，e(4, 3)，e(3, 1)又使1234节点形成环，也是强连通分支
//称这样的再增加任意一个节点都不再是强连通分支的强连通分支是极大强连通分支
//本节和本章第2节Tarjan算法中涉及到强连通分支的算法都是指极大强连通分支
//
//图的转置：
//有向图G=<V,E>的逆图G'=<V',E'>的节点集V'和原图G的节点集V的节点完全相同
//但边集E'中的任意一条边e'=(j,i)，即边e'是一条从节点j指向节点i的边
//该边e'在原图G中对应的边是e=(i,j)，即从节点i指向节点j的方向完全相反的边
//有向图G的逆图G'也称为G的转置
//
//2)具体实现
//求极大强连通分支属于深度优先搜索的应用
//Kosaraju算法先对于有向图G的逆图G'进行拓扑排序
//再按照拓扑顺序对原图G上的各节点依次进行深度优先搜索
//然后每次深度优先搜索遍历到的所有节点属于一个极大强连通分支
//而且Kosraju算法有一个副作用
//即第二次通过dfs遍历有向图G时，遍历节点的顺序也是该节点在极大强连通分支中的拓扑顺序
//
//由于极大强连通分支一定存在环，因此这个拓扑排序只能使用dfs方法的拓扑排序代码
//不能使用判断节点度数方法的拓扑排序代码，详见本节拓扑排序

#include "general_head.h"
#include "graph.h"
//topological_sort.cpp
extern void topological_sort1(graph_list g, deque<graph_node>& topo);
void transpose(graph_list g, graph_list& trans);
void dfs_kosaraju(graph_list& g, int p, int *visited, int grp);

void kosaraju(graph_list& g)
{//图G有g_l.size()个节点，下标从0到g_l.size()-1
 //返回图G的所有极大强连通分量，存储于邻接表头节点的g_value成员中
 //属于同一极大强连通分支的节点其g_value值相等
	//将邻接表所有头结点的g_value初始化为0
	for(int i = 0; i < (int)g.g_l.size(); ++ i)
		g.g_l[i][0].g_value = 0;
	graph_list trans;
	//求有向图G的逆图trans
	transpose(g, trans);
	deque<graph_node> trans_topo;
	//求逆图trans的拓扑排序
	//注意本文使用dfs的方法求拓扑顺序，而不能使用删除入度为0节点的方法
	topological_sort1(trans, trans_topo);
	//一次dfs遍历到的所有节点属于同一个极大强连通分支，用grp标记分支号
	//visited数组标记节点是否被访问，并记录该节点所属强联通分支的分支号grp
	int visited[MAX], grp(1);
	memset(visited, 0, MAX * sizeof(int));
	for(int i = 0; i < (int)trans_topo.size(); ++ i)
		//trans_topo中按照拓扑顺序存储着有向图逆图的节点拓扑顺序
		//按照该拓扑顺序dfs所有节点
		if(!visited[trans_topo[i].g_idx]){
			//一次dfs遍历到的节点属于同一个极大强连通分支
			//邻接表中对应的头节点的g_value成员值都为grp
			//这里可以只通过头结点的g_value来判断该节点是否被访问过
			dfs_kosaraju(g, trans_topo[i].g_idx, visited, grp);
			++ grp;
		}
}
void dfs_kosaraju(graph_list& g, int p, int *visited, int grp)
{//与深度优先搜索中的dfs_kosaraju函数遍历方法一样
 //但不记录遍历的节点数量，而且visited数组用grp的值标记
	//用grp值来标记visited数组，使得不同的极大强连通分支的visited值不一样
	visited[p] = 1;
	g.g_l[p][0].g_value = grp;
	for(int i = 1; i < (int)g.g_l[p].size(); ++ i)
		if(!visited[g.g_l[p][i].g_idx])
			dfs_kosaraju(g, g.g_l[p][i].g_idx, visited, grp);
}
void transpose(graph_list g, graph_list& trans)
{
	trans.g_l.clear();
	for(int i = 0; i < (int)g.g_l.size(); ++ i){
		deque<graph_node> tmp;
		//每个队列中插入头结点
		tmp.push_back(graph_node(i));
		//再把该队列插入邻接表中
		trans.g_l.push_back(tmp);
	}
	for(int i = 0; i < (int)g.g_l.size(); ++ i)
		for(int j = 1; j < (int)g.g_l[i].size(); ++ j)
			trans.g_l[g.g_l[i][j].g_idx].push_back(g.g_l[i][0]);
}
