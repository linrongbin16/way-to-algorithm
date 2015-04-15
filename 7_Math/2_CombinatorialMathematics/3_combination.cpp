//组合
//combination.cpp

//序列s有n个成员，从中选出m(m < n)个成员，有多少种组合

//将有n个成员的序列s中被选中的成员看作该成员取值为1，未被选中的成员看作取值为0
//比如s有5个成员，从中选出3个，则有一种方式为s = {1, 1, 1, 0, 0}
//还有一种方式为s = {1, 1, 0, 0, 1}

#include "general_head.h"
#include "com_local.h"
//1)全排列方法
//当n=3，m=1，可选择的组合有3种：{1, 0, 0}, {0, 1, 0}, {0, 0, 1}
//当n=4，m=2，可选择的组合有：{1, 1, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}...
//组合问题是一种特殊的全排列
//对于这样的序列s = {1, 2, 3}，有6种全排列：
//{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}
//当我们将其中{1, 2, 3}和{1, 3, 2}的后面两个数字2，3看作0时
//可以发现这两个都是{1, 0, 0}，实际上全排列是将这两个0看作不同的两个数字
//但在组合中这两个0是相同的
//因此用本节全排列的算法就可以找出所有组合可能，但是其中会有重复的组合

//brute_force.cpp
extern void print_status(int *s, int beg, int end);

void combination1(int *s, int n, int m, int prev)
{//序列s有n个成员，下标从0到n-1
 //求出从中选取m个成员的所有可能，被选取的成员为1，未被选取的成员为0
	if(prev == n){
		print_status(s, 0, n);
		return;
	}
	for(int i = prev; i < n; ++ i){
		swap(s[prev], s[i]);
		combination1(s, n, m, prev + 1);
		swap(s[prev], s[i]);
	}
}

//2)深度优先搜索方法
//本书第二章中深度优先搜索算法也可以解决这个问题
//实际上本书第二章中深度优先搜索就是解决了一个排列组合类的问题
//假设序列s有3个成员，每个成员可以取值0，1，2，3，则序列s的状态有：
//{0, 0, 0}, {0, 0, 1}, {0, 0, 2}, {0, 0, 3}, {0, 1, 0}, {0, 1, 1}...
//这个形式很像一个四进制的三位数，每一位上满4进1位
//将深度优先搜索算法应用于本文的组合问题时，序列s的n个成员
//每个成员的取值是0或1，而当s中恰好有m个取值为1的成员时成为一个组合

bool is_combination(int *s, int n, int m);

void combination2(int *s, int n, int m, int prev )
{
	if(prev == n){
		if(is_combination(s, n, m))
			//检查取值为1的成员数是否为m
			print_status(s, 0, n);
		return;
	}
	for(int i = 0; i < 2; ++ i){
		//成员prev只能取值0或1
		s[prev] = i;
		combination2(s, n, m, prev + 1);
	}
}
bool is_combination(int *s, int n, int m)
{
	int cnt(0);
	for(int i = 0; i < n; ++ i)
		if(s[i])
			++ cnt;
	if(cnt == m)
		return(true);
	else
		return(false);
}

//3)高效组合算法
//这个算法是真正专门应用于组合问题的
//其计算效率也最高，前两个方法在实际中无法满足时间复杂度的要求
//对于序列s，初始时将前m个成员都取值1，其余为0，作为第1个组合
//之后重复以下步骤：
//在序列s中找到第1个这样的两个相邻的成员s[i]和s[i+1]
//其中s[i] = 1且s[i+1] = 0，即这两个相邻成员组成了一个“10”组合
//将这个“10”组合交换位置变成“01”
//再将该“01”组合之前的所有“1”都挪到序列s的起始处
//比如对于s = {0, 1, 1, 1, 0}，第一个“10”组合是s[3]和s[4]，将其交换位置
//得到s = {0, 1, 1, 0, 1}，再将“01”之前的两个“1”放置在序列s的起始处
//即有s = {1, 1, 0, 0, 1}，这样即可得到一个新的组合
//重复上述步骤，直到无法继续找出这样的“10”组合即可

bool next_combination(int *s, int n);

void combination3(int *s, int n, int m)
{
	//初始时s序列前m个成员取值1，其余为0
	for(int i = 0; i < n; ++ i)
		s[i] = (i < m) ? 1 : 0;
	do{
		print_status(s, 0, n);
	}while(next_combination(s, n));
	//若存在“10”组合则求出下一个序列s的组合并返回true
	//若没有“10”组合算法结束
}
bool next_combination(int *s, int n)
{
	for(int i = 0; i < n - 1; ++ i)
		if(s[i] == 1 && s[i + 1] == 0){
			//在s序列中找到“10”组合s[i]和s[i+1]两成员
			swap(s[i], s[i + 1]);
			int cnt(0);
			//求出s[i]成员之前，即s中从0到i-1有多少成员取1值
			for(int j = 0; j < i; ++ j)
				if(s[j])
					++ cnt;
			//将s中前cnt个成员赋值为1，其余到i之前的成员赋值为0
			for(int j = 0; j < i; ++ j)
				s[j] = (j < cnt) ? 1 : 0;
			return(true);
		}
	//若没有“10”组合算法结束
	return(false);
}
