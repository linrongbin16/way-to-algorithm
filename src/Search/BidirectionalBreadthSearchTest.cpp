#include "BidirectionalBreadthSearch.h"
#include "Util.h"
#include <cassert>
#include <iostream>
using namespace std;

#define TEST_M_MAX 16
#define TEST_N_MAX 16

int main() {
  for (int i = 1; i < TEST_N_MAX; i++)
    for (int j = 1; j < TEST_M_MAX; j++) {
      BfsNode beg_pos(0, 0);
      BfsNode end_pos(i - 1, j - 1);
      deque<BfsNode> path = BidirectionalBreadthSearch(i, j, beg_pos, end_pos);
      //保证路径长度为 j-1+i-1+1
      assert(path.size() == (i - 1 + j - 1 + 1));
      //保证起点和终点位置
      assert(path.front() == beg_pos);
      assert(path.back() == end_pos);
      for (int k = 0; k < path.size() - 1; k++) {
        //保证路径中相邻两点在二维方格中也是相邻点
        AssertAdjacent(path[k], path[k + 1]);
      }
    }
  return 0;
}

