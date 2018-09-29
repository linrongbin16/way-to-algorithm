#include "AStarSearch.h"
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

struct Test {
  const char *begin;
  const char *end;
} test_cases[] = {
    {"1348x5726", "1238x4765"}, {"2317x8654", "1238x4765"},
    {"2318x4765", "1238x4765"}, {"1238x4765", "2318x4765"},
    {"2831x4765", "1238x4765"}, {"1348x5726", "1238x4765"},
};

void AssertXCount(const char *a) {
  int xcount = 0;
  for (int i = 0; i < 9; i++) {
    if (a[i] == 'x')
      xcount++;
  }
  assert(xcount == 1);
}

void AssertAdjacent(const char *a, const char *b) {
  AssertXCount(a);
  AssertXCount(b);

  int xpos = -1;
  for (int i = 0; i < 9; i++) {
    if (a[i] == 'x') {
      xpos = i;
      break;
    }
  }
  for (int i = 0; i < 4; i++) {
    if (i + a_star_dir[i] < 0 || i + a_star_dir[i] >= 9) {
      continue;
    }
    if (b[i + a_star_dir[i]] == 'x') {
      return;
    }
  }
  assert(false);
}

void AssertPath(const vector<const char *> &path) {
  if (path.size() == 1)
    return;
  for (int i = 0; i < path.size() - 1; i++) {
    AssertAdjacent(path[i], path[i + 1]);
  }
}

int main() {
  for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
    cout << "i: " << i << endl;
    Test &t = test_cases[i];
    vector<const char *> path = AStarSearch(t.begin, t.end);
    assert(path.size() > 0);
    assert(path.front() == t.begin);
    assert(path.back() == t.begin);
    AssertPath(path);
  }

  return 0;
}

