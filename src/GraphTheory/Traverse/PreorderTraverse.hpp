#ifndef PREORDER_TRAVERSE_HPP
#define PREORDER_TRAVERSE_HPP

#include <iostream>
#include <vector>
using namespace std;
#ifndef MAX
#define MAX 1024
#endif


// tree[i]的左孩子节点为tree[i*2+1] 右孩子节点为tree[i*2+2]

void PreorderTraverseImpl(int index, int tree[MAX], int n, vector<int> & seq)
{
    if (index > n) {
        return;
    }
    seq.push_back(tree[index]);
    PreorderTraverse(index * 2 + 1, tree, n, seq);
    PreorderTraverse(index * 2 + 2, tree, n, seq);
}

vector<int> PreorderTraverse(int tree[MAX], int n)
{
    vector<int> seq;
    PreorderTraverse(0, tree, n, seq);
    return seq;
}



#endif
