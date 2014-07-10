//test

#include "general_head.h"
extern int minimum_merge_cost(int *s, int n);
extern int extend_minimum_merge(int *s, int n);
extern int maximum_binary_tree_merge(int *s, int n);
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
	cout << "extend  minimum merge: " << extend_minimum_merge(s1, 6) << endl;
	cout << "maximum binary tree merge: " << maximum_binary_tree_merge(s1, 6) << endl;
	return(0);
}
