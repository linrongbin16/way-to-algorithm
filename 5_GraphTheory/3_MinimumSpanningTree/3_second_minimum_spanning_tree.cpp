//次小生成树
//second_minimum_spanning_tree.cpp

//假设无向简单图G中的最小生成树为T，次小生成树为T1
//其他生成树为T2,T3...则T权值最小，T1其次，T2,T3等均大于(等于)T1
//求次小生成树的边集权值和
//题目的原型为POJ1679

//次小生成树定理：最小生成树替换一条边即可得到次小生成树
//设无向简单图G中的最小生成树为T，存在一个可行替换(-e1, +e2)
//即将T中的边e1删去，将不属于T但属于g的边e2加入生成树
//经过一次替换的结果若仍然是图G的一个生成树，则该替换为可行替换
//替换代价为 e2权值 - e1权值
//则可知：图G的次小生成树即为最小生成树进行一次代价最小的可行替换得到的生成树
//进一步有：
//设可行替换中加入生成树的边e2的两端点为v1和v2
//则e1一定是原最小生成树中v1和v2两端点之间权值最大的边
//
//枚举所有属于图G但不属于T的边e，设边e的两端点为v1和v2
//则可行替换一定是用e替换最小生成树中v1和v2路上权值最大的边
//则替换代价cost = 最小生成树权值和 - v1和v2间权值最大边的权值 + e权值
//由此可以找出最小cost即为次小生成树的权值和
//
//实际应用时，用动态规划和bfs的方法构造一个max_edge表
//max_edge[i][j]指代在最小生成树上，从节点i到节点j经过的路径上权值最大的边的权值
//按照bfs遍历生成树上的边时，有状态转移方程：
//max_edge[i][j] = max(max_edge[i][j-1], edge[j-1][j])
//edge[j-1][j]指代从j-1节点向相邻节点j扩展时的那条邻边的权值

#include "general_head.h"
#include "graph.h"
//kruskal.cpp
extern void kruskal(edge_list& e);
int tree_weight(edge_list e);
void bfs_visit(edge_list e, int **max_edge, int n, int beg);

int second_minimum_spanning_tree(edge_list e, int n)
{//边集e有e_l.size()条边，下标从0到e_l.size()-1，节点数量n
 //返回次小生成树中边的权值之和
	kruskal(e);
	int weight = tree_weight(e);
	//max_edge[i][j]指代从节点i到节点j的路上，权值最大的边的权值
	//从i到j的路是最小生成树的路径
	int **max_edge = new int*[MAX];
	for(int i = 0; i < MAX; ++ i){
		max_edge[i] = new int[MAX];
		memset(max_edge[i], 0, MAX * sizeof(int));
	}
	//应用动态规划和bfs求出图中的所有点之间，在最小生成树的路径上的权值最大的边
	for(int i = 0; i < n; ++ i)
		bfs_visit(e, max_edge, n, i);
	//min_weight为次小生成树的权值和
	int min_weight(INF);
	for(int i = 0; i < (int)e.e_l.size(); ++ i)
		if(!e.e_l[i].e_join)
			//若该边不属于生成树
			//生成树中添加e中的边i，减去边i的两端点之间权值最大的边的权值
			//枚举所有边即可得到次小生成树的权值和
			min_weight = min(min_weight,
					weight + (int)e.e_l[i].e_value -
					max_edge[e.e_l[i].e_beg][e.e_l[i].e_end]);
	return(min_weight);
}
int tree_weight(edge_list e)
{//求出边集e中加入生成树的边的权值和
	int weight(0);
	for(int i = 0; i < (int)e.e_l.size(); ++ i)
		if(e.e_l[i].e_join)
			weight += e.e_l[i].e_value;
	return(weight);
}
void bfs_visit(edge_list e, int **max_edge, int n, int beg)
{//bfs方法从beg节点开始在最小生成树上进行遍历并操作max_edge表
	//visit_node[i]标志节点i被遍历过
	//visit_edge[i]标志边i被遍历过
	int visit_node[MAX], visit_edge[MAX];
	memset(visit_node, 0, MAX * sizeof(int));
	memset(visit_edge, 0, MAX * sizeof(int));
	//q队列存储节点下标号
	queue<int> q;
	q.push(beg);
	visit_node[beg] = 1;
	//从beg节点开始进行bfs遍历
	while(!q.empty()){
		int p = q.front(); q.pop();
		//找出p的未被遍历过的在生成树中的邻边
		for(int i = 0; i < (int)e.e_l.size(); ++ i){
			if(e.e_l[i].e_join && !visit_edge[i] &&
					(e.e_l[i].e_beg == p || e.e_l[i].e_end == p)){
				//考虑当前p的邻边
				//对于边e[i]，p可能是其起点e_beg，也可能是终点e_end
				if(e.e_l[i].e_beg == p){
					//若p是边e[i]的起点
					if(max_edge[beg][e.e_l[i].e_end] <
							e.e_l[i].e_value){
						max_edge[beg][e.e_l[i].e_end] = e.e_l[i].e_value;
						max_edge[e.e_l[i].e_end][beg] = e.e_l[i].e_value;
					}
					//继续从该边的终点e_end搜索
					q.push(e.e_l[i].e_end);
					visit_node[e.e_l[i].e_end] = 1;
				}
				if(e.e_l[i].e_end == p){
					//若p是边e[i]的终点
					if(max_edge[beg][e.e_l[i].e_beg] <
							e.e_l[i].e_value){
						max_edge[beg][e.e_l[i].e_beg] = e.e_l[i].e_value;
						max_edge[e.e_l[i].e_beg][beg] = e.e_l[i].e_value;
					}
					q.push(e.e_l[i].e_beg);
					visit_node[e.e_l[i].e_beg] = 1;
				}
				//标记边i，在一次bfs中只遍历生成树中的每条边一次
				visit_edge[i] = 1;
			}
		}
	}
}
