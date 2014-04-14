//test

#include "general_head.h"
void full_permutation(int *s, int n, int& cnt, int prev = 0);	//1
void combination1(int *s, int n, int m, int prev = 0);	//2
void combination2(int *s, int n, int m, int prev = 0);	//3
void combination3(int *s, int n, int m);	//4
int main()
{
	int q[] = {1, 2, 3, 4};
	int cnt(0);
	full_permutation(q, 4, cnt, 0);
	cout << "full permutation: " << cnt << endl;
	int s1[5] = {1, 1, 1, 0, 0};
	int s2[5] = {1, 1, 1, 0, 0};
	int s3[5] = {1, 1, 1, 0, 0};
	cout << endl << "combination 1" << endl;
	combination1(s1, 5, 3);
	cout << endl << "combination 2" << endl;
	combination2(s2, 5, 3);
	cout << endl << "combination 3" << endl;
	combination3(s3, 5, 3);
	return(0);
}


