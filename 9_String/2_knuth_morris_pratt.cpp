//KMP算法
//knuth_morris_pratt.cpp

//在较长的文本中查找一个字符串

//为了方便与代码中的数组下标统一，本文中字符串的下标都从0开始
//1)考虑一个文本"BBC ABCDAB ABCDABCDABDE"，在其中查找一个字符串"ABCDABD"
//i)从文本的起始处B开始匹配：
//BBC ABCDAB ABCDABCDABDE
//ABCDABD
//ii)第0个字符不同，将字符串移动到下一个字符B也不同，一直到第4个字符A(算空格)：
//BBC ABCDAB ABCDABCDABDE
//    ABCDABD
//字符串第字6符D不匹配，从0到5字符匹配，按照原始的方法应该继续匹配文本中的第5字符B
//但KMP算法与原始匹配算法的不同之处在于在这里使用前缀函数(先不考虑如何构造)
//本问题中的字符串的前缀函数prefix为：
//ABCDABD
//0000120
//当字符串移动到文本第4个字符A时
//下一次移动的距离 = 字符串中最后一个匹配的字符下标 - 该字符的前缀函数 + 1
//注意该公式中的下标都是按照数组下标计算的，从0开始
//这时字符串中最后一个匹配的是第5个字符B，因此下一次移动的距离 = 5 - 2 + 1 = 4
//其中5为最后一个匹配的字符B的下标，2为该字符前缀函数值
//iii)移动4个位置后字符串到达文本第8个字符A：
//BBC ABCDAB ABCDABCDABDE
//        ABCDABD
//字符串中第1个字符B是最后匹配的，应用前缀函数可知移动距离 = 1 - 0 + 1 = 2
//iv)移动2个位置后到达文本第10个字符' '：
//BBC ABCDAB ABCDABCDABDE
//          ABCDABD
//v)字符串第0个字符不匹配
//当字符串中没有匹配到的字符时，不使用前缀函数，直接后移一位
//BBC ABCDAB ABCDABCDABDE
//           ABCDABD
//vi)字符串中最后一个匹配的字符是第5个字符B
//移动距离 = 5 - 2 + 1 = 4，向后移动4个位置：
//BBC ABCDAB ABCDABCDABDE
//               ABCDABD
//字符串与文本第16个字符A匹配，算法结束
//
//2)前缀与后缀
//对于一个字符串x，如果有x = yz，其中y和z也是字符串(可以是空串)
//则称字符串y是x的前缀，且|y|<=|x|
//类似的字符串z是x的后缀，且|z|<=|x|
//比如字符串x = "abcd"，它的前缀字符串有""(空串)，"a"，"ab"，"abc"，"abcd"
//后缀字符串有""(空串)，"d"，"cd"，"bcd"，"abcd"
//
//2)有限自动机
//算法导论第32章字符串匹配32.3一节中有关于利用有限自动机进行字符串匹配的讲解
//算法导论该章中还有关于字符串匹配Rabin-Karp算法的讲解，本文中都不再做解释
//
//3)构造前缀函数
//考虑文本text为"bacbababaabcbab"，字符串str为"ababaca"：
//b a c b a b a b a a b c b a b
//        a b a b a c a
//前缀函数的数学解释也比较难懂，有兴趣的读者可以参考算法导论中相关的概念与定理
//最简单的解释就是对于字符串str设置一个数组prefix
//prefix[i]指代str中前i个字符的前缀函数值，即上文的前缀函数
//
//这里需要着重指出的是：prefix[i]数组中的i代表的意义是，字符串中前“i”个字符
//假设我们的字符串有n个字符
//当字符串数组从1开始，是一个从1到n的字符数组时
//prefix[i]表示[1...i]这段字符串的前缀函数，显然i的最小值为1
//[1...i]这段字符串已经匹配文本中的一段，而i+1这个字符破坏了匹配
//当字符串数组从0开始，是一个从0到n-1的字符数组时
//prefix[i]表示[0...i-1]这段字符串的前缀函数，显然i的最小值为0
//[0...i-1]这段字符串已经匹配文本中的一段，而i这个字符破坏了匹配
//
//这里重点提出来，大多数资料中将字符串从1开始计算，而编程时数组则从0开始
//在实际编程中非常容易搞混，希望读者可以注意这个细节
//例如对于字符串str"ababaca"
//它的prefix[5]的意思是str的前5个字母组成的子串"ababa"已经匹配了文本
//但是第6个字母"c"不匹配文本，现在只考虑已经匹配的子串"ababa"
//
//然后再来真正的考虑前缀函数的数学意义
//算法导论中原文是“子串(指字符串str的子串"ababa")的真后缀P的最长前缀的长度”
//这句难以理解的话就是前缀函数的核心
//以及公式prefix[q] = “max{k: k < q 且 Pk 后缀于 Pq}”
//其中Pk和Pq是匹配字符串"ababaca"的前k和前q个字符组成的字符串，Pk是Pq的后缀
//当q = 5时，Pq = "ababa"
//
//参考网络上一些文档的描述，可以得到的更容易理解的解释是：
//对于本文的字符串str的由前5个字符的子串"ababa"中
//它的真后缀有：""，"a"，"ba"，"aba"，"baba"，真子串不能与原字符串完全相同
//它的前缀有：""，"a"，"ab"，"aba"，"abab"，"ababa"
//在这前缀和真后缀的两个集合中，相同且长度最长的那个字符串就是"aba"
//它的长度3就是str的前5个字符组成的子串"ababa"的前缀函数值prefix[5]
//即本例子中prefix[5] = 3
//
//算法导论原书中有一个关于字符串"ababababca"的前缀函数的例子：
//a b a b a b a b c a
//0 0 1 2 3 4 5 6 0 1
//我们来用上述的解释来进行验证
//算法导论中的字符串是从1开始计数，与数组下标不同
//本文这里将算法导论中的下标记为q，而将本文自己定义的数组下标记为u
//
//q = 1, u = 0时子串为"a"，真后缀：{""}，前缀：{"","a"}
//相同的最长的字符串为""，长度0，prefix[q] = 0，prefix[u] = 0
//q = 2, u = 1时子串为"ab"，真后缀：{"","b"}，前缀：{"","a","ab"}
//相同的最长的字符串为""，长度0，prefix[q] = 0，prefix[u] = 0
//q = 3, u = 2时子串为"aba"，真后缀：{"","a","ba"}，前缀：{"","a","ab","aba"}
//相同的最长的字符串为"a"，长度1，prefix[q] = 1，prefix[u] = 1
//q = 4, u = 3时子串为"abab"，真后缀：{"","b","ab","bab"}
//前缀：{"","a","ab","aba","abab"}
//字符串为"ab"，长度2，prefix[q] = 2，prefix[u] = 0
//q = 5, u = 4时子串为"ababa"，真后缀：{"","a","ba","aba","baba"}
//前缀：{"","a","ab","aba","abab","ababa"}
//字符串为"aba"，长度3，prefix[q] = 3，prefix[u] = 3
//...
//q = 9, u = 8时子串为"ababababc"
//真后缀：{"","c","bc","abc","babc","ababc","bababc","abababc","babababc"}
//前缀：{"","a","ab","aba","abab","ababa","ababab","abababa","abababab","ababababc"}
//字符串为""，长度0，prefix[q] = 0，prefix[u] = 0
//q = 10时子串为"ababababca"
//真后缀：{"","a","ca","bca",...,"babababca"}
//前缀：{"","a","ab","aba",...,"ababababc","ababababca"}
//字符串为"a"，长度1，prefix[q] = 1，prefix[u] = 1
//
//由此可以验证前缀函数prefix[q]是匹配字符串中由前q个字符组成的子串中
//前缀和真后缀两个字符串集合中相同的，且长度最长的字符串的长度
//
//计算匹配字符串str的每个字符的prefix即可得到本文开始使用的前缀函数数组
//
//4)前缀函数与移动位置
//在文本text的某个位移s处，文本匹配了字符串str的前q个字符
//即字符串str中从0到q-1字符匹配，第q字符不匹配(这里q是字符串下标)
//根据本文一开始的公式：
//下一次移动的距离 = 字符串中最后一个匹配的字符下标 - 该字符下标的前缀函数 + 1
//则有移动位移 = q-1 - prefix[q-1] + 1，当q = 0时不使用这个公式，直接移动1位
//可以化为：
//移动位移 = q - prefix[q-1]
//注意这里的q是字符串数组中不匹配的字符下标
//
//本文忠实的实现了算法导论中关于KMP算法的伪语言描述
//其中用于计算prefix数组的子函数compute_prefix_function是我自己的实现
//因为在重写算法导论中该子函数时发现该函数无法达到计算prefix数组的效果
//因此我将算法导论中该子函数的伪代码废弃不用
//
//本文引用了“字符串匹配的KMP算法”，作者“阮一峰”
//“KMP算法详解——适合初学KMP算法的朋友”，作者“Bill_Hoo”

#include "general_head.h"
void compute_prefix_function(string s, int *prefix);

void knuth_morris_pratt(string s, string t, vector<int>& pos)
{//字符串s在文本t中进行匹配
 //返回字符串在文本中匹配到的子串的数量和位置，存储于数组pos中
 	pos.clear();
	int prefix[MAX];
	//计算字符串s的前缀函数prefix
	compute_prefix_function(s, prefix);
	int i(0);
	while(i < (int)t.length()){
		int q(0);
		while(q < (int)s.length() && s[q] == t[i + q])
			++ q;
		if(q == (int)s.length())
			pos.push_back(i);
		if(q == 0)
			++ i;
		else
			//移动位移i = q - prefix[q - 1]
			//这里的q是字符串不匹配的字符下标
			i += q - prefix[q - 1];
	}
}
void compute_prefix_function(string s, int *prefix)
{
	int k;
	for(int i = 0; i < (int)s.length(); ++ i){
		for(int j = 0; j <= i; ++ j)
			//C++中int std::string::compare(int pos, int n,
			//		const string &s, int pos2, int n2) const;
			//比较当前string从pos位置起n个字符组成的子串
			//与s从pos2位置起n2个字符组成的子串，若相等返回0
			if(s.compare(0, j, s, i - j + 1, j) == 0)
				k = j;
		prefix[i] = k;
	}
}
//算法导论中被我废弃的伪代码
//void compute_prefix_function(string s, int *prefix)
//{
//	prefix[0] = 0;
//	int k(0);
//	for(int i = 1; i < (int)s.length(); ++ i){
//		//s中从0到i这个字符串s[0...i]
//		//的前缀和真后缀中相同且最长的子串的长度
//		while(k > 0 && s[k] != s[i])
//			k = prefix[k];
//		if(s[k] == s[i])
//			++ k;
//		prefix[i] = k;
//	}
//}
