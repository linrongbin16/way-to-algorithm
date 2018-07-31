// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

#ifndef MAX
#define MAX 128
#endif
#include <vector>
#include <cstring>

//
// interface
//

std::vector<int> DepthFirstSearch(int g[MAX][MAX], int n);


// implement

namespace detail {

  void DFS(int g[MAX][MAX], int n, int begin, int *visited, std::vector<int> &seq);

}

std::vector<int> DepthFirstSearch(int g[MAX][MAX], int n) {
  int visited[MAX];
  // 将遍历到的节点加入seq中
  std::vector<int> seq;

  // DFS from node-i
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < n; ++ i)
    if (!visited[i]) {
      detail::DFS(g, n, i, visited, seq);
    }

  return seq;
}

namespace detail {

  void DFS(int g[MAX][MAX], int n, int begin, int *visited, std::vector<int> &seq) {
    visited[begin] = 1;
    seq.push_back(begin);
    for (int i = 0; i < n; i++)
      if (i != begin && g[begin][i] && !visited[i])
        DFS(g, n, i, visited, seq);
  }

}
