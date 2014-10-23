//test

#include "general_head.h"
extern void sieve1(int n, int *prime);		//1
extern void sieve2(int n, int *prime);		//2
extern void sieve3(int n, int *prime);		//3
extern int euclid(int a, int b);			//4
extern int least_common_multiple(int a, int b);	//5
extern int euclid_extension(int a, int b, int& x, int& y);	//6
extern bool modular_linear_equation(int a, int b, int n, int& d, int *x);	//7
extern int chinese_remainer_theorem(int *a, int *n, int k);	//8
extern int modular_exponentiation(int a, int b, int n);	//9
int main()
{
	int prime[MAX];
	sieve1(MAX, prime);	//1
	cout << "sieve1:" << endl;
	for(int i = 2; i < MAX; ++ i)
		if(prime[i])
			cout << i << ' ';
	cout << endl;
	sieve2(MAX, prime);	//2
	cout << "sieve2:" << endl;
	cout<< 2 << ' ';
	for(int i = 3; i < MAX; i += 2)
		if(prime[i])
			cout << i << ' ';
	cout << endl;
	sieve3(MAX, prime);	//3
	cout << "sieve3:" << endl;
	for(int i = 0; i < MAX; ++ i)
		if(prime[i])
			cout << prime[i] << ' ';
		else
			break;
	cout << endl;
	cout << "greatest common divisor of 24 and 39 is: " << euclid(24, 39) << endl;	//4
	cout << "least common multiple of 24 and 39 is: " << least_common_multiple(24, 39) << endl;	//5
	cout << "extended euclid, x and y that satisfied gcd(24,39) = 24*x + 39*y" << endl;	
	int x, y, d;
	d = euclid_extension(24, 39, x, y);	//6
	cout << "gcd(24,39): " << d << ", x: " << x << ", y: " << y << endl;

	int xx[MAX];
	cout << "modular linear equation: 35*x mod= 10(mod 50)" << endl;
	if(modular_linear_equation(35, 10, 50, d, xx)){	//7
		cout << "all soluntions: ";
		for(int i = 0; i < d; ++ i)
			cout << xx[i] << ' ';
		cout << endl;
	}
	else
		cout << "no solution" << endl;

	int n[] = {9, 8, 7}, a[] = {1, 2, 3};
	cout << "divise by 9, 8, 7 left 1, 2, 3, the number is: " << chinese_remainer_theorem(a, n, 3) << endl;	//8

	cout << "7^560 mod 561: " << modular_exponentiation(7, 560, 561) << endl;	//9
	return(0);
}
