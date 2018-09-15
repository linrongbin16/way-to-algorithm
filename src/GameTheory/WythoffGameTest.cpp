#include "WythoffGame.h"
#include <cassert>
#include <iostream>
using namespace std;

struct Test {
  int p;
  int k;
  bool result;
} tests[] = {{1, 2, false}, {2, 1, false}, {1, 1, true},  {3, 5, false},
             {5, 3, false}, {4, 7, false}, {7, 4, false}, {4, 4, true},
             {3, 2, true},  {2, 3, true},  {3, 4, true},  {4, 3, true},
             {6, 4, true},  {6, 1, true}, {4, 9, true}};

int main() {
  for (int i = 0; i < sizeof(tests) / sizeof(Test); i++) {
    Test &t = tests[i];
	cout << i << endl;
    assert(WythoffGame(t.p, t.k) == t.result);
  }
  return 0;
}

