#include "Kosaraju.h"
#include <algorithm>
#include <cstring>
#include <vector>

static void Dfs(int g[MAX][MAX], int n, int beg, int *visit,
                std::vector<int> &q) {
  if (visit[beg]) {
    return;
  }

  for (int i = 0; i < n; i++) {
    if (g[beg][i] > 0 && !visit[i]) {
      visit[i] = 1;
      q.push_back(i);
      Dfs(g, n, i, visit, q);
    }
  }
}

std::vector<std::vector<int>> Kosaraju(int g[MAX][MAX], int n) {
  std::vector<std::vector<int>> result;
  std::vector<int> q;
  int visit[MAX];
  std::memset(visit, 0, MAX * sizeof(int));

  for (int i = 0; i < n; i++) {
    Dfs(g, n, i, visit, q);
  }

  int father[MAX];
  for (int i = 0; i < n; i++) {
    father[i] = i;
  }
  std::reverse(q.begin(), q.end());

  for (int i = 0; i < n; i++) {
    int v = q[i];
    std::vector<int> strong_component;
    std::memset(visit, 0, MAX * sizeof(int));
    Dfs(g, n, v, visit, strong_component);
    result.push_back(strong_component);
  }

  return result;
}

