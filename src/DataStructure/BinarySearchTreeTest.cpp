#include "BinarySearchTree.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#define is_nil(e) ((e) == &BSNIL)
#define not_nil(e) ((e) != &BSNIL)
#define MAX 1024

int main(void) {
  for (int i = 1; i < MAX; i++) {
    vector<int> val;
    for (int j = 0; j < i; j++) {
      val.push_back(j);
    }

    std::random_shuffle(val.begin(), val.end());
    BinarySearchTree *t = BinarySearchTreeNew();
    for (int j = 0; j < i; j++) {
      assert(is_nil(BinarySearchTreeFind(t, val[j])));
      BinarySearchTreeInsert(t, val[j]);
      assert(not_nil(BinarySearchTreeFind(t, val[j])));
    } // for
    std::random_shuffle(val.begin(), val.end());
    for (int j = 0; j < i; j++) {
      assert(not_nil(BinarySearchTreeFind(t, val[j])));
      BinarySearchTreeErase(t, val[j]);
      assert(is_nil(BinarySearchTreeFind(t, val[j])));
    } // for
    vector<int> preOrder = BinarySearchTreePreOrder(t);
    vector<int> postOrder = BinarySearchTreePostOrder(t);
    vector<int> inOrder = BinarySearchTreeInOrder(t);
    vector<int> levelOrder = BinarySearchTreeLevelOrder(t);
    assert(preOrder.size() == postOrder.size());
    assert(postOrder.size() == inOrder.size());
    assert(inOrder.size() == levelOrder.size());
    BinarySearchTreeFree(t);
  }
  return 0;
}

