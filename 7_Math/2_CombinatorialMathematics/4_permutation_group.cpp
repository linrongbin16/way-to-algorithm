//置换群
//permutation_group.cpp

//给出长度为n的一个序列s，其中从1到n每个数字都会出现且仅出现一次
//比如序列s有10个数字从1到10，s = {4, 5, 3, 7, 2, 8, 1, 6, 10, 9}
//将该序列作为一个置换准则序列
//再给出一些其他长度相同的序列t = {a, b, c, d, e, f, g, h, i, j}和一个数字k
//求出序列t以序列s作为置换准则，经过k次置换之后的状态
//每次置换过程中，序列t的第i个成员t[i]变为第s[i]个成员t[s[i]]，其中1 <= i <= n
//比如10个成员的序列t经过1次以s为置换准则的置换后变为
//t = {g, e, c, a, b, h, d, f, j, i}，注意这里的成员号从1到10

//显然不能通过暴力的循环k次来求出最后t的状态，当k是一个较大的整数时时间复杂度过高
//
//我们来单独的考察上面这个例子中序列t开始时的第1个成员t[1]，即a
//第1次置换，由于s[1] = 4，t[1]即a被挪到t[4]的位置，即t[4] = a
//第2次置换，由于s[4] = 7，t[4]即a被挪到t[7]的位置，即t[7] = a
//第3次置换，由于s[7] = 1，t[7]即a被挪到t[1]的位置，即t[1] = a
//序列s总是具有这样的性质，其中每个成员不需要暴力的枚举k次循环，而是存在一个周期
//通过上面的计算可以得出序列s中s[1]，s[4]，s[7]的周期是3
//即序列t上位于1，4，7这三个位置的成员每经过3次置换操作，就会回到原来自己的位置
//因此，预先计算出长度为n的序列s上每个位置的周期
//再计算序列t即可快速的得到序列t的最终状态

#include "general_head.h"
#include "com_local.h"

void permutation_group(int *s, int n, int *t, int k, int *f)
{//序列s和t都有n个成员，下标都从1到n
 //求出序列t以s为置换准则，经过k次置换后的状态，存储于数组f中
	//cycle[i]指代s[i]的周期
	int cycle[MAX];
	memset(cycle, 0, MAX * sizeof(int));
	for(int i = 1; i <= n; ++ i){
		if(cycle[i] == 0){
			//求s[i]的周期数cycle[i]
			int top(0), pos(i), cnt(0);
			int tmp[MAX];
			memset(tmp, 0, MAX * sizeof(int));
			do{
				//pos指代置换的当前位置，初始时pos从s序列的第i个位置开始
				tmp[top] = pos;
				++ cnt;
				++ top;
				//pos的下一个位置是s[pos]
				//即比如s = {4, 5, 3, 7, 2, 8, 1, 6, 10, 9}
				//pos = 1时，pos的下一个位置是s[pos] = s[1] = 4
				//再下一个位置是s[pos] = s[4] = 7
				//再下一个位置是s[pos] = s[7] = 1，即一个循环周期结束
				//cnt累加记录一个周期的循环次数
				//top累加记录属于该周期的s成员号
				pos = s[pos];
			}while(pos != i);
			//所有该周期的成员都被赋值为cnt
			for(int j = 0; j < top; ++ j)
				cycle[tmp[j]] = cnt;
		}
	}
	for(int i = 1; i <= n; ++ i){
		int pos(i);
		for(int j = 0; j < k % cycle[i]; ++ j)
			//序列t中成员i只需要循环k % cycle[i]次即可，不需要暴力循环k次
			pos = s[pos];
		f[pos] = t[i];
	}
}
