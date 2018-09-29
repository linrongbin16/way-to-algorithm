#pragma once
#include <vector>

std::vector<int> IntArrayToVector(int *s, int n);
void AssertEq(int *s1, int n1, int *s2, int n2);
void AssertUnique(const std::vector<std::vector<int>> &v);

struct BfsNode {
  int col;
  int row;
  bool block;

  BfsNode();
  BfsNode(int col, int row, bool block);
  friend bool operator==(const BfsNode &a, const BfsNode &b);
  friend bool operator!=(const BfsNode &a, const BfsNode &b);
};

extern int col_dir[4];
extern int row_dir[4];

void AssertAdjacent(const BfsNode &a, const BfsNode &b);

