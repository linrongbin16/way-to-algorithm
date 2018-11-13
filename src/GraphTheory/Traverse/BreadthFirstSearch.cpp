#include "BreadthFirstSearch.h"
#include <cstring>
#include <queue>
#include <vector>

std::vector<int> BreadthFirstSearch(int g[MAX][MAX], int n) {
  std::vector<int> result;
  std::queue<int> q;
  int visited[MAX];
  std::memset(visited, 0, sizeof(visited));

  q.push(0);
  visited[0] = 1;

  while (!q.empty()) {
    int e = q.front();
    q.pop();
    result.push_back(e);

    // adjacent node to e
    for (int i = 0; i < n; i++) {
      if (i != e && g[e][i] && !visited[i]) {
        q.push(i);
        visited[i] = 1;
      }
    }
  }
  return result;
}

