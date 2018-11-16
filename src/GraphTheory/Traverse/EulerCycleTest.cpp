#include "EulerCycle.h"
#include <cassert>
#include <utility>
#include <vector>
using namespace std;

struct Test {
  int g[MAX][MAX];
  int n;
  bool exist;
} test_cases[] = {
    {
        {
            {1},
        },
        1,
        true,
    },
    {
        {
            {1},
        },
        1,
        true,
    },
    {
        {
            {1},
        },
        1,
        true,
    },
};

void AssertEulerPath(int g[MAX][MAX], int n, vector<int> path) {}

int main(void) {
  for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
    Test &t = test_cases[i];
    pair<bool, vector<int>> result = EulerCycle(t.g, t.n);
    assert(result.first == t.exist);
    AssertEulerPath(t.g, t.n, result.second);
  }
  return 0;
}

