#include "KnuthMorrisPratt.h"
#include <string>
#include <vector>

static void PartialMatchFunction(const std::string &text, int *next) {
  next[0] = -1;
  next[1] = 0;
  for (int i = 1; i < text.length(); i++) {
    int k = i;
    while (k > 0 && text[i] != text[next[k]]) {
      k = next[k];
    }
    if (text[k + 1] == text[k]) {
      next[i] = k + 1;
    } else {
      next[i] = -1;
    }
  }
}

std::vector<int> KnuthMorrisPratt(const std::string &text,
                                  const std::string &pattern) {
  std::vector<int> match;
  int next[MAX];
  PartialMatchFunction(text, next);

  int i = 0;
  int j = 0;
  while (i < text.length()) {
    if (text[i] == pattern[j]) {
      i++;
      j++;
    } else if (i == 0) {
      i++;
    } else {
      i = next[i - 1] + 1;
    }
    if (j == pattern.length()) {
      match.push_back(i - j);
      j = 0;
    }
  }
  return match;
}
