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

