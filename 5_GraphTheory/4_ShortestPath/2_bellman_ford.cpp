//Bellman-Ford算法
//bellman ford

//图G中连接的两节点的边拥有一定距离或权值
//求给定起点beg到其他所有节点的最短路径长度

//若图G存在这样的回路 能从节点u到节点v再经过其他路径回到u 并且经过边的权值之和为负
//则路径在这个回路上每循环一次都可以得到更小的权值 则无限循环不会停止
//存在这样负权值回路的图不存在最短路径
//存在0权值回路和正权值回路的图可以找出最短路径

//按照遍历点集和边集两层来做松弛操作
//再遍历检查一遍边集 若出现使两点距离更小的边
//则说明图G中含有负权值回路 不存在最短路径


#include "general_head.h"
#include "graph.h"

bool bellman_ford(graph_matrix g, edge_list e, int beg, int *distance, int *path)
{//图G有g_cnt个节点 下标从0到g_cnt-1 边集e有e_l.size()条边 下标从0到e_l.size()-1
 //邻接矩阵g和边集e描绘同一个图G 起点为beg
 //distance[i]指代起点beg到节点i的最短距离 path[i]指代节点i在最短路径上的父节点
 //path和distance数组足够大(长度为MAX)
 //返回是否存在最短路径 若存在返回数组distance和path
	//起点beg到各节点距离初始化为INF beg自己距离为0
	for(int i = 0; i < g.g_cnt; ++ i)
		distance[i] = INF;
	distance[beg] = 0;
	//path[beg]值为beg表示该节点为根节点 没有父节点 初始时所有节点path值设为beg
	memset(path, -1, MAX * sizeof(int));
	//for(int i = 0; i < g.g_cnt; ++ i)
	//	path[i] = beg;
	for(int i = 0; i < g.g_cnt; ++ i)
		//外层遍历图的节点个数g_cnt次
		//与具体节点的下标号无关
		for(int j = 0; j < (int)e.e_l.size(); ++ j){
			//内层遍历边集
			//同一节点的g.g_m值为0 不连接的两节点为INF
			//对每条边都需要进行“两个方向”的松弛操作
			//只做一个方向的松弛操作无法得到正确结果
			if(distance[e.e_l[j].e_beg] > 
					distance[e.e_l[j].e_end] + 
					g.g_m[e.e_l[j].e_end][e.e_l[j].e_beg]){
				//若beg->e_beg的距离大于beg->e_end + e_end->e_beg
				distance[e.e_l[j].e_beg] = 
					distance[e.e_l[j].e_end] + 
					g.g_m[e.e_l[j].e_end][e.e_l[j].e_beg];
				path[e.e_l[j].e_beg] = e.e_l[j].e_end;
			}
			if(distance[e.e_l[j].e_end] >
					distance[e.e_l[j].e_beg] +
					g.g_m[e.e_l[j].e_beg][e.e_l[j].e_end]){
				//若beg->e_end距离大于beg->e_beg + e_beg->e_end
				distance[e.e_l[j].e_end] =
					distance[e.e_l[j].e_beg] +
					g.g_m[e.e_l[j].e_beg][e.e_l[j].e_end];
				path[e.e_l[j].e_end] = e.e_l[j].e_beg;
			}
		}
	//遍历边集进行检查
	for(int i = 0; i < (int)e.e_l.size(); ++ i)
		if(distance[e.e_l[i].e_beg] > 
					distance[e.e_l[i].e_end] + 
					g.g_m[e.e_l[i].e_end][e.e_l[i].e_beg] ||
					distance[e.e_l[i].e_end] >
					distance[e.e_l[i].e_beg] +
					g.g_m[e.e_l[i].e_beg][e.e_l[i].e_end])
			//若还存在更短的路径则说明存在负权值回路
			return(false);
	return(true);
}
