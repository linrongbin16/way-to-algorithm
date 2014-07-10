//test

#include "general_head.h"
#include "matrix.h"
extern int simplex(matrix e, int m, int n, double *c, double *x, double& z);
extern double dinkelback(double *a, double *b, int n);
void test_m(matrix e, double *c, int m, int n);
int main()
{
	matrix e(3, 4);
	e.m_m[0][0] = 1; e.m_m[0][1] = 1; e.m_m[0][2] = 3; e.m_m[0][3] = 30;
	e.m_m[1][0] = 2; e.m_m[1][1] = 2; e.m_m[1][2] = 5; e.m_m[1][3] = 24;
	e.m_m[2][0] = 4; e.m_m[2][1] = 1; e.m_m[2][2] = 2; e.m_m[2][3] = 36;
	double c[MAX];
	memset(c, 0, MAX * sizeof(double));
	c[0] = 3; c[1] = 1; c[2] = 2;
	//有唯一解
	test_m(e, c, 3, 3);
	
	matrix e1(1, 2);
	e1.m_m[0][0] = 1; e1.m_m[0][1] = 1; e1.m_m[0][2] = 2;
	double c1[MAX];
	memset(c1, 0, MAX * sizeof(double));
	c1[0] = 1; c1[1] = 1;
	//有无穷解
	test_m(e1, c1, 1, 2);

	matrix e2(1, 2);
	e2.m_m[0][0] = 1; e2.m_m[0][1] = -1; e2.m_m[0][2] = 2;
	double c2[MAX];
	memset(c2, 0, MAX * sizeof(double));
	c2[0] = 1; c2[1] = 1;
	//无界
	test_m(e2, c2, 1, 2);

	matrix e3(1, 2);
	e3.m_m[0][0] = 1; e3.m_m[0][1] = 1; e3.m_m[0][2] = -2;
	double c3[MAX];
	memset(c3, 0, MAX * sizeof(double));
	c3[0] = 1; c3[1] = 1;
	//无解
	test_m(e3, c3, 1, 2);

	double a[MAX], b[MAX];
	a[0] = 5, a[1] = 0, a[2] = 2;
	b[0] = 5, b[1] = 1; b[2] = 6;
	cout << "dinkelback: " << dinkelback(a, b, 3) << endl;
	return(0);
}
void test_m(matrix e, double *c, int m, int n)
{
	double x[MAX], z;
	memset(x, 0, MAX * sizeof(double));
	cout << "linear programming, matrix e:" << endl;
	e.m_print();
	cout << "target function: ";
	for(int i = 0; i < n; ++ i)
		cout << c[i] << ' ';
	cout << endl;
	int ans = simplex(e, m, n, c, x, z);
	cout << "simplex: ";
	if(ans == -1)
		cout << "no solution" << endl;
	else if(ans == 1)
		cout << "no bounded" << endl;
	else if(ans == 0){
		cout << "get one soluntion" << endl;
		cout << "target z: " << z << endl;
		cout << "target c: ";
		for(int i = 0; i < m + n; ++ i)
			cout << c[i] << ' ';
		cout << endl;
		cout << "target x: ";
		for(int i = 0; i < m + n; ++ i)
			cout << x[i] << ' ';
		cout << endl;
	}
	cout << endl;
}
