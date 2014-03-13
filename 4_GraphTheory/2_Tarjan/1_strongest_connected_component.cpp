//强连通分支
//strongest_connected_component.cpp

//用Tarjan算法求有向图的强连通分支

//Tarjan在大多数情况下比Kosaraju算法有更好的效率
//仅用一次dfs遍历就可以得到图中的所有强连通分量
//但无法像Kosaraju算法对所有强连通分量中的节点进行拓扑排序
//
//Tarjan算法设置两个数组dfn和low
//dfn[i]指代节点i的下标号i
//low[i]指代节点i的最早祖先节点，所有low值相同的节点同属一个强连通分支
//该算法通过对图的深度优先搜索
//将未处理的节点压入栈中，回溯时可以判定栈中节点是否属于某个强连通分量
//
//由于需要在栈中查找元素，故使用deque来实作栈，而不使用stack

#include "general_head.h"
#include "graph.h"
void set_value(graph_list& g);
void dfs_scc(graph_list& g, int p, int& time, int *dfn, int *low, 
		deque<int>& stk);

void strongest_connected_component(graph_list& g)
{//图G有g_l.size()个节点，下标从0到g_l.size()-1
 //返回图G的所有强连通分量，存储于邻接表头节点的g_value成员中
 //属于同一强连通分支的节点其g_value值相等
	//将邻接表所有头结点的g_value初始化为-1
	set_value(g);
	int dfn[MAX], low[MAX], time(1);
	memset(dfn, 0, MAX * sizeof(int));
	memset(low, 0, MAX * sizeof(int));
	deque<int> stk;
	for(int i = 0; i < (int)g.g_l.size(); ++ i)
		if(!dfn[i])
			//借用dfn数组标记节点是否被访问
			//若未被访问则通过深度递归进行遍历，得到强连通分支
			dfs_scc(g, i, time, dfn, low, stk);
}
void set_value(graph_list& g)
{
	for(int i = 0; i < (int)g.g_l.size(); ++ i)
		g.g_l[i][0].g_value = -1;
}
void dfs_scc(graph_list& g, int p, int& time, int *dfn, int *low,
		deque<int>& stk)
{//栈stk中存储节点的下标号，p为当前节点的下标号
 //从0号节点开始dfs搜索，数组dfn和low中所有成员初始化为0
 //返回图G中的所有强连通分支，存储于com，com初始时为空
	dfn[p] = low[p] = time ++;
	//压入队头push_front操作模拟栈的push
	//压出队头pop_front操作模拟栈的pop
	stk.push_front(p);
	for(int i = 1; i < (int)g.g_l[p].size(); ++ i){
		if(!dfn[g.g_l[p][i].g_idx]){
			//若节点p的邻节点i.g_idx未被访问
			//这里借用dfn数组来标记节点是否被访问
			//递归的考察节点p的邻节点i.g_idx
			dfs_scc(g, g.g_l[p][i].g_idx, time, dfn, low, stk);
			low[p] = min(low[p], low[g.g_l[p][i].g_idx]);
		}
		else if((find(stk.begin(), stk.end(), g.g_l[p][i].g_idx)) != stk.end())
			//若节点p的邻节点i.g_idx已经存储在stk中
			//则将节点p的low值设置为与该邻节点i.g_idx相同，表明它们属于同一强连通分支
			low[p] = min(low[p], dfn[g.g_l[p][i].g_idx]);
	}
	if(dfn[p] == low[p]){
		int q;
		do{
			q = stk.front(); stk.pop_front();
			//节点q属于分支号为dfn[p]的强连通分支
			g.g_l[q][0].g_value = dfn[p];
		}while(q != p);
	}
}


