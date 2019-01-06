#include "Dijkstra.h"
#include <algorithm>
#include <cstring>
#include <vector>

static int MinDistance(int *distance, int *visit, int n) {
  int min_dist = INF, min_index = 0;
  for (int i = 0; i < n; i++)
    if (min_dist > distance[i] && !visit[i]) {
      min_dist = distance[i];
      min_index = i;
    }
  return min_index;
}

std::vector<int> Dijkstra(int g[MAX][MAX], int n, int beg) {
  int visit[MAX];
  int distance[MAX];
  std::memset(visit, 0, MAX * sizeof(int));
  std::memset(distance, 0, MAX * sizeof(int));

  for (int i = 0; i < n; i++) {
    distance[i] = (i == beg) ? 0 : INF;
  }

  for (int i = 0; i < n; i++) {
    int k = MinDistance(distance, visit, n);
    visit[k] = 1;
    for (int j = 0; j < n; j++) {
      if (distance[k] + g[k][j] < distance[j]) {
        distance[j] = distance[k] + g[k][j];
      }
    }
  }

  std::vector<int> result;
  std::for_each(distance, distance + n, [&result](const int &v) { result.push_back(v); });
  return result;
}

