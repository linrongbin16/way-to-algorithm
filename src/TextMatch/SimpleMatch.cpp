// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#include "SimpleMatch.hpp"
#include <iostream>
#include <cassert>
using namespace std;

#define TEST_MAX 1024

struct Test {
  const char *text;
  const char *str;
  int pos[];
} tests = {
  { "asdfasdfasdfasdf", "asdf", { 0, 4, 8, 12 } },
  { "asdfasdfasdfasdf", "asdf", { 0, 4, 8, 12 } }
};

int main(void) {

  for (int i = 0; i < sizeof(tests) / sizeof(Test); i++) {
    Test &t = tests[i];
    assert(SimpleMatch(t.text, strlen(t.text), t.str, strlen(t.str)) == t.pos);
  }
  return 0;
}
