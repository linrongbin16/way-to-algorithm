//广度优先搜索图
//breadth_first_search_adjlist.cpp

//在给定的邻接表和给定的起点beg上广度优先搜索图

//使用队列从起点beg开始扩展邻节点

#include "general_head.h"
#include "graph.h"
//traverse_tree.cpp
extern void print_node(graph_node *p);

void breadth_first_search_adjlist(graph_list g, int beg)
{//图G有g_l.size()个节点，下标从0到g_l.size()-1
	//本文的技术可以参考第1章中的广搜
	queue<int> q;
	int visited[MAX];
	memset(visited, 0, MAX * sizeof(int));
	q.push(beg);
	visited[beg] = 1;
	while(!q.empty()){
		int p = q.front(); q.pop();
		print_node(&g.g_l[p][0]);
		for(int i = 1; i < (int)g.g_l[p].size(); ++ i)
			if(!visited[g.g_l[p][i].g_idx]){
				q.push(g.g_l[p][i].g_idx);
				visited[g.g_l[p][i].g_idx] = 1;
			}
	}
}
