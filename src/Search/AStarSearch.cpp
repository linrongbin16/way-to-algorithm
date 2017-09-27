// Copyright 2017 zhaochenyou16@gmail.com

#include "AStarSearch.hpp"
#include <cassert>
#include <string>
using namespace std;

struct Test {
  string begin;
  string end;
} test_cases[] = {
  { "1348x5726", "1238x4765" },
  { "2317x8654", "1238x4765" },
  { "2318x4765", "1238x4765" },
};

auto AssertXCount(string a) -> void {
  int xcount = 0;
  assert(a.length() == 9);
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == 'x')
      xcount++;
  }
  assert(xcount == 1);
}

auto AssertIsAdjacent(string a, string b) -> void {
  static int dir[4] = { -3, 3, -1, 1 };
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
    if (i + dir[i] < 0 or i + dir[i] >= 9) {
      continue;
    }
    if (b[i + dir[i]] == 'x') {
      return;
    }
  }
  assert(false);
}

auto AssertPath(vector<string> path) -> void {
  if (path.size() == 1)
    return;
  for (int i = 0; i < path.size()-1; i++) {
    AssertIsAdjacent(path[i], path[i+1]);
  }
}

auto main() -> int {
  for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
    Test & t = test_cases[i];
    vector<string> path = AStarSearch(t.beg_, t.end_);
    assert(path.size() > 0);
    assert(path.front() == t.beg_);
    assert(path.back() == t.beg_);
    AssertPath(path);
  }

  /* case 4:
  beg      end
  1 2 3    2 3 1
  8 x 4    8 x 4
  7 6 5    7 6 5
  */
  memset(&beg, 0, sizeof(beg));
  memset(&end, 0, sizeof(end));
  memcpy(beg.value, "1238x4765", 9);
  memcpy(end.value, "2318x4765", 9);
  UnitTest(beg, end);

  /* case 5:
  beg      end
  1 2 3    2 3 1
  8 x 4    8 x 4
  7 6 5    7 6 5
  */
  memset(&beg, 0, sizeof(beg));
  memset(&end, 0, sizeof(end));
  memcpy(beg.value, "1238x4765", 9);
  memcpy(end.value, "2318x4765", 9);
  UnitTest(beg, end);

  /* case 6:
  beg      end
  2 8 3    1 2 3
  1 x 4    8 x 4
  7 6 5    7 6 5
  */
  memset(&beg, 0, sizeof(beg));
  memset(&end, 0, sizeof(end));
  memcpy(beg.value, "2831x4765", 9);
  memcpy(end.value, "1238x4765", 9);
  UnitTest(beg, end);

  /* case 7:
  beg      end
  1 3 4    1 2 3
  8 x 5    8 x 4
  7 2 6    7 6 5
  */
  memset(&beg, 0, sizeof(beg));
  memset(&end, 0, sizeof(end));
  memcpy(beg.value, "1348x5726", 9);
  memcpy(end.value, "1238x4765", 9);
  UnitTest(beg, end);

  return 0;
}

