#ifndef TOPOLOGICAL_SORT_HPP
#define TOPOLOGICAL_SORT_HPP 1

#include <deque>
#include <vector>
using namespace std;
#ifndef MAX
#define MAX 128
#endif
#include "DepthFirstSearch.hpp"

struct TopoNode {
    int index;
    int depth;
    TopoNode() : index(0), depth(0) {}
};

bool TopoComp(const TopoNode & a, const TopoNode & b)
{
    return a.depth > b.depth;
}

/**
 * @brief TopologicalSort 拓扑排序
 *
 * @param g[MAX][MAX]   图G
 * @param n             图中节点数量 下标范围为[0, n-1]
 * @return sequence     拓扑排序结果
*/
auto TopologicalSort(int g[MAX][MAX], int n) -> vector<TopoNode>
{
    vector<TopoNode> sequence;
    int visited[MAX];
    int time = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; ++ i)
        sequence[i].index = i;

    // dfs[i]所代表的节点 其到达DFS终点的距离为i
    vector<int> dfs = DepthFirstSearch(g, n);
    for (int i = 0; i < n; i++) {
        sequence[ dfs[n-i-1] ].depth = i;
    }
    sort(sequence.begin(), sequence.end(), TopoComp);
    return sequence;
}
