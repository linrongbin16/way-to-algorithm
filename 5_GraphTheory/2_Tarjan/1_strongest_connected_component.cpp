//强连通分支
//strongest_connected_component.cpp

//用Tarjan算法求有向图的强连通分支

//1)基础概念
//求有向图的强连通分支除了Kosaraju算法外还有Tarjan算法和Gabow算法
//后两个算法基本是相同的，可以看作前者的改进
//Tarjan算法初始用于求解强连通分支
//而强连通分支的多个扩展问题也都通过该算法解决
//割点，割边，双连通分支，最近公共祖先
//
//该算法的核心仍然是dfs
//事实上本章中前两节遍历和Tarjan算法中所有的问题都离不开dfs，可见该技术的重要性
//该算法中还使用了搜索树的概念
//有向图G中从节点i出发dfs可以遍历到的所有节点可以看作以节点i为根节点的子树
//当然树的概念是不允许出现环的有向图
//但搜索树可以宽松的看作选取其中一个作为根节点，然后进行dfs得到的子树
//事实上搜索树就是Tarjan算法的核心概念
//通过搜索树可以求出强连通分支以及本节中的所有问题
//
//2)具体实现
//该算法与深度优先搜索邻接表的框架是一样的，但有两处主要的地方不同
//其一是该算法设置一个栈，按照dfs遍历的顺序将节点压栈
//假设遍历从节点i开始，先将节点i压栈，然后对i的所有邻节点递归的进行dfs
//在节点i的递归函数中
//当遍历节点i的搜索树中的全部节点之后，即递归遍历它的所有邻节点之后
//搜索树中的所有节点都已经判断出所属的强连通分支，出栈后加入答案集即可
//
//其二是Tarjan算法对每个节点设置两个标号dfn和low
//节点i的dfn值指代该节点是第几个被访问的，即节点i的访问顺序
//low值指代从节点i出发遍历到的所有节点(包括节点i自己)中最小的dfn值
//当节点i没有邻节点时它的low值和dfn值相等，显然节点i的low值不会大于dfn值
//节点i是一个强连通分支的根节点当且仅当它的low值等于dfn值即low[i] = dfn[i]
//其实dfn和low是一对相反意义的标号，对于节点i
//dfn值标记节点i的访问顺序，越早访问的节点i的dfn值越小，i也越可能是强连通分支的根节点
//而low值标记从节点i往后的所有节点中最小的dfn值，若节点i在一个环(强连通分支)上
//则从节点i继续dfs必然会回到节点i前面的根节点，设这个根节点为k
//则k的dfn值必小于i的dfn值，而且k的dfn值也是强连通分支上所有节点的最小dfn值(最早访问)
//因此该环上所有节点的low值最后都可以更新为k的dfn值，k自己的low值等于自己的dfn值
//若节点i不在一个强连通分支上，则从节点i往后的所有节点的dfn值越来越大
//则节点i的low值最小就是它自己的dfn值，而不可能更新为更小的值
//
//栈和dfn，low标号是Tarjan算法的核心技术
//深入的理解dfn和low标号的意义，就可以深入的理解Tarjan算法的核心技术
//由于需要查找某个元素是否存在于栈中，将栈实作为deque
//
//本文引用了“Tarjan算法(维基百科)”，无作者

#include "general_head.h"
#include "graph.h"
void set_value(graph_list& g);
void dfs_scc(graph_list& g, int p, int *visited, int& time,
		int *dfn, int *low, deque<int>& stk);

void strongest_connected_component(graph_list& g)
{//图G有g_l.size()个节点，下标从0到g_l.size()-1
 //返回图G的所有极大强连通分量，存储于邻接表头节点的g_value成员中
 //属于同一强连通分支的节点其g_value值相等
	int dfn[MAX], low[MAX], visited[MAX], time(1);
	memset(dfn, 0, MAX * sizeof(int));
	memset(low, 0, MAX * sizeof(int));
	memset(visited, 0, MAX * sizeof(int));
	//将栈stk实作为deque
	deque<int> stk;
	for(int i = 0; i < (int)g.g_l.size(); ++ i)
		if(!visited[i])
			//若未被访问则通过深度递归进行遍历，得到强连通分支
			dfs_scc(g, i, visited, time, dfn, low, stk);
}
void dfs_scc(graph_list& g, int p, int *visited, int& time,
		int *dfn, int *low, deque<int>& stk)
{//栈stk中存储节点的下标号，p为当前节点的下标号
 //从0号节点开始dfs搜索，数组dfn和low中所有成员初始化为0
 //返回图G中的所有强连通分支，存储于com，com初始时为空
	//将节点p的low值初始化为dfn值
	dfn[p] = low[p] = time ++;
	//deque的push_front模拟push操作，front模拟top操作，pop_front模拟pop操作
	stk.push_front(p);
	//将节点p入栈则visited值设置为1，直到该节点p被分配到强连通分支后visited值设置为2
	visited[p] = 1;
	for(int i = 1; i < (int)g.g_l[p].size(); ++ i){
		if(!visited[g.g_l[p][i].g_idx]){
			//若节点p的邻节点i.g_idx未被访问，递归的继续遍历邻节点i.g_idx
			//这里借用dfn数组来标记节点是否被访问
			dfs_scc(g, g.g_l[p][i].g_idx, visited, time, dfn, low, stk);
			//递归将它设置为它的所有邻节点中low值最小的
			//而它的每个邻节点也会将自己的low值设置为邻节点的所有邻节点low值中最小的
			//从而使节点p的low值设置为从它开始遍历的所有节点中dfn值最小的
			low[p] = min(low[p], low[g.g_l[p][i].g_idx]);
		}
		else if(find(stk.begin(), stk.end(), g.g_l[p][i].g_idx) != stk.end())
			//visited值为1标记该节点存储在栈stk中
			//若节点p的邻节点i.g_idx已经属于栈stk
			//说明i.g_idx在被从p出发的dfs访问之前已经被从另一个节点发出的dfs访问过了
			//则将节点p的low值设置为与该邻节点i.g_idx的dfn值中较小的那个
			//而不能用i.g_idx节点的low值，因为该邻节点也许不属于节点p的强连通分支
			low[p] = min(low[p], dfn[g.g_l[p][i].g_idx]);
		//以上对节点p的low值的设置是Tarjan算法中一处核心技术，即
		//low[p] = min(dfn[p],	初始化
		//		low(q),			若节点q是p的子树中的节点
		//		dfn(q))			若节点q是p的子树中属于一个环中的节点
	}
	if(dfn[p] == low[p]){
		//若节点p的low值和dfn值相等，则p是强连通分支的根节点
		int q;
		do{
			q = stk.front(); stk.pop_front();
			//节点q属于节点p的强连通分支，将g_value值设置为p的dfn值
			g.g_l[q][0].g_value = dfn[p];
		}while(q != p);
		//直到出栈节点为p自己时停止
		//节点p是该强连通分支中第一个入栈的节点
	}
}
