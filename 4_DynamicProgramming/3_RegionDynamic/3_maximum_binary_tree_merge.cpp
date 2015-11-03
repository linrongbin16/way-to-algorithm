#include "3_maximum_binary_tree_merge.h"
#include <iostream>
#include <string>
using namespace std;

void print(int *s, int len, string info)
{
	cout << info;
	for(int i = 1; i <= len; ++ i)
		cout << s[i] << ' ';
	cout << endl;
}
int main()
{
	int s1[7] = {0, 1, 1, 5, 4, 3, 6};
	print(s1, 6, "s1: ");
	cout << "maximum binary tree merge: " << maximum_binary_tree_merge(s1, 6) << endl;
	return(0);
}
