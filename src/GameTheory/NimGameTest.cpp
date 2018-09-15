#include "NimGame.h"
#include <cassert>
#include <iostream>
using namespace std;

#define TEST_MAX 128

struct Test {
  int s[TEST_MAX];
  int n;
  bool result;
} tests[] = {{{1}, 1, true},    {{1, 1}, 2, false},   {{1, 1, 1}, 3, true},
             {{1, 2}, 2, true}, {{3, 4, 5}, 3, true}, {{7, 2, 4, 1}, 4, false}};

int main() {
  for (int i = 0; i < sizeof(tests) / sizeof(Test); i++) {
    Test &t = tests[i];
    assert(NimGame(t.s, t.n) == t.result);
  }
  return 0;
}

