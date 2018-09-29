#include "Util.h"
#include <cassert>
#include <string>
#include <unordered_set>

std::vector<int> IntArrayToVector(int *s, int n) {
  std::vector<int> result;
  for (int i = 0; i < n; i++) {
    result.push_back(s[i]);
  }
  return result;
}

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

/* 4个方向: 上 下 右 左 */
/* m列n行二维方格 col范围[0, m) row范围[0, n) */
int col_dir[4] = {0, 0, 1, -1};
int row_dir[4] = {1, -1, 0, 0};

BfsNode::BfsNode() : col(0), row(0), block(false) {}

BfsNode::BfsNode(int col, int row, bool block)
    : col(col), row(row), block(block) {}

bool operator==(const BfsNode &a, const BfsNode &b) {
  return a.col == b.col && a.row == b.row;
}

bool operator!=(const BfsNode &a, const BfsNode &b) { return !(a == b); }

void AssertAdjacent(const BfsNode &a, const BfsNode &b) {
  bool a1 = (a.row == b.row) && (a.col == b.col + 1);
  bool a2 = (a.row == b.row) && (a.col == b.col - 1);
  bool a3 = (a.row == b.row + 1) && (a.col == b.col);
  bool a4 = (a.row == b.row - 1) && (a.col == b.col);
  assert(a1 || a2 || a3 || a4);
}

