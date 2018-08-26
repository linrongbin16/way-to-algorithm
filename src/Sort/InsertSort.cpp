// MIT License
// Copyright 2017- linrongbin16@gmail.com

#include "InsertSort.h"

void InsertSort(int *s, int beg, int end) {
	for (int j = beg + 1; j < end; j++) {
		int i;
		int p = s[j];
		//s[0]到s[j]找到i，满足s[i-1]<=p<=s[i]
		//注意i=beg时不存在s[i-1]的情况
		for (i = beg; i < j; i++) {
			if (i == beg && p <= s[i])
				break;
			else if (i > beg && s[i - 1] <= p && p <= s[i])
				break;
		}
		//i即为p将被插入的位置
		//将[i,j-1]之间的元素向右移动一位
		for (int k = j; k > i; k--)
			s[k] = s[k - 1];
		s[i] = p;
	}
}
