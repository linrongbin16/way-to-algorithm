#include "DifferenceConstraints.h"
#include "BellmanFord.h"
#include <cstring>

static void CreateDirectedGraph(int a[MAX][MAX], int n, int m, int *b,
                                int g[MAX][MAX], int &gn) {
  std::memset(g, 0, MAX * MAX * sizeof(int));

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      g[i][j] = (i == j) ? 0 : INF;
    } // for
  }   // for

  for (int i = 0; i < n; i++) {
    g[0][i + 1] = 0;
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    for (int j = 0; j < n; ++j) {
      if (a[i][j] == 1) {
        u = j;
      } else if (a[i][j] == -1) {
        v = j;
      }
    } // for
    g[u + 1][v + 1] = b[i];
  } // for

  gn = n + 1;
}

std::pair<bool, std::vector<int>> DifferenceConstraints(int a[MAX][MAX], int n,
                                                        int m, int *b) {
  int g[MAX][MAX];
  int gn;
  CreateDirectedGraph(a, n, m, b, g, gn);
  std::pair<bool, std::vector<int>> result = BellmanFord(g, gn, 0);
  return result;
}

