#include "4_segment_tree.h"
#include <iostream>
using namespace std;

int main()
{
	//segment tree
    cout << endl << "segment tree [0, 10]" << endl;
    segment_tree_node *root = segment_tree_build(0, 10);
    segment_tree_insert(root, 2, 4);
    segment_tree_insert(root, 6, 9);
    cout << "insert [2, 4], [6, 9], length: " << segment_tree_length(root) << endl;
    segment_tree_print(root);
    segment_tree_insert(root, 5, 7);
    cout << "insert [5, 7], length: " << segment_tree_length(root) << endl;
    segment_tree_print(root);
	
	return(0);
}
