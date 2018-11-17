#include "TopologicalSort.h"
#include "../Util.h"
#include <algorithm>
#include <cstring>
#include <deque>
#include <vector>

static bool CompareVertex(const Vertex &a, const Vertex &b) {
  return a.value > b.value;
}

static void Dfs(int g[MAX][MAX], int n, int beg, int *visited,
                std::vector<int> &path) {
  visited[beg] = 1;
  path.push_back(beg);
  for (int i = 0; i < n; i++)
    if (i != beg && g[beg][i] && !visited[i])
      Dfs(g, n, i, visited, path);
}

std::vector<int> TopologicalSort(int g[MAX][MAX], int n) {
  std::vector<Vertex> ts(n);
  int visited[MAX];
  for (int i = 0; i < n; i++)
    ts[i].index = i;

  for (int i = 0; i < n; i++) {
    // 重置visited
    // 对节点i进行DFS搜搜

    std::memset(visited, 0, sizeof(visited));
    std::vector<int> counter;
    Dfs(g, n, i, visited, counter);
    ts[i].value = counter.size();
  }
  std::sort(ts.begin(), ts.end(), CompareVertex);

  std::vector<int> result;
  for (int i = 0; i < ts.size(); i++)
    result.push_back(ts[i].index);
  return result;
}

