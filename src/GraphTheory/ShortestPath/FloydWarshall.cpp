#include "FloydWarshall.h"
#include <algorithm>

std::vector<std::vector<int>> FloydWarshall(int g[MAX][MAX], int n) {
  int distance[MAX][MAX];
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

  std::vector<std::vector<int>> result;
  for (int i = 0; i < n; i++) {
    std::vector<int> tmp;
    for (int j = 0; j < n; j++) {
      tmp.push_back(distance[i][j]);
    }
    result.push_back(tmp);
  }
  return result;
}

