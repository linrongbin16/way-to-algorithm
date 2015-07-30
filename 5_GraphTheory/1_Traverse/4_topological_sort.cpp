//拓扑排序
//topological sort

//对有向无环图进行拓扑排序 图中确定存在一个起点 一个终点
//拓扑顺序是将图中的所有节点排成一条直线 使得左边节点的边总是指向右边节点

//拓扑排序属于深度搜索的应用
//1)深度优先搜索方法
//对图中每个节点重复以下步骤:
//对该节点进行深度递归搜索 并且每进行一次递归都累加递归次数
//最终得到该节点的递归次数 这个次数是该节点在图中通过深度优先搜索所能经过的节点数
//当递归到达终点时无法继续递归 所以这个次数也可以看做该节点到终点的距离
//得到所有节点的递归次数之后按该值对所有节点从大到小排序
//距离最大的也就是离终点最远的点即起点 距离最小的节点即终点自己
//则排序后的节点顺序即为节点的拓扑顺序
//2)判断节点度数方法
//i)对邻接表重复以下步骤:
//每次在邻接表中找出入度为0的节点 将该节点删去
//这个入度为0的节点只指向别的节点 但没有被别的节点指向的节点
//可以看作当前有向图中的起点
//直到图中所有节点都被删去 节点被删去的顺序即为该节点在拓扑中的顺序
//ii)也可以逆向的从有向图的终点开始 删除所有出度为0的节点 直到所有节点都被删去
//节点被删去的顺序与拓扑排序中的节点顺序正好相反
//
//3)补注
//通过dfs方法和通过判断节点度数的方法来进行拓扑排序 二者有着本质的区别
//dfs的方法本质上是寻找一个节点通过递归能够到达的最远距离
//判断节点度数的方法本质上是寻找各节点到有向图终点的最近距离
//但是判断节点度数的方法无法应用在存在环的图中 但dfs方法仍然可以使用
//因此dfs方法比判断节点度数的方法更好 算法导论中关于拓扑排序的描述也使用dfs方法


//1)深度优先搜索方法 算法导论中伪语言的实现

#include "general_head.h"
#include "graph.h"
//depth_first_search_adjlist.cpp
extern void dfs_visit(graph_list& g, int p, int *visited, int& time);
bool compare(graph_node a, graph_node b);

void topological_sort1(graph_list g, deque<graph_node>& topo)
{//图G有g_l.size()个节点 下标从0到g_l.sizeZ()-1
 //返回的队列中的节点顺序即为拓扑序列
	topo.resize((int)g.g_l.size());
	int visited[MAX], time(0);
	memset(visited, 0, MAX * sizeof(int));
	for(int i = 0; i < (int)g.g_l.size(); ++ i)
		topo[i].g_idx = i;
	for(int i = 0; i < (int)g.g_l.size(); ++ i)
		if(!visited[i])
			//从i.g_idx节点开始dfs遍历
			dfs_visit(g, i, visited, time);
	for(int i = 0; i < (int)g.g_l.size(); ++ i)
		topo[i].g_value = g.g_l[i][0].g_value;
	//按照dfs搜索到的时间排序 时间大的在前面 小的在后
	//可以认为时间最小的是dfs次数最少的节点 即拓扑排序中最后面的节点
	//而dfs次数最大的节点是起始节点
	sort(topo.begin(), topo.end(), compare);
}
bool compare(graph_node a, graph_node b)
{
	return(a.g_value > b.g_value);
}

//2)判断节点度数方法

void degree(graph_list g, int *in_degree);

void topological_sort2(graph_list g, deque<graph_node>& topo)
{
	topo.clear();
	//in_degree[i]指代节点i的入度
	int in_degree[MAX];
	while(!g.g_l.empty()){
		//每次循环之前更新节点入度为0 因为上次循环中删除节点会改变节点状态
		//求出当前图中各节点的入度
		degree(g, in_degree);
		for(int i = 0; i < MAX; ++ i)
			if(in_degree[i] == 0) 
				//在in_degree中找 出入度为0的节点
				for(deque<deque<graph_node> >::iterator it = g.g_l.begin();
						it != g.g_l.end(); ++ it)
					if((*it)[0].g_idx == i){
						//加入答案集
						topo.push_back((*it)[0]);
						//在邻接表g_l中删除该节点
						g.g_l.erase(it);
						//该节点只有一个 可以跳过余下的判断
					 	break;
					} 
	}
}
void degree(graph_list g, int *in_degree)
{
	memset(in_degree, 0, MAX * sizeof(int));
	for(int i = 0; i < (int)g.g_l.size(); ++ i)
		for(int j = 1; j < (int)g.g_l[i].size(); ++ j)
			//第i个队列上第j个节点即为节点j.g_idx的一条入弧边
			++ in_degree[g.g_l[i][j].g_idx];
}
