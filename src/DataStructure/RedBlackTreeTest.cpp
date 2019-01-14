#include "RedBlackTree.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#define TEST_MAX 4096

static void DumpArray(const vector<int> &val) {
  cout << endl << "dump array: ";
  for (int i = 0; i < val.size(); i++) {
    cout << "val[" << i << "]:" << val[i] << " ";
  }
  cout << endl;
}

int main() {
  for (int i = 1; i < TEST_MAX; i++) {
    vector<int> val;
    for (int j = 1; j <= i; j++) {
      val.push_back(j);
    }

    random_shuffle(val.begin(), val.end());
    RedBlackTree *t = RedBlackTreeNew();
    for (int j = 0; j < i; j++) {
      cout << "insert i:" << i << " j:" << j << " val:" << val[j] << endl;
      assert(is_nil(RedBlackTreeFind(t, val[j])));
      RedBlackTreeInsert(t, val[j]);
      RbNode *e = RedBlackTreeFind(t, val[j]);
      assert(not_nil(e));
      assert(e->value == val[j]);
    } // for
    random_shuffle(val.begin(), val.end());
    for (int j = 0; j < i; j++) {
      DumpArray(val);
      cout << "erase i:" << i << " j:" << j << " val:" << val[j] << endl;
      RbNode *e = RedBlackTreeFind(t, val[j]);
      assert(not_nil(e));
      assert(e->value == val[j]);
      RedBlackTreeErase(t, val[j]);
      assert(is_nil(RedBlackTreeFind(t, val[j])));
    } // for
    RedBlackTreeFree(t);
  }
  return 0;
}

