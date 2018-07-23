// MIT License
// Copyright 2018 linrongbin16@gmail.com

#include "MergeSort.h"
#include <cstring>

void Merge(int *s, int start, int mid, int last) {
    int *t = new int[last-start+2];
    int i, j, k;

    for (i = start, j = mid+1, k = start; i <= mid && j <= last; k++) {
        if (s[i] <= s[j]) {
            t[k] = s[i];
            i++;
        } else {
            t[k] = s[j];
            j++;
        }
    }
    for (; i <= mid; ++i, ++k)
        t[k] = s[i];
    for (; j <= last; ++j, ++k)
        t[k] = s[j];

    std::memcpy(s+start, t+start, (last-start)*sizeof(int));
    delete[] t;
}

void MergeSort(int *s, int beg, int end) {
    int mid = (beg + end-1) / 2; 
    if (beg + 2 >= end) {
        Merge(s, beg, mid, end-1);
        return;
    }
    MergeSort(s, beg, mid+1);
    MergeSort(s, mid+1, end);
    Merge(s, beg, mid, end-1);
}
