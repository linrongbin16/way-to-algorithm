#include "RedBlackTree.h"
#include <cassert>

#define TEST_MAX 1024
#define is_nil(e) ((e) == &RBNIL)
#define not_nil(e) ((e) != &RBNIL)

int main() {
  RedBlackTree *t = RedBlackTreeNew();
  assert(t);

  for (int i = 1; i <= TEST_MAX; i++) {
    RedBlackTreeInsert(t, i);
  }
  for (int i = 1; i <= TEST_MAX; i++) {
    RbNode *e = RedBlackTreeFind(t, i);
    assert(not_nil(e));
    assert(e->value == i);
  }
  for (int i = 1; i <= TEST_MAX; i++) {
    RedBlackTreeErase(t, i);
    assert(is_nil(RedBlackTreeFind(t, i)));
  }
  RedBlackTreeFree(t);

  return 0;
}

