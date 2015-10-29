#ifndef SORT_BUBBLE_SORT_H
#define SORT_BUBBLE_SORT_H 1
//冒泡排序
//bubble sort

//用冒泡排序算法将未序序列s从小到大排序

//外部循环从s[0]到倒数第二个元素s[length-2]
//对于循环的当前元素s[i]
//再进行一次内部循环
//从倒数第一个元素s[length-1]逆向到元素s[i]依次比较相邻两个元素
//总是将较小的放在前面
//最终可得到s从小到达排序

#ifndef MAX
#define MAX 60
#endif
#include <algorithm>
using std::swap;

void bubble_sort(int s[MAX], int beg, int end)
{
    //[beg, end)为左闭右开区间 序列s下标从beg到end-1
    for (int i = beg; i < end - 1; ++i)
        for (int j = end - 1; j > i; --j)
            if (s[j] < s[j - 1])
                swap(s[j], s[j - 1]);
}



#endif
