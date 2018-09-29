#include "BreadthFirstSearch.h"
#include <cstring>
#include <deque>
#include <vector>

/* 4个方向: 上 下 右 左 */
/* m列n行二维方格 col范围[0, m) row范围[0, n) */
const int direction_col[4] = {0, 0, 1, -1};
const int direction_row[4] = {1, -1, 0, 0};

Node::Node() : col(0), row(0) {}

Node::Node(int col, int row) : col(col), row(row) {}

bool operator==(const Node &a, const Node &b) {
  return a.col == b.col && a.row == b.row;
}

bool operator!=(const Node &a, const Node &b) {
  return a.col != b.col || a.row != b.row;
}

/* 递归生成从beg到end的路径 */
void BFSPath(Node father[MAX][MAX], Node end, std::vector<Node> &path) {
  if (father[end.col][end.row] != end) {
    BFSPath(father, father[end.col][end.row], path);
  }
  path.push_back(end);
}

bool InRange(int pos, int range) { return pos >= 0 && pos < range; }

std::vector<Node> BreadthFirstSearch(int m, int n, const Node &beg,
                                     const Node &end) {
  Node father[MAX][MAX];
  int visit[MAX][MAX];
  std::memset(visit, 0, MAX * MAX * sizeof(int));
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
      father[i][j] = Node(i, j);

  std::deque<Node> q;
  q.push_back(beg);
  /* beg.col范围是[0, m) */
  /* beg.row范围是[0, n) */
  visit[beg.col][beg.row] = 1;

  while (!q.empty()) {
    Node node = q.front();
    q.pop_front();
    if (node == end) {
      std::vector<Node> path;
      BFSPath(father, node, path);
      return path;
    }
    /* 上下左右4个方向 */
    for (int i = 0; i < 4; i++) {
      int neighbor_col = node.col + direction_col[i];
      int neighbor_row = node.row + direction_row[i];
      /* 检查边界和是否访问过/染红 */
      if (InRange(neighbor_col, m) && InRange(neighbor_row, n) &&
          !visit[neighbor_col][neighbor_row]) {
        /* 加入等待队列 */
        q.push_back(Node(neighbor_col, neighbor_row));
        /* 染红 */
        visit[neighbor_col][neighbor_row] = 1;
        /* 记录父节点 */
        father[neighbor_col][neighbor_row] = Node(node.col, node.row);
      }
    }
  }

  return {};
}

