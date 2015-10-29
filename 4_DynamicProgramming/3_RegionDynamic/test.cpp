//test

#include "1_minimum_merge_cost.h"
#include "2_minimum_merge_extension.h"
#include "3_maximum_binary_tree_merge.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

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
	print(s1, 4, "s1: ");
	cout << "minimum merge cost: " << minimum_merge_cost(s1, 6) << endl;
	cout << "minimum merge extension: " << minimum_merge_extension(s1, 6) << endl;
	cout << "maximum binary tree merge: " << maximum_binary_tree_merge(s1, 6) << endl;
	return(0);
}
