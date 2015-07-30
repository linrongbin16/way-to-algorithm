//Prim算法
//prim

//用Prim算法求图中从某点beg扩展而成的最小生成树

//1)基础概念
//割: 
//设图G中的一部分点的集合为S 其他点的集合为T 其中T=g-S
//存在这样一些边e 它的一端点属于S 另一端点属于T 这些边就组成了割
//即图G的两个连通分量S和T之间的那些边 上述的边e即为割边
//在Prim算法中 将生成树中的节点作为一个集合 其他节点作为一个集合
//则两集合之间的割边是生成树中节点的所有非生成树中的邻节点的邻边
//
//2)具体实现
//该算法与Kruskal算法都是贪心算法的应用
//生成树初始为单独的一个起点beg 重复以下步骤进行扩展该生成树:
//选择生成树中节点和剩余节点之间的所有割边中权值最小的边加入生成树中
//重复以上步骤 每次加入生成树的都是生成树可以向外扩展的节点中路径距离最短的邻节点
//很多文档都会提到Prim算法和最短路径中的Dijkstra算法很像
//事实上两者确实使用了完全相同的思路
//两者的区别在于Prim算法用distance数组标志一节点是否属于生成树
//而Dijkstra用distance标记起点到各节点的最短路径距离


#include "general_head.h"
#include "graph.h"
int min_distance(int *visited, edge_list e, int beg, int end);

void prim(edge_list& e, int n, int beg)
{//边集e有e_l.size()条边 下标从0到e_l.size()-1
 //节点数量为n 生成树起点为beg 直接操作edge中成员e_join来标记该边是否加入生成树
	//visited[i]为1时表示节点i已经加入生成树
	int visited[MAX];
	memset(visited, 0, sizeof(visited));
	visited[beg] = 1;
	for (int i = 0; i < n - 1; ++ i) {
		//对于n个节点的图 其最小生成树具有n-1条边 故循环n-1次
		//使用distmal_distance函数完成优先队列这个结构的功能
		int index = min_distance(visited, e, 0, (int)e.e_l.size());
		//每次选择最近的一边加入答案集中 进行标记
		e.e_l[index].e_join = 1;
		//边k的末节点加入生成树
		visited[e.e_l[index].e_end] = 1;
	}
}
int min_distance(int *visited, edge_list e, int beg, int end)
{//[beg, end)是左闭右开区间 返回最小权值的边的下标号index
	int dist(INF), index(-1);
	for(int i = beg; i < end; ++ i)
		//遍历visited中每一个生成树中的节点
		if(visited[i])
			for(int j = 0; j < (int)e.e_l.size(); ++ j)
				//遍历边集
				if(e.e_l[j].e_beg == i && !visited[e.e_l[j].e_end])
					//所有从生成树节点向外发射的边中
					//即所有边的起始点beg在visited中
					//而终止点end不在visited中
					//选择最小距离的那条边作为新的生成树节点
					if(dist > e.e_l[j].e_value)
						dist = e.e_l[j].e_value, index = j;
	return(index);
}
