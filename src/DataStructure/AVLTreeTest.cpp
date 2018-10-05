#include "AvlTree.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#define is_nil(e) ((e) == &AVLNIL)
#define not_nil(e) ((e) != &AVLNIL)
#define MAX 1024

int main(void) {
  for (int i = 1; i < MAX; i++) {
    vector<int> val;
    for (int j = 0; j < i; j++) {
      val.push_back(j);
    }

    random_shuffle(val.begin(), val.end());
    AvlTree *t = AvlTreeNew();
    for (int j = 0; j < i; j++) {
      cout << "1 - i:" << i << ", j:" << j << endl;
      assert(is_nil(AvlTreeFind(t, val[j])));
      AvlTreeInsert(t, val[j]);
      assert(not_nil(AvlTreeFind(t, val[j])));
    } // for
    random_shuffle(val.begin(), val.end());
    for (int j = 0; j < i; j++) {
      cout << "2 - i:" << i << ", j:" << j << endl;
      assert(not_nil(AvlTreeFind(t, val[j])));
      AvlTreeErase(t, val[j]);
      assert(is_nil(AvlTreeFind(t, val[j])));
    } // for
    AvlTreeFree(t);
  }
  return 0;
}

