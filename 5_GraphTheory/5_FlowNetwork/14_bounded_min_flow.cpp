//有源汇容量有上下界的最小流
//bounded_min_flow.cpp

//求有源汇容量有上下界的流网络是否存在可行流，若存在求其最小流

//该问题与有源汇容量有上下界的最大流问题的唯一区别是求最小流，可行流部分完全一样
//该问题的求解方法与有源汇网络最大流的方法也类似，但在构造流网络的顺序上有不同
//对本文中的原流网络，不填加从汇点end到源点beg容量无穷大的边
//直接应用无源汇流网络的方法，添加超级源点超级汇点，构造为对应的普通流网络
//求普通流网络中从超级源点到超级汇点的最大流lower_max_flow
//再添加从汇点end到源点beg容量无穷大的边
//再求一次从超级源点到超级汇点的最大流lower_max_flow2
//若lower_max_flow2最大流等于超级源点所有出弧边容量之和，即超级源点满负荷
//则原有源汇网i络存在可行流，其最小流即为第二次最大流中汇点end到源点beg那条边的流量
//
//本文引用了“sgu 176 上下界最小流（抄ZZY的）”，作者“Bungee Jump”

#include "general_head.h"
#include "graph.h"
//no_source_sink_bounded_flow.cpp
extern void construct_c(graph_matrix upper, graph_matrix lower,
		int beg, int end, graph_matrix& residue);
extern int beg_out(graph_matrix residue, int beg, int n);
//distance_label.cpp
extern int distance_label(graph_matrix residue, int beg, int end);
//source_sink_bounded_max_flow.cpp
extern void construct_n(graph_matrix& n_upper, int beg, int end);

bool bounded_min_flow(graph_matrix upper, graph_matrix lower,
		int beg, int end, int& min_flow)
{//流网络有g_cnt个节点，下标从0到g_cnt-1，upper为上界容量，lower为下界容量
 //返回有源汇容量有上下界的流网络中是否存在可行流，若存在返回最小流min_flow
	min_flow = 0;
	graph_matrix n_upper(upper), n_lower(lower);
	int s_beg, s_end;
	graph_matrix residue(n_upper);
	residue.g_cnt += 2;
	s_beg = residue.g_cnt - 2;
	s_end = residue.g_cnt - 1;
	construct_c(n_upper, n_lower, s_beg, s_end, residue);
	//第一次计算最大流
	int lower_max_flow = distance_label(residue, s_beg, s_end);
	int s_beg_out = beg_out(residue, s_beg, n_upper.g_cnt);
	//若第一次最大流已经等于超级源点所有出弧边容量之和，即已经满负荷
	if(lower_max_flow == s_beg_out)
		return(false);

	//若lower_max_flow < s_beg_out，即尚未满负荷
	//添加从汇点end到源点beg容量无穷大的边
	construct_n(residue, beg, end);
	//再次计算最大流
	//由于计算从汇点end到源点beg边上的流需要更改distance_label代码，不方便扩展
	//所以本文略去具体的代码(读者只需要对distance_label代码稍作更改即可求出min_flow)
	int lower_max_flow2 = distance_label(residue, s_beg, s_end);
	int s_beg_out2 = beg_out(residue, s_beg, n_upper.g_cnt);
	if(lower_max_flow2 == s_beg_out2)
		return(true);
	else
		return(false);
}
