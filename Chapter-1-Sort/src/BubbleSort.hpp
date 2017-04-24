#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H 1

#ifndef MAX
#define MAX 1024
#endif
#include <algorithm>
using namespace std;


/* ----------------------------------------------------------------------*/
/**
 * @brief BubbleSort 
 * 冒泡排序
 *
 * @param s[MAX]        无序序列
 * @param beg           序列s的起始下标
 * @param end           序列s的末尾下标加1，即左闭右开区间[beg, end)
 */
/* ----------------------------------------------------------------------*/
void BubbleSort(int s[MAX], int beg, int end)
{
    for (int i = end-1; i >= beg; --i)
        for (int j = beg; j < i; ++j)
            if (s[j] > s[j+1])
                swap(s[j], s[j+1]);
}


#endif
