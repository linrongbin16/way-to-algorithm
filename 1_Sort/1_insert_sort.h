#ifndef SORT_INSERT_SORT_H
#define SORT_INSERT_SORT_H 1
//插入排序
//insert sort

//用插入排序算法将无序序列s从小到大排序

//从序列s中第二个元素到最后一个元素，重复以下步骤：
//设该元素为第i个元素
//从第i-1到第1个元素倒着遍历前面已经排序的序列(初始时只有一个元素也可看做已序状态)
//找到位置j，满足s[j] <= s[i] <= s[j+1]，j元素是已序序列中第一个比i小的元素
//将j+1到i-1的所有元素向后挪动一个位置，第i-1个元素占用原i元素的位置
//将i元素放置在原j元素的位置
//最终可将序列s整个排序


void insert_sort(int *s, int beg, int end) 
{//[beg, end)为左闭右开区间，序列s下标从beg到end-1
	int i, j, k, tmp;
	for(i = beg + 1; i < end; ++ i){
		j = i - 1;
		while(j >= beg && s[j] > s[i])
			-- j;
		//当s[j]小于等于s[i]时
		//将s[i]插入原s[j + 1]的位置
		tmp = s[i];
		for(k = i; k > j + 1; --k)
			s[k] = s[k - 1];
		s[j + 1] = tmp;
	}
}


#endif
