#include "6_prefix_tree.h"
#include <iostream>
using namespace std;

int main()
{
	//prefix tree
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
	return(0);
}
