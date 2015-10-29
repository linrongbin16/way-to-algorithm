//距离标号算法邻接表优化
//distance_label_list.cpp

//距离标号算法邻接表优化属于增广路径类算法，用该算法求解最大流问题

//用邻接表的数据结构对距离标号算法进行优化
//该解法是最大流问题的终极解法，它对于稀疏图具有非常好的空间复杂度优化
//但实际比赛编程中使用图矩阵更容易，一般最大流题目不会有很大的节点数量
//
//到目前为止，我们已经讲解了所有的最大流算法
//其中最重要最常用的算法是距离标号算法
//如果读者一时无法理解，请按照中国人的传统进行强行背诵
//经过多次的调试程序自然会明白其中的技巧
//
//该算法和本节第4篇的距离标号算法，这两篇算法
//使用了Peking University Judge Online for ACM/ICPC中的1087 A Plug for UNIX题目
//作为测试，实际测试中发现虽然代码的接口提供了最大流起点beg，终点end节点号的参数
//但实际上我将起点设置为一个其他的数字时，在该题目中是Wrong Answer
//比如说最大流中起点号为10，终点号为11，其他中间节点号为从0到9，节点总数为12
//则在该题目的测试中会出错，而若起点为0，终点为11，其他节点从1到10则正确
//因此读者在编码时也应该注意保证起点和终点分别是节点号的0和最大值
//
//而且在1087 A Plug for UNIX这个题目中流网络中的所有节点也是自然按照拓扑顺序出现的
//每个节点的节点号按照拓扑顺序增加，我没有测试过乱序情况下该算法的表现
//为了形成对比我也上传了POJ中1087 A Plug for UNIX题目的两个版本的算法
//一个使用邻接矩阵，另一个使用邻接表
//
//本文引用了“J-1087-A Plug for UNIX(菜鸟的程序人生)”，作者“Cambridge”

#include "general_head.h"
#include "graph.h"
void construct_h(edge_list &residue, int *head);
int find_allow_edge(int u, edge_list residue, int *d,
		int *path, int *current, int *augment);
int relabel(int u, edge_list residue, int *d, int *head, int *current);

int distance_label_list(edge_list residue, int beg, int end, int n)
{//流网络residue有e_l.size()条边，下标从0到e_l.size()-1，流网络中共有n个节点
 //e_l[i].e_value指代边i的残留容量，该边的起点是e_beg终点是e_end
 //使用该代码应该总保证流网络的起点beg的节点号为0，终点end为所有节点号的最大值
 //并且在边集合residue中偶数号的边是初始容量为正的边，奇数的边是初始容量为0的边
 //其中容量初始为0的边是为了添加反向边操作而加入的，初始时没有容量
 //比如边集residue中residue.e_l[0]偶数边是初始有容量的边
 //对应的residue.e_l[1]奇数边是其反向边，初始容量为0
	int d[MAX], d_num[MAX], path[MAX], augment[MAX], head[MAX], current[MAX];
	memset(path, -1, MAX * sizeof(int));
	memset(d, 0, MAX * sizeof(int));
	memset(d_num, 0, MAX * sizeof(int));
	memset(augment, 0, MAX * sizeof(int));

	augment[beg] = INF;
	path[beg] = -1;
	d_num[0] = n;
	construct_h(residue, head);
	copy(head, head + MAX, current);

	int max_flow(0), u(beg);
	//基本结构与距离标号算法一样
	while(d[beg] < n){
		if(u == end){
			//找到一条增广路径
			max_flow += augment[end];
			for(int v = path[end]; v != -1; v = path[v]){
				//更新残留网络
				int index = current[v];	
				residue.e_l[index].e_value -= augment[end];
				residue.e_l[index ^ 1].e_value += augment[end];
				augment[v] -= augment[end];
				if(residue.e_l[index].e_value == 0)
					u = v;
			}
		}
		int p = find_allow_edge(u, residue, d, path, current, augment);
		if(p >= 0){
			u = p;
		}
		else{
			if(-- d_num[d[u]] == 0)
				return(max_flow);
			d[u] = relabel(u, residue, d, head, current);
			++ d_num[d[u]];
			if(u != beg)
				u = path[u];
		}
	}
	return(max_flow);
}
void construct_h(edge_list &residue, int *head)
{
	//因为边集residue总是偶数，每条有容量的边都对应有一条初始容量为0的反向边
	memset(head, -1, MAX * sizeof(int));
	//初始化head数组
	for(int i = 0; i < (int)residue.e_l.size(); i += 2){
		//residue.e_l[i].e_next的值即为该边的起点的head值
		residue.e_l[i].e_next = head[residue.e_l[i].e_beg];
		//而该边的起点的head值为边的下标号
		head[residue.e_l[i].e_beg] = i;
		//对应的反向边
		residue.e_l[i + 1].e_next = head[residue.e_l[i + 1].e_beg];
		head[residue.e_l[i + 1].e_beg] = i + 1;
	}
}
int find_allow_edge(int u, edge_list residue, int *d,
		int *path, int *current, int *augment)
{
	for(int i = current[u]; i != -1; i = residue.e_l[i].e_next){
		int v = residue.e_l[i].e_end;
		if(residue.e_l[i].e_value > 0 && d[u] == d[v] + 1){
			path[v] = u;
			current[u] = i;
			augment[v] = min(augment[u], (int)residue.e_l[i].e_value);
			return(v);
		}
	}
	return(-1);
}
int relabel(int u, edge_list residue, int *d, int *head, int *current)
{
	int min_dist(INF);
	for(int i = head[u]; i != -1; i = residue.e_l[i].e_next){
		int v = residue.e_l[i].e_end;
		if(residue.e_l[i].e_value > 0 && d[v] + 1 < min_dist){
			min_dist = d[v] + 1;
			current[u] = i;
		}
	}
	return(min_dist);
}
