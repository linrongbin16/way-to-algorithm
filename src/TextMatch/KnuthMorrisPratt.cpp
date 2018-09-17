#include "KnuthMorrisPratt.h"
#include <string>
#include <vector>

static void PartialMatchTable(const std::string &pattern, int *pmt) {
  pmt[0] = -1;
  pmt[1] = 0;
  for (int i = 1; i < pattern.length(); i++) {
    int k = i;
    while (k > 0 && pattern[i] != pattern[pmt[k]]) {
      k = pmt[k];
    }
    if (pattern[k + 1] == pattern[k]) {
      pmt[i] = k + 1;
    } else {
      pmt[i] = 0;
    }
  }
  pmt[0] = 0;
}

std::vector<int> KnuthMorrisPratt(const std::string &text,
                                  const std::string &pattern) {
  std::vector<int> match;
  int pmt[MAX];
  PartialMatchTable(pattern, pmt);

  int i = 0;
  int j = 0;
  while (i < text.length()) {
    if (text[i] == pattern[j]) {
      i++;
      j++;
    } else {
      i = pmt[i] + 1;
    }
    if (j == pattern.length()) {
      match.push_back(i - j);
      j = 0;
    }
  }
  return match;
}

