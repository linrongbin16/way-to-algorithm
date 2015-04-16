//Gabow算法
//gabow.cpp

//用Gabow算法求有向图的强连通分支

//Gabow算法是Tarjan算法的另一个版本
//不同的是Tarjan算法中的low数组在Gabow算法中通过另一个栈来实现
//
//本文引用了“有向图强连通分量 Gabow 算法”，作者“小乐”

#include "general_head.h"
#include "graph.h"
//strongest_connected_component.cpp
extern void set_value(graph_list& g);
void dfs_gabow(graph_list& g, int p, int *visited, int& time,
		int *dfn, stack<int>& low, stack<int>& stk, int& grp);

void gabow(graph_list& g)
{//图G有g_l.size()个节点，下标从0到g_l.size()-1
 //返回图G的所有极大强连通分量，存储于邻接表头节点的g_value成员中
 //属于同一强连通分支的节点其g_value值相等
	int dfn[MAX], visited[MAX], time(1), grp(1);
	memset(dfn, 0, MAX * sizeof(int));
	memset(visited, 0, MAX * sizeof(int));
	stack<int> stk, low;
	for(int i = 0; i < (int)g.g_l.size(); ++ i)
		if(!visited[i])
			dfs_gabow(g, i, visited, time, dfn, low, stk, grp);
}
void dfs_gabow(graph_list& g, int p, int *visited, int& time,
		int *dfn, stack<int>& low, stack<int>& stk, int& grp)
{//通过dfs递归的遍历图中所有节点
	dfn[p] = time ++;
	stk.push(p);
	low.push(p);
	visited[p] = 1;
	for(int i = 1; i < (int)g.g_l[p].size(); ++ i){
		if(visited[g.g_l[p][i].g_idx] == 0)
			dfs_gabow(g, g.g_l[p][i].g_idx, visited, time, dfn, low, stk, grp);
		else if(!g.g_l[g.g_l[p][i].g_idx][0].g_value){
			//若节点p的邻节点i.g_idx尚未分配强连通分支号，即i.g_idx尚未分配分支
			while(dfn[stk.top()] > dfn[g.g_l[p][i].g_idx])
				stk.pop();
		}
	}
	if(stk.top() == p){
		//栈中存储了两次节点p，两个节点p之间的所有节点都属于p的强连通分支
		stk.pop();
		int q;
		do{
			q = low.top(); low.pop();
			g.g_l[q][0].g_value = grp;
		}while(q != p);
		++ grp;
	}
}
