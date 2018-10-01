#include "BidirectionalBreadthSearch.h"
#include "Util.h"
#include <cassert>
#include <cstring>
#include <deque>
#include <utility>
#include <vector>

static std::deque<BfsNode> BidirectionalPath(BfsNode bfather[MAX][MAX],
                                             BfsNode efather[MAX][MAX],
                                             const BfsNode &beg,
                                             const BfsNode &end,
                                             const BfsNode &meet_pos) {
  std::deque<BfsNode> path;
  BfsNode i;
  for (i = meet_pos; i != beg; i = bfather[i.row][i.col]) {
    path.push_front(i);
  }
  path.push_front(i);
  for (i = efather[meet_pos.row][meet_pos.col]; i != end;
       i = efather[i.row][i.col]) {
    path.push_back(i);
  }
  path.push_back(i);
  return path;
}

std::deque<BfsNode> BidirectionalBreadthSearch(int n, int m, const BfsNode &beg,
                                               const BfsNode &end) {
  int bvisit[MAX][MAX], evisit[MAX][MAX];
  BfsNode bfather[MAX][MAX], efather[MAX][MAX];

  std::memset(bvisit, 0, sizeof(int) * MAX * MAX);
  std::memset(evisit, 0, sizeof(int) * MAX * MAX);
  std::memset(bfather, 0, sizeof(int) * MAX * MAX);
  std::memset(efather, 0, sizeof(int) * MAX * MAX);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bfather[i][j] = BfsNode(i, j);
      efather[i][j] = BfsNode(i, j);
    }
  }

  std::deque<BfsNode> bq, eq;
  bq.push_back(beg);
  eq.push_back(end);
  bvisit[beg.row][beg.col] = 1;
  evisit[end.row][end.col] = 1;

  while (true) {
    //先扩展bq
    BfsNode beg_node = bq.front();
    bq.pop_front();

    // beg_node已被evisit访问过
    // beg_node为bq和eq的相遇节点
    if (evisit[beg_node.row][beg_node.col]) {
      return BidirectionalPath(bfather, efather, beg, end, beg_node);
    }

    for (int i = 0; i < 4; i++) {
      int nrow = beg_node.row + row_dir[i];
      int ncol = beg_node.col + col_dir[i];

      if (!in_range(nrow, n) || !in_range(ncol, m)) {
        continue;
      }

      // 点<nrow, ncol>是beg_node的邻节点
      if (!bvisit[nrow][ncol]) {
        bq.push_back(BfsNode(nrow, ncol));
        bvisit[nrow][ncol] = 1;
        bfather[nrow][ncol] = beg_node;
      }
    }

    //后扩展eq
    BfsNode end_node = eq.front();
    eq.pop_front();
    // end_node已被evisit访问过
    // end_node为bq和eq的相遇节点
    if (bvisit[end_node.row][end_node.col]) {
      return BidirectionalPath(bfather, efather, beg, end, end_node);
    }

    for (int i = 0; i < 4; i++) {
      int nrow = end_node.row + row_dir[i];
      int ncol = end_node.col + col_dir[i];

      if (!in_range(nrow, n) || !in_range(ncol, m)) {
        continue;
      }

      // 点<nrow, ncol>是end_node的邻节点
      if (!evisit[nrow][ncol]) {
        eq.push_back(BfsNode(nrow, ncol));
        evisit[nrow][ncol] = 1;
        efather[nrow][ncol] = end_node;
      }
    }
  }

  return {};
}

