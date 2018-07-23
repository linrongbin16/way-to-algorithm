// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#include "quick_sort.h"
#include "ascend_util.h"
#include <iostream>
#include <cstdlib>
using namespace std;

#define TEST_MAX 1024
#define MAX 64

void assert_quick_sort(int *s, int n) {
    assert_not_ascend(s, n);
    quick_sort(s, 0, n);
    assert_ascend(s, n);
}

int main(void) {
    int s[MAX];
    for (int i = 0; i < TEST_MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            s[j] = rand() % TEST_MAX;
        }
        assert_quick_sort(s, MAX);
    }
    return 0;
}

