// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

#ifndef MAX
#define MAX 1024
#endif
#include <cstring>
#include <cassert>
#include <vector>
#include <string>


std::vector<int> SimpleMatch(const std::string &text, const std::string &str) {
  std::vector<int> pos;
  for (int i = 0; i < text.length(); i++) {
    bool match = true;
    for (int j = 0; j < str.length(); j++) {
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
