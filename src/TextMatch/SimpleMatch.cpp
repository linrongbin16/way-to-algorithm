#include "SimpleMatch.h"
#include <cassert>
#include <cstring>
#include <string>
#include <vector>

std::vector<int> SimpleMatch(const std::string &text,
                             const std::string &pattern) {
  std::vector<int> pos;
  for (int i = 0; i < text.length(); i++) {
    bool match = true;
    for (int j = 0; j < pattern.length(); j++) {
      if (text[i + j] != pattern[j]) {
        match = false;
        break;
      }
    }
    if (match) {
      pos.push_back(i);
    }
  }
  return pos;
}
