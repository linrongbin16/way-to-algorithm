#include "AStarSearch.h"
#include <cassert>
#include <string>
using namespace std;

struct Test {
  Node begin;
  Node end;
} test_cases[] = {
    {Node("1348x5726"), Node("1238x4765")},
    {Node("2317x8654"), Node("1238x4765")},
    {Node("2318x4765"), Node("1238x4765")},
    {Node("1238x4765"), Node("2318x4765")},
    {Node("2831x4765"), Node("1238x4765")},
    {Node("1348x5726"), Node("1238x4765")},
};

void AssertXCount(Node a) {
  int xcount = 0;
  for (int i = 0; i < 9; i++) {
    if (a.number[i] == 'x')
      xcount++;
  }
  assert(xcount == 1);
}

void AssertIsAdjacent(Node a, Node b) {
  static int dir[4] = {-3, 3, -1, 1};
  AssertXCount(a);
  AssertXCount(b);

  int xpos = -1;
  for (int i = 0; i < 9; i++) {
    if (a.number[i] == 'x') {
      xpos = i;
      break;
    }
  }
  for (int i = 0; i < 4; i++) {
    if (i + dir[i] < 0 || i + dir[i] >= 9) {
      continue;
    }
    if (b.number[i + dir[i]] == 'x') {
      return;
    }
  }
  assert(false);
}

void AssertPath(const vector<Node> &path) {
  if (path.size() == 1)
    return;
  for (int i = 0; i < path.size() - 1; i++) {
    AssertIsAdjacent(path[i], path[i + 1]);
  }
}

int main() {
  for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
    Test &t = test_cases[i];
    vector<Node> path = AStarSearch(t.begin, t.end);
    assert(path.size() > 0);
    assert(path.front() == t.begin);
    assert(path.back() == t.begin);
    AssertPath(path);
  }

  return 0;
}

