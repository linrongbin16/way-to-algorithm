//Gabow算法
//gabow.cpp

//用Gabow算法求有向图的强连通分支

//Gabow算法是Tarjan算法的另一个版本
//不同的是Tarjan算法中的low数组在Gabow算法中通过另一个栈来实现

#include "general_head.h"
#include "graph.h"
//strongest_connected_component.cpp
extern void set_value(graph_list& g);
void dfs_gabow(graph_list& g, int p, int& time, int *dfn, 
		stack<int>& stk, stack<int>& stk2, int& grp);

void gabow(graph_list& g)
{//图G有g_l.size()个节点，下标从0到g_l.size()-1
 //返回图G的所有强连通分量，存储于邻接表头节点的g_value成员中
 //属于同一强连通分支的节点其g_value值相等
	//将邻接表所有头结点的g_value初始化为-1
	set_value(g);
	int dfn[MAX], time(1), grp(1);
	memset(dfn, 0, MAX * sizeof(int));
	stack<int> stk, stk2;
	for(int i = 0; i < (int)g.g_l.size(); ++ i)
		if(!dfn[i])
			dfs_gabow(g, i, time, dfn, stk, stk2, grp);
}
void dfs_gabow(graph_list& g, int p, int& time, int *dfn, 
		stack<int>& stk, stack<int>& stk2, int& grp)
{//通过dfs递归的遍历图中所有节点
	dfn[p] = time ++;
	stk.push(p);
	stk2.push(p);
	for(int i = 1; i < (int)g.g_l[p].size(); ++ i){
		if(!dfn[g.g_l[p][i].g_idx])
			dfs_gabow(g, g.g_l[p][i].g_idx, time, dfn, stk, stk2, grp);
		else if(g.g_l[g.g_l[p][i].g_idx][0].g_value == -1){
			while(dfn[stk.top()] > dfn[g.g_l[p][i].g_idx])
				stk.pop();
		}
	}
	if(stk.top() == p){
		stk.pop();
		int q;
		do{
			q = stk2.top(); stk2.pop();
			g.g_l[q][0].g_value = grp;
		}while(q != p);
		++ grp;
	}
}






