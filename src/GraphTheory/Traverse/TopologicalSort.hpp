// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

#include <algorithm>
#include <deque>
#include <vector>
#include <cstring>
#include "DepthFirstSearch.hpp"
#ifndef MAX
#define MAX 128
#endif


//
// interface
//

std::vector<int> TopologicalSort(int g[MAX][MAX], int n);


//
// implement
//

namespace detail {

  struct TopoNode {
    int index;  // 节点下标
    int dist;  // 节点的DFS长度
    TopoNode() : index(0), dist(0) { }
    TopoNode(int i, int d) : index(i), dist(d) { }
  };

  bool TopoCompare(const TopoNode &a, const TopoNode &b);

}

/**
 * @brief TopologicalSort 拓扑排序
 *
 * @param g[MAX][MAX]   图G
 * @param n             图中节点数量 下标范围为[0, n-1]
 * @return seq     拓扑排序结果
*/
std::vector<int> TopologicalSort(int g[MAX][MAX], int n) {
  std::vector<detail::TopoNode> seq(n);
  int visited[MAX];
  for (int i = 0; i < n; ++ i)
    seq[i].index = i;

  for (int i = 0; i < n; i++) {
    int dist = 0;
    // 重置visited 让任意节点i可以尽可能深的进行DFS
    memset(visited, 0, sizeof(visited));
    std::vector<int> counter;
    detail::DFS(g, n, i, visited, counter);
    seq[i].dist = counter.size();
  }
  std::sort(seq.begin(), seq.end(), detail::TopoCompare);

  std::vector<int> topologic;
  for (int i = 0; i < seq.size(); i++)
    topologic.push_back(seq[i].index);
  return topologic;
}

namespace detail {

  bool TopoCompare(const TopoNode &a, const TopoNode &b) {
    return a.dist > b.dist;
  }

}
