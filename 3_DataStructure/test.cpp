//test

#include "2_hash_table.hpp"	//struct hash_table
#include "3_segment_tree.hpp"	//struct segment_tree
#include "4_binary_index_tree.hpp"	//struct binary_index_tree
#include "5_disjoint_set.hpp"	//struct disjoint_set
#include "6_leftist_tree.hpp"	//struct leftist_tree
int main()
{
	hash_table ht(13);	//1
	cout << "hash table" << endl;
	for(int i = 0; i < 30; ++ i)
		ht.h_insert(i);
	ht.h_print();
	hash_node *p1 = ht.h_find(24);
	if(p1)
		cout << "find 24 in hash table: " << p1->h_value << endl;
	else
		cout << "can't find 24 in hash table" << endl;
	ht.h_delete(24);
	p1 = ht.h_find(24);
	cout << "after delete 24 from hash table" << endl;
	if(p1)
		cout << "find 24 in hash table: " << p1->h_value << endl;
	else
		cout << "can't find 24 in hash table" << endl;
	ht.h_print();

	segment_tree st;	//2
	cout << endl << "segment tree [0, 10]" << endl;
	st.s_print();
	st.s_build(0, 10);
	st.s_insert(2, 4);
	st.s_insert(6, 9);
	cout << "insert [2, 4], [6, 9], length: " << st.s_length() << endl;
	st.s_print();
	st.s_insert(5, 7);
	cout << "insert [5, 7], length: " << st.s_length() << endl;
	st.s_print();
	
	binary_index_tree bit;	//3
	cout << endl << "binary index tree" << endl;
	for(int i = 1; i < 20; ++ i){
		cout << "array s[" << i << "] add " << 2 * i << endl;
		bit.b_add(i, 2 * i);
	}
	bit.b_print();
	cout << "array sum from 1 to 10: " << bit.b_sum(10) << endl;

	disjoint_set ds;	//4
	cout << endl << "disjoint set" << endl;
	cout << "union" << endl;
	for(int i = 0; i < 10; ++ i){
		cout << "number " << i << " and " << 3 * i << " is in one set" << endl;
		ds.d_union(i, 3 * i);
	}
	ds.d_print();
	cout << "query" << endl;
	if(ds.d_query(1, 6))
		cout << "number 1 and 6 in one set" << endl;
	else
		cout << "number 1 and 6 not in one set" << endl;
	if(ds.d_query(1, 4))
		cout << "number 1 and 4 in one set" << endl;
	else
		cout << "number 1 and 4 not in one set" << endl;
	if(ds.d_query(2, 6))
		cout << "number 2 and 6 in one set" << endl;
	else
		cout << "number 2 and 6 not in one set" << endl;
	
	cout << endl << "leftist tree" << endl;
	leftist_tree lt, rt;	//5
	left_node tr[51];
	for(int i = 0; i < 51; ++ i)
		tr[i].l_idx = i;
	lt.l_root = &tr[6];
	tr[6].l_lc = &tr[11]; tr[6].l_rc = &tr[8]; tr[6].l_dist = 2;
	tr[11].l_lc = &tr[17]; tr[11].l_rc = &tr[14]; tr[11].l_dist = 2;
	tr[17].l_lc = &tr[18]; tr[17].l_rc = &tr[20]; tr[17].l_dist = 1;
	tr[14].l_lc = &tr[19]; tr[14].l_rc = &tr[24]; tr[14].l_dist = 1;
	tr[8].l_lc = &tr[10]; tr[8].l_rc = &tr[13]; tr[8].l_dist = 1;
	tr[10].l_lc = &tr[15]; tr[10].l_rc = &tr[30]; tr[10].l_dist = 1;
	tr[13].l_lc = &tr[28];
	rt.l_root = &tr[7];
	tr[7].l_lc = &tr[9]; tr[7].l_rc = &tr[12]; tr[7].l_dist = 2;
	tr[9].l_lc = &tr[21]; tr[9].l_rc = &tr[16]; tr[9].l_dist = 1;
	tr[12].l_lc = &tr[31]; tr[12].l_rc = &tr[26]; tr[12].l_dist = 1;
	tr[31].l_lc = &tr[42]; tr[31].l_rc = &tr[33]; tr[31].l_dist = 1;
	tr[42].l_lc = &tr[50];
	tr[26].l_lc = &tr[27];
	cout << "tree lt:" << endl;
	lt.l_print();
	cout << "tree rt:" << endl;
	rt.l_print();
	lt.l_merge(&rt);
	cout << endl << "after lt merge rt:" << endl;
	lt.l_print();
	cout << endl << "after pop the top node:" << endl;
	lt.l_pop();
	lt.l_print();
	return(0);
}




