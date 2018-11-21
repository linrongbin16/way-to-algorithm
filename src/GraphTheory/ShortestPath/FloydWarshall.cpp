#include "FloydWarshall.h"

void floyd(int g[MAX][MAX], int n, int distance[MAX][MAX]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      distance[i][j] = g[i][j];
    }
  }

  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        distance[i][j] =
            std::min(distance[i][j], distance[i][k] + distance[k][j]);
}

