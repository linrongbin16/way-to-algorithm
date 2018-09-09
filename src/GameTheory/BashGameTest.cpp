#include "BashGame.h"
#include <cassert>
#include <iostream>
using namespace std;

struct Test {
  int n;
  int m;
  bool result;
} tests[] = {
    {50, 4, false},
    {50, 5, true},
    {80, 6, true},
    {70, 9, false},
    {60, 5, false},
};

int main() {
  for (int i = 0; i < sizeof(tests) / sizeof(Test); i++) {
    Test &t = tests[i];
    cout << i << " " << BashGame(t.n, t.m) << endl;
    assert(BashGame(t.n, t.m) == t.result);
  }
  return 0;
}

