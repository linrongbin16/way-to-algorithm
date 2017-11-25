// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

#ifndef MAX
#define MAX 1024
#endif
#include <cstring>
#include <cassert>
#include <vector>


std::vector<int> SimpleMatch(const char *text, int tlen, const char *str, int slen) {
  std::vector<int> pos;
  for (int i = 0; i < tlen; i++) {
    bool match = true;
    for (int j = 0; j < slen; j++) {
      if (text[i+j] != str[j]) {
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
