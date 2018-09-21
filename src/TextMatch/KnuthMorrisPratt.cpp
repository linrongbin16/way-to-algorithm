#include "KnuthMorrisPratt.h"
#include <string>
#include <vector>

static void GenNext(const std::string &pattern, int *next) {
  next[0] = -1;
  int i = 0, j = -1;
  while (i < pattern.length()) {
    if (j == -1 || pattern[i] == pattern[j]) {
      j++;
      i++;
      next[i] = j;
    } else {
      j = next[j];
    }
  }
}

std::vector<int> KnuthMorrisPratt(const std::string &text,
                                  const std::string &pattern) {
  std::vector<int> match;
  int next[MAX];
  GenNext(pattern, next);

  int i = 0;
  int j = 0;
  while (i < text.length()) {
    if (j == -1 || text[i] == pattern[j]) {
      i++;
      j++;
    } else {
      j = next[j];
    }
    if (j == pattern.length()) {
      match.push_back(i - j);
      j = 0;
    }
  }

  return match;
}

