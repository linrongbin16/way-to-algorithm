#include "Prim.h"
#include <cassert>
#include <unordered_set>

static Edge MinAdjacentEdge(int g[MAX][MAX], int n,
                            const std::unordered_set<int> &vtree) {
  int min_value = INF;
  int a_vertex = -1;
  int b_vertex = -1;
  for (auto i = vtree.begin(); i != vtree.end(); i++) {
    int v = *i;
    for (int j = 0; j < n; j++) {
      if (g[v][j] > 0 && vtree.find(j) == vtree.end() && g[v][j] < min_value) {
        min_value = g[v][j];
        a_vertex = v;
        b_vertex = j;
      }
    }
  }
  assert(min_value != INF);
  assert(a_vertex != -1);
  assert(b_vertex != -1);
  return Edge(a_vertex, b_vertex, min_value);
}

std::vector<Edge> Prim(int g[MAX][MAX], int n) {
  std::unordered_set<int> vtree = {0};
  std::vector<Edge> etree;
  while (vtree.size() != n) {
    Edge e = MinAdjacentEdge(g, n, vtree);
    if (vtree.find(e.u) == vtree.end()) {
      vtree.insert(e.u);
    }
    if (vtree.find(e.v) == vtree.end()) {
      vtree.insert(e.v);
    }
    etree.push_back(e);
  }
  return etree;
}

