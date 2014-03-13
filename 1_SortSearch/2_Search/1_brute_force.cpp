//暴力枚举
//brute_force.cpp

//给定集合s中有n个成员，每个成员有m种选择
//当这n个成员每个人都作出一种选择后，组成了一个序列，显然这样不同的组合有m^n个
//在给定集合s中寻找所有这样的排列组合
//比如数组s[4]，它的每个元素都可以选择0到2这三个数字中的任何一个
//显然{1,0,0,0},{0,1,0,0}这两个序列是两种不同的排列组合方式

//1)基础概念
//加法原理：完成一件事，有n类方法
//第1类方法中有m1种方法
//第2类方法中有m2种方法
//第n类方法中有mn种方法，则完成这件事共有 m1+m2+...+mn 种方法
//乘法原理：完成一件事，有n个步骤
//第1步有m1种方法
//第2步有m2种方法
//第n步有mn种方法，则完成这件事共有 m1*m2*...*mn 种方法
//
//2)具体实现
//通过循环枚举出序列中每个成员的所有选择
//每个成员的选择变化一次都是一种新的组合，将其加入答案集中

#include "general_head.h"
void print_status(int *s, int beg, int end);

void brute_force(int *s, int n, int m) 
{//序列s有n个成员，下标从0到n-1，每个成员s[i]有m种选择
	for(int i0 = 0; i0 < m; ++ i0)
		for(int i1 = 0; i1 < m; ++ i1)
			for(int i2 = 0; i2 < m; ++ i2)
				//...序列s共有n个成员...
					for(int in_1 = 0; in_1 < m; ++ in_1){
						//s中每个成员作出一次选择
						s[0] = i0;
						s[1] = i1;
						s[2] = i2;
						//...
						s[n - 1] = in_1;

						//将这次选择加入答案集
						print_status(s, 0, n);
					}
}
void print_status(int *s, int beg, int end)
{//[beg, end)是左闭右开区间，序列s下标从beg到end-1
	for(int i = beg; i < end; ++ i)
		cout << s[i] << ' ';
	cout << endl;
}




