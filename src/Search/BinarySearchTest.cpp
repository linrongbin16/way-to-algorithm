#include "BinarySearch.h"
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int s[MAX];
  for (int i = 0; i < MAX; i++) {
    s[i] = i;
  }
  for (int i = 1; i < MAX; i++) {
    for (int j = -MAX; j < 0; j++) {
      pair<bool, int> r = BinarySearch(s, 0, i, j);
      assert(!r.first);
    }
    for (int j = 0; j < i; j++) {
      pair<bool, int> r = BinarySearch(s, 0, i, j);
      assert(r.first);
      assert(r.second == j);
    }
    for (int j = i; j < MAX; j++) {
      pair<bool, int> r = BinarySearch(s, 0, i, j);
      assert(!r.first);
    }
  }
  return 0;
}

