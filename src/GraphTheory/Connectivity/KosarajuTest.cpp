#include "Kosaraju.h"
#include "../Util.h"
#include <vector>
using namespace std;

struct Test {
  int g[MAX][MAX];
  int n;
} test_cases[] = {};

static void AssertStrongCompoennts(const vector<vector<int>> &components) {}

int main(void) {
  for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
    Test &t = test_cases[i];
    vector<vector<int>> result = Kosaraju(t.g, t.n);
    AssertStrongCompoennts(result);
  }
  return 0;
}

