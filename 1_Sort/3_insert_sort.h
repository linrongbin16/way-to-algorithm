#ifndef SORT_INSERT_SORT_H
#define SORT_INSERT_SORT_H 1
//插入排序
//insert sort

//用插入排序算法将无序序列s从小到大排序

//设s[0]到s[i](其中i>=0)是一个已经排序的序列
//原始状态下的s[0]可以看作只有一个元素的已序序列
//在s[0]到s[i]中找出位置j
//使得s[j]<=s[i+1]<=s[j+1] 将s[i+1]插入s[j]后面
//并将s[j+1]到s[i]统一向后挪动一个位置 其中注意j==-1时的临界情况
//即可将序列s整个排序

#ifndef MAX
#define MAX 60
#endif

void insert_sort(int s[MAX], int beg, int end)
{
    //[beg, end)为左闭右开区间 序列s下标从beg到end-1
    for (int i = beg; i < end - 1; ++i) {
        int j = i;
        int tmp = s[i + 1];
        //从s[0]到s[i]找到位置j满足s[j-1]<=s[i+1]<=s[j]注意j==-1的临界情况
        while(j >= beg && s[j] > tmp)
            --j;
        //将s[i+1]插入s[j]位置
        for(int k = i; k >= j + 1; --k)
            s[k + 1] = s[k];
        s[j + 1] = tmp;
    }
}

#endif
