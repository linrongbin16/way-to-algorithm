#include "SkipList.h"
#include <algorithm>
#include <cassert>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

#define TEST_MAX 16384

int main(void) {
  int start = time(NULL);
  for (int i = 1; i < TEST_MAX; i++) {
    vector<int> val;
    for (int j = 1; j <= i; j++) {
      val.push_back(j);
    }

    random_shuffle(val.begin(), val.end());
    SkList *sl = SkipListNew(TEST_MAX);
    for (int j = 0; j < i; j++) {
      assert(SkipListFind(sl, val[j]) == NULL);
      SkipListInsert(sl, val[j]);
      SkNode *e = SkipListFind(sl, val[j]);
      assert(e != NULL);
      assert(e->value == val[j]);
    } // for
    random_shuffle(val.begin(), val.end());
    for (int j = 0; j < i; j++) {
      SkNode *e = SkipListFind(sl, val[j]);
      assert(e != NULL);
      assert(e->value == val[j]);
      SkipListErase(sl, val[j]);
      assert(SkipListFind(sl, val[j]) == NULL);
    } // for
    SkipListFree(sl);
  }
  int end = time(NULL);
  cout << "start: " << start << " end: " << end << " use: " << (end - start)
       << endl;
  return 0;
}

