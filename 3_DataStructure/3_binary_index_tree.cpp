#include "3_binary_index_tree.h"
#include <iostream>
using namespace std;

int main()
{
	
	//binary index tree
	binary_index_tree bit;
	binary_index_tree_init(&bit);
	cout << endl << "binary index tree" << endl;
	for (int i = 1; i < 20; ++ i) {
		cout << "array s[" << i << "] add " << 2 * i << endl;
		binary_index_tree_add(&bit, i, 2 * i);
	}
	cout << "array sum from 1 to 10: " << binary_index_tree_sum(&bit, 10) << endl;

	return 0;
}
