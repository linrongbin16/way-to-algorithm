#include "Kruskal.h"
#include "../Util.h"
#include <algorithm>
#include <vector>

static bool CompareEdge(const Edge &a, const Edge &b) {
  return a.value < b.value;
}

static void InitFather(int *father, int n) {
  for (int i = 0; i < n; i++) {
    father[i] = i;
  }
}

static int FindFather(int *father, int i) {
  if (father[i] != i) {
    // 减小并查集中父节点的路径
    father[i] = FindFather(father, father[i]);
    return father[i];
  }
  return father[i];
}

std::vector<Edge> Kruskal(int g[MAX][MAX], int n) {
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

  std::sort(edge_list.begin(), edge_list.end(), CompareEdge);

  std::vector<Edge> result;

  // 顶点的并查集
  // 顶点i的并查集父节点初始化为i自己
  int father[MAX];
  InitFather(father, n);

  for (int i = 0; i < edge_n; i++) {
    int uf = FindFather(father, edge_list[i].u);
    int vf = FindFather(father, edge_list[i].v);

    // 两个顶点不属于同一个并查集
    // 因此该边不会使生成树中形成环
    if (uf != vf) {
      result.push_back(edge_list[i]);
      father[vf] = uf;
    }
  }
  return result;
}

