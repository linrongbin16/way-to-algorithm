#include "AvlTree.h"
#include <assert.h>
#include <math.h>

#define TEST_MAX 1024

int main() {
  AvlTree *t = AvlTreeNew();
  for (int i = 1; i <= TEST_MAX; i++) {
    AvlTreeInsert(t, i);
    assert(pow(2, AvlTreeDepth(t)) <= i);
  }
  assert(pow(2, AvlTreeDepth(t)) <= TEST_MAX);
  for (int i = 1; i <= TEST_MAX; i++) {
    assert(AvlTreeFind(t, i) == 1);
  }
  for (int i = 1; i <= TEST_MAX; i++) {
    AvlTreeErase(t, i);
  }
  AvlTreeFree(t);
  return 0;
}

