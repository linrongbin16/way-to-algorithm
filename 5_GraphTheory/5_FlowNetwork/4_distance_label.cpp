//距离标号算法
//distance_label.cpp

//距离标号算法属于增广路径类算法，也称SAP算法，Improved-SAP(ISAP)算法
//用该算法求解最大流问题

//1)具体实现
//设置距离标号d
//重复步骤 1：
//借助距离标号d，从源点搜索一条增广路径
//使用距离标号搜索增广路径的操作是重复步骤 2：
//对节点u(从源点开始)查找其任意一条容许边(设该容许边是从节点u到节点v的)
//步骤2的情况1：若节点u存在一条容许边
//将该容许边保留为当前弧
//当然初始时源点必定存在至少一条容许边，因为源点至少要向它的一个邻节点发出流
//然后把节点v作为下一次重复的节点，继续重复步骤 2
//步骤2的情况2：若节点u没有容许边
//这时检查 u 的所有向外发出(出弧边)的有残余容量(运输能力)的边
//在这些能够为节点u运输的边中挑选邻节点(边的另一个端点)的 d 值最小的那个
//将u的 d 值设置为这个最小的 d 值加 1
//“退回”u的父节点(步骤2中u的上一个节点)，重新对它的父节点进行步骤2
//重复步骤2直到找到汇点，这时我们就找到了一条增广路径
//然后使用这条增广路径上的残留容量，向最大流中累加这个残留容量
//同时也要记得处理其副作用“添加反向边”
//直到无法继续找出增广路径，该算法结束
//
//通过距离标号d来判断是否能继续找出增广路径
//判断源点beg的 d 值，当 d[beg] 小于流网络中节点数量时
//仍然可以找出一条增广路径
//而当 d[beg] 大于等于节点数量时该算法结束
//距离标号d值指代节点的拓扑距离
//源点d值最大也只可能是节点数量减 1，即所有节点排成一单链表的情况
//而当源点到汇点的拓扑距离大于等于节点数量时，可以认为该拓扑中存在断层
//无法继续找到增广路径了
//还有一个优化是间隙优化，见本文后半部分
//
//2)核心技术
//重标记操作：
//在上述算法过程中的步骤2中，情况2的若节点u没有容许边
//对它进行的更改d值这个操作即重标记操作(详见一般性压入与重标记算法)
//当前弧优化：
//当节点每次新找到一个容许边，就把它作为当前弧(当前的边)
//当节点u没有容许边，对其进行重标记操作之后，并不是立即重新处理u的更新的容许边
//而是退回u的父节点(通过标号技术找回路径上u节点的上一个节点)
//u的父节点的那条容许边是当前弧
//因为节点u是没有找到容许边的，这时当前弧还是u的父节点的那条容许边
//然后处理u的父节点的容许边，重新到达节点u
//间隙优化，也称gap heuristic优化：
//对节点u进行重标记操作时，设节点u的原d值为x，重标记之后变为y
//实践中多数情况下 y 比 x 大 1
//这时d值为 x 的节点的数量减 1，而d值为 y 的节点的数量加 1
//若出现这样的情况即d值为 x 的节点数量变为 0
//则即使还有d值为 x-1 的节点，也无法再满足容许边的条件 d[i] = d[j] + 1
//其中i和j为两节点，现在只有 x+1 的d值和 x-1 的d值，中间没有 x 的d值了
//称之为断层现象
//从本质上来说断层是流网络的拓扑顺序中出现了不连通的情况
//存在到汇点的拓扑距离为 x+1 的节点，存在到汇点拓扑距离为 x-1 的节点
//而不存在一个到汇点拓扑距离为 x 的节点
//可以判断再也没有一条从源点到汇点的增广路径，算法直接结束
//
//该算法和本节第7篇的距离标号算法的邻接表优化，这两篇算法
//使用了Peking University Judge Online for ACM/ICPC中的1087 A Plug for UNIX题目
//作为测试，实际测试中发现虽然代码的接口提供了最大流起点beg，终点end节点号的参数
//但实际上我将起点设置为一个其他的数字时，在该题目中的测试结果是Wrong Answer
//比如说最大流中起点号为10，终点号为11，其他中间节点号为从0到9，节点总数为12
//则在该题目的测试中会出错，而若起点为0，终点为11，其他节点从1到10则正确
//因此读者在编码时也应该注意保证起点和终点分别是节点号的0和最大值
//这个规则适用于本节的所有算法
//
//而且在1087 A Plug for UNIX这个题目中流网络中的所有节点也是自然按照拓扑顺序出现的
//每个节点的节点号按照拓扑顺序增加，我没有测试过乱序情况下该算法的表现
//为了形成对比我也上传了POJ中1087 A Plug for UNIX题目的两个版本的算法
//一个使用邻接矩阵，另一个使用邻接表
//
//本文引用了“最大流ISAP(距离标号最短增广路算法)模板”，作者“北海小龙”
//“距离标号最短增广路算法模板”，作者“冰糖葫芦”

#include "general_head.h"
#include "graph.h"
void construct_d(graph_matrix residue,
		int beg, int end, int *d, int *d_num);
int find_allow_edge(int u, graph_matrix residue, int *d);
int relabel(int u, graph_matrix residue, int *d);

int distance_label(graph_matrix residue, int beg, int end)
{
	//d[i]指代节点i到汇点的距离标号
	//d_num[i]指代距离标号为i的节点数量，用于间隙优化，也称gap heuristic优化
	//d和d_num是实现距离标号技术的核心体现，注意d_num代表的意义
	//path[i]指代增广路径上节点i的父节点下标号，用于记录增广路径
	int d[MAX], d_num[MAX], path[MAX];
	memset(path, -1, MAX * sizeof(int));
	//将各节点的d值初始化为流网络中各节点的拓扑距离
	construct_d(residue, beg, end, d, d_num);
	int max_flow(0), u(beg);
	//算法结束条件是源点beg的距离标号d值小于节点数量g_cnt
	while(d[beg] < residue.g_cnt){
		if(u == end){
			//当走到汇点end，可以使用这条增广路径上的残留网络volum
			int volum = INF;
			//在该增广路径上找出剩余容量volum
			for(u = end; u != beg; u = path[u])
				volum = min(volum, residue.g_m[path[u]][u]);
			//更新残留网络
			for(u = end; u != beg; u = path[u]){
				residue.g_m[path[u]][u] -= volum;
				residue.g_m[u][path[u]] += volum;
			}
			//经过此遍历u又倒着回到beg
			//下一轮循环时u仍从源点出发，搜索下一条增广路径
			max_flow += volum;
		}
		//从残留网络residue中找出节点u的容许边
		//返回节点u的这条容许边的邻节点p
		int p = find_allow_edge(u, residue, d);
		if(p >= 0){
			//若存在这样的邻节点p，从0到g_cnt-1
			//在path中记录节点p的父节点为u
			path[p] = u;
			//从节点u走到当前节点p
			u = p;
		}
		else{
			//若不存在这样的容许边则find_allow_edge返回-1
			//对u节点尝试重标记操作，在重标记之前先进行间隙优化
			-- d_num[d[u]];
			if(d_num[d[u]] == 0)
				//距离标号算法存在退化现象
				//对节点u进行重标记之后，与u距离标号相等的节点数量为0
				//即再没有距离标号为d[u]这样的节点，判定算法直接结束
				//这是著名的gap heuristic优化，也成为间隙优化，它的思路是：
				//如果一次重标号操作后，出现断层，即节点d值没有d[v]=d[u]+1的情况
				//可以证明残留网络中再无增广路径，判定算法结束
				return(max_flow);

			//对u节点进行重标号，返回重标号后u节点的d值
			//本文中间隙优化与重标记操作的顺序与
			//引用的文档“最大流ISAP(距离标号最短增广路算法)模”中的顺序不同
			//因为在实际测试中我发现这里的顺序按照
			//另一篇文档“网络最大流算法算法拓展(最大流算法拓展，百度文库)”中的更好
			//调整顺序之后重标记中不会出现min_dist==INF的意外情况
			d[u] = relabel(u, residue, d);
			//距离标号为d[u]的节点数量加1
			++ d_num[d[u]];
			if(u != beg)
				//将节点u退回其父节点重走
				//这是当前弧优化
				//为了使每次寻找增广路径的时间均摊为O(V)，对每个节点保留当前弧
				//初始时当前弧是第一条容许边，每次查找容许边都从当前弧开始查找
				//找到一条容许边后则把该容许边设置为当前弧
				//当未找到容许边时退回上一节点
				u = path[u];
		}
	}
	return(max_flow);
}
void construct_d(graph_matrix residue,
		int beg, int end, int *d, int *d_num)
{//通过bfs将距离函数d初始化为拓扑顺序
	for(int i = 0; i < MAX; ++ i)
		d[i] = INF;
	//也可以用memset(d, 1, MAX * sizeof(int));
	//memset中的1意思是将d中成员初始化为最大正整数，而不是真的1
	memset(d_num, 0, MAX * sizeof(int));
	queue<int> q;
	q.push(end);
	d[end] = 0;		//d[end]指代汇点的距离标号为0
	d_num[0] = 1;	//d_num[0]指代距离标号为0的节点(即汇点end)数量为1
	//从汇点开始沿着边的反方向bfs直到源点，bfs的访问顺序即为节点的拓扑顺序
	while(!q.empty()){
		int p = q.front(); q.pop();
		//找出节点p的入弧边，即以p为入度的边
		for(int i = 0; i < residue.g_cnt; ++ i)
			if(d[i] >= residue.g_cnt && residue.g_m[i][p] > 0){
				d[i] = d[p] + 1;
				q.push(i);
				//与节点i的距离标号相等的节点数加1
				++ d_num[d[i]];
			}
	}
}
int find_allow_edge(int u, graph_matrix residue, int *d)
{//找出节点u的容许边
 //该边满足条件：是u的出弧边，且d[u]==d[v]+1，其中v为该出弧边的另一端点
	for(int i = 0; i < (int)residue.g_cnt; ++ i)
		if(residue.g_m[u][i] > 0 && d[u] == d[i] + 1)
			return(i);
	return(-1);
}
int relabel(int u, graph_matrix residue, int *d)
{//对u节点进行重标号操作，返回重标号之后u节点的d值
	int min_dist(INF);
	for(int i = 0; i < residue.g_cnt; ++ i)
		//设置min_dist为u节点出弧(向外)边的邻节点中距离标号最低的d值加1
		if(residue.g_m[u][i] > 0)
			min_dist = min(min_dist, d[i] + 1);
	//若min_dist == INF则忽略min_dist==INF的重标记操作
	//这次重标记中节点u已经没有出弧边，即没有可以向外运输的管道了
	//if(min_dist == INF)
	//	return(residue.g_cnt);
	//调整重标记与间隙优化的顺序之后可以避免这里出现该情况
	//当然按照原文“最大流ISAP(距离标号最短增广路算法)模”中的顺序也可以
	//但本文的方法显然更简洁
	return(min_dist);
}
