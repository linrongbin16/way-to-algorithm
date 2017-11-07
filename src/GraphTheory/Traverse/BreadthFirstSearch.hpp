// Copyright 2017 zhaochenyou16@gmail.com

#ifndef GRAPHTHEORY_BREADTHFIRSTSEARCH_HPP
#define GRAPHTHEORY_BREADTHFIRSTSEARCH_HPP

#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#ifndef MAX
#define MAX 128
#endif


/* 总是从节点0开始进行遍历 */
auto BreadthFirstSearch(int g[MAX][MAX], int n) -> vector<int> {
  vector<int> sequence;
  queue<int> que;
  int visited[MAX];
  memset(visited, 0, sizeof(visited));
  que.push(0);
  visited[0] = 1;

  while(not que.empty()) {
    int e = que.front();
    que.pop();
    sequence.push_back(e);

    // for each node adjacent to e
    for(int i = 0; i < n; i++)
      if(i != e and g[e][i] and not visited[i]) {
        que.push(i);
        visited[i] = 1;
      }
  }
  return sequence;
}


#endif  // GRAPHTHEORY_BREADTHFIRSTSEARCH_HPP
