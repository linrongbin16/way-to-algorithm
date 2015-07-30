//KMP算法
//knuth morris pratt

//在较长的文本中查找一个字符串

//KMP算法与原始的字符串匹配算法的最大区别就是
//通过使用回文next数组避免了原始算法中查找的字符串中的回溯
//其中使用前缀函数来计算查找字符串的相同前缀
//前缀函数prefix对于KMP算法是一个非常重要的概念
//该函数用于计算字符串的next数组 下面给出两个例子
//1)
//下标: 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
//字符: a g c t a g c a g c t a g c t g
//next: 0 0 0 0 1 2 3 1 2 3 4 5 6 7 4 0
//2)算法导论中的示例
//下标: 0 1 2 3 4 5 6 7 8 9
//字符: a b a b a b a b c a
//next: 0 0 1 2 3 4 5 6 0 1
//注意算法导论原书中这个例子的数组下标是从1到10 而非从0到9
//next[i]表示由从0到i组成的字符串中
//所有真前缀和真后缀中相同的字符串的最大长度的值
//注意真前缀和真后缀不能和原字符串完全相同 最多比原字符串的长度少1
//比如对于示例1 当i=6 next[6] = 3
//从0到6组成的字符串为"agctagc" 它有一个真前缀"agc" 真后缀"agc"
//该字符串的最长真前缀是"agctag" 最长真后缀是"gctagc"
//其中真前缀和真后缀相同的最长字符串即"agc" 长度为3 这就是next[6]的值
//而当i=0时 next[0] = 0
//从0到0组成的字符串为"a" 它的真前缀和真后缀都只有一个""(空字符串)
//长度为0 因此next[0] = 0
//这个规则对于第二个算法导论中的例子也完全适用
//
//但是由于字符串从0开始和从1开始的不同 实际编程中存在两种版本的前缀函数
//一种得到的是和上面所说的完全一致的next数组
//第二种方法得到的是整个后移一位 next[0]=-1的next数组
//比如对于字符串"agctagcagctagctg"
//第一种方法得到的next: 0 0 0 0 1 2 3 1 2 3 4 5 6 7 4 0
//第二种方法得到的next: -1 0 0 0 0 1 2 3 1 2 3 4 5 6 7 4 0
//在实际使用时必须把第一种方法得到的数组转化为第二种形式 即next[0]=-1
//才能够被KMP算法的主函数使用
//
//KMP算法的核心就在于对next数组的计算和使用
//但是这个部分的解释比较麻烦 因此本文只给出几个网上比较流行的文档
//"KMP算法" 作者"海子"
//"KMP算法的next[]数组通俗解释" 作者"山路水桥"
//
//本文引用了"KMP算法" 作者"海子"



#include "general_head.h"
void compute_prefix_function1(string s, int *next);
void compute_prefix_function2(string s, int *next);

void knuth_morris_pratt(string s, string t, vector<int>& pos)
{//字符串s在文本t中进行匹配
 //返回字符串在文本中匹配到的子串的数量和位置 存储于数组pos中
	pos.clear();
	int next[MAX];
	compute_prefix_function2(s, next);

	int i = 0, j = 0;
	while(i < (int)t.length()){
		if(j == -1 || t[i] == s[j]){
			++i;
			++j;
		}
		else
			j = next[j];
		if(j == (int)s.length()){
			pos.push_back(i - j);
			j = 0;
		}
	}
}

//1)第一种计算next数组的前缀函数实际上是算法导论中给出的伪代码
//不同之处仅仅在于算法导论原书中该伪代码的字符串下标是从1开始计算的
//在使用时需要把next数组整个后移一位 并且设置next[0]=-1

void compute_prefix_function1(string s, int *next)
{
	next[0] = 0;
	for(int i = 1; i < (int)s.length(); ++i){
		int k = next[i - 1];
		while(s[i] != s[k] && k != 0)
			k = next[k - 1];
		if(s[i] == s[k])
			next[i] = k + 1;
		else
			next[i] = 0;
	}
	//网上的很多文档其实并没有后面这一部分代码 本文加进去是保证next[0]=-1
	for(int i = (int)s.length(); i >= 1; --i)
		next[i] = next[i - 1];
	next[0] = -1;
}

//2)第二种计算next数组的前缀函数则是网上较为流行的一种方法 推荐使用该方法

void compute_prefix_function2(string s, int *next)
{
	int i = 0, j = -1;
	next[0] = -1;
	while(i < (int)s.length()){
		if(j == -1 || s[i] == s[j])
			next[++i] = ++j;
		else
			j = next[j];
	}
}
