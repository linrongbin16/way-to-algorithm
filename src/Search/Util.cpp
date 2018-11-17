#include "Util.h"
#include <cassert>
#include <string>
#include <unordered_set>

void AssertEq(int *s1, int n1, int *s2, int n2) {
  assert(n1 == n2);
  for (int i = 0; i < n1; i++)
    assert(s1[i] == s2[i]);
}

void AssertUnique(const std::vector<std::vector<int>> &v) {
  std::unordered_set<std::string> uniques;
  std::vector<std::string> v2;
  for (int i = 0; i < v.size(); i++) {
    std::string tmp;
    for (int j = 0; j < v[i].size(); j++) {
      tmp.append(std::to_string(v[i][j]));
    }
    v2.push_back(tmp);
  }
  for (int i = 0; i < v2.size(); i++) {
    assert(uniques.find(v2[i]) == uniques.end());
    uniques.insert(v2[i]);
  }
}

// 上下右左
int row_dir[4] = {1, -1, 0, 0};
int col_dir[4] = {0, 0, 1, -1};

BfsNode::BfsNode() : row(0), col(0) {}

BfsNode::BfsNode(int row, int col) : row(row), col(col) {}

bool operator==(const BfsNode &a, const BfsNode &b) {
  return a.row == b.row && a.col == b.col;
}

bool operator!=(const BfsNode &a, const BfsNode &b) { return !(a == b); }

void AssertAdjacent(const BfsNode &a, const BfsNode &b) {
  bool a1 = (a.row == b.row) && (a.col == b.col + 1);
  bool a2 = (a.row == b.row) && (a.col == b.col - 1);
  bool a3 = (a.row == b.row + 1) && (a.col == b.col);
  bool a4 = (a.row == b.row - 1) && (a.col == b.col);
  assert(a1 || a2 || a3 || a4);
}

