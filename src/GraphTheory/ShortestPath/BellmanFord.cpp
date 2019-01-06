#include "BellmanFord.h"
#include "../Util.h"
#include <algorithm>
#include <cstring>
#include <memory>
#include <tuple>
#include <utility>
#include <vector>

std::pair<bool, std::vector<int>> BellmanFord(int g[MAX][MAX], int n, int beg) {
  int distance[MAX];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      distance[i] = (i == j) ? 0 : INF;
    }
  }

  std::vector<Edge> edge_list;
  int edge_n = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (g[i][j] > 0) {
        edge_list.push_back(Edge(i, j, g[i][j]));
        edge_n++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < edge_n; j++) {
      int u = edge_list[j].u;
      int v = edge_list[j].v;

      if (distance[u] > distance[v] + g[u][v]) {
        distance[u] = distance[v] + g[u][v];
      }
      if (distance[v] > distance[u] + g[v][u]) {
        distance[v] = distance[u] + g[v][u];
      }
    } // for
  }   // for

  // 检查是否有问题

  for (int i = 0; i < edge_n; i++) {
    int u = edge_list[i].u;
    int v = edge_list[i].v;
    if (distance[u] > distance[v] + g[u][v]) {
      return std::make_pair(false, std::vector<int>());
    }
    if (distance[v] > distance[u] + g[v][u]) {
      return std::make_pair(false, std::vector<int>());
    }
  } // for

  std::vector<int> result;
  std::for_each(distance, distance + n, [&result](const int &v){ result.push_back(v); });
  return std::make_pair(true, result);
}

