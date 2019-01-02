#include "FenwickTree.h"
#include <cassert>
#include <cstdlib>
#include <cstring>
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
  for (int i = 2; i < TEST_MAX; i++) {
    int s[TEST_MAX];
    memset(s, 0, sizeof(int) * TEST_MAX);
    FwTree *t = FenwickTreeNew();
    for (int j = 1; j < i; j++) {
      int r = rand() % TEST_MAX;
      FenwickTreeAdd(t, j, r);
      s[j] += r;
      for (int p = 2; p <= i; p++) {
        int r1 = Sum(s, 1, p);
        int r2 = FenwickTreeSum(t, 1, p);
        assert(r1 == r2);
      } // for
    }   // for
    FenwickTreeFree(t);
  } // for

  return 0;
}

