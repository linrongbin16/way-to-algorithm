// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#ifndef SEARCH_BIDIRECTIONALBREADTHSEARCH_HPP
#define SEARCH_BIDIRECTIONALBREADTHSEARCH_HPP

#include <utility>
#include <deque>
#include <cstring>
#include <queue>
#include <cassert>
#include <vector>
using namespace std;

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

/* 4个方向：上下右左 */
/* m行n列二维方格 col范围[0, m) row范围[0, n)*/
const int direction_col[4] = { 1, -1, 0, 0 };
const int direction_row[4] = { 0, 0, 1, -1 };

auto BidirectionalPath(const vector<vector<Position>> &beg_father,
                        const vector<vector<Position>> &end_father,
                        Position beg,
                        Position end,
                        Position meet_pos) -> deque<Position> {
  deque<Position> path;
  Position t = meet_pos;
  while (t != beg) {
    path.push_front(t);
    t = beg_father[t.col][t.row];
  }
  path.push_front(beg);
  t = end_father[meet_pos.col][meet_pos.row];
  while (t != end) {
    path.push_back(t);
    t = end_father[t.col][t.row];
  }
  if (path.back() != end) {
    path.push_back(end);
  }
  return path;
}

auto InRange(int pos, int range) -> bool {
  return pos >= 0 and pos < range;
}

/**
 * BidirectionalBreadthSearch 双向广度搜索
 * @param m     列col
 * @param n     行row
 * @param beg   起点座标
 * @param end   终点座标
 * @return      从起点到终点的座标路径
 */
auto BidirectionalBreadthSearch(int m,
                                int n,
                                Position beg,
                                Position end) -> deque<Position> {
  vector<vector<int>> beg_visit, end_visit;
  vector<vector<Position>> beg_father, end_father;

  beg_visit.resize(n);
  end_visit.resize(n);
  beg_father.resize(n);
  end_father.resize(n);
  for (int i = 0; i < n; i++) {
    beg_visit[i].resize(m);
    end_visit[i].resize(m);
    beg_father[i].resize(m);
    end_father[i].resize(m);
    for (int j = 0; j < m; j++) {
      beg_visit[i][j] = 0;
      end_visit[i][j] = 0;
      beg_father[i][j] = Position(i, j);
      end_father[i][j] = Position(i, j);
    }
  }

  deque<Position> beg_que, end_que;
  beg_que.push_back(beg);
  end_que.push_back(end);
  /* x.col范围是[0, m) */
  /* x.row范围是[0, n) */
  beg_visit[beg.col][beg.row] = 1;
  end_visit[end.col][end.row] = 1;

  while (true) {
    /* 先扩展beg_que */
    Position beg_node = beg_que.front();
    beg_que.pop_front();
    for (int i = 0; i < 4; i++) {
      int neighbor_col = beg_node.col + direction_col[i];
      int neighbor_row = beg_node.row + direction_row[i];

      // 点<neighbor_col, neighbor_row>是beg_node的邻节点
      // 并且它已经被end_visit访问过
      // 因此beg_que和end_que在此处相遇
      if (InRange(neighbor_col, m)
                  and InRange(neighbor_row, n)
                  and not beg_visit[neighbor_col][neighbor_row]
                  and end_visit[neighbor_col][neighbor_row]) {
        beg_father[neighbor_col][neighbor_row] = Position(beg_node.col, beg_node.row);
        deque<Position> path = BidirectionalPath(beg_father,
                                                  end_father,
                                                  beg,
                                                  end,
                                                  Position(neighbor_col, neighbor_row));
        return path;
      } else if (InRange(neighbor_col, m)
                          and InRange(neighbor_row, n)
                          and not beg_visit[neighbor_col][neighbor_row]
                          and not end_visit[neighbor_col][neighbor_row]) {
        // 点<neighbor_col, neighbor_row>尚未被beg_que和end_que访问过
        beg_que.push_back(Position(neighbor_col, neighbor_row));
        beg_visit[neighbor_col][neighbor_row] = 1;
        beg_father[neighbor_col][neighbor_row] = Position(beg_node.col,
                                                          beg_node.row);
      }
    }

    /* 后扩展end_que */
    Position end_node = end_que.front();
    end_que.pop_front();
    for (int i = 0; i < 4; i++) {
      int neighbor_col = end_node.col + direction_col[i];
      int neighbor_row = end_node.row + direction_row[i];

      // 点<neighbor_col, neighbor_row>是end_node的邻节点
      // 并且它已经被beg_visit访问过
      // 因此beg_que和end_que在此处相遇
      if (InRange(neighbor_col, m)
                  and InRange(neighbor_row, n)
                  and not end_visit[neighbor_col][neighbor_row]
                  and beg_visit[neighbor_col][neighbor_row]) {
        end_father[neighbor_col][neighbor_row] = Position(end_node.col, end_node.row);
        deque<Position> path = BidirectionalPath(beg_father,
                                                  end_father,
                                                  beg,
                                                  end,
                                                  Position(neighbor_col, neighbor_row));
        return path;
      } else if (InRange(neighbor_col, m)
                          and InRange(neighbor_row, n)
                          and not end_visit[neighbor_col][neighbor_row]
                          and not beg_visit[neighbor_col][neighbor_row]) {
        // 点 <neighbor_col, neighbor_row> 尚未被 beg_que 和 end_que 访问过
        end_que.push_back(Position(neighbor_col, neighbor_row));
        end_visit[neighbor_col][neighbor_row] = 1;
        end_father[neighbor_col][neighbor_row] = Position(end_node.col,
                                                          end_node.row);
      }
    }
  }
  // never reach here
  return {};
}

#endif  // SEARCH_BIDIRECTIONALBREADTHSEARCH_HPP
