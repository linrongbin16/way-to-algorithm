#ifndef DATASTRUCTURE_PREFIX_TREE_H
#define DATASTRUCTURE_PREFIX_TREE_H 1
//前缀树
//prefix tree

//前缀树也叫字典树 是一种典型的以空间换时间的算法
//典型的用法是统计一组字符串中某个字符串出现的次数
//我们只考虑a-z这26个小写字母
//前缀树的每个节点包含以下几个部分 子节点指针数组 本节点字符 字符串终止符
//本节点字符是字符串中本节点所在的字符
//子节点指针数组用来表明在字符串中 本字符的下一个字符
//字符串终止符表示从根节点到当前节点是一个字符串 也可以标记该字符串出现的次数


#include <iostream>
#include <cstring>
#include <string>
using std::string;
using std::cout;
using std::endl;
struct prefix_tree_node
{
	char m_value;	//字符本身
	int m_count;	//该字符串出现次数
	string m_final;	//该字符作为字符串的最后一个字符 这个字符串的值
	prefix_tree_node *m_children[26];	//下一个字符

	prefix_tree_node()
	{
		m_value = 0;
		m_count = 0;
		for (int i = 0; i < 26; ++i)
			m_children[i] = 0;
	}
};

void prefix_tree_init(prefix_tree_node *root) 
{//实际上我们在节点构造函数中已经完成了这些代码，这里是为了保证C语言代码风格
	root->m_value = 0;
	root->m_count = 0;
	root->m_final = "";
	for (int i = 0; i < 26; ++i)
		root->m_children[i] = 0;
}
void prefix_tree_insert(prefix_tree_node *root, char *str)
{
	prefix_tree_node *p = root;
	char *s = str;
	int index;
	for (int i = 0; i < (int)strlen(s); ++i) {
		index = s[i] - 'a';
		if (p->m_children[index] == 0) {
			p->m_children[index] = new prefix_tree_node();
			p->m_children[index]->m_value = s[i];
		}
		p = p->m_children[index];
		if (i == (int)strlen(s) - 1) {
			++p->m_count;
			p->m_final = string(str);
		}
	}
}
int prefix_tree_find(prefix_tree_node *root, char *str)
{//寻找字符串str，若不存在则返回0，存在则返回该字符串出现次数
	prefix_tree_node *p = root;
	char *s = str;
	int index;
	for (int i = 0; i < (int)strlen(s); ++i) {
		index = s[i] - 'a';
		p = p->m_children[index];
		if (i == (int)strlen(s) - 1 && p->m_final == string(str))
			return(p->m_count);
	}
	return(0);
}
void prefix_tree_delete(prefix_tree_node *root, char *str)
{//我们不处理该字符串str不存在的异常情况，认为该字符串str一定存在并且删除
	prefix_tree_node *p = root;
	char *s = str;
	int index;
	for (int i = 0; i < (int)strlen(s); ++i) {
		index = s[i] - 'a';
		p = p->m_children[index];
		if (i == (int)strlen(s) - 1) {
			p->m_count = 0;
			p->m_final = "";
		}
	}
}
void prefix_tree_print(prefix_tree_node *root)
{
	prefix_tree_node *p = root;
	if (p->m_count)
		cout << p->m_final << endl;
	for (int i = 0; i < 26; ++i)
		if (p->m_children[i])
			prefix_tree_print(p->m_children[i]);
}


#endif
