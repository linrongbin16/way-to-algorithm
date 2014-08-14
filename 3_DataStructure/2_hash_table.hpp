//哈希表
//hash_table.hpp

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

//1)素数取模哈希

#include "general_head.h"

struct hash_node{
	int h_value;
	hash_node *h_next;
	hash_node(int cvalue = 0)
		: h_value(cvalue), h_next(NULL){
	}
};
struct hash_table{
private:
	//h_table数组中的节点均为单链头节点，不存储实际值
	hash_node h_table[MAX];
	int h_prime;
	int h_hash(int value){
		return(value % h_prime);
	}
public:
	hash_table(int cprime)
		: h_prime(cprime){
	}
	void h_insert(int r){
		//向哈希表中插入值为value的节点
		//用哈希函数计算出在值value在哈希表中对应的节点下标
		int idx = h_hash(r);
		hash_node *p = &h_table[idx];
		while(p->h_next != NULL)
			p = p->h_next;
		//直接将该点链入最末位置
		p->h_next = new hash_node(r);	
	}
	hash_node* h_find(int r){
		int idx = h_hash(r);
		hash_node *p = &h_table[idx];
		while(p->h_next != NULL){
			if(p->h_next->h_value == r)
				return(p->h_next);
			p = p->h_next;
		}
		return(NULL);
	}
	void h_delete(int r){
		//h_delete函数认为值value一定已经存储于哈希表
		//而不处理值value不存在的情况
		int idx = h_hash(r);
		hash_node *p = &h_table[idx];
		while(p->h_next->h_value != r)
			p = p->h_next;
		hash_node *del = p->h_next;
		p->h_next = p->h_next->h_next;	//链表中删除p->h_next点
		delete(del);
	}
	void h_print(){
		cout << "prime: " << h_prime << endl;
		for(int i = 0; i < h_prime; ++ i){
			cout << "key: " << i << ", node: ";
			hash_node *p = h_table[i].h_next;
			while(p != NULL){
				cout << p->h_value << ' ';
				p = p->h_next;
			}
			cout << endl;
		}	
	}
};

//2)BKDR哈希

struct bkdr_hash_table{
private:
	int b_table[MAX];
	int b_seed;
public:
	bkdr_hash_table(int seed = 131)	//种子可以是31 131 1313 13131 ...
		: b_seed(seed){
		memset(b_table, 0, sizeof(b_table));
	}
	int b_hash(char *str){
		int hash = 0;
		while(*str)
			hash = hash * b_seed + (*str++);
		hash = (hash & 0x7FFFFFFF) % MAX;
		return(hash);
	}
	void b_insert(int r){
		b_table[r] = 1;
	}
	void b_delete(int r){
		b_table[r] = 0;
	}
	bool b_find(int r){
		return(b_table[r]);
	}
};
