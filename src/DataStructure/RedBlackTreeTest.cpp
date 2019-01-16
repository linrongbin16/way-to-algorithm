#include "RedBlackTree.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <ctime>
#include <iostream>
using namespace std;

#define TEST_MAX 8192

int main(void) {
  int start = time(NULL);
  for (int i = 1; i < TEST_MAX; i++) {
    vector<int> val;
    for (int j = 1; j <= i; j++) {
      val.push_back(j);
    }

    random_shuffle(val.begin(), val.end());
    RbTree *t = RedBlackTreeNew();
    for (int j = 0; j < i; j++) {
      assert(is_nil(t, RedBlackTreeFind(t, val[j])));
      RedBlackTreeInsert(t, val[j]);
      RbNode *e = RedBlackTreeFind(t, val[j]);
      assert(not_nil(t, e));
      assert(e->value == val[j]);
    } // for
    random_shuffle(val.begin(), val.end());
    for (int j = 0; j < i; j++) {
      RbNode *e = RedBlackTreeFind(t, val[j]);
      assert(not_nil(t, e));
      assert(e->value == val[j]);
      RedBlackTreeErase(t, val[j]);
      assert(is_nil(t, RedBlackTreeFind(t, val[j])));
    } // for
    RedBlackTreeFree(t);
  }
  int end = time(NULL);
  cout << "start: " << start << " end: " << end << " use: " << (end - start) << endl;
  return 0;
}

