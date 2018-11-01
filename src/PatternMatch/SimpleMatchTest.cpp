#include "SimpleMatch.h"
#include <cassert>
#include <iostream>
using namespace std;

#define TEST_MAX 1024

struct Test {
  string text;
  string pattern;
  vector<int> pos;
} tests[] = {
    {"asdfasdfasdfasdf", "asdf", {0, 4, 8, 12}},
    {"sting", "in", {2}},
    {"abedget", "bed", {1}},
    {"aaaaaaaa", "aaa", {0, 1, 2, 3, 4, 5}},
    {"shherishers", "he", {2, 7}},
    {"helloworldgoodbyeworldthisisagoodbookformanycomputersciencestudentihop"
     "eyouenjoy",
     "oo",
     {11, 30, 34}},
    {"helloworldgoodbyeworldthisisagoodbookformanycomputersciencestudentihop"
     "eyouenjoy",
     "world",
     {5, 17}},
};

int main() {
  for (int i = 0; i < sizeof(tests) / sizeof(Test); i++) {
    Test &t = tests[i];
    assert(SimpleMatch(t.text, t.pattern) == t.pos);
  }
  return 0;
}

