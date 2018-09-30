#include "AStarSearch.h"
#include "Util.h"
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

struct Test {
  int block[MAX][MAX];
  int n;
  int m;
  BfsNode begin;
  BfsNode end;
} test_cases[] = {
    {
        {
            {0, 0},
            {0, 0},
        },
        2,
        2,
        {0, 0},
        {1, 1},
    },
    {
        {
            {0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 1, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 1, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
        },
        8,
        5,
        {0, 0},
        {0, 7},
    },
    {
        {
            //  1           5              10
            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0}, // 0
            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0}, // 1
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
            {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // 5
            {0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, // 10
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1},
            {0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        },
        14,
        15,
        {0, 0},
        {14, 13},
    },
};

int main() {
  for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
    Test &t = test_cases[i];
    vector<BfsNode> path = AStarSearch(t.block, t.m, t.n, t.begin, t.end);
    assert(path.size() > 0);
    assert(path[0] == t.end);
    assert(path[path.size() - 1] == t.begin);
    for (int k = 0; k < path.size() - 1; k++) {
      /* 保证路径中相邻两点在二维方格中也是相邻点 */
      AssertAdjacent(path[k], path[k + 1]);
    }
    for (int i = 0; i < path.size(); i++) {
      assert(!t.block[path[i].col][path[i].row]);
    }
  }

  return 0;
}

