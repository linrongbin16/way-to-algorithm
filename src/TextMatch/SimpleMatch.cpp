// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#include "SimpleMatch.hpp"
#include <cassert>
#include <iostream>
using namespace std;

#define TEST_MAX 1024

struct Test {
    string text;
    string str;
    vector<int> pos;
} tests[] = {{"asdfasdfasdfasdf", "asdf", {0, 4, 8, 12}},
             {"asdfasdfasdfasdf", "asdf", {0, 4, 8, 12}}};

int main(void)
{
    for (int i = 0; i < sizeof(tests) / sizeof(Test); i++) {
        Test &t = tests[i];
        assert(SimpleMatch(t.text, t.str) == t.pos);
    }
    return 0;
}
