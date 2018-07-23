// MIT License
// Copyright 2018 linrongbin16@gmail.com

#include "MergeSort.h"
#include "AscendUtil.h"
#include <iostream>
#include <cstdlib>
using namespace std;

#define TEST_MAX 1024
#define MAX 64

void AssertMergeSort(int *s, int n) {
    AssertNotAscend(s, n);
    MergeSort(s, 0, n);
    AssertAscend(s, n);
}

int main(void) {
    int s[MAX];
    for (int i = 0; i < TEST_MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            s[j] = rand() % TEST_MAX;
        }
        AssertMergeSort(s, MAX);
    }
    return 0;
}
