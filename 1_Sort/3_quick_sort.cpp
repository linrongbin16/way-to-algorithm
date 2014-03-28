//快速排序
//quick_sort.cpp

//用快速排序算法将无序序列s从小到大排序

//将序列中第一个元素设为基准元素
//将所有比它小的元素放在基准元素左边，所有比它大的放在右边
//由此分别得到两段未排序的子序列，再用相同方法递归的处理子序列
//直到子序列长度为3时，比基准元素小的元素只有1个，比它大的元素也只有1个
//即可得到已序序列s

#include "general_head.h"
int partion(int *s, int beg, int end);

void quick_sort(int *s, int beg, int end) 
{//[beg, end)为左闭右开区间，序列s下标从beg到end-1
	if(beg < end - 1){
		int mid = partion(s, beg, end - 1);
		quick_sort(s, beg, mid);
		quick_sort(s, mid + 1, end);
	}
}
int partion(int *s, int beg, int end) 
{//[beg, end]为左闭右闭区间，序列s下标从beg到end
	int pivot = s[beg];
	int tmp = s[beg];
	while(beg < end){
		while(beg < end && s[end] >= pivot)
			-- end;
		s[beg] = s[end];
		while(beg < end && s[beg] <= pivot)
			++ beg;
		s[end] = s[beg];
	}
	s[beg] = tmp;
	return(beg);
}











