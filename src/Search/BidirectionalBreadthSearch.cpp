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
  for (i = meet_pos; i != beg; i = bfather[i.col][i.row]) {
    path.push_front(i);
  }
  path.push_front(i);
  for (i = efather[meet_pos.col][meet_pos.row]; i != end;
       i = efather[i.col][i.row]) {
    path.push_back(i);
  }
  path.push_back(i);
  return path;
}

std::deque<BfsNode> BidirectionalBreadthSearch(int m, int n, const BfsNode &beg,
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
  /* x.col范围是[0, m) */
  /* x.row范围是[0, n) */
  bvisit[beg.col][beg.row] = 1;
  evisit[end.col][end.row] = 1;

  while (true) {
    /* 先扩展bq */
    BfsNode beg_node = bq.front();
    bq.pop_front();
    for (int i = 0; i < 4; i++) {
      int ncol = beg_node.col + col_dir[i];
      int nrow = beg_node.row + row_dir[i];

      if (!in_range(ncol, m) || !in_range(nrow, n)) {
        continue;
      }

      // 点<ncol, nrow>是beg_node的邻节点
      // 并且它已经被evisit访问过
      // 因此bq和eq在此处相遇
      if (!bvisit[ncol][nrow] && evisit[ncol][nrow]) {
        bfather[ncol][nrow] = beg_node;
        return BidirectionalPath(bfather, efather, beg, end,
                                 BfsNode(ncol, nrow));
      }
      if (!bvisit[ncol][nrow] && !evisit[ncol][nrow]) {
        // 点<ncol, nrow>尚未被bq和eq访问过
        bq.push_back(BfsNode(ncol, nrow));
        bvisit[ncol][nrow] = 1;
        bfather[ncol][nrow] = beg_node;
      }
    }

    /* 后扩展eq */
    BfsNode end_node = eq.front();
    eq.pop_front();
    for (int i = 0; i < 4; i++) {
      int ncol = end_node.col + col_dir[i];
      int nrow = end_node.row + row_dir[i];

      if (!in_range(ncol, m) || !in_range(nrow, n)) {
        continue;
      }

      // 点<ncol, nrow>是end_node的邻节点
      // 并且它已经被bvisit访问过
      // 因此bq和eq在此处相遇
      if (!evisit[ncol][nrow] && bvisit[ncol][nrow]) {
        efather[ncol][nrow] = end_node;
        return BidirectionalPath(bfather, efather, beg, end,
                                 BfsNode(ncol, nrow));
      }
      if (!evisit[ncol][nrow] && !bvisit[ncol][nrow]) {
        // 点 <ncol, nrow> 尚未被 bq 和 eq
        // 访问过
        eq.push_back(BfsNode(ncol, nrow));
        evisit[ncol][nrow] = 1;
        efather[ncol][nrow] = end_node;
      }
    }
  }

  // never reach here
  return {};
}

