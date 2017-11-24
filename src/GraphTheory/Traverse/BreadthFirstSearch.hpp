// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

#ifndef MAX
#define MAX 128
#endif
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>


/* 总是从节点0开始进行遍历 */
std::vector<int> BreadthFirstSearch(int g[MAX][MAX], int n) {
  std::vector<int> sequence;
  std::queue<int> que;
  int visited[MAX];
  memset(visited, 0, sizeof(visited));
  que.push(0);
  visited[0] = 1;

  while(!que.empty()) {
    int e = que.front();
    que.pop();
    sequence.push_back(e);

    // for each node adjacent to e
    for (int i = 0; i < n; i++) {
      if (i != e && g[e][i] && !visited[i]) {
        que.push(i);
        visited[i] = 1;
      }
    }
  }
  return sequence;
}
