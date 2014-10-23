//重标记与前移算法
//relabel_to_front.cpp

//重标记与前移算法属于预推进流类算法，用该算法求解最大流问题

//1)具体实现，本文忠实的实现了算法导论中关于重标记与前移算法的论述
//该算法也使用到了容许边，间隙优化这样的技术
//它与距离标号算法最大的不同就是不去寻找一条增广路径
//而是从源点开始将节点的余流尽最大的可能压入其容许边的邻节点
//最终到达汇点的流即为流网络的最大流
//该算法更像是将增广路径分成一条一条的边，分散的进行压入
//
//该算法使用了邻接表的数据结构
//邻接表数据结构适合稀疏图而邻接矩阵数据结构适合稠密图
//考虑有向图G=<V,E>
//当G为一个完全图则|E|=|V|*|V-1|，E的数量接近O(V^2)是平方级数量(最稠密图)
//当G为一颗生成树则|E|=|V-1|，E的数量接近O(V)是常数级(最稀疏图)
//可见节点数相同的图中边的数量差距可以相当大
//在节点数一定的流网络中，邻接矩阵数据结构的空间复杂度恒为O(V^2)
//而邻接表数据结构的空间复杂度为O(E)，稀疏图时空间复杂度O(V)比矩阵小很多
//
//顶点表：
//邻接表上头节点的一列称为顶点表
//顶点表是由所有节点组成的，算法导论中说除过源点汇点，但我实现时发觉还是需要这两点的
//顶点表的顺序初始为这些节点的拓扑顺序
//当然拓扑顺序会随着压入操作的副作用(添加反向边)而改变
//相邻表：
//节点u的相邻表是节点u的所有出弧边组成的单链
//其实就是邻接表中一个头节点之后的部分
//
//初始时顶点表按照流网络中各节点的拓扑顺序入队
//该算法重复进行排除操作，直到顶点表为空结束
//排除操作(Discharge)：
//每次从顶点表中取头节点u，对其进行排除操作(Discharge)
//该操作是对节点u进行最大可能的压入操作，直到它没有容许边或没有余流为止
//然后再检查节点u是否可以进行重标记操作
//若可以则对它进行重标记之后再将它插回顶点表的头节点处(下一次还排除该节点)
//若该节点无法进行重标记操作，则将该点从顶点表中删除，即拓扑序列中不再考虑该节点
//重复以上操作直到顶点表为空，记录汇点中压入的流即为最大流
//
//2)谈谈重标记前移算法与距离标号算法的联系与区别
//我们简称重标记与前移算法为 RF，距离标号算法为 DL
//数据结构：
//RF 通过邻接表数据结构实现，DL 通过邻接矩阵数据结构实现
//压入与重标记操作：
//它们都使用压入与重标记操作，它们都将距离标号d(拓扑顺序)作为优先级来进行算法的每一步
//优先级：
//虽然无法证明，但是相信读者也能看出
//距离标号d与以拓扑顺序为优先级的顶点表，这两者之间并没有本质的区别
//优化：
//DL 中一个重要的部分是间隙优化和当前弧优化
//而 RF 中使用了一个顶点表，当节点无法继续压入就删除该节点
//这二者没有什么明显的联系
//主过程：
//两算法的主过程是它们最大的不同之处
//DL 的每次循环都会找出一条增广路径，而RF 的每次循环是对头节点进行最大限度的排除
//DL 是以头节点的d值作为算法结束的判断，再加上间隙优化中对d值的判断
//RF 是按照队列的顺序进行顺序排除
//初始时 RF 的节点是按拓扑顺序入队的，显然也是从头节点开始d值单调递减的(可能相等)
//而每次对头节点进行排除操作，若发生重标记立即加回队列头部
//也就是说它的d值还是最高的
//可以看出其本质也有着共同之处
//核心技术的使用：
//DL 和 RF 虽然都使用了拓扑排序和重标记操作这样的技术，很多操作上都有相似之处
//但在二者最为核心的技术上却并不一样
//DL 的主循环是寻找一条增广路径，而 RF 的主循环是对每个节点进行排除操作
//其中排除操作的核心技术是前置流技术，即将每个节点看作可以存储无穷大的流
//这两个核心技术体现了DL 和 RF 的本质
//而拓扑排序和重标记可以看作两类算法在追求低时间复杂度过程中的重合
//
//最后的结论：
//RF 和 DL 是最大流算法中两类算法的代表
//都使用了拓扑排序和重标记操作，但在本质上仍有区别
//RF 占用内存低而编程难度较大，DL 占用内存高而编程难度较小
//
//我忠实的实现了算法导论中关于重标记算法的伪语言，网络上没有类似的实现方式
//
//本文引用了“最大流算法拓展(网络最大流算法算法拓展)”，作者“无”

#include "general_head.h"
#include "graph.h"
//topological_sort.cpp
extern void topological_sort2(graph_list g, deque<graph_node>& topo);
int discharge(graph_list& residue, int beg, int end,
		int p, int& max_flow, int *excess, int *d);
void construct_d(graph_list residue, int beg, int end, int *d);

int relabel_to_front(graph_list residue, int beg, int end)
{//流网络residue中有g_l.size()个节点，下标从0到g_l.size()-1
 //其中第i个队列的头节点g_l[i][0]是邻接表中的头节点i自身
 //剩下从1到g_l[i].size()-1是头节点i的所有邻节点组成的单链
 //g_l[i][j].g_value指代节点i到邻节点j的边的权值，即该边的残余容量
 //没有该边或其残留容量为0时其权值为0
	//初始时按拓扑顺序将所有节点入队列
	deque<graph_node> topo;
	topological_sort2(residue, topo);
	//excess[i]指代节点i拥有的余流，注意后面对它的操作
	//这是前置流的核心技术，也是预留与推进类算法的核心技术
	int max_flow(0), excess[MAX], d[MAX];
	memset(excess, 0, MAX * sizeof(int));
	memset(d, 0, MAX * sizeof(int));
	//初始时源点余流是无穷大，其他节点为0
	excess[beg] = INF;
	//通过bfs将距离标号d初始化为拓扑顺序
	construct_d(residue, beg, end, d);
	while(!topo.empty()){
		//顶点表为空时该算法结束
		graph_node p = topo.front();
		topo.pop_front();
		//进行排除操作时同时也对max_flow变量进行累加
		if(discharge(residue, beg, end, p.g_idx, max_flow, excess, d))
			topo.push_front(p);
	}
	return(max_flow);
}
int discharge(graph_list& residue, int beg, int end,
		int p, int& max_flow, int *excess, int *d)
{//对节点p进行最大限度的压入操作之后，尝试重标记操作
	for(int i = 1; i < (int)residue.g_l[p].size(); ++ i){
		//遍历节点p的邻节点，对其所有容许边进行最大程度的压入
		//u是p节点的一条容许边上对应邻节点的下标号
		int u = residue.g_l[p][i].g_idx;
		if(excess[p] > 0 &&
			residue.g_l[p][i].g_value > 0 &&
			d[p] == d[u] + 1){
			//从p到u是p的一条容许边，且p点有余流
			//这次压入的流是上二者中较小者
			int tmp = min(excess[p], residue.g_l[p][i].g_value);
			//原p点减少该流
			excess[p] -= tmp;
			//u节点增加该流
			excess[u] += tmp;
			//该容许边容量减少该流
			residue.g_l[p][i].g_value -= tmp;
			//对应的反向边(从u到p的边)增加该流
			//若u已经有邻节点p，即已存在从u到p的反向边，给该邻节点p的权值加tmp
			//若u还没有邻节点p，则新增一条权值为tmp的反向边
			//edge_exist指代邻接表中是否存在该反向边
			int edge_exist = 0;
			for(int j = 1; j < (int)residue.g_l[u].size(); ++ j)
				//遍历u节点的所有边
				if(residue.g_l[u][j].g_idx == p){
					//找到从u到p这条边并增加该流
					residue.g_l[u][j].g_value += tmp;
					edge_exist = 1;
					break;
				}
			//若u还没有邻节点p，给u增加邻节点p()，权值为tmp
			if(!edge_exist){
				graph_node v;
				v.g_idx = p; v.g_value = tmp;
				residue.g_l[u].push_back(v);
			}
			//若邻节点u是汇点，则累加到最大流中
			if(u == end)
				max_flow += tmp;
		}
	}
	if(excess[p] > 0){
		//判断是否需要重标记，如果p点仍有余流
		int d_tmp(INF);
		for(int i = 1; i < (int)residue.g_l[p].size(); ++ i)
			if(residue.g_l[p][i].g_value > 0)
				//p的出弧边上仍有残留容量，即可以重标记
				d_tmp = min(d_tmp, d[residue.g_l[p][i].g_idx] + 1);
		if(d_tmp < INF){
			d[p] = d_tmp;
			return(1);
		}
	}
	return(0);
}
void construct_d(graph_list residue, int beg, int end, int *d)
{//通过bfs将距离函数d初始化为拓扑顺序
	for(int i = 0; i < MAX; ++ i)
		d[i] = INF;
	queue<int> q;
	q.push(end);
	d[end] = 0;		//d[end]指代汇点的距离标号为0
	while(!q.empty()){
		int p = q.front(); q.pop();
		//找出节点p的入弧边，即以p为入度的边
		for(int i = 0; i < (int)residue.g_l.size(); ++ i)
			for(int j = 1; j < (int)residue.g_l[i].size(); ++ j)
				if(d[i] >= (int)residue.g_l.size() &&
					residue.g_l[i][j].g_idx == p &&
					residue.g_l[i][j].g_value > 0){
					d[i] = d[p] + 1;
					q.push(i);
			}
	}
}
