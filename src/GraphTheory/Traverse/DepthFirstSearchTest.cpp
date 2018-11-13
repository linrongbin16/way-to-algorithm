#include "DepthFirstSearch.h"
#include <cassert>
#include <cstring>
#include <vector>
using namespace std;

struct Test {
  int g[MAX][MAX];
  int n;
  vector<int> result;
} test_cases[] = {
    {
        {
            {0, 1, 0, 0, 1, 1},
            {1, 0, 1, 1, 0, 1},
            {0, 1, 0, 1, 0, 1},
            {0, 1, 2, 0, 1, 0},
            {1, 0, 0, 1, 0, 0},
            {1, 1, 1, 0, 0, 0},
        },
        6,
        {0, 1, 2, 3, 4, 5},
    },
    {
        {
            {0, 1, 0, 0, 0, 0, 1, 0},
            {1, 0, 1, 0, 1, 0, 0, 1},
            {0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 1, 0, 0},
            {0, 1, 0, 1, 0, 0, 0, 0},
            {0, 0, 0, 1, 0, 0, 1, 1},
            {1, 0, 0, 0, 0, 1, 0, 1},
            {0, 1, 0, 0, 0, 1, 1, 0},
        },
        8,
        {0, 1, 2, 4, 3, 5, 6, 7},
    },
    {
        {
            {0, 1, 1, 0, 0, 0}, // 0
            {0, 0, 0, 1, 0, 0}, // 1
            {0, 0, 0, 1, 1, 0}, // 2
            {1, 0, 0, 0, 0, 1}, // 3
            {0, 0, 0, 0, 0, 1}, // 4
            {0, 0, 0, 0, 0, 0}, // 5
        },
        6,
        {0, 1, 3, 5, 2, 4},
    },
};

void AssertEqual(const vector<int> &a, const vector<int> &b) {
  assert(a.size() == b.size());
  for (int i = 0; i < a.size(); i++)
    assert(a[i] == b[i]);
}

int main(void) {
  for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
    Test &t = test_cases[i];
    vector<int> r = DepthFirstSearch(t.g, t.n);
    AssertEqual(r, t.result);
  }
  return 0;
}

