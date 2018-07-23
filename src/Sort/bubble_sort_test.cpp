// MIT License
// Copyright 2018 linrongbin16@gmail.com

#include "bubble_sort.h"
#include "ascend_util.h"
#include <iostream>
#include <cstdlib>
using namespace std;

#define TEST_MAX 1024
#define MAX 64

void assert_bubble_sort(int *s, int n) {
    assert_not_ascend(s, n);
    bubble_sort(s, 0, n);
    assert_ascend(s, n);
}

int main(void) {
    int s[MAX];
    for (int i = 0; i < TEST_MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            s[j] = rand() % TEST_MAX;
        }
        assert_bubble_sort(s, MAX);
    }
    return 0;
}
