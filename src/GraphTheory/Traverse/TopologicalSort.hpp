#ifndef TOPOLOGICAL_SORT_HPP
#define TOPOLOGICAL_SORT_HPP 1

#include <deque>
using namespace std;
#ifndef MAX
#define MAX 128
#endif
#include "DepthFirstSearch.hpp"

struct TopologicalNode {
    int index;
    int depth;
    TopologicalNode() : index(0), depth(0) {}
};

bool TopologicalComp(const TopologicalNode & a, const TopologicalNode & b)
{
    return a.depth > b.depth;
}



/**
 * @brief TopologicalSort 拓扑排序
 *
 * @param g[MAX][MAX]   图G
 * @param n             图中节点数量 下标范围为[0, n-1]
 * @return sequence     排序后的节点下标
*/
auto TopologicalSort(int g[MAX][MAX], int n) -> vector<int>
{
    vector<TopologicalNode> sequence;
	int visited[MAX];
    int time = 0;
	memset(visited, 0, sizeof(visited));
	for(int i = 0; i < n; ++ i)
        sequence[i].index = i;
	for(int i = 0; i < n; ++ i)
		if(not visited[i])
			dfs_visit(g, n, i, visited, time);
	for(int i = 0; i < (int)g.g_l.size(); ++ i)
		sequence[i].depth = g.g_l[i][0].g_value;
	sort(sequence.begin(), sequence.end(), TopologicalComp);

    vector<int> result(sequence.size());
    for (int i = 0; i < result.size(); i++)
        result[i] = sequence[i].index;
    return result;
}
