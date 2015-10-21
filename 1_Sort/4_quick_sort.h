#ifndef SORT_QUICK_SORT_H
#define SORT_QUICK_SORT_H 1
//快速排序
//quick sort

//用快速排序算法将未序序列s从小到大排序

#include <algorithm>
using std::swap;
#ifndef MAX
#define MAX 60
#endif

//1
//将s[beg]设为哨兵元素
//将s中其余元素中所有比哨兵小的放s[0]左边 所有比哨兵大的放s[0]右边
//即可得到两段未排序的子序列 再用相同方法递归的处理子序列
//即可得到已序序列s
//时间复杂度O(N*logN)
int partion1(int s[MAX], int beg, int end)
{
    //[beg, end]为左闭右闭区间 序列s下标从beg到end
    //哨兵pivot
    int pivot = s[beg];
    while (beg < end) {
        while (beg < end && s[end] >= pivot)
            --end;
        s[beg] = s[end];
        while (beg < end && s[beg] <= pivot)
            ++beg;
        s[end] = s[beg];
    }
    //此时beg下标为哨兵pivot下标
    s[beg] = pivot;
    return(beg);
}
void quick_sort1(int s[MAX], int beg, int end)
{
    //[beg, end]为左闭右开区间 序列s下标从beg到end
    if (beg < end) {
        int mid = partion1(s, beg, end);
        quick_sort1(s, beg, mid);
        quick_sort1(s, mid + 1, end);
    }
}


//2
//TODO: 该算法有错误
//设置哨兵为s[end] i初始设置为beg-1 指向第一个大于当前主元的位置
//j从beg到end-1 每遇到一个比s[end]大的就交换i和j位置
//最后i+1的位置便是s[end]应在的位置
//时间复杂度O(N*logN)
int partition2(int s[MAX], int beg, int end)
{
    int p = s[end];
    int i = beg - 1;
    for (int j = beg; j < end-1; ++j) {
        if (s[j] <= p) {
            ++i;
			swap(s[i], s[j]);
        }
    }
	swap(s[i+1], s[end]);
    return i+1;
}
void quick_sort2(int s[MAX], int beg, int end)
{
    if (beg < end) {
		int mid = partition2(s, beg, end);
		quick_sort2(s, beg, mid-1);
		quick_sort2(s, mid+1, end);
	}
}


#endif
