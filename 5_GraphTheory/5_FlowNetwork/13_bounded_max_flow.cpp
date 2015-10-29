//有源汇容量有上下界的最大流
//bounded_max_flow.cpp

//与无源汇容量有上下界的流网络的结构基本相同，但存在源点汇点
//即源点只有出弧边，汇点只有入弧边，判断该网络是否存在可行流
//若存在可行流求出最大流

//求解有源汇容量有上下界的流网络的方法基于无源汇网络
//添加一条从汇点指向源点的边，容量上界为无穷，下界为0
//该网络即转变为无源汇网络，应用无源汇网络判断可行流的方法可判断该网络是否存在可行流
//在无源汇网络的基础上再添加超级源点s_beg和超级汇点s_end
//无源汇网络对应的普通网络的最大流是无源汇网络的下界最大流，称之为lower_max_flow
//将普通网络中的超级源点和超级汇点及其边删去
//将开始添加的从汇点到源点容量无限的边也删去
//这时的网络的拓扑结构与原有源汇网络是一样的
//但边的容量在无源汇网络转化为普通网络的过程中改变了
//边的容量上界变为upper-lower，容量下界为0，此时的网络实际是原有源汇网络中的自由流
//即在容量上下界之间lower<=f<=upper，这部分可有可无不影响可行流存在的流
//对该网络再求一次最大流得到free_max_flow，即为自由流的最大流
//则有源汇容量有上下界的流网络的最大流为max_flow = lower_max_flow + free_max_flow

#include "general_head.h"
#include "graph.h"
//no_source_sink_bounded_flow.cpp
extern void construct_c(graph_matrix upper, graph_matrix lower,
		int beg, int end, graph_matrix& residue);
//no_source_sink_bounded_flow.cpp
extern int beg_out(graph_matrix residue, int beg, int n);
//distance_label.cpp
extern int distance_label(graph_matrix residue, int beg, int end);
void construct_n(graph_matrix& n_upper, int beg, int end);
void deconstruct_c(graph_matrix& residue,
		int s_beg, int s_end, int beg, int end);

bool bounded_max_flow(graph_matrix upper, graph_matrix lower,
		int beg, int end, int& max_flow)
{//流网络有g_cnt个节点，下标从0到g_cnt-1，upper为上界容量，lower为下界容量
 //返回有源汇容量有上下界的流网络中是否存在可行流，若存在返回最大流max_flow
	max_flow = 0;
	//n_upper和n_lower是有源汇网络对应的无源汇网络
	graph_matrix n_upper(upper), n_lower(lower);
	//构造无源汇网络n_upper和n_lower，添加一条从end到beg的无穷大的边
	construct_n(n_upper, beg, end);
	//s_beg为超级源点，s_end为超级汇点
	int s_beg, s_end;
	graph_matrix residue(n_upper);
	residue.g_cnt += 2;
	s_beg = residue.g_cnt - 2;
	s_end = residue.g_cnt - 1;
	//将residue构造为无源汇网络对应的普通流网络
	construct_c(n_upper, n_lower, s_beg, s_end, residue);
	int lower_max_flow = distance_label(residue, s_beg, s_end);
	int s_beg_out = beg_out(residue, s_beg, n_upper.g_cnt);
	//若不相等则不存在可行流，也不存在最大流
	if(lower_max_flow != s_beg_out)
		return(false);

	//若存在可行流，则计算最大流
	//将residue中的超级源点超级汇点和原汇点到源点的边删去
	deconstruct_c(residue, s_beg, s_end, beg, end);
	int free_max_flow = distance_label(residue, beg, end);
	max_flow = lower_max_flow + free_max_flow;
	return(true);
}
void construct_n(graph_matrix& n_upper, int beg, int end)
{
	n_upper.g_m[end][beg] = INF;
}
void deconstruct_c(graph_matrix& residue,
		int s_beg, int s_end, int beg, int end)
{
	//删去超级源点超级汇点的所有边
	for(int i = 0; i < residue.g_cnt; ++ i){
		residue.g_m[s_beg][i] = 0;
		residue.g_m[i][s_beg] = 0;
		residue.g_m[s_end][i] = 0;
		residue.g_m[i][s_end] = 0;
	}
	//删去超级源点和超级汇点
	residue.g_cnt -= 2;
	//删去从end到beg的容量无穷大的边
	residue.g_m[end][beg] = 0;
}
