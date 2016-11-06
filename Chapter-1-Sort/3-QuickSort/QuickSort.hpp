#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP 1

#ifndef MAX
#define MAX 1024
#endif
#include <algorithm>
using namespace std;


/* ----------------------------------------------------------------------*/
/**
 * @brief Partion 
 * 以s[start]为中间值，将所有小于等于s[start]的放在左边，
 * 大于等于[start]的放在右边
 *
 * @param s[MAX]        无序序列
 * @param start         起始下标
 * @param last
 * @param start         序列s的起始下标
 * @param last          序列s的末尾下标，即左闭右闭区间[start, last]
 * @return              最终s[start]所在下标
 */
/* ----------------------------------------------------------------------*/
int Partion(int s[MAX], int start, int last)
{
    int p = s[start];
    while (start < last) {
        while (start < last && s[last] >= p)
            --last;
        s[start] = s[last];
        while (start < last && s[start] <= p)
            ++start;
        s[last] = s[start];
    }
    s[start] = p;
    return start;
}

/* ----------------------------------------------------------------------*/
/**
 * @brief QuickSort 
 * 快速排序
 *
 * @param s[MAX]        无序序列
 * @param beg           序列s的起始下标
 * @param end           序列s的末尾下标加1，即左闭右开区间[beg, end)
 */
/* ----------------------------------------------------------------------*/
void QuickSort(int s[MAX], int beg, int end)
{
    if (beg < end-1) {
        int mid = Partion(s, beg, end-1);
        QuickSort(s, beg, mid);
        QuickSort(s, mid+1, end);
    }
}


#endif
