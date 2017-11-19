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

auto InorderTraverse(int n) -> vector<int>;


//
// implement
//

namespace detail {

  auto InorderImpl(int index, int n, vector<int> & seq) -> void;

}

/* 节点i的左孩子节点为i*2+1 右孩子节点为i*2+2 */
/* 根节点为0 */
auto InorderTraverse(int n) -> vector<int> {
  vector<int> seq;
  detail::InorderImpl(0, n, seq);
  return seq;
}

namespace detail {

  auto InorderImpl(int index, int n, vector<int> & seq) -> void {
    if (index < 0 or index >= n) {
      return;
    }

    if (index >= 0 and index < n)
      InorderImpl(index * 2 + 1, n, seq);

    seq.push_back(index);

    if (index >= 0 and index < n)
      InorderImpl(index * 2 + 2, n, seq);
  }

}
