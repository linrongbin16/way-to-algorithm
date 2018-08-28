#pragma once
#ifndef MAX
#define MAX 64
#endif
#include <vector>

struct Node {
  int col;
  int row;

  Node();
  explicit Node(int c, int r);
  friend bool operator==(const Node &a, const Node &b);
  friend bool operator!=(const Node &a, const Node &b);
};

std::vector<Node> BreadthFirstSearch(int m, int n, Node beg, Node end);
