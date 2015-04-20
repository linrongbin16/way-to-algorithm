//test
/*
函数声明应该放在.h文件中
*/

#include "general_head.h"
#include "com_local.h"
/*
extern void full_permutation(int *s, int n, int& cnt, int prev = 0);	//1
extern void combination1(int *s, int n, int m, int prev = 0);	//2
extern void combination2(int *s, int n, int m, int prev = 0);	//3
extern void combination3(int *s, int n, int m);	//4
extern void permutation_group(int *s, int n, int *t, int k, int *f);	//5
*/
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

	int s[11] = {0, 4, 5, 3, 7, 2, 8, 1, 6, 10, 9};
	int t[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int f[11];
	cout << endl << "permutation group:" << endl;
	cout << "s:" << endl;
	for(int i = 1; i <= 10; ++ i)
		cout << s[i] << ' ';
	cout << endl;
	cout << "t" << endl << "before:" << endl;
	for(int i = 1; i <= 10; ++ i)
		cout << t[i] << ' ';
	cout << endl;
	permutation_group(s, 10, t, 10, f);
	cout << "after:" << endl;
	for(int i = 1; i <= 10; ++ i)
		cout << f[i] << ' ';
	cout << endl;
	cout<<"count the split of  number (enter a positive integer):";
	calculus_number_diverse(0,NULL);
	return(0);
}
