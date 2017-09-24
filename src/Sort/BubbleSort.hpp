#ifndef SORT_BUBBLE_SORT_H
#define SORT_BUBBLE_SORT_H

#include <vector>
#include <algorithm>
using namespace std;


/**
 * @brief BubbleSort 冒泡排序
 * @param s[MAX]    无序序列
 * @param beg       序列s的起始下标
 * @param end       序列s是左闭右开区间[beg, end)
 */

auto BubbleSort(vector<int> &s, int beg, int end) -> void
{
    for (int i = end-1; i >= beg; --i)
        for (int j = beg; j < i; ++j)
            if (s[j] > s[j+1])
                swap(s[j], s[j+1]);
}


#endif
