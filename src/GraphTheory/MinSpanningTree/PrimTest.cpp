#include "Prim.h"
#include "../Util.h"
#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

struct Test {
  int g[MAX][MAX];
  int n;
  int result;
} test_cases[] = {
    {
        {
            {0},
        },
        1,
        1,
    },
    {
        {
            {0},
        },
        1,
        1,
    },
};

void AssertVertex(const vector<Edge> &etree, int n) {
  unordered_set<int> vertexes;
  for (int i = 0; i < etree.size(); i++) {
    assert(etree[i].u >= 0);
    assert(etree[i].u < n);
    assert(etree[i].v >= 0);
    assert(etree[i].v < n);
    if (vertexes.find(etree[i].u) == vertexes.end()) {
      vertexes.insert(etree[i].u);
    }
    if (vertexes.find(etree[i].v) == vertexes.end()) {
      vertexes.insert(etree[i].v);
    }
  }
  assert(vertexes.size() == n);
}

int main(void) {
  for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
    Test &t = test_cases[i];
    vector<Edge> result = Prim(t.g, t.n);
    AssertVertex(result, t.n);
    int sum_value =
        accumulate(result.begin(), result.end(), 0,
                   [](int sum, const Edge &e) { return sum + e.value; });
    assert(sum_value == t.result);
  }
  return 0;
}

