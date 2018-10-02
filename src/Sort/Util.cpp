#include "Util.h"
#include <cassert>
#include <iostream>
using namespace std;

void AssertAscend(const int *s, int n) {
  bool asc = true;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] > s[i + 1]) {
      asc = false;
      break;
    }
  }
  assert(asc);
}

