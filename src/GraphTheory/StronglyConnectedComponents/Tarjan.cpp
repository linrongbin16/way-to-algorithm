#include "Tarjan.h"
#include "../Util.h"
#include <algorithm>
#include <cstring>
#include <deque>

void Dfs(int g[MAX][MAX], int n, int beg, int *visit, int *lowlink,
         std::deque<int> &stk) {
  visit[beg] = 1;
  stk.push_front(beg);

  for (int i = 0; i < n; i++) {
    if (!visit[i] && g[beg][i] > 0) {
      Dfs(g, n, i, visit, lowlink, stk);
      lowlink[beg] = std::min(lowlink[beg], lowlink[i]);
    }
  }
}

std::vector<std::vector<int>> Tarjan(int g[MAX][MAX], int n) {
  int visit[MAX];
  int lowlink[MAX];
  std::memset(visit, 0, MAX * sizeof(int));
  std::memset(lowlink, 0, MAX * sizeof(int));

  std::deque<int> stk;

  for (int i = 0; i < n; i++) {
    if (!visit[i]) {
      Dfs(g, n, i, visit, lowlink, stk);
    }
  }

  std::vector<int> tmp;
  std::vector<std::vector<int>> result;
  while (!stk.empty()) {
    int v = stk.front();
    stk.pop_front();

    tmp.push_back(v);
    if (lowlink[v] == v) {
      result.push_back(tmp);
      tmp.clear();
    }
  }

  return result;
}

