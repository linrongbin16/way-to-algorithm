#ifndef PREORDER_TRAVERSE_HPP
#define PREORDER_TRAVERSE_HPP

#include <iostream>
#include <vector>
using namespace std;
#ifndef MAX
#define MAX 1024
#endif


auto PreorderImpl(int index, int n, vector<int> & seq) -> void
{
    if (index < 0 or index >= n) return;
    seq.push_back(index);
    if (index >= 0 and index < n) PreorderImpl(index * 2 + 1, n, seq);
    if (index >= 0 and index < n) PreorderImpl(index * 2 + 2, n, seq);
}

/* 节点i的左孩子节点为i*2+1 右孩子节点为i*2+2 */
/* 根节点为0 */
auto PreorderTraverse(int n) -> vector<int>
{
    vector<int> seq;
    PreorderImpl(0, n, seq);
    return seq;
}

#endif
