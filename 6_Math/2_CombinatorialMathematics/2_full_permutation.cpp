//全排列
//full_permutaion.cpp

//求序列s的所有成员的组合

//全排列的方法非常像深度优先搜索，同样通过递归技术实现

#include "general_head.h"
//brute_force.cpp
extern void print_status(int *s, int beg, int end);

void full_permutation(int *s, int n, int &cnt, int prev = 0)
{//数组s有n个成员，从0到n-1，对他们进行全排列，cnt初始应该为0
	if(prev == n){
		//将每种排列加入答案集
		print_status(s, 0, n);
		++ cnt;
		return;
	}
	for(int i = prev; i < n; ++ i){
		swap(s[prev], s[i]);
		full_permutation(s, n, cnt, prev + 1);
		swap(s[prev], s[i]);
	}
}




