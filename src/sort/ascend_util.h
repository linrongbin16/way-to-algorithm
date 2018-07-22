// MIT License
// Copyright 2018 linrongbin16@gmail.com

#pragma once
#include <cassert>
using namespace std;

void assert_not_ascend(const int *s, int n) {
    bool asc = true;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] > s[i + 1]) {
            asc = false;
            break;
        }
    }
    assert(!asc);
}

void assert_ascend(const int *s, int n) {
    bool asc = true;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] > s[i + 1]) {
            asc = false;
            break;
        }
    }
    assert(asc);
}
