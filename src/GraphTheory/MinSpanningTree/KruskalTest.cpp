#include "Kruskal.h"
#include "../Util.h"
#include <vector>
using namespace std;

struct Test {
  int g[MAX][MAX];
  int n;
} test_cases[] = {};

int main(void) {
  for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
    Test &t = test_cases[i];
    vector<Edge> result = Kruskal(t.g, t.n);
  }
  return 0;
}

