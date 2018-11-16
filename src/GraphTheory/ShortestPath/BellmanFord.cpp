#include "BellmanFord.h"
#include "../Util.h"
#include <cstring>
#include <memory>
#include <tuple>
#include <utility>
#include <vector>

bool BellmanFord(int g[MAX][MAX], int n, int distance[MAX][MAX]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      distance[i][j] = (i == j) ? 0 : INF;
    }
  }

  std::vector<Edge> edge_list;
  int edge_n = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (g[i][j] > 0) {
        Edge e;
        e.u = i;
        e.v = j;
        e.value = g[i][j];
        edge_list.push_back(e);
        edge_n++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < edge_n; j++) {
      int u = edge_list[j].u;
      int v = edge_list[j].v;

      if (distance[u][g] > distance[g][v] + g[u][v]) {
        distance[u][g] = distance[g][v] + g[u][v];
      }
      if (distance[v][g] > distance[g][u] + g[v][u]) {
        distance[v][g] = distance[g][u] + g[v][u];
      }
    } // for
  }   // for

  // 检查是否有问题

  for (int i = 0; i < edge_n; i++) {
    int u = edge_list[i].u;
    int v = edge_list[i].v;
    if (distance[u] > distance[v] + g[u][v]) {
      return false;
    }
    if (distance[v] > distance[u] + g[v][u]) {
      return false;
    }
  } // for

  return true;
}

