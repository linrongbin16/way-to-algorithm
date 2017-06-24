#ifndef TOPOLOGICAL_SORT_HPP
#define TOPOLOGICAL_SORT_HPP 1

#include <algorithm>
#include <deque>
#include <vector>
#include <cstring>
#include "DepthFirstSearch.hpp"
using namespace std;
#ifndef MAX
#define MAX 128
#endif


struct TopoNode {
    int index;  // 节点下标
    int distance;  // 节点的DFS长度
    TopoNode() : index(0), distance(0) {}
    TopoNode(int i, int d) : index(i), distance(d) {}
};

bool TopoComp(const TopoNode & a, const TopoNode & b)
{
    return a.distance > b.distance;
}

/**
 * @brief TopologicalSort 拓扑排序
 *
 * @param g[MAX][MAX]   图G
 * @param n             图中节点数量 下标范围为[0, n-1]
 * @return sequence     拓扑排序结果
*/
auto TopologicalSort(int g[MAX][MAX], int n) -> vector<int>
{
    vector<TopoNode> sequence(n);
    int visited[MAX];
    for (int i = 0; i < n; ++ i)
        sequence[i].index = i;

    for (int i = 0; i < n; i++) {
        int dist = 0;
        // 重置visited 让任意节点i可以尽可能深的进行DFS
        memset(visited, 0, sizeof(visited));
        vector<int> seq;
        DFS(g, n, i, visited, seq);
        sequence[i].distance = seq.size();
    }
    sort(sequence.begin(), sequence.end(), TopoComp);

    vector<int> topo_sequence;
    for (int i = 0; i < sequence.size(); i++)
        topo_sequence.push_back(sequence[i].index);
    return topo_sequence;
}


#endif
