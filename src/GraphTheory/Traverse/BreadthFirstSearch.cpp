#include "BreadthFirstSearch.hpp"
#include <cassert>
#include <vector>
using namespace std;

struct Test {
  int g[MAX][MAX];
  int n;
  vector<int> result;
} test_cases[] = {
  {
    {
      { 0, 1, 0, 0, 1, 1 },
      { 1, 0, 1, 1, 0, 1 },
      { 0, 1, 0, 1, 0, 1 },
      { 0, 1, 1, 0, 1, 0 },
      { 1, 0, 0, 1, 0, 1 },
      { 1, 1, 1, 0, 0, 0 },
    },
    6,
    { 0, 1, 4, 5, 2, 3 },
  },
  {
    {
      { 0, 1, 0, 0, 0, 0, 1, 0 },
      { 1, 0, 1, 0, 1, 0, 0, 1 },
      { 0, 1, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 1, 1, 0, 0 },
      { 0, 1, 0, 1, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 0, 0, 1, 1 },
      { 1, 0, 0, 0, 0, 1, 0, 1 },
      { 0, 1, 0, 0, 0, 1, 1, 0 },
    },
    8,
    { 0, 1, 6, 2, 4, 7, 5, 3 },
  },
};

auto AssertEqual(const vector<int> & a, const vector<int> & b) -> void {
  assert(a.size() == b.size());
  for (int i = 0; i < a.size(); i++)
    assert(a[i] == b[i]);
}

auto main() -> int {
  for (int i = 0; i < sizeof(test_cases)/sizeof(Test); i++) {
    Test &t = test_cases[i];
    vector<int> r = BreadthFirstSearch(t.g, t.n);
    AssertEqual(r, t.result);
  }
  return 0;
}
