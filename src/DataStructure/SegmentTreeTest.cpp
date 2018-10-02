#include "SegmentTree.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;

#define TEST_MAX 128

int main() {
  int s[TEST_MAX];
  for (int i = 0; i < TEST_MAX; i++) {
    s[i] = i;
  }
  for (int i = 1; i < TEST_MAX; i++) {
    SegNode *t = SegmentTreeNew(s, 0, i);
    for (int j = 0; j < i; j++) {
      int r = rand() % MAX;
      SegmentTreeModify(t, j, r);
      s[j] += r;
      for (int p = 0; p <= i; p++) {
        int sum = 0;
        for (int q = 0; q < p; q++) {
          sum += s[q];
        }
        assert(sum == SegmentTreeQuery(t, 0, p));
      } // for
    }   // for
    SegmentTreeFree(t);
  } // for

  return 0;
}

