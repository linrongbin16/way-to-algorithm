#include "BinarySearchTree.h"
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#define is_nil(e) ((e) == &BSNIL)
#define not_nil(e) ((e) != &BSNIL)
#define MAX 1024

int main(void) {
  for (int i = 1; i < MAX; i++) {
    BinarySearchTree *t = BinarySearchTreeNew();
    for (int j = 0; j < i; j++) {
      assert(is_nil(BinarySearchTreeFind(t, j)));
      BinarySearchTreeInsert(t, j);
      assert(not_nil(BinarySearchTreeFind(t, j)));
    } // for
    for (int j = 0; j < i; j++) {
      assert(not_nil(BinarySearchTreeFind(t, j)));
      BinarySearchTreeErase(t, j);
      assert(is_nil(BinarySearchTreeFind(t, j)));
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

