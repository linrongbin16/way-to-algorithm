#include "Util.h"
#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

bool StringEq(const std::string &s1, int p1, const std::string &s2, int p2,
              int len) {
  for (int i = 0; i < len; i++) {
    if (s1[p1 + i] != s2[p2 + i])
      return false;
  }
  return true;
}

