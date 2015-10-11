//test

#include "0_classic_data_structure_introduction.h"
#include "1_hash_table.h"
#include "2_disjoint_set.h"
#include "3_binary_index_tree.h"
#include "4_segment_tree.h"
#include "5_leftist_tree.h"
#include "6_prefix_tree.h"
#include "7_suffix_tree.h"
#include "8_AVL_tree.h"
#include "9_red_black_tree.h"

int main()
{
	//prime hash table
	{
		cout << "hash table" << endl;
		prime_hash_table ht;
		prime_hash_init(&ht, 13);
		for(int i = 0; i < 30; ++ i)
			prime_hash_insert(&ht, i);
		prime_hash_print(&ht);
		prime_hash_node *p1 = prime_hash_find(&ht, 24);
		if(p1)
			cout << "find 24 in hash table: " << p1->m_value << endl;
		else
			cout << "can't find 24 in hash table" << endl;
		prime_hash_delete(&ht, 24);
		p1 = prime_hash_find(&ht, 24);
		cout << "after delete 24 from hash table" << endl;
		if(p1)
			cout << "find 24 in hash table: " << p1->m_value << endl;
		else
			cout << "can't find 24 in hash table" << endl;
		prime_hash_print(&ht);
	}

	//bkdr hash
	{
		cout << endl << "bkdr hash table" << endl;
		bkdr_hash_table bt;
		bkdr_hash_init(&bt, 31);
		char s1[] = "hello world";
		char s2[] = "henno hoood";
		char s3[] = "hh you wrong";
		char s4[] = "that's a test";
		int h1 = bkdr_hash(bt.m_seed, s1);
		int h2 = bkdr_hash(bt.m_seed, s2);
		int h3 = bkdr_hash(bt.m_seed, s3);
		int h4 = bkdr_hash(bt.m_seed, s4);
		cout << "string 1:" << endl << s1 << endl << "hash value: " << h1 << endl;
		cout << "string 2:" << endl << s2 << endl << "hash value: " << h2 << endl;
		cout << "string 3:" << endl << s3 << endl << "hash value: " << h3 << endl;
		cout << "string 4:" << endl << s4 << endl << "hash value: " << h4 << endl;
		cout << "insert string 1" << endl;
		bkdr_hash_insert(&bt, s1);
		if(bkdr_hash_find(&bt, s1))
			cout << "find string 1" << endl;
		else
			cout << "can't find string 1" << endl;
	}

	//segment tree
	{
		cout << endl << "segment tree [0, 10]" << endl;
		segment_tree_node *root = segment_tree_build(0, 10);
		segment_tree_insert(root, 2, 4);
		segment_tree_insert(root, 6, 9);
		cout << "insert [2, 4], [6, 9], length: " << segment_tree_length(root) << endl;
		segment_tree_print(root);
		segment_tree_insert(root, 5, 7);
		cout << "insert [5, 7], length: " << segment_tree_length(root) << endl;
		segment_tree_print(root);
	}
	
	{
	//binary index tree
	binary_index_tree bit;
	binary_index_tree_init(&bit);
	cout << endl << "binary index tree" << endl;
	for(int i = 1; i < 20; ++ i){
		cout << "array s[" << i << "] add " << 2 * i << endl;
		binary_index_tree_add(&bit, i, 2 * i);
	}
	cout << "array sum from 1 to 10: " << binary_index_tree_sum(&bit, 10) << endl;
	}

	//disjoint set
	{
		disjoint_set set;
		disjoint_set_init(&set);
		cout << endl << "disjoint set" << endl;
		cout << "union" << endl;
		for(int i = 0; i < 10; ++ i){
			cout << "number " << i << " and " << 3 * i << " is in one set" << endl;
			disjoint_set_union(&set, i, 3 * i);
		}
		cout << "query" << endl;
		if(disjoint_set_query(&set, 1, 27))
			cout << "number 1 and 27 in one set" << endl;
		else
			cout << "number 1 and 27 not in one set" << endl;
		if(disjoint_set_query(&set, 2, 18))
			cout << "number 2 and 18 in one set" << endl;
		else
			cout << "number 2 and 18 not in one set" << endl;
		if(disjoint_set_query(&set, 2, 21))
			cout << "number 2 and 21 in one set" << endl;
		else
			cout << "number 2 and 21 not in one set" << endl;
	}
	
	//leftist tree
	{
	cout << endl << "leftist tree" << endl;
	leftist_tree_node tr[51];
	for(int i = 0; i < 51; ++ i)
		tr[i].m_index = i;
	//left child: &tr[6];
	tr[6].m_leftchild = &tr[11]; tr[6].m_leftchild = &tr[8]; tr[6].m_depth = 2;
	tr[11].m_leftchild = &tr[17]; tr[11].m_leftchild = &tr[14]; tr[11].m_depth = 2;
	tr[17].m_leftchild = &tr[18]; tr[17].m_leftchild = &tr[20]; tr[17].m_depth = 1;
	tr[14].m_leftchild = &tr[19]; tr[14].m_leftchild = &tr[24]; tr[14].m_depth = 1;
	tr[8].m_leftchild = &tr[10]; tr[8].m_leftchild = &tr[13]; tr[8].m_depth = 1;
	tr[10].m_leftchild = &tr[15]; tr[10].m_leftchild = &tr[30]; tr[10].m_depth = 1;
	tr[13].m_leftchild = &tr[28];
	//right child: &tr[7];
	tr[7].m_leftchild = &tr[9]; tr[7].m_leftchild = &tr[12]; tr[7].m_depth = 2;
	tr[9].m_leftchild = &tr[21]; tr[9].m_leftchild = &tr[16]; tr[9].m_depth = 1;
	tr[12].m_leftchild = &tr[31]; tr[12].m_leftchild = &tr[26]; tr[12].m_depth = 1;
	tr[31].m_leftchild = &tr[42]; tr[31].m_leftchild = &tr[33]; tr[31].m_depth = 1;
	tr[42].m_leftchild = &tr[50];
	tr[26].m_leftchild = &tr[27];
	cout << "tree lt:" << endl;
	leftist_tree_print(&tr[6]);
	cout << "tree rt:" << endl;
	leftist_tree_print(&tr[7]);

	cout << endl << "after lt merge rt:" << endl;
	leftist_tree_node *root2 = leftist_tree_merge(&tr[6], &tr[7]);
	leftist_tree_print(root2);

	cout << endl << "after pop the top node:" << endl;
	root2 = leftist_tree_pop(root2);
	leftist_tree_print(root2);

	cout << endl << "after push node 3:" << endl;
	root2 = leftist_tree_push(root2, 3);
	leftist_tree_print(root2);
	}
	
	//avl tree
	{
		cout<<endl << "avl test :"<<endl;
		AVLTree<int> te;
		for (int i=0;i<10;i++)
		{
			te.insert(i);
		}
		te.Treversal();
		cout << endl;
	}
	//red black tree
	{
		cout<< endl << "reb black tree test :"<<endl;
		RedBlackTree p;
		cout<<p.Find(4)<<endl;
		p.Insert(9);
		p.Insert(37);
		p.Insert(4);
		p.Insert(53);
		p.Insert(6);
		p.Insert(45);
		p.Insert(1);
		p.InOrderTraverse();
		p.Delete(9);
		p.InOrderTraverse();
		cout<<p.Find(4)<<endl;
		p.Delete(4);
		cout<<p.Find(4)<<endl;
		p.InOrderTraverse();
		p.Insert(9);
		p.Insert(37);
		p.InOrderTraverse();
	}

	//prefix tree
	{
		cout << endl << endl << "prefix tree" << endl;
		prefix_tree_node *pfnode = new prefix_tree_node();
		prefix_tree_init(pfnode);
		char str1[] = "hello";
		char str2[] = "ok";
		char str3[] = "dontworry";
		char str4[] = "happy";
		char str5[] = "hello";
		char str6[] = "letmedown";
		char str7[] = "pppppppp";
		char str8[] = "thisisatest";
		char str9[] = "ok";
		char str10[] = "happy";
		prefix_tree_insert(pfnode, str1);
		prefix_tree_insert(pfnode, str2);
		prefix_tree_insert(pfnode, str3);
		prefix_tree_insert(pfnode, str4);
		prefix_tree_insert(pfnode, str5);
		prefix_tree_insert(pfnode, str6);
		prefix_tree_insert(pfnode, str7);
		prefix_tree_insert(pfnode, str8);
		prefix_tree_insert(pfnode, str9);
		prefix_tree_insert(pfnode, str10);
		cout << "find \"" << str1 << "\":" << prefix_tree_find(pfnode, str1) << endl;
		cout << "find \"" << str2 << "\":" << prefix_tree_find(pfnode, str2) << endl;
		cout << "find \"" << str3 << "\":" << prefix_tree_find(pfnode, str3) << endl;
		cout << "prefix print:" << endl;
		prefix_tree_print(pfnode);
		prefix_tree_delete(pfnode, str1);
		prefix_tree_delete(pfnode, str3);
		prefix_tree_delete(pfnode, str8);
		prefix_tree_delete(pfnode, str10);
		cout << "find \"" << str5 << "\":" << prefix_tree_find(pfnode, str5) << endl;
		cout << "find \"" << str6 << "\":" << prefix_tree_find(pfnode, str6) << endl;
		cout << "find \"" << str7 << "\":" << prefix_tree_find(pfnode, str7) << endl;
		cout << "find \"" << str8 << "\":" << prefix_tree_find(pfnode, str8) << endl;
		cout << "prefix print:" << endl;
		prefix_tree_print(pfnode);
	}
	return(0);
}
