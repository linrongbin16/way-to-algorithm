#ifndef SEARCH_BRUTE_FORCE_H
#define SEARCH_BRUTE_FORCE_H 1
//暴力枚举
//brute force

//序列s中有n个成员 每个成员有m种选择
//当n个成员每个人都作出一种选择后 组成了一种序列 这样不同的组合有m^n个
//比如数组s[4]，它的每个元素都可以选择0到2这三个数字中的任何一个
//那么会有以下这些排列
//[0 0 0 0]
//[1 0 0 0] [0 1 0 0] [0 0 1 0] [0 0 0 1]
//[1 1 0 0] [1 0 1 0] [1 0 0 1] [0 1 1 0] [0 1 0 1] [0 0 1 1]
//[1 1 1 0] [1 1 0 1] [1 0 1 1] [0 1 1 1]
//[1 1 1 1]
//[2 0 0 0] [0 2 0 0] [0 0 2 0] [0 0 0 2]
//...
//寻找所有这样的序列组合

//1)基础概念
//加法原理
//完成一件事有n类方法
//第1类方法中有m1种方法
//第2类方法中有m2种方法
//...
//第n类方法中有mn种方法
//则完成这件事共有m1+m2+...+mn种方法
//乘法原理
//完成一件事有n个步骤
//第1步有m1种方法
//第2步有m2种方法
//第n步有mn种方法
//则完成这件事共有m1*m2*...*mn种方法
//
//2)具体实现
//通过循环枚举出序列中每个成员的所有选择
//每个成员的选择变化一次都是一种新的组合


#ifndef MAX
#define MAX 60
#endif
#include <iostream>
using namespace std;

void brute_print(int s[MAX], int beg, int end)
{
    //[beg, end)是左闭右开区间 序列s下标从beg到end-1
	for (int i = beg; i < end; ++i)
		cout << s[i] << " ";
	cout << endl;
}

void brute_force(int s[MAX], int n, int m) 
{
    //序列s有n个成员 下标从0到n-1 每个成员s[i]有m种选择
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
						brute_print(s, 0, n);
					}
}


#endif
