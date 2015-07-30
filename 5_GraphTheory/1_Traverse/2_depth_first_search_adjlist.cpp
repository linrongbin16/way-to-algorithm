//深度优先搜索邻接表
//depth first search adjlist

//在给定邻接表上深度优先搜索

//1)基础概念
//图: 
//图G=<V,E>是由节点集V与边集E组成的数据结构
//无向边: 
//设一条无向边e连接两节点u和v 这两个节点称为e的两端点
//允许从u向v出发也允许从v向u出发 好比一条路可以从两个方向走过
//有向边: 
//设一条有向边e是从节点u到节点v的 只允许从u到v而不能反向
//无向边可以看做是对应的两条相反的有向边组合而成的边
//出度: 
//节点u的出度是从u出发的边的数量 即从节点u向外发出的边的数量 也称u的出度度数
//从u出发的边也称u节点的出弧边
//入度: 
//节点u的入度是到达u的边的数量 即指向u的边的数量 也称u的入度度数
//到达u或指向u的边也称u节点的入弧边
//对于无向图来说节点u连接的边的数量即为节点u的度数 没有出入之分
//
//2)具体实现
//使用递归技术对邻接表进行遍历
//但邻接表的深度搜索和排列组合中使用的深度搜索方法不太一样 注意区分


#include <cstring>
#include "graph.h"
//extern void print_node(graph_node *p);
#include "1_traverse_tree.cpp"
void dfs_visit(graph_list& g, int p, int *visited, int& time)
{//返回dfs搜索节点p的递归次数
 //即从节点p开始dfs遍历到的节点数量 也是递归遍历花费的时间
	print_node(&g.g_l[p][0]);
	visited[p] = 1;
	for(int i = 1; i < (int)g.g_l[p].size(); ++ i)
		//寻找节点p的邻节点中 尚未被访问的所有邻节点
		if(!visited[g.g_l[p][i].g_idx])
			//对未被访问的所有节点进行下一轮dfs递归
			//在有向图中 将当前节点看作子树中的根节点 所有其邻节点看作该节点的孩子
			//则dfs过程也可以看作对当前节点的子树进行一次遍历
			dfs_visit(g, g.g_l[p][i].g_idx, visited, time);
	g.g_l[p][0].g_value = time++;
}

void depth_first_search_adjlist(graph_list g)
{//图G有g_l.size()个节点 下标从0到g_l.size()-1
 //邻接表graph_list由嵌套队列deque<deque<graph_node> >实现
 //第i个队列g_l[i]指代由i节点的所有邻节点组成的单链
 //每个队列中都有一个头节点
 //即队列i中的节点g_l[i][0]是节点i自身 之后从1开始才是节点i的邻节点
 //而且还有一个需要注意的地方 即对于队列i的头结点g_l[i][0] 它的g_idx成员与i相等
 //即图G的邻接表中各单链的头结点按照节点下标排列
 //而队列中除过头结点之外的节点 其g_idx成员与它在该队列中的下标号则不对应
 //比如graph_list中第i个队列g_l[i]中
 //头结点0满足g_l[i][0].g_idx = i 但节点1的g_l[i][1].g_idx != 1 两者无关
 //以后关于该数据结构不再特别说明
	//visited数组标记节点是否被访问过
	//节点成员g_value标记从该节点开始的dfs遍历到的节点数量 递归次数 dfs时间
	int visited[MAX], time(0);
	memset(visited, 0, MAX * sizeof(int));
	for (int i = 0; i < (int)g.g_l.size(); ++ i)
		if (!visited[i])
			//对每个节点调用dfs_visit
			dfs_visit(g, i, visited, time);
}
