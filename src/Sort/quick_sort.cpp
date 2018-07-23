// MIT License
// Copyright 2018 linrongbin16@gmail.com
#include "quick_sort.h"


/**
* @brief Partion 
* 以s[low]为中间值，将所有小于等于s[low]的放在左边，
* 大于等于[low]的放在右边
*
* @param s[MAX]    无序序列
* @param low       序列s的起始下标
* @param high      序列s的末尾下标，即左闭右闭区间[low, high]
* @return          最终s[low]所在下标
*/
int partion(int *s, int low, int high) {
    int p = s[low];
    while (low < high) {
        while (low < high && s[high] >= p)
            --high;
        s[low] = s[high];
        while (low < high && s[low] <= p)
            ++low;
        s[high] = s[low];
    }
    s[low] = p;
    return low;
}

void quick_sort(int *s, int beg, int end) {
    if (beg < end-1) {
        int mid = partion(s, beg, end-1);
        quick_sort(s, beg, mid);
        quick_sort(s, mid+1, end);
    }
}

