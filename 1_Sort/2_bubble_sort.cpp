//冒泡排序
//bubble_sort.cpp

//用冒泡排序算法将无序序列s从小到大排序

//序列s从第一个元素到倒数第二个元素，重复以下步骤 1：
//设步骤1中当前元素为第i个元素
//从最后一个元素逆序到元素i的后一个元素i+1，重复以下步骤 2：
//设步骤2中当前元素为第j个元素
//将j和它前面的元素j-1进行比较，较小者在前而较大者在后
//最终可将s排序

#include "general_head.h"

void bubble_sort(int *s, int beg, int end) 
{//[beg, end)为左闭右开区间，序列s下标从beg到end-1
	for(int i = beg; i < end - 1; ++ i)
		for(int j = end - 1; j > i; -- j)
			if(s[j] < s[j - 1])
				swap(s[j], s[j - 1]);
}
