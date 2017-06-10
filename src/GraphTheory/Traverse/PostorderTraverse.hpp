#ifndef POSTORDER_TRAVERSE_HPP
#define POSTORDER_TRAVERSE_HPP

#include <iostream>
#include <vector>
using namespace std;
#ifndef MAX
#define MAX 1024
#endif


/* tree[i]的左孩子节点为tree[i*2+1] 右孩子节点为tree[i*2+2] */
auto PostorderTraverseImpl(int index, int tree[MAX], int n, vector<int> & seq) -> void
{
    if (index < 0 or index > n) return;
    if (index >= 0 and index < n) PostorderTraverseImpl(index * 2 + 1, tree, n, seq);
    if (index >= 0 and index < n) PostorderTraverseImpl(index * 2 + 2, tree, n, seq);
    seq.push_back(tree[index]);
}

auto PostorderTraverse(int tree[MAX], int n) -> vector<int>
{
    vector<int> seq;
    PostorderTraverseImpl(0, tree, n, seq);
    return seq;
}

#endif
