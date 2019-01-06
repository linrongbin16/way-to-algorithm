#include "AvlTree.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#define TEST_MAX 4096

int main() {
  for (int i = 1; i < TEST_MAX; i++) {
    vector<int> val;
    for (int j = 0; j < i; j++) {
      val.push_back(j);
    }

    random_shuffle(val.begin(), val.end());
    AvlTree *t = AvlTreeNew();
    for (int j = 0; j < i; j++) {
      assert(is_nil(AvlTreeFind(t, val[j])));
      AvlTreeInsert(t, val[j]);
      AvlNode *e = AvlTreeFind(t, val[j]);
      assert(not_nil(e));
      assert(e->value == val[j]);
    } // for
    random_shuffle(val.begin(), val.end());
    for (int j = 0; j < i; j++) {
      AvlNode *e = AvlTreeFind(t, val[j]);
      assert(not_nil(e));
      assert(e->value == val[j]);
      AvlTreeErase(t, val[j]);
      assert(is_nil(AvlTreeFind(t, val[j])));
    } // for
    AvlTreeFree(t);
  }
  return 0;
}
