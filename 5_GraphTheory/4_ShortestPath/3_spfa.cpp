//最短路径更快算法
//spfa

//求给定图中从起点beg到各节点的最短路径长度

//最短路径更快算法(Shortest Path Faster Algorithm)是Bellman-Ford算法的队列优化版本
//它比Bellman-Ford拥有更好的性能
//当图中存在负权值边(无法使用Dijkstra) 但不存在负权值回路(存在最短路径)时使用该算法
//但spfa算法时间效率没有Dijkstra稳定 后者更为流行
//
//使用distance数组记录起点到各节点的最短距离 初始时除起点自身值为0其他均为INF
//维护一个节点队列 初始时将起点beg加入队列 重复以下步骤: 
//从队列取出头结点i 枚举i节点的所有出弧边 假设有一条从节点i指向节点j的出弧边e
//若 distance[i]+value(e)<distance[j] 则对节点j进行松弛操作
//若节点j进行了松弛操作且j不存在于队列中 则将j加入队尾
//重复以上步骤直到队列为空 算法结束
//若某个节点入队次数超过图的节点数量则该图存在负权环 不存在最短路径
//Small Lable First优化: 
//当要加入队尾的节点j的distance值比此时队头节点i-1的distance值小
//distance[j] < distance[i-1] 则将j节点加入队头 否则仍然加入队尾
//Large Lable Last优化: 
//将要取出(尚未取出)队列头节点i 队列中所有节点distance值平均值为average
//若distace[i] > average则不扩展节点i的所有出发边的邻节点而是将节点i直接插入队尾
//继续考虑下一个节点 只对那些distance值<=average的节点进行松弛操作
//本文未实现Large Lable Last优化
//
//本文引用了“SPFA算法(NOCOW)” 无作者

#include "general_head.h"
#include "graph.h"

bool spfa(graph_matrix g, int beg, int *distance, int *path)
{//distance[i]指代起点beg到节点i的最短路径距离 path[i]指代节点i在最短路径上的父节点
 //图G有g_cnt个节点 下标从0到g_cnt-1 起点为beg
 //返回是否存在最短路径 若存在返回distance和path数组
	//除beg外所有节点distance值初始化为INF
	for(int i = 0; i < MAX; ++ i)
		distance[i] = INF;
	distance[beg] = 0;
	memset(path, -1, MAX * sizeof(int));
	//for(int i = 0; i < MAX; ++ i)
	//	path[i] = beg;
	//in_queue[i]指代节点i入队次数
	int in_queue[MAX];
	memset(in_queue, 0, MAX * sizeof(int));
	deque<int> q;
	q.push_back(beg);
	++ in_queue[beg];
	while(!q.empty()){
		int p = q.front(); q.pop_front();
		for(int i = 0; i < g.g_cnt; ++ i)
			if(p != i && distance[p] + g.g_m[p][i] < distance[i]){
				//松弛操作
				distance[i] = distance[p] + g.g_m[p][i];
				path[i] = p;
				deque<int>::iterator pos;
				if((pos = find(q.begin(),
							q.end(),
							i)) == q.end()){
					//若队列中不存在已经进行了松弛操作的节点i则将其加入队列
					//Small Lable First优化
					if(distance[i] < distance[q.front()])
						q.push_front(i);
					else
						q.push_back(i);
					++ in_queue[i];
					//若节点i入队次数超过图中节点数量则说明不存在最短路径
					if(in_queue[i] > g.g_cnt)
						return(false);
				}
			}
	}
	return(true);
}
