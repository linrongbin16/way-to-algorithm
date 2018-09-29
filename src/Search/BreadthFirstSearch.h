#pragma once
#ifndef MAX
#define MAX 128
#endif
#include <vector>

struct Node {
  int col;
  int row;

  Node();
  Node(int col, int row);
  friend bool operator==(const Node &a, const Node &b);
  friend bool operator!=(const Node &a, const Node &b);
};

/**
 * BreadthFirstSearch 广度优先搜索
 * @param m     列col
 * @param n     行row
 * @param beg   起点座标
 * @param end   终点座标
 * @return      从beg到end的搜索路径
 */
std::vector<Node> BreadthFirstSearch(int m, int n, const Node &beg,
                                     const Node &end);

