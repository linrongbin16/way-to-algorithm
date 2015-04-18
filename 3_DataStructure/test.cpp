//test

#include "general_head.h"
#include "data_structure.h"
#include "AVL.h"

//prime_hash_table
extern void prime_hash_init(int prime);
extern void prime_hash_insert(int value);
extern hash_node* prime_hash_find(int value);
extern void prime_hash_delete(int value);
extern void prime_hash_print(int n);//for test
//bkdr_hash_table
extern int bkdr_hash(char *s);
extern void bkdr_hash_init(int seed = 131);
extern void bkdr_hash_insert(int value);
extern void bkdr_hash_delete(int value);
extern bool bkdr_hash_find(int value);
//segment_tree
extern seg_node* segment_tree_build(int beg, int end);
extern void segment_tree_insert(seg_node *root, int beg, int end);
extern int segment_tree_length(seg_node *root);
extern void segment_tree_print(seg_node *root);//for test
//binary_index_tree
extern void binary_index_tree_init();
extern void binary_index_tree_add(int i, int value);
extern int binary_index_tree_sum(int i);
//disjoint_set
extern void disjoint_set_init();
extern void disjoint_set_union(int p1, int p2);
extern bool disjoint_set_query(int p1, int p2);
//leftist_tree
extern left_node* leftist_tree_merge(left_node *a, left_node *b);
extern int leftist_tree_top(left_node *root);
extern left_node* leftist_tree_push(left_node *root, int value);
extern left_node* leftist_tree_pop(left_node *root);
extern void leftist_tree_print(left_node *root);//for test
int main()
{
	//prime hash table
	cout << "hash table" << endl;
	prime_hash_init(13);
	for(int i = 0; i < 30; ++ i)
		prime_hash_insert(i);
	prime_hash_print(13);
	hash_node *p1 = prime_hash_find(24);
	if(p1)
		cout << "find 24 in hash table: " << p1->h_value << endl;
	else
		cout << "can't find 24 in hash table" << endl;
	prime_hash_delete(24);
	p1 = prime_hash_find(24);
	cout << "after delete 24 from hash table" << endl;
	if(p1)
		cout << "find 24 in hash table: " << p1->h_value << endl;
	else
		cout << "can't find 24 in hash table" << endl;
	prime_hash_print(13);

	//bkdr hash
	cout << endl << "bkdr hash table" << endl;
	bkdr_hash_init();
	char s1[] = "hello world";
	char s2[] = "henno hoood";
	char s3[] = "hh you wrong";
	char s4[] = "that's a test";
	int h1 = bkdr_hash(s1);
	int h2 = bkdr_hash(s2);
	int h3 = bkdr_hash(s3);
	int h4 = bkdr_hash(s4);
	cout << "string 1:" << endl << s1 << endl << "hash value: " << h1 << endl;
	cout << "string 2:" << endl << s2 << endl << "hash value: " << h2 << endl;
	cout << "string 3:" << endl << s3 << endl << "hash value: " << h3 << endl;
	cout << "string 4:" << endl << s4 << endl << "hash value: " << h4 << endl;
	cout << "insert string 1" << endl;
	bkdr_hash_insert(h1);
	if(bkdr_hash_find(h1))
		cout << "find string 1" << endl;
	else
		cout << "can't find string 1" << endl;

	//segment tree
	cout << endl << "segment tree [0, 10]" << endl;
	seg_node *root = segment_tree_build(0, 10);
	segment_tree_insert(root, 2, 4);
	segment_tree_insert(root, 6, 9);
	cout << "insert [2, 4], [6, 9], length: " << segment_tree_length(root) << endl;
	segment_tree_print(root);
	segment_tree_insert(root, 5, 7);
	cout << "insert [5, 7], length: " << segment_tree_length(root) << endl;
	segment_tree_print(root);
	
	//binary index tree
	binary_index_tree_init();
	cout << endl << "binary index tree" << endl;
	for(int i = 1; i < 20; ++ i){
		cout << "array s[" << i << "] add " << 2 * i << endl;
		binary_index_tree_add(i, 2 * i);
	}
	cout << "array sum from 1 to 10: " << binary_index_tree_sum(10) << endl;

	//disjoint set
	disjoint_set_init();	
	cout << endl << "disjoint set" << endl;
	cout << "union" << endl;
	for(int i = 0; i < 10; ++ i){
		cout << "number " << i << " and " << 3 * i << " is in one set" << endl;
		disjoint_set_union(i, 3 * i);
	}
	cout << "query" << endl;
	if(disjoint_set_query(1, 27))
		cout << "number 1 and 27 in one set" << endl;
	else
		cout << "number 1 and 27 not in one set" << endl;
	if(disjoint_set_query(2, 18))
		cout << "number 2 and 18 in one set" << endl;
	else
		cout << "number 2 and 18 not in one set" << endl;
	if(disjoint_set_query(2, 21))
		cout << "number 2 and 21 in one set" << endl;
	else
		cout << "number 2 and 21 not in one set" << endl;
	
	cout << endl << "leftist tree" << endl;
	left_node tr[51];
	for(int i = 0; i < 51; ++ i)
		tr[i].l_idx = i;
	//left child: &tr[6];
	tr[6].l_lc = &tr[11]; tr[6].l_rc = &tr[8]; tr[6].l_dist = 2;
	tr[11].l_lc = &tr[17]; tr[11].l_rc = &tr[14]; tr[11].l_dist = 2;
	tr[17].l_lc = &tr[18]; tr[17].l_rc = &tr[20]; tr[17].l_dist = 1;
	tr[14].l_lc = &tr[19]; tr[14].l_rc = &tr[24]; tr[14].l_dist = 1;
	tr[8].l_lc = &tr[10]; tr[8].l_rc = &tr[13]; tr[8].l_dist = 1;
	tr[10].l_lc = &tr[15]; tr[10].l_rc = &tr[30]; tr[10].l_dist = 1;
	tr[13].l_lc = &tr[28];
	//right child: &tr[7];
	tr[7].l_lc = &tr[9]; tr[7].l_rc = &tr[12]; tr[7].l_dist = 2;
	tr[9].l_lc = &tr[21]; tr[9].l_rc = &tr[16]; tr[9].l_dist = 1;
	tr[12].l_lc = &tr[31]; tr[12].l_rc = &tr[26]; tr[12].l_dist = 1;
	tr[31].l_lc = &tr[42]; tr[31].l_rc = &tr[33]; tr[31].l_dist = 1;
	tr[42].l_lc = &tr[50];
	tr[26].l_lc = &tr[27];
	cout << "tree lt:" << endl;
	leftist_tree_print(&tr[6]);
	cout << "tree rt:" << endl;
	leftist_tree_print(&tr[7]);

	cout << endl << "after lt merge rt:" << endl;
	left_node *root2 = leftist_tree_merge(&tr[6], &tr[7]);
	leftist_tree_print(root2);

	cout << endl << "after pop the top node:" << endl;
	root2 = leftist_tree_pop(root2);
	leftist_tree_print(root2);

	cout << endl << "after push node 3:" << endl;
	root2 = leftist_tree_push(root2, 3);
	leftist_tree_print(root2);
	
	{
		cout<<"avl test :"<<endl;
		AVLTree<int> te;
		for (int i=0;i<10;i++)
		{
			te.insert(i);
		}
		te.Treversal();
	}
	return(0);
}
