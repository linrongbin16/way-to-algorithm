#include "8_AVL_tree.h"
#include <iostream>
using namespace std;

int main()
{
	
	//avl tree
    cout<<endl << "avl test :"<<endl;
    AVLTree<int> te;
    for (int i=0;i<10;i++)
    {
        te.insert(i);
    }
    te.Treversal();
    cout << endl;

	return(0);
}
