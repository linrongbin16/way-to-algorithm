#include "SegmentTree.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;

#define TEST_MAX 128

static int Sum(const int *s, int beg, int end) {
  int sum = 0;
  for (int i = beg; i < end; i++) {
    sum += s[i];
  }
  return sum;
}

int main() {
  int s[TEST_MAX];
  for (int i = 0; i < TEST_MAX; i++) {
    s[i] = i;
  }
  for (int i = 1; i < TEST_MAX; i++) {
    SegNode *t = SegmentTreeNew(s, 0, i);
    for (int j = 0; j < i; j++) {
      int r = rand() % TEST_MAX;
      SegmentTreeAdd(t, j, r);
      s[j] += r;
      for (int p = 0; p <= i; p++) {
        assert(Sum(s, 0, p) == SegmentTreeSum(t, 0, p));
      } // for
    }   // for
    SegmentTreeFree(t);
  } // for

  return 0;
}

