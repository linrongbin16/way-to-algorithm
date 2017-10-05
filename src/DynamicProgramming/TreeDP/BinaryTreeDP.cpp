#include "1_binary_tree.h"
#include <iostream>
#include <cstring>
using namespace std;

int binary_tree1(binary_tree_node1 *r, int resv);	//1
int binary_tree2(binary_tree_node2 *r, int **f, int resv);	//2

void init_2f(int f[MAX][MAX])
{
	for(int i = 0; i < MAX; ++ i)
		for(int j = 0; j < MAX; ++ j)
			f[i][j] = 0;
}

void test1()
{
	//construct a tree, 46 nodes, 45 branches
    //This tree is a little too big
    //you have to draw it by yourself
	binary_tree_node1 t[60];
    memset(t, 0, sizeof(t));
	for(int i = 0; i < 60; ++ i) {
		t[i].m_value = i;
    }
	t[1].m_leftchild = &t[2]; t[1].m_rightchild = &t[3];
	t[2].m_leftchild = &t[5]; t[2].m_rightchild = &t[6];
	t[3].m_leftchild = &t[8]; t[3].m_rightchild = &t[9];
	t[4].m_leftchild = &t[10]; t[4].m_rightchild = &t[11]; 
	t[6].m_leftchild = &t[13]; t[6].m_rightchild = &t[14];
	t[9].m_leftchild = &t[16]; t[9].m_rightchild = &t[17];
	t[15].m_leftchild = &t[22]; t[15].m_rightchild = &t[23]; 
	t[20].m_leftchild = &t[24]; t[20].m_rightchild = &t[25]; 
	t[22].m_leftchild = &t[28]; t[22].m_rightchild = &t[29]; 
	t[25].m_leftchild = &t[31]; t[25].m_rightchild = &t[32];
	t[30].m_leftchild = &t[34]; t[30].m_rightchild = &t[35];
	t[31].m_leftchild = &t[36]; t[31].m_rightchild = &t[37]; 
	t[33].m_leftchild = &t[38]; t[33].m_rightchild = &t[39];
	t[34].m_leftchild = &t[40]; t[34].m_rightchild = &t[41]; 
	t[37].m_leftchild = &t[43]; t[37].m_rightchild = &t[44];
	t[43].m_leftchild = &t[47]; t[43].m_rightchild = &t[48];
	t[44].m_leftchild = &t[49]; t[44].m_rightchild = &t[50];
	t[47].m_leftchild = &t[51]; t[47].m_rightchild = &t[52];
	t[49].m_leftchild = &t[53]; t[49].m_rightchild = &t[54]; 
	t[50].m_leftchild = &t[55]; t[50].m_rightchild = &t[56];
	t[53].m_leftchild = &t[57]; t[53].m_rightchild = &t[58];

	cout << endl << "binary tree dynamic 1: ";
	cout << binary_tree1(&t[44], 5) <<  endl;	//1

}
void test2()
{
	//construct a tree, 46 nodes, 45 branches
    //This tree is a little too big
    //you have to draw it by yourself
	binary_tree_node2 t[60];
    memset(t, 0, sizeof(t));
	for(int i = 0; i < 60; ++ i) {
		t[i].m_index = i;
        t[i].m_value = i;
    }
	t[1].m_leftchild = &t[2]; t[1].m_rightchild = &t[3];
	t[2].m_leftchild = &t[5]; t[2].m_rightchild = &t[6];
	t[3].m_leftchild = &t[8]; t[3].m_rightchild = &t[9];
	t[4].m_leftchild = &t[10]; t[4].m_rightchild = &t[11]; 
	t[6].m_leftchild = &t[13]; t[6].m_rightchild = &t[14];
	t[9].m_leftchild = &t[16]; t[9].m_rightchild = &t[17];
	t[15].m_leftchild = &t[22]; t[15].m_rightchild = &t[23]; 
	t[20].m_leftchild = &t[24]; t[20].m_rightchild = &t[25]; 
	t[22].m_leftchild = &t[28]; t[22].m_rightchild = &t[29]; 
	t[25].m_leftchild = &t[31]; t[25].m_rightchild = &t[32];
	t[30].m_leftchild = &t[34]; t[30].m_rightchild = &t[35];
	t[31].m_leftchild = &t[36]; t[31].m_rightchild = &t[37]; 
	t[33].m_leftchild = &t[38]; t[33].m_rightchild = &t[39];
	t[34].m_leftchild = &t[40]; t[34].m_rightchild = &t[41]; 
	t[37].m_leftchild = &t[43]; t[37].m_rightchild = &t[44];
	t[43].m_leftchild = &t[47]; t[43].m_rightchild = &t[48];
	t[44].m_leftchild = &t[49]; t[44].m_rightchild = &t[50];
	t[47].m_leftchild = &t[51]; t[47].m_rightchild = &t[52];
	t[49].m_leftchild = &t[53]; t[49].m_rightchild = &t[54]; 
	t[50].m_leftchild = &t[55]; t[50].m_rightchild = &t[56];
	t[53].m_leftchild = &t[57]; t[53].m_rightchild = &t[58];

	int f2[MAX][MAX];
	init_2f(f2);
	cout << endl << "binary tree dynamic 2: ";
	cout << binary_tree2(&t[44], f2, 5) << endl;	//2

}

int main()
{
    test1();
    test2();

    return 0;
}
