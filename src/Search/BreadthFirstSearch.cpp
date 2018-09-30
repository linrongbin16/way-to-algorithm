#include "BreadthFirstSearch.h"
#include "Util.h"
#include <cstring>
#include <deque>
#include <vector>

#define invalid (BfsNode(-1, -1))

// 生成从end到beg的路径
static std::vector<BfsNode> BFSPath(BfsNode father[MAX][MAX],
                                    const BfsNode &end) {
  std::vector<BfsNode> path;
  BfsNode i;
  for (i = end; i != father[i.col][i.row]; i = father[i.col][i.row]) {
    path.push_back(i);
  }
  path.push_back(i);
  return path;
}

std::vector<BfsNode> BreadthFirstSearch(int m, int n, const BfsNode &beg,
                                        const BfsNode &end) {
  BfsNode father[MAX][MAX];
  int visit[MAX][MAX];

  std::memset(visit, 0, sizeof(int) * MAX * MAX);
  std::memset(father, 0, sizeof(int) * MAX * MAX);
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
      father[i][j] = BfsNode(i, j);

  std::deque<BfsNode> q;
  q.push_back(beg);
  // beg.col范围是[0, m)
  // beg.row范围是[0, n)
  visit[beg.col][beg.row] = 1;

  while (!q.empty()) {
    BfsNode node = q.front();
    q.pop_front();
    if (node == end) {
      return BFSPath(father, node);
    }
    // 上下左右4个方向
    for (int i = 0; i < 4; i++) {
      int ncol = node.col + col_dir[i];
      int nrow = node.row + row_dir[i];

      // 检查边界
      if (!in_range(ncol, m) || !in_range(nrow, n)) {
        continue;
      }
      // 检查是否访问过/染红
      if (!visit[ncol][nrow]) {
        // 加入等待队列
        q.push_back(BfsNode(ncol, nrow));
        // 染红
        visit[ncol][nrow] = 1;
        // 记录父节点
        father[ncol][nrow] = node;
      }
    }
  }

  return {};
}

