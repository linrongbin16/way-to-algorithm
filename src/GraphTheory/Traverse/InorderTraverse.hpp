#ifndef PREORDER_TRAVERSE_HPP
#define PREORDER_TRAVERSE_HPP

#include <iostream>
#include <vector>
using namespace std;
#ifndef MAX
#define MAX 1024
#endif


// tree[i]的左孩子节点为tree[i*2+1] 右孩子节点为tree[i*2+2]

void InorderTraverseImpl(int index, int tree[MAX], int n, vector<int> & seq)
{
    if (index > n) {
        return;
    }
    seq.push_back(tree[index]);
    InorderTraverseImpl(index * 2 + 1, tree, n, seq);
    InorderTraverseImpl(index * 2 + 2, tree, n, seq);
}

vector<int> InorderTraverse(int tree[MAX], int n)
{
    vector<int> seq;
    InorderTraverseImpl(0, tree, n, seq);
    return seq;
}



#endif
