#ifndef SORT_QUICK_SORT_H
#define SORT_QUICK_SORT_H 1
//快速排序
//quick sort

//用快速排序算法将未序序列s从小到大排序

//将s[0]设为哨兵元素
//将s中其余元素中所有比哨兵小的放s[0]左边 所有比哨兵大的放s[0]右边
//即可得到两段未排序的子序列 再用相同方法递归的处理子序列
//直到子序列长度<=3时 直接进行排序 这样的操作时间复杂度视为O(1)
//即可得到已序序列s


int quick_sort_partion(int *s, int beg, int end) 
{//[beg, end]为左闭右闭区间 序列s下标从beg到end
    //哨兵pivot
	int pivot = s[beg];
	while(beg < end){
		while(beg < end && s[end] >= pivot)
			--end;
		s[beg] = s[end];
		while(beg < end && s[beg] <= pivot)
			++beg;
		s[end] = s[beg];
	}
    //此时beg下标为哨兵pivot下标
	s[beg] = pivot;
	return(beg);
}

void quick_sort(int *s, int beg, int end) 
{//[beg, end)为左闭右开区间 序列s下标从beg到end-1
	if(beg < end - 1){
		int mid = quick_sort_partion(s, beg, end - 1);
		quick_sort(s, beg, mid);
		quick_sort(s, mid + 1, end);
	}
}


#endif
