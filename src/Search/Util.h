#pragma once
#include <algorithm>
#include <vector>

std::vector<int> IntArrayToVector(int *s, int n);
void AssertEq(int *s1, int n1, int *s2, int n2);
void AssertUnique(const std::vector<std::vector<int>> &v);

struct BfsNode {
  int col;
  int row;

  BfsNode();
  BfsNode(int col, int row);
  friend bool operator==(const BfsNode &a, const BfsNode &b);
  friend bool operator!=(const BfsNode &a, const BfsNode &b);
};

namespace std {

template <> struct hash<BfsNode> {
  std::size_t operator()(const BfsNode &e) const {
    using std::hash;
    using std::size_t;

    return hash<int>()(e.col) ^ hash<int>()(e.row);
  }
};

} // namespace std

extern int col_dir[4];
extern int row_dir[4];

#ifndef in_range
#define in_range(pos, range) ((pos) >= 0 && (pos) < range)
#endif

void AssertAdjacent(const BfsNode &a, const BfsNode &b);

