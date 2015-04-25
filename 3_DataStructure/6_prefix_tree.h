#ifndef DATASTRUCTURE_PREFIX_TREE_H
#define DATASTRUCTURE_PREFIX_TREE_H 1
//前缀树
//prefix tree

//前缀树也叫字典树，是一种简单的以空间换时间的算法
//典型的用法是统计一组字符串中某个字符串出现的次数
//假设我们只考虑a-z这26个小写字母
//前缀树的每个节点包含以下几个部分：子节点指针数组，本节点字符，字符串终止符
//本节点字符是字符串中本节点所在的字符
//子节点指针数组用来表明在字符串中，本字符的下一个字符
//字符串终止符表示从根节点到当前节点是一个字符串，也可以标记该字符串出现的次数


#include <iostream>
#include <cstring>
#include <string>
using std::string;
using std::cout;
using std::endl;
#ifndef MAX
#define MAX 26
#endif
struct prefix_tree_node
{
	char _value;	//字符本身
	int _count;		//该字符串出现次数
	string _final;	//该字符作为字符串的最后一个字符，这个字符串的值
	prefix_tree_node *_children[MAX];	//下一个字符

	prefix_tree_node()
	{
		_value = 0;
		_count = 0;
		_final = "";
		memset(_children, 0, MAX * sizeof(prefix_tree_node));
	}
	prefix_tree_node(const prefix_tree_node& node)
	{
		_value = node._value;
		_count = node._count;
		_final = node._final;
		memcpy((void*)_children, (void*)node._children, MAX * sizeof(prefix_tree_node));
	}
	prefix_tree_node& operator=(const prefix_tree_node& node)
	{
		_value = node._value;
		_count = node._count;
		_final = node._final;
		memcpy((void*)_children, (void*)node._children, MAX * sizeof(prefix_tree_node));
		return(*this);
	}
};

void prefix_tree_init(prefix_tree_node& root) 
{//实际上我们在节点构造函数中已经完成了这些代码，这里是为了保证C语言代码风格
	root._value = 0;
	root._count = 0;
	root._final = "";
	memset(root._children, 0, MAX * sizeof(prefix_tree_node));
}
void prefix_tree_insert(prefix_tree_node& root, char *str)
{
	prefix_tree_node *p = &root;
	char *s = str;
	int index;
	for (int i = 0; i < (int)strlen(s); ++i) {
		index = s[i] - 'a';
		if (p->_children[index] == (prefix_tree_node*)0) {
			p->_children[index] = new prefix_tree_node();
			p->_children[index]->_value = s[i];
		}
		p = p->_children[index];
		if (i == (int)strlen(s) - 1) {
			++p->_count;
			p->_final = string(str);
		}
	}
}
int prefix_tree_find(prefix_tree_node root, char *str)
{//寻找字符串str，若不存在则返回0，存在则返回该字符串出现次数
	prefix_tree_node *p = &root;
	char *s = str;
	int index;
	for (int i = 0; i < (int)strlen(s); ++i) {
		index = s[i] - 'a';
		p = p->_children[index];
		if (i == (int)strlen(s) - 1 && p->_final == string(str))
			return(p->_count);
	}
	return(0);
}
void prefix_tree_delete(prefix_tree_node& root, char *str)
{//我们不处理该字符串str不存在的异常情况，认为该字符串str一定存在并且删除
	prefix_tree_node *p = &root;
	char *s = str;
	int index;
	for (int i = 0; i < (int)strlen(s); ++i) {
		index = s[i] - 'a';
		p = p->_children[index];
		if (i == (int)strlen(s) - 1) {
			p->_count = 0;
			p->_final = "";
		}
	}
}
void prefix_tree_print(prefix_tree_node root)
{
	prefix_tree_node *p = &root;
	if (p->_count)
		cout << p->_final << endl;
	for (int i = 0; i < MAX; ++i)
		if (p->_children[i])
			prefix_tree_print(*(p->_children[i]));
}


#endif
