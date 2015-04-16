//原始字符串匹配
//naive_string_match.cpp

//在一个文本中寻找一个字符串
//称为字符串匹配问题

//文本编辑器中查找字符串是字符串匹配的典型应用场景
//文本text是一个很长的字符串，字符串str是一个较短的字符串
//比如文本为“asdf wehlisdfn ed qrqr”，在该文本中查找字符串“lis”：
//asdf wehlisdfn ed qrqr
//        lis
//字符串“lis”从文本text起点开始移动8个字符之后匹配到文本的第9到第11个字符“lis”
//则上述问题可以描述为在text[1...23]中有匹配str[1...3] = text[8+1...8+3]
//设字符串模式的长度为m，文本的长度为n，匹配位移s是字符串从文本起点开始移动s个位置
//匹配的一般形式为在text[1...n]中有str[1...m] = text[s+1...s+m]，其中0 <= s <= n - m
//原始字符串匹配从文本起点s = 0开始，依次遍历文本的每个字符，直到位移s = n - m
//比较每个字符处文本的子串与字符串是否相同
//代码的实现中数组下标从0开始
//因此字符串str和文本text也从0开始，变化为str[0...m-1]和text[1...n-1]

#include "general_head.h"

void naive_string_match(string s, string t, vector<int>& pos)
{//字符串s在文本t中进行匹配
 //返回字符串在文本中匹配到的子串数量和位置，存储于数组pos中
	pos.clear();
	//i是字符串匹配文本的位移
	int i(0);
	while(i <= (int)t.length() - (int)s.length()){
		int q(0);
		while(q < (int)s.length() && s[q] == t[i + q])
			++ q;
		if(q == (int)s.length())
			pos.push_back(i);
		++ i;
		//注意这里不可以出现这样的“优化”：
		//if(q == (int)s.length()){
		//	pos.push_back(i);
		//	i += (int)s.length();//在i处匹配也不能直接跳过字符串长度
		//						 //在本章测试用例中读者可以进行测试
		//						 //若这样“优化”会忽略可能出现的匹配位置
		//}
		//else
		//	++ i;
	}
}
