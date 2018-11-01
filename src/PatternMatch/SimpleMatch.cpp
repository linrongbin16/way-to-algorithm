#include "SimpleMatch.h"
#include "Util.h"
#include <cassert>
#include <cstring>
#include <string>
#include <vector>

std::vector<int> SimpleMatch(const std::string &text,
                             const std::string &pattern) {
  std::vector<int> match;
  int i, j;

  for (i = 0; i < text.length(); i++) {
    if (StringEq(text, i, pattern, 0, pattern.length())) {
      match.push_back(i);
    }
  }
  return match;
}

