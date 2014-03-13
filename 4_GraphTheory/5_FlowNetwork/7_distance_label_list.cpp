//距离标号算法邻接表优化
//distance_label_list.cpp

//属于增广路径类算法

//用邻接表的数据结构对距离标号算法进行优化
//网络文档“最大流算法拓展(网络最大流算法算法拓展)”中所谓的邻接表恰好是
//我自定义的边集数据结构edge_list，所以也可以称其为边集数据结构的优化
//
//本文是最大流问题的终极解法，它对于稀疏图具有非常好的空间复杂度优化
//但实际比赛编程中使用图矩阵更容易，一般最大流题目不会有很大的节点数量
//
//到目前为止，我们已经讲解了所有的最大流算法
//其中最重要最常用的算法是距离标号算法
//如果读者一时无法理解，请按照中国人的传统进行强行背诵
//经过多次的调试程序自然会明白其中的技巧
//
//本文引用了“网络最大流算法算法拓展(最大流算法拓展，百度文库)”，作者“lkbllkbl”

#include "general_head.h"
#include "graph.h"
void construct_d(edge_list residue,
		int beg, int end, int *d, int *d_num);
int find_allow_edge(int u, edge_list residue, int *d);
int relabel(int u, edge_list residue, int *d);

int distance_label_list(edge_list residue, int beg, int end)
{//流网络residue有e_l.size()条边，下标从0到e_l.size()-1
 //e_l[i].e_value指代边i的残留容量，该边的起点是e_beg终点是e_end
	int d[MAX], d_num[MAX], path[MAX];
	memset(path, -1, MAX * sizeof(int));
	construct_d(residue, beg, end, d, d_num);
	int max_flow(0), u(beg);
	//这里的条件与距离标号中的条件不太一样
	//距离标号算法是判断距离标号是否小于节点数量|V|
	//这里判断距离标号是否小于边的数量|E|
	while(d[beg] < (int)residue.e_l.size()){
			int p = find_allow_edge(u, residue, d);
		if(p >= 0){
			path[p] = u;
			u = p;
			if(u == end){
				//找到一条增广路径
				int volum = INF;
				for(u = end; u != beg; u = path[u]){
					//从v到u的边是一条增广路径上的边
					int v = path[u];	
					for(int i = 0; i < (int)residue.e_l.size(); ++ i)
						//遍历残留网络residue中的边
						//注意这里对边edge中e_beg和e_end两成员的用法
						if(residue.e_l[i].e_beg == v && residue.e_l[i].e_end == u){
							//找出这条从v到u的边
							volum = min(volum, (int)residue.e_l[i].e_value);
							//这条边是唯一的可直接跳出循环
							break;
						}
				}
				for(u = end; u != beg; u = path[u]){
					int v = path[u];
					//增广路径上所有的容许边减去增广路径的容量
					for(int i = 0; i < (int)residue.e_l.size(); ++ i)
						if(residue.e_l[i].e_beg == v && residue.e_l[i].e_end == u){
							residue.e_l[i].e_value -= volum;
							break;
						}
					//添加反向边
					//edge_exist指代边集中是否存在该反向边
					//若边集residue中已经有这条反向边，增加权值volum
					int edge_exist = 0;
					for(int i = 0; i < (int)residue.e_l.size(); ++ i)
						if(residue.e_l[i].e_beg == u && residue.e_l[i].e_end == v){
							residue.e_l[i].e_value += volum;
							edge_exist = 1;
							break;
						}
					//若没有这条反向边，则增加一条权值为volum的边
					if(!edge_exist){
						edge e;
						e.e_beg = u; e.e_end = v; e.e_value = volum;
						residue.e_l.push_back(e);
					}
				}
				max_flow += volum;
			}
		}
		else{
			-- d_num[d[u]];
			if(d_num[d[u]] == 0)
				return(max_flow);
			int v = relabel(u, residue, d);
			++ d_num[v];
			d[u] = v;
			if(u != beg)
				u = path[u];
		}
	}
	return(max_flow);
}
void construct_d(edge_list residue,
		int beg, int end, int *d, int *d_num)
{
	for(int i = 0; i < MAX; ++ i)
		d[i] = INF;
	memset(d_num, 0, MAX * sizeof(int));
	queue<int> q;
	q.push(end);
	d[end] = 0;
	d_num[0] = 1;
	while(!q.empty()){
		int p = q.front(); q.pop();
		for(int i = 0; i < (int)residue.e_l.size(); ++ i)
			if(residue.e_l[i].e_end == p &&
					d[residue.e_l[i].e_beg] >= (int)residue.e_l.size() &&
					residue.e_l[i].e_value > 0){
				d[residue.e_l[i].e_beg] = d[residue.e_l[i].e_end] + 1;
				q.push(residue.e_l[i].e_beg);
				++ d_num[d[residue.e_l[i].e_beg]];
			}
	}
}
int find_allow_edge(int u, edge_list residue, int *d)
{
	for(int i = 0; i < (int)residue.e_l.size(); ++ i)
		if(residue.e_l[i].e_beg == u &&
				residue.e_l[i].e_value > 0 && d[u] == d[residue.e_l[i].e_end] + 1)
			return(residue.e_l[i].e_end);
	return(-1);
}
int relabel(int u, edge_list residue, int *d)
{
	int d_tmp(INF);
	for(int i = 0; i < (int)residue.e_l.size(); ++ i)
		if(residue.e_l[i].e_beg == u &&
				residue.e_l[i].e_value > 0)
			d_tmp = min(d_tmp, d[residue.e_l[i].e_end] + 1);
	return(d_tmp);
}






