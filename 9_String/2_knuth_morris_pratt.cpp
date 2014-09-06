//KMP算法
//knuth_morris_pratt.cpp

//在较长的文本中查找一个字符串

//KMP算法与原始的字符串匹配算法的最大区别就是
//避免了原始算法中查找的字符串中的回溯
//其中使用了前缀函数来计算查找字符串的相同前缀和后缀
//从而实现了避免回溯
//1)本文直接引用“KMP算法”(作者“海子”)的代码
//这也是网上关于KMP算法最为流行的一种实现
//2)另外给出算法导论上的伪代码
//虽然算法导论中对字符数组下标的计算从1开始，但在测试中我发现该代码确实无法使用
//所以最终还是推荐第一种方法
//
//本文引用了“KMP算法”，作者“海子”

#include "general_head.h"
void compute_prefix_function1(string s, int *prefix);
void compute_prefix_function2(string s, int *prefix);

//1)网上流行的一种计算prefix数组的方法

void knuth_morris_pratt1(string s, string t, vector<int>& pos)
{//字符串s在文本t中进行匹配
 //返回字符串在文本中匹配到的子串的数量和位置，存储于数组pos中
	pos.clear();
	int prefix[MAX];
	compute_prefix_function1(s, prefix);

	for(int i = 0;  i < s.length() + 2; ++ i)
		cout << prefix[i] << ' ';
	cout << endl;

	int i = 0, j = 0;
	while(i < (int)t.length()){
		if(j == -1 || t[i] == s[j]){
			++ i;
			++ j;
		}
		else
			j = prefix[j];
		if(j == (int)s.length()){
			pos.push_back(i - j);
			j = 0;
		}
	}
}
void compute_prefix_function1(string s, int *prefix)
{
	int i = 0, j = -1;
	prefix[0] = -1;
	while(i < (int)s.length()){
		if(j == -1 || s[i] == s[j])
			prefix[++ i] = ++ j;
		else
			j = prefix[j];
	}
}

//算法导论的伪代码

void knuth_morris_pratt2(string s, string t, vector<int>& pos)
{
	pos.clear();
	int prefix[MAX];
	compute_prefix_function1(s, prefix);

	int j = 0;
	for(int i = 1; i <= (int)t.length(); ++ i){
		while(j > 0 && s[j + 1] != t[i])
			j = prefix[j];
		if(s[j + 1] == t[i])
			++ j;
		if(j == (int)s.length()){
			pos.push_back(i - j + 1);
			//j = prefix[j];
			j = 0;
		}
	}
}
void compute_prefix_function2(string s, int *prefix)
{
	prefix[1] = 0;
	int j = 0;
	for(int i = 2; i <= (int)s.length(); ++ i){
		while(j > 0 && s[j + 1] != s[i])
			j = prefix[j];
		if(s[j + 1] == s[i])
			++ j;
		prefix[i] = j;
	}
}
