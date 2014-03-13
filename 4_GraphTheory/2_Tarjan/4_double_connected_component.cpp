//双连通分量
//double_connected_component.cpp

//求无向图的双连通分量

//1)基础概念
//点连通度：
//无向图中割点的数量
//边连通度：
//无向图中割边的数量
//块，点双连通分支：
//极大连通子图的点连通度大于等于2，即该图中至少有两个割点
//删除这两个割点才能破坏该图的连通性
//边双连通分支：
//极大连通子图的边连通度大于等于2，即该图中至少有两个割边
//删除这两个割边才能破坏该图的连通性
//
//点双连通分支和边双连通分支其实与割点和割边本质上是相同的概念
//割点是两个点双连通分支的交点，割边则连接两个边双连通分支
//即割点和割边其实本质上是将两个双连通分支分开的边界
//因此当求出割点和割边时也就求出了对应的点双连通分支和边双连通分支
//具体的实现中一般通过一个栈暂时存储节点或边
//
//本文的代码仍然存在问题，由于时间关系我可能以后将Tarjan算法进一步的改写
//保证该算法在数学模型的构造上更加科学易懂，在本节最后的测试用例中本文的函数注释掉了

#include "general_head.h"
#include "graph.h"
//strongest_connected_component.cpp
extern void set_value(graph_list& g);
void dfs_dcc(graph_list& g, int p, int& time, int *dfn, int *low, 
		int father, stack<int>& stk, int& grp);

void double_connected_component(graph_list& g)
{//无向无环图G有g_l.size()个节点，下标从0到g_l.size()-1，图G是一课树，根节点是0
 //返回图G的所有点双连通分量，存储于邻接表头节点的g_value成员中
	//将邻接表头结点的g_value初始化为-1
	set_value(g);
	int dfn[MAX], low[MAX], time(1), grp(1);
	memset(dfn, 0, MAX * sizeof(int));
	memset(low, 0, MAX * sizeof(int));
	stack<int> stk;
	for(int i = 0; i < (int)g.g_l.size(); ++ i)
		if(!dfn[i])
			dfs_dcc(g, i, time, dfn, low, i, stk, grp);
}
void dfs_dcc(graph_list& g, int p, int& time, int *dfn, int *low, 
		int father, stack<int>& stk, int& grp)
{
	dfn[p] = low[p] = time ++;
	//将当前节点p入栈
	stk.push(p);
	for(int i = 1; i < (int)g.g_l[p].size(); ++ i){
		if(!dfn[g.g_l[p][i].g_idx]){
			dfs_dcc(g, g.g_l[p][i].g_idx, time, dfn, low, p, stk, grp);
			low[p] = min(low[p], low[g.g_l[p][i].g_idx]);
			if(dfn[p] <= low[g.g_l[p][i].g_idx]){
				int tmp;
				do{
					tmp = stk.top(); stk.pop();
					g.g_l[tmp][0].g_value = grp;
				}while(tmp != p);
				++ grp;
			}
		}
		else if(g.g_l[p][i].g_idx != father){
			low[p] = min(low[p], dfn[g.g_l[p][i].g_idx]);
		}
	}
}


