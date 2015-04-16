//无源汇容量有上下界的流网络
//no_source_sink_bounded_flow.cpp

//无源汇容量有上下界的流网络是这样的：
//其边不仅拥有最大容量，同时还拥有最小容量(至少必须使用的容量)
//每个节点都有入弧边(从别的节点指向该节点)和出弧边(从该节点指向其他节点)
//即没有源点和汇点，源点是只具有出弧边的流起点，汇点是只具有入弧边的流终点
//在该流网络中，每个节点的流入和流出相等，每条边都会运输一定的流
//如果在该流网络中存在大于0的流则称为存在可行流(下界的存在可能会使断流)
//判断这样的流网络中是否存在可行流

//设流网络中边的上界为upper，下界为lower，其中 0<=lower<=upper
//则边可以使用的容量f取值范围为 lower<=f<=upper
//显然当lower为0时，该边退化为普通流网络的边即最大可使用容量为upper
//或者说之前问题中的流网络中的边是下界lower等于0的边
//无源汇容量有上下界流网络判定存在可行流的问题可以转化为普通流网络的最大流问题
//设置新的源点beg和汇点end，sum_in，sum_out和ennode数组，对于每个节点i有
//sum_in[i]指代所有流入节点i的下界流之和，sum_out[i]指代所有从节点i流出的下界流之和
//ennode[i]=sum_in[i]-sum_out[i]指代节点i预存的流
//若ennode[i]>0，则节点i还需流出该流
//连接一条从源点beg到节点i的边，容量上界为ennode[i]，下界为0
//若ennode[i]<0，则节点i还需流入该流
//连接一条从节点i到汇点end的边，容量上界为|ennode[i]|，下界为0
//对于原流网络中的所有边，将它们设置为上界upper-lower，下界为0
//这样即得到新的普通流网络，求其最大流
//该普通网络中源点的出弧边和汇点的入弧边都是原无源汇网络的下界容量
//显然该网络的最大流受到下界容量的限制
//普通网络的最大流实际是原无源汇网络的下界流，即无源汇网络中的最小流
//当该最大流等于源点beg的所有出弧边的容量之和时，源点的所有出弧边都被流占满了
//即源点是处于满负荷状态的，此时可判断原无源汇流网络存在可行流
//
//本文以及后面的有源汇容量有上下界的最大流，有源汇容量有上下界的最小流三篇都引用了
//“有上下界的网络流问题”，作者“Mr.Ant”

#include "general_head.h"
#include "graph.h"
//distance_label.cpp
extern int distance_label(graph_matrix residue, int beg, int end);
void construct_c(graph_matrix upper, graph_matrix lower,
		int beg, int end, graph_matrix& residue);
int beg_out(graph_matrix residue, int beg, int n);

bool no_source_sink_bounded_flow(graph_matrix upper, graph_matrix lower)
{//流网络有g_cnt个节点，下标从0到g_cnt-1，upper是上界容量，lower是下界容量
 //返回无源汇容量有上下界的流网络是否存在可行流
	//beg和end是新增源点汇点
	int beg, end;
	graph_matrix residue(upper);
	residue.g_cnt += 2;
	beg = residue.g_cnt - 2;	//新增源点beg是倒数第二个节点
	end = residue.g_cnt - 1;	//新增汇点end是倒数第一个节点
	//将residue构造为有上下界流网络的对应普通流网络
	construct_c(upper, lower, beg, end, residue);
	//判断普通流网络的最大流等于beg的出弧边的容量之和
	if(distance_label(residue, beg, end) ==
			beg_out(residue, beg, upper.g_cnt))
		return(true);
	else
		return(false);
}
void construct_c(graph_matrix upper, graph_matrix lower,
		int beg, int end, graph_matrix& residue)
{
	int ennode[MAX], sum_in[MAX], sum_out[MAX];
	memset(ennode, 0, MAX * sizeof(int));
	memset(sum_in, 0, MAX * sizeof(int));
	memset(sum_out, 0, MAX * sizeof(int));
	//新增源点汇点添加边
	for(int i = 0; i < upper.g_cnt; ++ i){
		//对原流网络中每个节点i
		for(int j = 0; j < upper.g_cnt; ++ j){
			//对节点i的每个邻节点j
			//从i到j的出弧边的下界容量为节点i的出流
			if(lower.g_m[i][j])
				sum_out[i] += lower.g_m[i][j];
			//从j到i的出弧边的下界容量为节点i的入流
			if(lower.g_m[j][i])
				sum_in[i] += lower.g_m[j][i];
		}
		ennode[i] = sum_in[i] - sum_out[i];
		if(ennode[i] > 0)
			residue.g_m[beg][i] = ennode[i];	
		else if(ennode[i] < 0)
			residue.g_m[i][end] = abs(ennode[i]);
	}
	//原无源汇流网络中边的容量上界变为upper-lower，下界变为0
	for(int i = 0; i < upper.g_cnt; ++ i)
		for(int j = 0; j < upper.g_cnt; ++ j)
			residue.g_m[i][j] = upper.g_m[i][j] - lower.g_m[i][j];
}
int beg_out(graph_matrix residue, int beg, int n)
{
	int sum(0);
	for(int i = 0; i < n; ++ i)
		sum += residue.g_m[beg][i];
	return(sum);
}
