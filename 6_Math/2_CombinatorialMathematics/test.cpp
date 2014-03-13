//test

#include "general_head.h"
void full_permutation(int *s, int n, int& cnt, int prev = 0);
int main()
{
	int q[] = {1, 2, 3, 4};
	int cnt(0);
	full_permutation(q, 4, cnt, 0);
	cout << "full permutation: " << cnt << endl;
	return(0);
}


