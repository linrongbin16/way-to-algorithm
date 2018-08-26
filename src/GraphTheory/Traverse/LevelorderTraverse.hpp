#pragma once
#ifndef MAX
#define MAX 1024
#endif
#include <iostream>
#include <vector>
#include <deque>


/* 节点i的左孩子节点为i*2+1 右孩子节点为i*2+2 */
/* 根节点为0 */
std::vector<int> LevelorderTraverse(int n) {
  std::vector<int> seq;
  std::deque<int> que;
  que.push_back(0);

  while (!que.empty()) {
    int index = que.front();
    que.pop_front();
    seq.push_back(index);
    int left_index = index * 2 + 1;
    int right_index = index * 2 + 2;
    if (left_index >= 0 && left_index < n)
      que.push_back(left_index);
    if (right_index >= 0 && right_index < n)
      que.push_back(right_index);
  }

  return seq;
}
