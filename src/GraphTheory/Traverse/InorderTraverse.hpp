#pragma once
#ifndef MAX
#define MAX 1024
#endif
#include <iostream>
#include <vector>


//
// interface
//

std::vector<int> InorderTraverse(int n);


//
// implement
//

namespace detail {

  void InorderImpl(int index, int n, std::vector<int> &seq);

}

/* 节点i的左孩子节点为i*2+1 右孩子节点为i*2+2 */
/* 根节点为0 */
std::vector<int> InorderTraverse(int n) {
  std::vector<int> seq;
  detail::InorderImpl(0, n, seq);
  return seq;
}

namespace detail {

  void InorderImpl(int index, int n, std::vector<int> &seq) {
    if (index < 0 || index >= n) {
      return;
    }

    if (index >= 0 && index < n)
      InorderImpl(index * 2 + 1, n, seq);
    seq.push_back(index);
    if (index >= 0 && index < n)
      InorderImpl(index * 2 + 2, n, seq);
  }

}
