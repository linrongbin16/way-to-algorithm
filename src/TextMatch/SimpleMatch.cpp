#include "SimpleMatch.h"
#include <cassert>
#include <cstring>
#include <string>
#include <vector>

std::vector<int> SimpleMatch(const std::string &text,
                             const std::string &pattern) {
  std::vector<int> pos;
  int i, j;

  for (i = 0; i < text.length(); i++) {
    for (j = 0; j < pattern.length(); j++) {
      if (text[i + j] != pattern[j]) {
        break;
      }
    }
    if (j == pattern.length()) {
      pos.push_back(i);
    }
  }
  return pos;
}

