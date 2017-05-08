//割
//cut.cpp

//求无向图中的割点与割边

//1)基础概念
//割点：
//无向图中某个点，删去该点后图的连通分支数量加1，即该点将原图分成两个连通分支
//桥，割边：
//无向图中某条边，删去该边后图的连通分支数量加1，即该边将原图分成两个连通分支
//割点和割边性质：
//事实上割点和割边有两个很直观的特性
//假设删去一个割点后得到两个新的连通分支
//则割点可以看作同时属于两个新连通分支，而非割点总是只属于一个连通分支
//假设删去一条割边后得到两个新的连通分支
//则割边的两端点可以看作分别属于两个新连通分支，而非割边的两端点只属于同一个连通分支
//
//2)具体实现
//在无向图上仍然使用Tarjan算法的框架，设置栈和数组dfn，low
//无向图中应用Tarjan算法与有向图的强连通分支或环的情况并不一样
//事实上连通的无向图总是一个连通分支，因此问题扩展为求割点割边
//
//对于节点i，若该节点为割点当满足以下两条件之一：
//i)节点i为树的根节点即i满足low[i] = dfn[i]，且节点i有两个子树
//
//考虑这样的节点i，它有3个邻节点j1，j2，j3，即从节点i向外出发有三条边连接到这三个节点
//从节点i开始dfs遍历，递归的进入节点j1继续遍历，当遍历完j1节点时发现节点j3也被访问过
//而j2未被访问，需要重新递归进入j2进行dfs，则认为节点i有两个子树，而不是三个
//若节点i只有j1和j2两个邻节点，或孩子节点，且从j1可以dfs遍历到j2，则认为i只有一个子树
//
//ii)节点i不是树的根节点即不满足low[i] = dfn[i]，设节点i的根节点(或i的祖先节点)是k
//且节点i存在一个这样的孩子节点j
//从j往后进行dfs遍历不会回到i的根节点(或i的祖先节点)k，至多回到节点i自己
//因此节点i是节点j往后的连通分支和根节点k的唯一连通节点，注意节点i，k，j三节点连通
//该条件表示为dfn[i] <= low[j]，即从节点j往后的所有节点中最小的dfn值至多是i的dfn值
//
//对于节点i和它的一个孩子节点(邻节点)j有边e(i, j)，若该边为割边(桥)当满足以下条件：
//dfn[i] < low[j]，即从节点j出发往后dfs，遍历到的节点的dfn值最小也比i的dfn值大
//即从节点i的邻节点j出发往后dfs，无法回到节点i和i之前那些节点
//因此节点j及以后的连通分支与节点i只有一条边e(i, j)连通，因此该边为割边
//
//本文引用了“无向连通图求割点割边”，作者“myjfm”

#include "general_head.h"
#include "graph.h"
//strongest_connected_component.cpp
extern void set_value(graph_list& g);
void dfs_cut(graph_list& g, int p, int *visited, int& time, int *dfn, int *low,
		int father, int root, int& root_son, vector<pair<int, int> >& cut_edge);

void cut(graph_list& g, vector<pair<int, int> >& cut_edge)
{//无向图G有g_l.size()个节点，下标从0到g_l.size()-1
 //返回无向图G的所有割点和割边，存储于g_value和cut_edge中
	cut_edge.clear();
	//root_son标记根节点的子树数量
	//其实本节前面算法中不必要设置visited数组，用其他数组例如dfn也可以标记是否被访问
	//但本文中visited数组的标记与本节前面的不同，必须使用
	int dfn[MAX], low[MAX], visited[MAX], time(1), root_son(0);
	memset(dfn, 0, MAX * sizeof(int));
	memset(low, 0, MAX * sizeof(int));
	memset(visited, 0, MAX * sizeof(int));
	for(int i = 0; i < (int)g.g_l.size(); ++ i)
		if(visited[i] == 0)
			dfs_cut(g, i, visited, time, dfn, low, i, i, root_son, cut_edge);
}
void dfs_cut(graph_list& g, int p, int *visited, int& time, int *dfn, int *low,
		int father, int root, int& root_son, vector<pair<int, int> >& cut_edge)
{
	//Tarjan算法在割点割边的应用与前面强连通分支的最大区别
	//就是不需要设置栈，因为割点和割边不需要用栈来存储整个强连通分支的节点
	dfn[p] = low[p] = time ++;
	//visited值为0指代该节点未被访问，为1指代该节点被访问但不确定是否为割点或割边
	visited[p] = 1;
	for(int i = 1; i < (int)g.g_l[p].size(); ++ i){
		if(visited[g.g_l[p][i].g_idx] == 0){
			dfs_cut(g, g.g_l[p][i].g_idx, visited, time,
					dfn, low, p, root, root_son, cut_edge);
			low[p] = min(low[p], low[g.g_l[p][i].g_idx]);
			if(p == root)
				//判断根节点的子树个数并累加标记到root_son上
				++ root_son;
			//判断割点
			if((p == root && root_son >= 2) ||
					(p != root && dfn[p] <= low[g.g_l[p][i].g_idx]))
				//若节点p为根节点且节点p有至少2个子树
				//或着若节点p不为根节点且满足dfn[p] <= dfn[i.g_idx]
				g.g_l[p][0].g_value = 1;
			//判断割边
			if(dfn[p] < low[g.g_l[p][i].g_idx])
				//若满足dfn[p] < low[i.g_idx]则边(p, i.g_idx)是割边
				cut_edge.push_back(make_pair(p, g.g_l[p][i].g_idx));
		}
		else if(g.g_l[p][i].g_idx != father && visited[g.g_l[p][i].g_idx] == 1)
			low[p] = min(low[p], dfn[g.g_l[p][i].g_idx]);
	}
	//visited值为2指代该节点已经确定
	visited[p] = 2;
}
