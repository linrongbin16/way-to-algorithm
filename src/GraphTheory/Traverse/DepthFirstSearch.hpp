// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

#include <vector>
#include <cstring>
#include <tuple>
using namespace std;
#ifndef MAX
#define MAX 128
#endif

//
// interface
//

auto DepthFirstSearch(int g[MAX][MAX], int n) -> vector<int>;


// implement

namespace detail {

  auto DFS(int g[MAX][MAX],
           int n,
           int begin,
           int visited[MAX],
           vector<int> &out_sequence) -> void;

}

auto DepthFirstSearch(int g[MAX][MAX], int n) -> vector<int> {
  int visited[MAX];
  // 将遍历到的节点加入sequence中
  vector<int> sequence;

  // DFS from node-i
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < n; ++ i)
    if (not visited[i]) {
      detail::DFS(g, n, i, visited, sequence);
    }

  return sequence;
}

namespace detail {

  auto DFS(int g[MAX][MAX],
           int n,
           int begin,
           int visited[MAX],
           vector<int> &out_sequence) -> void {

    visited[begin] = 1;
    out_sequence.push_back(begin);
    for (int i = 0; i < n; i++)
      if(i != begin and g[begin][i] and not visited[i])
        DFS(g, n, i, visited, out_sequence);
  }

}
