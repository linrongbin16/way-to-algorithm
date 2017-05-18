//双连通分支
//double_connected_component.cpp

//求无向图的双连通分支

//1)基础概念
//对于无向连通图G=<V,E>
//点割集：
//点集V中有这样的非空真子集V1，G中删去V1后不再连通
//但对于V1的任意真子集V2，G中删去V2后都仍然连通，称这样的点集V1是G的一个点割集
//边割集：
//边集E中有这样的非空真子集E1，G中删去E1后不再连通
//但对于E1的任意真子集E2，G中删去E2后都仍然连通，称这样的边集E1是G的一个边割集
//平凡图：
//只有一个节点，没有边的图
//非平凡图：
//有至少两个节点，一条边的图
//点割集和边割集性质：
//任何非平凡的无向连通图一定具有边割集
//而非平凡的无向连通图存在点割集的充要条件是该图中至少存在两个不相邻的相异节点
//点连通度：
//非平凡的无向连通图G的所有点割集V1的节点数量最少的点割集数量k即为图G的点连通度k
//即该图中删除任意k-1个节点后都仍然连通，但存在一个方案(点割集)使删除k个节点后不连通
//特别的当k = 2时，即该图任意删除1个节点都仍然连通
//但存在一个方案使删除2个节点后不再连通，称点连通度k = 2的连通分支(图)为点双连通分支
//边连通度：
//非平凡的无向连通图G的所有边割集E1的边数量最少的边割集数量k即为图G的边连通度k
//即该图中删去任意k-1条边后都仍然连通，但存在一个方案(边割集)使删除k条边后不再连通
//特别的当k = 2时，即该图任意删除1条边都仍然连通
//但存在一个方案使删除2条边后不再连通，称边连通度k = 2的连通分支(图)为边双连通分支
//
//一般性的点连通度和边连通度的问题则应用了最大流算法，详见本章第5节流网络
//本文只讲解点和边双连通分支的求解算法
//
//2)具体实现
//在本节割cut.cpp中我曾讲过割点和割边有两个很直观的特性：
//假设删去一个割点后得到两个新的连通分支
//则割点可以看作同时属于两个新连通分支，而非割点总是只属于一个连通分支
//假设删去一条割边后得到两个新的连通分支
//则割边的两端点可以看作分别属于两个新连通分支，而非割边的两端点只属于同一个连通分支
//事实上点或边的双连通分支就是通过割点割边的这个特性来求出的
//边双连通分支：
//应用Tarjan算法求出无向图的所有割边
//将原图中所有割边删去后的所有连通分支即为原图的所有边双连通分支
//点双连通分支：
//应用Tarjan算法求出无向图的所有割点
//每个割点都分别属于两个连通分支，这两个连通分支就是两个点双连通分支
//也可以说将原图中所有割点删去后的所有连通分支再加上原割点即可得所有点双连通分支
//
//边双连通分支完全由割边得到，因此本文不再花费篇幅编写代码，只解决点双连通分支问题
//Tarjan算法通过设置栈来存储连通分支，点双连通分支也是通过这个方法来求解
//但存储的方式并非本节的强连通分支那样用栈存储节点
//因为一个节点属于且只属于一个强连通分支，而割点同时属于两个点双连通分支
//因此本问题中栈存储的不是单个的节点，而是边，因为每条边都只属于一个点或边双连通分支
//当dfs递归的遍历到节点i时，对于i的一个邻节点j(或称孩子节点j)，将边e(i, j)压栈
//而当节点i及其邻节点j满足dfn[i] <= low[j]，即节点i是割点时
//将栈中的边出栈，直到出栈的边是e(i, j)为止
//
//点双连通分支与割点还有一处不同就是根节点上的判断
//在割点的判断中会特别强调若根节点有两个孩子子树，则该根节点是割点
//但在点双连通分支中不会进行这样的判断，具体的原因我也无法解释
//通过自己画一些图读者看出，根节点不可能同时属于两个点双连通分支，最多只能属于一个
//
//本文引用了“图的割点、桥与双连通分支”，作者“byvoid”

#include "general_head.h"
#include "graph.h"
void dfs_dcc(graph_list& g, int p, int *visited, int& time, int *dfn, int *low,
		stack<pair<int, int> >& stk, int& grp, deque<deque<pair<int, int> > >& com);

void double_connected_component(graph_list g, deque<deque<pair<int, int> > >& com)
{//无向图G有g_l.size()个节点，下标从0到g_l.size()-1
 //返回图G的所有点双连通分支，每个连通分支存储于com的一个deque<pair<int, int> >元素中
	com.clear();
	int dfn[MAX], low[MAX], visited[MAX], time(1), grp(1);
	memset(dfn, 0, MAX * sizeof(int));
	memset(low, 0, MAX * sizeof(int));
	memset(visited, 0, MAX * sizeof(int));
	stack<pair<int, int> > stk;
	for(int i = 0; i < (int)g.g_l.size(); ++ i)
		if(visited[i] == 0)
			dfs_dcc(g, i, visited, time, dfn, low, stk, grp, com);
}
void dfs_dcc(graph_list& g, int p, int *visited, int& time, int *dfn, int *low,
		stack<pair<int, int> >& stk, int& grp, deque<deque<pair<int, int> > >& com)
{
	dfn[p] = low[p] = time ++;
	visited[p] = 1;
	//除了栈的操作其他与求割点算法是完全相同的
	//注意这里并不像强连通分支一样一开始就stk.push(p)将节点p压栈
	for(int i = 1; i < (int)g.g_l[p].size(); ++ i){
		if(visited[g.g_l[p][i].g_idx] == 0){
			//将边e(p, i.g_idx)压栈
			stk.push(make_pair(p, g.g_l[p][i].g_idx));
			dfs_dcc(g, g.g_l[p][i].g_idx, visited, time, dfn, low, stk, grp, com);
			low[p] = min(low[p], low[g.g_l[p][i].g_idx]);
			//判断点双连通分支
			if(dfn[p] <= low[g.g_l[p][i].g_idx]){
				//节点p是割点
				deque<pair<int, int> > tmp;
				pair<int, int> tmp_edge;
				do{
					tmp_edge = stk.top(); stk.pop();
					tmp.push_back(tmp_edge);
				}while(!((tmp_edge.first == p &&
								tmp_edge.second == g.g_l[p][i].g_idx)
							|| (tmp_edge.first == g.g_l[p][i].g_idx &&
								tmp_edge.second == p)));
				//直到出栈的边是e(p, i.g_idx)为止
				//tmp是一个点双连通分支
				com.push_back(tmp);
			}
		}
		else if(visited[g.g_l[p][i].g_idx] == 1)
			low[p] = min(low[p], dfn[g.g_l[p][i].g_idx]);
	}
	visited[p] = 2;
}
