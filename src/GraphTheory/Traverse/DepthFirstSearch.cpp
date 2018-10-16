#include "DepthFirstSearch.h"
#include <cstring>
#include <vector>

static void Dfs(int G[MAX][MAX], int n, int beg, int *visited,
                std::vector<int> &result) {
  visited[beg] = 1;
  result.push_back(beg);
  for (int i = 0; i < n; i++)
    if (i != beg && G[beg][i] && !visited[i])
      Dfs(G, n, i, visited, result);
}

std::vector<int> DepthFirstSearch(int G[MAX][MAX], int n) {
  int visited[MAX];
  std::vector<int> result;

  std::memset(visited, 0, sizeof(visited));

  // all node [0,n-1]
  for (int i = 0; i < n; i++)
    if (!visited[i]) {
      Dfs(G, n, i, visited, result);
    }

  return result;
}

