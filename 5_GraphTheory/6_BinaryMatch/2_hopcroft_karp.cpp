//Hopcroft-Karp算法
//hopcroft_karp

//用Hopcroft-Karp算法求给定二分图的最大匹配

//该算法比匈牙利算法的时间效率高
//该算法先使用bfs查找多条增广轨，然后使用dfs遍历增广轨，重复dfs直到找不到增广轨
//该算法的bfs只对二分图中节点进行分层，类似最大流中使用的距离标号
//然后用dfs对已分层的二分图进行遍历，寻找增广轨
//
//2)具体实现
//该算法的匹配标记必须使用两个数组xmatch和ymatch

#include "general_head.h"
#include "graph.h"
bool bfs_path(bipartite b, int *visited, int *xmatch, int *ymatch,
		int *xdist, int *ydist, int& dist);
int dfs_path(bipartite b, int *visited, int p, int *xmatch, int *ymatch,
		int *xdist, int *ydist, int dist);

int hopcroft_karp(bipartite b, int *xmatch, int *ymatch)
{
	//算法大体框架与匈牙利算法差不多
	memset(xmatch, -1, MAX * sizeof(int));
	memset(ymatch, -1, MAX * sizeof(int));
	int visited[MAX], max_match(0), dist;
	int xdist[MAX], ydist[MAX];
	//通过bfs找出二分图中的所有增广轨
	while(bfs_path(b, visited, xmatch, ymatch, xdist, ydist, dist)){
		memset(visited, 0, MAX * sizeof(int));
		for(int i = 0; i < b.b_xn; ++ i)
			//通过dfs使用增广轨得到新匹配
			if(xmatch[i] == -1 && dfs_path(b, visited, i, xmatch, ymatch,
						xdist, ydist, dist))
				++ max_match;
	}
	return(max_match);
}
bool bfs_path(bipartite b, int *visited, int *xmatch, int *ymatch,
		int *xdist, int *ydist, int& dist)
{
	dist = INF;
	queue<int> q;
	memset(xdist, -1, MAX * sizeof(int));
	memset(ydist, -1, MAX * sizeof(int));
	for(int i = 0; i < b.b_xn; ++ i)
		if(xmatch[i] == -1){
			q.push(i);
			xdist[i] =	0;
		}
	while(!q.empty()){
		int p = q.front(); q.pop();
		if(xdist[p] > dist)
			break;

		for(int i = 0; i < b.b_yn; ++ i)
			if(b.b_g[p][i] && ydist[i] == -1){
				ydist[i] = xdist[p] + 1;
				if(ymatch[i] == -1)
					dist = ydist[i];
				else{
					xdist[ymatch[i]] = ydist[i] + 1;
					q.push(ymatch[i]);
				}
			}
	}
	return(dist != INF);
}
int dfs_path(bipartite b, int *visited, int p, int *xmatch, int *ymatch,
		int *xdist, int *ydist, int dist)
{
	for(int i = 0; i < b.b_yn; ++ i)
		if(!visited[i] && b.b_g[p][i] && ydist[i] == xdist[p] + 1){
			visited[i] = 1;
			//bfs用于减少dfs中多余的重复遍历，跳过dist
			if(ymatch[i] != -1 && ydist[i] == dist)
				continue;

			if(ymatch[i] == -1 ||
					dfs_path(b, visited, ymatch[i], xmatch, ymatch,
						xdist, ydist, dist)){
				xmatch[p] = i;
				ymatch[i] = p;
				return(1);
			}
		}
	return(0);
}
