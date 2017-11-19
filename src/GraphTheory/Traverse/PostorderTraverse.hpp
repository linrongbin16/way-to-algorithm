// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

#include <iostream>
#include <vector>
using namespace std;
#ifndef MAX
#define MAX 1024
#endif


//
// interface
//

auto PostorderTraverse(int n) -> vector<int>;


//
// implement
//

namespace detail {

  auto PostorderImpl(int index, int n, vector<int> &seq) -> void;

}

/* 节点i的左孩子节点为i*2+1 右孩子节点为i*2+2 */
/* 根节点为0 */
auto PostorderTraverse(int n) -> vector<int> {
  vector<int> seq;
  detail::PostorderImpl(0, n, seq);
  return seq;
}

namespace detail {

  auto PostorderImpl(int index, int n, vector<int> &seq) -> void {
    if (index < 0 or index >= n) return;
    if (index >= 0 and index < n)
      PostorderImpl(index * 2 + 1, n, seq);
    if (index >= 0 and index < n)
      PostorderImpl(index * 2 + 2, n, seq);
    seq.push_back(index);
  }

}
