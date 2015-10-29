#include "5_leftist_tree.h"
#include <iostream>
using namespace std;

int main()
{
	
	//leftist tree
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
	
	return(0);
}
