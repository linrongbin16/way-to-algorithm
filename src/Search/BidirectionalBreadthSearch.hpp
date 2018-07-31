// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

#include <utility>
#include <cstring>
#include <cassert>
#include <vector>
#include <deque>


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

std::deque<Node> BidirectionalBreadthSearch(int m, int n, Node beg, Node end);


//
// implement
//

namespace detail {

  /* 4个方向：上下右左 */
  /* m行n列二维方格 col范围[0, m) row范围[0, n)*/
  const int direction_col[4] = { 1, -1, 0, 0 };
  const int direction_row[4] = { 0, 0, 1, -1 };

  std::deque<Node> BidirectionalPath(const std::vector<std::vector<Node>> &beg_father,
                                     const std::vector<std::vector<Node>> &end_father,
                                     Node beg,
                                     Node end,
                                     Node meet_pos);

  bool InRange(int pos, int range);
}

/**
 * BidirectionalBreadthSearch 双向广度搜索
 * @param m     列col
 * @param n     行row
 * @param beg   起点座标
 * @param end   终点座标
 * @return      从起点到终点的座标路径
 */
std::deque<Node> BidirectionalBreadthSearch(int m, int n, Node beg, Node end) {
  std::vector<std::vector<int>> beg_visit, end_visit;
  std::vector<std::vector<Node>> beg_father, end_father;

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
      beg_father[i][j] = Node(i, j);
      end_father[i][j] = Node(i, j);
    }
  }

  std::deque<Node> beg_que, end_que;
  beg_que.push_back(beg);
  end_que.push_back(end);
  /* x.col范围是[0, m) */
  /* x.row范围是[0, n) */
  beg_visit[beg.col][beg.row] = 1;
  end_visit[end.col][end.row] = 1;

  while (true) {
    /* 先扩展beg_que */
    Node beg_node = beg_que.front();
    beg_que.pop_front();
    for (int i = 0; i < 4; i++) {
      int neighbor_col = beg_node.col + detail::direction_col[i];
      int neighbor_row = beg_node.row + detail::direction_row[i];

      // 点<neighbor_col, neighbor_row>是beg_node的邻节点
      // 并且它已经被end_visit访问过
      // 因此beg_que和end_que在此处相遇
      if (detail::InRange(neighbor_col, m)
          && detail::InRange(neighbor_row, n)
          && !beg_visit[neighbor_col][neighbor_row]
          && end_visit[neighbor_col][neighbor_row]) {

        beg_father[neighbor_col][neighbor_row] = Node(beg_node.col, beg_node.row);
        std::deque<Node> path = detail::BidirectionalPath(beg_father, end_father, beg, end, Node(neighbor_col, neighbor_row));
        return path;
      } else if (detail::InRange(neighbor_col, m)
                 && detail::InRange(neighbor_row, n)
                 && !beg_visit[neighbor_col][neighbor_row]
                 && !end_visit[neighbor_col][neighbor_row]) {

        // 点<neighbor_col, neighbor_row>尚未被beg_que和end_que访问过
        beg_que.push_back(Node(neighbor_col, neighbor_row));
        beg_visit[neighbor_col][neighbor_row] = 1;
        beg_father[neighbor_col][neighbor_row] = Node(beg_node.col, beg_node.row);
      }
    }

    /* 后扩展end_que */
    Node end_node = end_que.front();
    end_que.pop_front();
    for (int i = 0; i < 4; i++) {
      int neighbor_col = end_node.col + detail::direction_col[i];
      int neighbor_row = end_node.row + detail::direction_row[i];

      // 点<neighbor_col, neighbor_row>是end_node的邻节点
      // 并且它已经被beg_visit访问过
      // 因此beg_que和end_que在此处相遇
      if (detail::InRange(neighbor_col, m)
          && detail::InRange(neighbor_row, n)
          && !end_visit[neighbor_col][neighbor_row]
          && beg_visit[neighbor_col][neighbor_row]) {

        end_father[neighbor_col][neighbor_row] = Node(end_node.col, end_node.row);
        std::deque<Node> path = detail::BidirectionalPath(beg_father, end_father, beg, end, Node(neighbor_col, neighbor_row));
        return path;
      } else if (detail::InRange(neighbor_col, m)
                 && detail::InRange(neighbor_row, n)
                 && !end_visit[neighbor_col][neighbor_row]
                 && !beg_visit[neighbor_col][neighbor_row]) {

        // 点 <neighbor_col, neighbor_row> 尚未被 beg_que 和 end_que 访问过
        end_que.push_back(Node(neighbor_col, neighbor_row));
        end_visit[neighbor_col][neighbor_row] = 1;
        end_father[neighbor_col][neighbor_row] = Node(end_node.col, end_node.row);
      }
    }
  }

  // never reach here
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

  std::deque<Node> BidirectionalPath(const std::vector<std::vector<Node>> &beg_father,
                                     const std::vector<std::vector<Node>> &end_father,
                                     Node beg,
                                     Node end,
                                     Node meet_pos) {
    std::deque<Node> path;
    Node t = meet_pos;
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
    return pos >= 0 && pos < range;
  }

}

