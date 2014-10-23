//图论头文件
//graph.h

//支持图一章的自定义数据结构
//在图这一章中，默认为在一个图或树的空间中可用一个下标号来唯一标识一个节点
//在邻接矩阵，邻接表和边集这样的集合型数据结构中节点下标从0开始
//而且结构体中的指针都支持复制，即将一个结构体复制给另一个时也包括指针成员

#include <vector>
#include <deque>
#include <cstring>
#ifndef NULL
#define NULL 0
#endif
#ifndef MAX
#define MAX 60
#endif
using std::vector;
using std::deque;

struct tree_node{
	int t_idx;					//t_idx指代当前节点的下标号，从0开始
								//它是该节点在树中的唯一标识
	int t_value;				//t_value指代当前节点权值
	tree_node *t_lc;			//t_lc指向左孩子节点
	tree_node *t_rc;			//t_rc指向右孩子节点
	tree_node *t_fa;			//t_fa指向父节点
	tree_node(int cidx = 0, int cvalue = 0)
		: t_idx(cidx), t_value(cvalue), t_lc(NULL), t_rc(NULL), t_fa(NULL){
	}
	tree_node(const tree_node& cr)
		: t_idx(cr.t_idx), t_value(cr.t_value),
		t_lc(cr.t_lc), t_rc(cr.t_rc), t_fa(cr.t_fa){
	}
};
struct graph_node{
	int g_idx;					//g_idx指代当前节点在图中的下标号，从0开始
								//它是该节点在图中的唯一标识
	int g_value;				//g_value指代当前节点权值
	graph_node(int cidx = 0, int cvalue = 0)
		:g_idx(cidx), g_value(cvalue){
	}
	graph_node(const graph_node& cr)
		: g_idx(cr.g_idx), g_value(cr.g_value){
	}
};
struct graph_matrix{
	int g_m[MAX][MAX];			//g_m[i][j]指代矩阵中节点i到j的单向距离
	int g_cnt;					//g_cnt指代矩阵中节点数量，节点下标从0到g_cnt-1
	graph_matrix(int ccnt = 0)
		: g_cnt(ccnt){
			memset(g_m, 0, MAX * MAX * sizeof(int));
	}
	graph_matrix(const graph_matrix& cr)
		: g_cnt(cr.g_cnt){
			for(int i = 0; i < MAX; ++ i)
				for(int j = 0; j < MAX; ++ j)
					g_m[i][j] = cr.g_m[i][j];
	}
};
struct graph_list{
	deque<deque<graph_node> > g_l;	//邻接表通过嵌套队列实现
									//第i个队列g_l[i]表示i节点的邻节点组成的单链
									//每个队列中都有一个头节点
									//即队列i中的节点g_l[i][0]是节点i
									//之后从1开始才是节点i的邻节点
									//并且保证队列i中的头结点g_l[i][0]
									//中的g_idx成员与i相等
									//但队列i中其他的节点的g_idx成员与下标则无关系
	graph_list(int ccnt = 0)
		: g_l(ccnt){
	}
	graph_list(const graph_list& cr)
		: g_l(cr.g_l){
	}
};
struct edge{	
	//edge数据结构以及后面的edge_list数据结构是我自己进行设计的
	//edge指代图中的一条有向边，从节点e_beg指向节点e_end
	
	int e_beg;					//边的起点
	int e_end;					//边的终点
	double e_value;				//边的权值
								//使用double专门支持最优比率生成树的计算
	int e_join;					//标记该边是否已经加入生成树
								//以及该边所属的生成树的下标号
	double e_cost;				//边的费用
	double e_dist;				//边的长度
								//费用和长度两个成员专门支持
								//最优比率生成树和最小费用流问题的计算

	int e_next;					//专门用于支持最大流中距离标号算法的邻接表优化形式

	edge(int cbeg = 0, int cend = 0, double cvalue = 0,
			int cjoin = 0, double ccost = 0, double cdist = 0, int cnext = 0)
		: e_beg(cbeg), e_end(cend), e_value(cvalue),
		e_join(cjoin), e_cost(ccost), e_dist(cdist), e_next(cnext){
	}
	edge(const edge& cr)
		: e_beg(cr.e_beg), e_end(cr.e_end), e_value(cr.e_value),
		e_join(cr.e_join), e_cost(cr.e_cost), e_dist(cr.e_dist), e_next(cr.e_next){
	}
};
struct edge_list{
	//一个图可以使用边集edge_list来描述，存储图中所有的边
	//并且规定：无向图中的一条边使用两条反向且权值相等的edge来描述
	
	vector<edge> e_l;			//使用vector实作该数据结构
	edge_list(int ccnt = 0)
		: e_l(ccnt){
	}
	edge_list(const edge_list& cr)
		:e_l(cr.e_l){
	}
};
struct bipartite{
	//专门用于支持二分图的计算

	int b_g[MAX][MAX];					//b_g[i][j]指代二分图中节点i和j之间存在边
										//且节点i属于X集合，节点j属于Y集合
	int b_xn, b_yn;						//b_xn(b_yn)指代属于X(Y)集合的节点数量
										//从0到b_xn-1(b_yn-1)
										//在xmatch和ymatch中有两个相等的下标号i
										//xmatch中的节点i是X集合中的第i个节点
										//ymatch中的节点i是Y集合中的第i个节点
										//但它们并不是在二分图中的唯一标记
										//二分图的节点数量=X节点数量+Y节点数量
	bipartite(int cxn = 0, int cyn = 0)
		: b_xn(cxn), b_yn(cyn){
			memset(b_g, 0, MAX * MAX * sizeof(int));
	}
	bipartite(const bipartite& cr)
		: b_xn(cr.b_xn), b_yn(cr.b_yn){
			for(int i = 0; i < MAX; ++ i)
				for(int j = 0; j < MAX; ++ j)
					b_g[i][j] = cr.b_g[i][j];
	}
};
