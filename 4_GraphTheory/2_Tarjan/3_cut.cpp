//割
//cut.cpp

//求无向图中的割点与割边

//1)基础概念
//割点：
//无向图中某个点，删去该点后图的连通分支数量加1，即该点将原图分成两个连通分支
//桥，割边：
//无向图中某条边，删去该边后图的连通分支数量加1，即该边将原图分成两个连通分支
//
//2)具体实现
//在无向无环图(其实是一棵树)中，Tarjan算法设置数组dfn和low
//
//节点i为割点，当满足以下量条件之一：
//i)节点i为树的根节点且节点i有两个子树
//ii)节点i不是树的根节点且有dfn[i] <= low[j]，由于low[j]指代节点j的最早祖先
//则节点i是节点j的祖先，删除节点i后节点j所在的子树和节点i以上的子树分成两个连通分支
//
//边(i,j)为割边(桥)，当满足以下条件：
//dfn[i] < low[j]，即节点i是节点j的祖先节点，删除该边后节点i和节点j分成两个连通分支
//
//本文引用了“POJ 2117 Electricity(割点)”，作者“Jack Ge” 

#include "general_head.h"
#include "graph.h"
//strongest_connected_component.cpp
extern void set_value(graph_list& g);
void dfs_cut(graph_list& g, int p, int& time, int *dfn, int *low, 
		int father, int root, vector<pair<int, int> >& cut_edge);

void cut(graph_list& g, vector<pair<int, int> >& cut_edge)
{//无向无环图G有g_l.size()个节点，下标从0到g_l.size()-1
 //图G是一课树，根节点是0，返回图G的所有割点和割边，存处于g_value和cut_edge中
	//将邻接表所有头结点的g_value初始化为-1
	set_value(g);
	cut_edge.clear();
	int dfn[MAX], low[MAX], visited[MAX], time(1);
	memset(dfn, 0, MAX * sizeof(int));
	memset(low, 0, MAX * sizeof(int));
	memset(visited, 0, MAX * sizeof(int));
	for(int i = 0; i < (int)g.g_l.size(); ++ i)
		if(!dfn[i])
			dfs_cut(g, i, time, dfn, low, i, i, cut_edge);
}
void dfs_cut(graph_list& g, int p, int& time, int *dfn, int *low, 
		int father, int root, vector<pair<int, int> >& cut_edge)
{
	dfn[p] = low[p] = time ++;
	for(int i = 1; i < (int)g.g_l[p].size(); ++ i){
		if(!dfn[g.g_l[p][i].g_idx]){
			dfs_cut(g, g.g_l[p][i].g_idx, time, dfn, low, p, root, cut_edge);
			low[p] = min(low[p], low[g.g_l[p][i].g_idx]);
			//判断割边
			if(dfn[p] < low[g.g_l[p][i].g_idx])
				//若节点p的dfn值小于节点i.g_idx的low值
				//则边(p,i)是割边
				cut_edge.push_back(make_pair(p, g.g_l[p][i].g_idx));
			//判断割点
			if((p == root && (int)g.g_l[p].size() > 2) ||
					(p != root && dfn[p] <= low[g.g_l[p][i].g_idx]))
				//若节点p为根节点且节点p有至少2个孩子子树
				g.g_l[p][0].g_value = 1;
		}
		else if(g.g_l[p][i].g_idx != father){
			low[p] = min(low[p], dfn[g.g_l[p][i].g_idx]);
		}
	}
}


