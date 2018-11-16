#include "EulerCycle.h"
#include <cassert>
#include <cstring>
#include <vector>

static bool Exist(int g[MAX][MAX], int n) {
  for (int i = 0; i < n; i++) {
    int indegree = 0;
    int outdegree = 0;
    for (int j = 0; j < n; j++) {
      if (g[i][j] > 0) {
        indegree++;
      }
      if (g[j][i] > 0) {
        outdegree++;
      }
    }
    assert(indegree == outdegree);
    if (indegree % 2 == 1) {
      return false;
    }
  }
  return true;
}

static void Dfs(int g[MAX][MAX], int n, int beg, int *visit,
                std::vector<int> &path) {
  if (visit[beg]) {
    return;
  }
  path.push_back(beg);
  visit[beg] = 1;

  for (int i = 0; i < n; i++) {
    if (g[beg][i] && !visit[i]) {
      g[beg][i] = 0;
      g[i][beg] = 0;
      Dfs(g, n, i, visit, path);
    }
  }
}

std::pair<bool, std::vector<int>> EulerCycle(int g[MAX][MAX], int n) {
  if (!Exist(g, n)) {
    return std::make_pair(false, std::vector<int>());
  }

  std::vector<int> path;
  int visit[MAX];
  std::memset(visit, 0, MAX * sizeof(int));
  int gc[MAX][MAX];
  std::memcpy(gc, g, MAX * MAX * sizeof(int));

  Dfs(gc, n, 0, visit, path);
  return std::make_pair(true, path);
}

