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

std::vector<int> PreorderTraverse(int n);


//
// implement
//

namespace detail {

  void PreorderImpl(int index, int n, std::vector<int> &seq);

}

/* 节点i的左孩子节点为i*2+1 右孩子节点为i*2+2 */
/* 根节点为0 */
std::vector<int> PreorderTraverse(int n) {
  std::vector<int> seq;
  detail::PreorderImpl(0, n, seq);
  return seq;
}

namespace detail {

  void PreorderImpl(int index, int n, std::vector<int> &seq) {
    if (index < 0 || index >= n)
      return;
    seq.push_back(index);
    if (index >= 0 && index < n)
      PreorderImpl(index*2+1, n, seq);
    if (index >= 0 && index < n)
      PreorderImpl(index*2+2, n, seq);
  }

}

