// Copyright 2017 zhaochenyou16@gmail.com

#ifndef SEARCH_BREADTHFIRSTSEARCH_HPP_
#define SEARCH_BREADTHFIRSTSEARCH_HPP_

#include <deque>
#include <vector>
#include <cstring>
using namespace std;
#ifndef MAX
#define MAX 64
#endif

struct Position {
  int col;
  int row;

  Position() : col(0), row(0) {}
  Position(int c, int r) : col(c), row(r) {}
  bool operator==(const Position & other) {
    return col == other.col and row == other.row;
  }
  bool operator!=(const Position & other) {
    return col != other.col or row != other.row;
  }
};

/* 4个方向: 上 下 右 左 */
/* m列n行二维方格 col范围[0, m) row范围[0, n) */
const int direction_col[4] = { 0, 0, 1, -1 };
const int direction_row[4] = { 1, -1, 0, 0 };

/* 递归生成从beg到end的路径 */
auto BFSPath(Position father[MAX][MAX],
              Position end,
              vector<Position> &path) -> void {
  if (father[end.col][end.row] != end) {
    BFSPath(father, father[end.col][end.row], path);
  }
  path.push_back(end);
}

auto InRange(int pos, int range) -> bool {
  return pos >= 0 and pos < range;
}

/**
 * BreadthFirstSearch 广度优先搜索
 * @param m     列col
 * @param n     行row
 * @param beg   起点座标
 * @param end   终点座标
 * @return      从beg到end的搜索路径
 */
auto BreadthFirstSearch(int m,
                        int n,
                        Position beg,
                        Position end) -> vector<Position> {
  Position father[MAX][MAX];
  int visit[MAX][MAX];
  memset(visit, 0, MAX * MAX * sizeof(int));
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
      father[i][j] = Position(i, j);

  deque<Position> que;
  que.push_back(beg);
  /* beg.col 范围是[0, m) */
  /* beg.row 范围是[0, n) */
  visit[beg.col][beg.row] = 1;

  while (!que.empty()) {
    Position node = que.front();
    que.pop_front();
    if (node == end) {
      vector<Position> path;
      BFSPath(father, node, path);
      return path;
    }
    /* 上下左右4个方向 */
    for (int i = 0; i < 4; i++) {
      int neighbor_col = node.col + direction_col[i];
      int neighbor_row = node.row + direction_row[i];
      /* 检查边界和是否访问过/染红 */
      if (InRange(neighbor_col, m)
                  and InRange(neighbor_row, n)
                  and not visit[neighbor_col][neighbor_row]) {
        /* 加入等待队列 */
        que.push_back(Position(neighbor_col, neighbor_row));
        /* 染红 */
        visit[neighbor_col][neighbor_row] = 1;
        /* 记录父节点 */
        father[neighbor_col][neighbor_row] = Position(node.col, node.row);
      }
    }
  }

  return vector<Position>();
}


#endif  // SRC_SEARCH_BREADTHFIRSTSEARCH_HPP_
