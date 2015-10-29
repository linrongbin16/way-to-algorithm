//最小费用最大流
//minimum_cost_maximum_flow.cpp

//在最大流问题基础上，若网络流中所有管道在拥有一定运输能力的同时也要求一定的运输费用
//即网络流中每条边都有单位流量所需要的费用cost，当使用volum容量时的花费是volum*cost
//在给定网络流上求出最大流前提下最小花费的流

//1)两种方法
//方法一：
//先使用最大流算法求出网络中的最大流，根据边的费用检查在平衡的前提下调整边的流量
//使得最大流不便但总费用减少，调整后得到一个新的最大流
//重复以上的调整过程直到无法继续调整，即可得到最小费用最大流
//方法二：
//与最大流算法中增广路径相似，每次在网络中找出一条花费最少的增广路径
//直到无法继续找出新的增广路径，即可得到最小费用最大流
//第二种方法较流行所以本文也实现该算法
//
//2)具体实现
//方法二的框架与最大流中增广路径方法一样，也是重复的寻找增广路径
//但本方法中要求每次找的增广路径必须是残留网络中费用最小的路径
//将每条边的费用看作边的长度，则寻找最小费用路径的问题等效于寻找一条最短路径
//则可以借用最短路径算法来求出一条残留网络中从源点beg到汇点end的最短路径
//由于残留网络中可能存在负权值路径，所以使用单源最短路径算法spfa求残留网络的最短路径
//但事实上由于本节中残留网络的“添加反向边”这一操作不会使残留网络中出现负权值的边
//整个算法过程中所有边的权值都保证大于等于0
//“添加反向边”在很多文档中有各种复杂的处理，所以在其他版本的方法中会存在负权值的边

#include "general_head.h"
#include "graph.h"
//spfa.cpp
extern bool spfa(graph_matrix g, int beg, int *distance, int *path);

pair<int, int> minimum_cost_max_flow(graph_matrix residue, graph_matrix cost,
		int beg, int end)
{//流网络residue有g_cnt个节点，下标从0到g_cnt-1
 //cost是流网络中边的单位开销，cost.g_m[i][j]指代从i到j的边的单位开销
 //其中同一节点花费的g_m值为0，不相连的两节点花费g_m值为INF(和之前的方式一样)
 //返回的pair.first是最大流max_flow，pair.second是最小花费min_cost
	int path[MAX], distance[MAX], max_flow(0), min_cost(0);
	//gc是残留网络对应的以花费为路径权值的图，cost留作花费参照不变
	graph_matrix gc(cost);
	//spfa找出gc中从源点beg到各节点的最短路径
	while(spfa(gc, beg, distance, path)){
		//通过spfa找出一条花费最小的路径存储于path中
		if(distance[end] == INF)
			//若源点到汇点的最短距离等于INF则说明无法继续找出增广路径，算法结束
			return(make_pair(max_flow, min_cost));
			
		int volum(INF);
		for(int u = end; u != beg; u = path[u])
			volum = min(volum, residue.g_m[path[u]][u]);
		for(int u = end; u != beg; u = path[u]){
			residue.g_m[path[u]][u] -= volum;
			//原边减去增广路径上该边使用的容量volum
			//若该边没有容量则gc图中认为该边为断路即权值为INF
			if(residue.g_m[path[u]][u] == 0)
				gc.g_m[path[u]][u] = INF;
			//对应添加反向边，在gc图中该边的花费与对应正向边的花费相等
			residue.g_m[u][path[u]] += volum;
			if(residue.g_m[u][path[u]] > 0)
				gc.g_m[u][path[u]] = cost.g_m[u][path[u]];
			//花费为该边的单位开销乘增广路径上使用的容量
			min_cost += cost.g_m[path[u]][u] * volum;
		}
		max_flow += volum;
	}
	return(make_pair(-1, -1));
}
