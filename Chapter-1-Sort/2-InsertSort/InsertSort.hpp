#ifndef SORT_INSERT_SORT_HPP
#define SORT_INSERT_SORT_HPP 1

#ifndef MAX
#define MAX 60
#endif


/**
 * 将无序序列s升序排列
 * @params s            无序序列
 * @params end          序列s的末尾下标加1，即左闭右开区间[beg, end)
 * @params end          序列s的末尾下标加1
 */
void InsertSort(int s[MAX], int beg, int end)
{
    for (int j = beg+1; j < end; ++j) {
        int i = j-1;
        int tmp = s[i + 1];
        /* s[0]到s[j]找到i，满足s[j-1]<=s[i+1]<=s[j]注意j==-1的临界情况 */
        while(j >= beg && s[j] > tmp)
            --j;
        //将s[i+1]插入s[j]位置
        for(int k = i; k >= j + 1; --k)
            s[k + 1] = s[k];
        s[j + 1] = tmp;
    }
}

#endif
