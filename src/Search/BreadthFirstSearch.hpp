#pragma once

#include <deque>
#include <vector>
#include <cstring>
#ifndef MAX
#define MAX 64
#endif


//
// interface
//

struct Node {
  int col;
  int row;

  Node();
  explicit Node(int c, int r);
  friend bool operator==(const Node &a, const Node &b);
  friend bool operator!=(const Node &a, const Node &b);
};

std::vector<Node> BreadthFirstSearch(int m, int n, Node beg, Node end);


//
// implement
//

namespace detail {

  /* 4个方向: 上 下 右 左 */
  /* m列n行二维方格 col范围[0, m) row范围[0, n) */
  const int direction_col[4] = { 0, 0, 1, -1 };
  const int direction_row[4] = { 1, -1, 0, 0 };

  /* 递归生成从beg到end的路径 */
  void BFSPath(Node father[MAX][MAX], Node end, std::vector<Node> &path);
  bool InRange(int pos, int range);

}

/**
 * BreadthFirstSearch 广度优先搜索
 * @param m     列col
 * @param n     行row
 * @param beg   起点座标
 * @param end   终点座标
 * @return      从beg到end的搜索路径
 */
std::vector<Node> BreadthFirstSearch(int m, int n, Node beg, Node end) {

  Node father[MAX][MAX];
  int visit[MAX][MAX];
  memset(visit, 0, MAX * MAX * sizeof(int));
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
      father[i][j] = Node(i, j);

  std::deque<Node> que;
  que.push_back(beg);
  /* beg.col 范围是[0, m) */
  /* beg.row 范围是[0, n) */
  visit[beg.col][beg.row] = 1;

  while (!que.empty()) {
    Node node = que.front();
    que.pop_front();
    if (node == end) {
      std::vector<Node> path;
      detail::BFSPath(father, node, path);
      return path;
    }
    /* 上下左右4个方向 */
    for (int i = 0; i < 4; i++) {
      int neighbor_col = node.col + detail::direction_col[i];
      int neighbor_row = node.row + detail::direction_row[i];
      /* 检查边界和是否访问过/染红 */
      if (detail::InRange(neighbor_col, m)
          && detail::InRange(neighbor_row, n)
          && !visit[neighbor_col][neighbor_row]) {
        /* 加入等待队列 */
        que.push_back(Node(neighbor_col, neighbor_row));
        /* 染红 */
        visit[neighbor_col][neighbor_row] = 1;
        /* 记录父节点 */
        father[neighbor_col][neighbor_row] = Node(node.col, node.row);
      }
    }
  }

  return {};
}

Node::Node() : col(0), row(0) { }

Node::Node(int c, int r) : col(c), row(r) { }

bool operator==(const Node &a, const Node &b) {
  return a.col == b.col && a.row == b.row;
}

bool operator!=(const Node &a, const Node &b) {
  return a.col != b.col || a.row != b.row;
}


namespace detail {

  /* 递归生成从beg到end的路径 */
  void BFSPath(Node father[MAX][MAX], Node end, std::vector<Node> &path) {
    if (father[end.col][end.row] != end) {
      BFSPath(father, father[end.col][end.row], path);
    }
    path.push_back(end);
  }

  bool InRange(int pos, int range) {
    return pos >= 0 && pos < range;
  }

}
