//欧拉回路
//euler_loop.cpp

//判断无向连通图中是否存在欧拉回路 若存在找出一条欧拉回路

//1)基础概念
//欧拉回路:
//图G中存在一条回路 经过每条边一次且仅一次(可以多次访问同一顶点)遍历所有边
//欧拉路:
//图G中存在一条路 经过每条边一次且仅一次(可以多次访问同一顶点)遍历所有边
//欧拉回路判定条件: 
//有向图G中 所有顶点出度等于入度
//无向图G中 所有顶点度数为偶数
//欧拉路判定条件: 
//有向图G中 一顶点出度比入度大1 一顶点入度比出度大1 其余点入度等于出度
//无向图G中 只有两个顶点度数为奇数 其余都是偶数
//
//2)求无向图的欧拉回路
//该问题属于dfs的应用 使用Fleury算法 其时间复杂度O(e*e)
//判断欧拉回路存在的条件: 图中所有节点的度数为偶数
//对该图进行dfs搜索: 
//对于节点i 在选择下一次dfs搜索的节点时使用贪心算法: 
//选择i的所有邻节点中剩余度数最高的节点作为下一次dfs的节点
//这是为了保证所有边在结束前都会被经过
//设置degree数组来指代每个节点的剩余度数
//
//3)求无向图的欧拉路
//判断欧拉路存在的条件: 有两个节点的度数为奇数 其余为偶数
//这两个度数为奇数的节点中一个作为欧拉路的起点 另一个作为欧拉路的终点
//对该图进行dfs搜索: 
//对于节点i的所有邻节点做两次判断
//首先判断该邻节点是否为欧拉路的终点
//在图中仍存在未访问的节点时不能访问终点 终点必须作为欧拉路的最后一个节点访问
//第二次判断与欧拉回路中的选择判断一样 选择邻节点中度数最高的节点作为下一次dfs的节点
//
//4)求有向图的欧拉路或欧拉回路
//有向图与无向图的欧拉路或欧拉回路的区别主要在于节点度数方面的差异
//其它方面使用的是相同的技术
//
//求有向图或无向图的欧拉路或者欧拉回路 使用的技术本质相同
//为了方便 本文只求无向图的欧拉回路

#include "general_head.h"
#include "graph.h"
bool loop_exist(int *degree, int n);
void dfs_loop(graph_matrix g, int *degree,
		int beg, stack<int>& path);
int max_degree(graph_matrix g, int *degree, int beg);

bool euler_loop(graph_matrix g, stack<int>& path)
{//邻接矩阵中g.g_m[i][j]的值为0或1 指代从节点i到j是否存在一条有向边
 //判断是否存在欧拉回路 若存在则返回栈path
 //栈path中从底至顶 逆序存储着欧拉回路的所有顶点下标号
 //依次对path出栈即可得到欧拉回路
 //在无向图中不用考虑这个逆序 因为欧拉回路或欧拉路在无向边中可以两个方向走
 //path初始为空
	int degree[MAX];
	memset(degree, 0, MAX * sizeof(int));
	//degree[i]指代节点i的度数
	for(int i = 0; i < g.g_cnt; ++ i)
		for(int j = 0; j < g.g_cnt; ++ j)
			degree[i] += g.g_m[i][j];
	if(loop_exist((int*)degree, g.g_cnt)){
		//判断无向连通图G中是否存在欧拉回路
		dfs_loop(g, degree, 0, path);
		return(true);
	}
	else
		return(false);
}
bool loop_exist(int *degree, int n)
{//判断无向连通图G中是否存在欧拉回路
	for(int i = 0; i < n; ++ i)
		//若存在度数为奇数的节点则不存在欧拉回路
		if(degree[i] % 2 == 1)
			return(false);
	return(true);
}
void dfs_loop(graph_matrix g, int *degree,
		int beg, stack<int>& path)
{//返回的path中从底至顶 逆序存储着欧拉回路的所有顶点下标号
 //对path出栈即可得到欧拉回路 path初始为空
	path.push(beg);
	//找出beg相邻节点中度数最大的节点 对他进行下一次dfs
	int d_max = max_degree(g, degree, beg);
	//终止递归条件 若beg没有邻节点则递归搜索结束
	if(d_max == -1)
		return;

	//每次从当前节点向外找一条新的边
	//并将当前走过的路删除
	g.g_m[beg][d_max] = 0;
	g.g_m[d_max][beg] = 0;
	//当前节点和下一个节点的度数也减1
	-- degree[beg];
	-- degree[d_max];
	dfs_loop(g, degree, d_max, path);
}
int max_degree(graph_matrix g, int *degree, int beg)
{
	int d_max(0), index(-1);
	for(int i = 0; i < g.g_cnt; ++ i){
		if(i == beg)
			continue;
		//在beg相邻节点中找出最大度数节点
		if(g.g_m[beg][i] && d_max < degree[i])
			d_max = degree[i], index = i;
	}
	return(index);
}
