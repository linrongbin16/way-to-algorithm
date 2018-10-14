#include "MaxBinaryTree.h"
#include <cassert>
#include <cstring>
#include <iostream>
using namespace std;

struct Test {
  int value[MAX];
  int left[MAX];
  int right[MAX];
  int n;
  int m;
  int result;
} testcases[] = {
    {
        {0, 1, 2, 3},
        {0, 2, 0, 0},
        {0, 3, 0, 0},
        3,
        2,
        4,
    },
    {
        {0, 10, 9, 4, 1, 13, 2, 10},
        {0, 2, 4, 6, 0, 0, 0, 0},
        {0, 3, 5, 7, 0, 0, 0, 0},
        7,
        4,
        36,
    },
};

int main(void) {
  for (int i = 0; i < sizeof(testcases) / sizeof(Test); i++) {
    Test &t = testcases[i];
    BiNode *tree = MaxBinaryTreeNew(t.value, t.left, t.right, t.n);
    int r = MaxBinaryTree(tree, t.n, t.m);
    MaxBinaryTreeFree(tree);
    assert(r == t.result);
  }
  return 0;
}

