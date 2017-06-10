#ifndef POSTORDER_TRAVERSE_HPP
#define POSTORDER_TRAVERSE_HPP

#include <iostream>
#include <vector>
using namespace std;
#ifndef MAX
#define MAX 1024
#endif


auto PostorderImpl(int index, int n, vector<int> & seq) -> void
{
    if (index < 0 or index >= n) return;
    if (index >= 0 and index < n) PostorderImpl(index * 2 + 1, n, seq);
    if (index >= 0 and index < n) PostorderImpl(index * 2 + 2, n, seq);
    seq.push_back(index);
}

/* 节点i的左孩子节点为i*2+1 右孩子节点为i*2+2 */
/* 根节点为0 */
auto PostorderTraverse(int n) -> vector<int>
{
    vector<int> seq;
    PostorderImpl(0, n, seq);
    return seq;
}

#endif
