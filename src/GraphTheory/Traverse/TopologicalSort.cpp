#include "TopologicalSort.h"
#include <algorithm>
#include <cstring>
#include <deque>
#include <vector>

struct ToNode {
  int index;
  int dist;
  ToNode() : index(0), dist(0) {}
  ToNode(int i, int d) : index(i), dist(d) {}
};

static bool Compare(const ToNode &a, const ToNode &b) {
  return a.dist > b.dist;
}

static void Dfs(int G[MAX][MAX], int n, int beg, int *visited,
                std::vector<int> &result) {
  visited[beg] = 1;
  result.push_back(beg);
  for (int i = 0; i < n; i++)
    if (i != beg && G[beg][i] && !visited[i])
      Dfs(G, n, i, visited, result);
}

std::vector<int> TopologicalSort(int g[MAX][MAX], int n) {
  std::vector<ToNode> seq(n);
  int visited[MAX];
  for (int i = 0; i < n; i++)
    seq[i].index = i;

  for (int i = 0; i < n; i++) {
    int dist = 0;

    // 重置visited
    // 对节点i进行DFS搜搜

    std::memset(visited, 0, sizeof(visited));
    std::vector<int> counter;
    Dfs(g, n, i, visited, counter);
    seq[i].dist = counter.size();
  }
  std::sort(seq.begin(), seq.end(), Compare);

  std::vector<int> topo;
  for (int i = 0; i < seq.size(); i++)
    topo.push_back(seq[i].index);
  return topo;
}

