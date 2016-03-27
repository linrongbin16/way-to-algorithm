#include "9_red_black_tree.h"
#include <iostream>
using namespace std;

int main()
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

    return(0);
}
