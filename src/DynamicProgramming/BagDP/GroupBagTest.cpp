#include "GroupBag.h"
#include <cassert>
#include <iostream>
using namespace std;

#define TEST_MAX 1024

struct GKTest {
  Item group[MAX][MAX];
  int group_n[MAX];
  int n;
  int total_weight;
  int result;
} test_cases[] = {
    {{
         {},
         {{}, {3, 71}, {402, 5}, {5, 10}, {1, 27}, {4, 5}},
         {{}, {11, 10}, {19, 4}, {343, 2342}, {13, 7}},
         {{}, {13, 3}, {12, 5}, {50, 1}, {2, 37}, {4, 35}, {7, 10}},
         {{}, {3, 11}, {2, 24}, {5, 10}, {3, 25}, {40, 9}, {92, 21}, {393, 19}},
         {{}, {12, 22}, {83, 11}, {5, 10}},
     },
     {0, 5, 4, 6, 7, 3},
     5,
     30,
     864}, // 0
    {{
         {},
         {{}, {1, 2}, {2, 4}, {3, 6}, {4, 8}, {5, 10}},
         {{}, {10, 31}, {2, 5}, {5, 78}, {3, 7}},
         {{}, {4, 7}, {2, 51}, {5, 10}, {3, 7}, {4, 5}, {7, 10}},
         {{}, {9, 8}, {48, 13}, {6, 17}, {13, 7}},
         {{}, {15, 21}, {39, 35}, {8, 17}},
         {{}, {5, 1}, {32, 51}, {9, 10}},
         {{}, {15, 21}, {2, 5}, {18, 13}},
     },
     {0, 5, 4, 6, 4, 3, 3, 3},
     7,
     100,
     129}, // 1
};

int main() {
  int count = sizeof(test_cases) / sizeof(GKTest);
  for (int i = 0; i < count; i++) {
    GKTest &t = test_cases[i];
    int r = GroupBag(t.group, t.group_n, t.n, t.total_weight);
    cout << i << ": " << r << endl;
    assert(r == t.result);
  }

  return 0;
}
