//二分查找法，也称折半查找法
//binary_search.cpp

//在从小到大排序的序列s中查找元素x是否存在
//若存在找出元素x的下标，若不存在x则找出比x小且距离最近的元素的下标

//设置low，high，mid三个标志位
//初始时low是序列s中第一个元素，high是最后一个元素，mid为low和high的中间元素
//若查找的元素x等于mid元素则返回结果
//若x < s[mid]则x在low到mid之间，将high更新为mid-1继续新一轮比较
//若x > s[mid]则x在mid到high之间，将low更新为mid+1继续新一轮比较
//直到找到x元素为止
//当low > high时说明排除所有可能后仍没有找到x，说明不存在x返回0

#include "general_head.h"

bool binary_search(int *s, int x, int beg, int end, int& idx)
{//[beg, end)是左闭右开区间，s为已序序列，下标从beg到end-1，查找元素值x
 //idx返回查找的下标，返回bool标志查找成功与否，若查找不成功返回最接近x且比x小的元素下标
	int low(beg), high(end - 1), mid((beg + end - 1) / 2);
	while(s[mid] != x && low <= high){
		if(s[mid] > x)
			high = mid - 1; 
		else if(s[mid] < x)
			low = mid + 1;
		mid = (low + high) / 2;
	}
	idx = mid;
	if(s[mid] == x)
		return(true);
	else
		return(false);
}










