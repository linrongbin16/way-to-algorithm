//哈希表
//hash_table.cpp

//实现哈希表

//哈希表
//一种根据键值直接访问内存存储位置的数据结构
//精心设计的哈希表效率非常高
//几乎所有数据结构在查询与插入一个元素时都要与已存储的元素进行至少O(lgn)次比较
//而哈希表通过设置哈希函数直接跳过了这个步骤，将操作效率减小至O(1)
//C++中将哈希表实作为hash_map容器，但实际C++编程中使用这个容器的人并不多
//
//哈希函数
//从值value到键key的映射函数key = f(value)
//存储与查询元素时先用哈希函数计算出值value对应的键key，key即为该值的存储位置
//实际的使用中会出现多个值映射出相同的键key，即键值冲突
//键值冲突问题没有办法真正解决
//但可以通过很多方法来构造不同性能的哈希函数，从而缓解键值冲突
//常见的设计方法有：直接定址法，平方取中法，折叠法，随机数法，除留取余法
//本文给出一个简单的素数取模哈希和一个常用于字符串处理的BKDR哈希
//
//为了方便，本章所有数据结构的实现中均不处理异常

#include "general_head.h"
#include "data_structure.h"
int _hash_seed;

//1)素数取模哈希

hash_node _hash_table1[MAX];
int _prime_hash(int value)
{
	return(value % _hash_seed);
}
void prime_hash_init(int prime)
{
	_hash_seed = prime;
}
void prime_hash_insert(int value)
{
	//向哈希表中插入值为value的节点
	//用哈希函数计算出在值value在哈希表中对应的节点下标
	int idx = _prime_hash(value);
	hash_node *p = &_hash_table1[idx];
	while(p->h_next != NULL)
		p = p->h_next;
	//直接将该点链入最末位置
	p->h_next = new hash_node(value);	
}
hash_node* prime_hash_find(int value)
{
	int idx = _prime_hash(value);
	hash_node *p = &_hash_table1[idx];
	while(p->h_next != NULL){
		if(p->h_next->h_value == value)
			return(p->h_next);
		p = p->h_next;
	}
	return(NULL);
}
void prime_hash_delete(int value)
{
	//prime_hash_delete函数认为值value一定已经存储于哈希表
	//而不处理值value不存在的异常情况
	int idx = _prime_hash(value);
	hash_node *p = &_hash_table1[idx];
	while(p->h_next->h_value != value)
		p = p->h_next;
	hash_node *del = p->h_next;
	p->h_next = p->h_next->h_next;	//链表中删除p->h_next点
	delete(del);
}
void prime_hash_print(int n)
{//打印素数取模哈希表
	for(int i = 0; i < n; ++ i){
		cout << "index " << i << ": ";
		hash_node *p = &_hash_table1[i];
		while(p->h_next != NULL){
			cout << p->h_next->h_value << ", ";
			p = p->h_next;
		}
		cout << endl;
	}
}

//2)BKDR哈希

int _hash_table2[MAX];
int bkdr_hash(char *s)
{
	int hash = 0;
	while(*s)
		hash = hash * _hash_seed + (*s++);
	hash = (hash & 0x7FFFFFFF) % MAX;
	return(hash);
}
void bkdr_hash_init(int seed = 131)
{//种子可以是31 131 1313 13131 ...
	memset(_hash_table2, 0, MAX * sizeof(int));
	_hash_seed = seed;
}
void bkdr_hash_insert(int value)
{
	_hash_table2[value]= 1;
}
void bkdr_hash_delete(int value)
{
	_hash_table2[value]= 0;
}
bool bkdr_hash_find(int value)
{
	return(_hash_table2[value]);
}
