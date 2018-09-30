#include "BreadthFirstSearch.h"
#include "Util.h"
#include <cassert>
#include <iostream>
using namespace std;

#define TEST_M_MAX 64
#define TEST_N_MAX 64

int main() {
  for (int i = 1; i < TEST_M_MAX; i++)
    for (int j = 1; j < TEST_N_MAX; j++) {
      BfsNode beg(0, 0);
      BfsNode end(i - 1, j - 1);
      vector<BfsNode> path = BreadthFirstSearch(i, j, beg, end);
      /* 保证路径长度为 j-1+i-1+1 */
      assert(path.size() == (i - 1 + j - 1 + 1));
      /* 保证起点和终点位置 */
      assert(path[0] == end);
      assert(path[path.size() - 1] == beg);
      for (int k = 0; k < path.size() - 1; k++) {
        /* 保证路径中相邻两点在二维方格中也是相邻点 */
        AssertAdjacent(path[k], path[k + 1]);
      }
    }

  return 0;
}

