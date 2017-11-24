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

std::vector<int> PostorderTraverse(int n);


//
// implement
//

namespace detail {

  void PostorderImpl(int index, int n, std::vector<int> &seq);

}

/* 节点i的左孩子节点为i*2+1 右孩子节点为i*2+2 */
/* 根节点为0 */
std::vector<int> PostorderTraverse(int n) {
  std::vector<int> seq;
  detail::PostorderImpl(0, n, seq);
  return seq;
}

namespace detail {

  void PostorderImpl(int index, int n, std::vector<int> &seq) {
    if (index < 0 || index >= n)
      return;
    if (index >= 0 && index < n)
      PostorderImpl(index * 2 + 1, n, seq);
    if (index >= 0 && index < n)
      PostorderImpl(index * 2 + 2, n, seq);
    seq.push_back(index);
  }

}
