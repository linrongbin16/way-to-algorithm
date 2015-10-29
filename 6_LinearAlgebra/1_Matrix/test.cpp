//test

#include "general_head.h"
#include "matrix.h"
extern matrix strassen(matrix x, matrix y, int n);	//1
extern void gauss_elimination(matrix e, int n, double *x);	//2
extern void lu_decomposition(matrix& e, int n);	//3
extern void lup_decomposition(matrix& e, int n, int *p);	//4
extern void construct_l(matrix e, int n, int *p, matrix& l);	//5
extern void construct_u(matrix e, int n, double *y, matrix& u);	//6
extern void forward_substitution(matrix e, int n, double *x);
extern void lup(matrix e, int n, double *x);	//6
void test_lu_decomposition(matrix e, int n);
void test_lup_decomposition(matrix e, int n);
int main()
{
	 matrix a(4, 4), c(4, 4);
	a.m_m[0][0] = 1; a.m_m[0][1] = 0.3; a.m_m[0][2] = -4.1; a.m_m[0][3] = 10;
	a.m_m[1][0] = 2; a.m_m[1][1] = 4.3; a.m_m[1][2] = 14; a.m_m[1][3] = 0;
	a.m_m[2][0] = 42; a.m_m[2][1] = -4; a.m_m[2][2] = 41; a.m_m[2][3] = -9;
	a.m_m[3][0] = 4.2; a.m_m[3][1] = 0.5; a.m_m[3][2] = 2; a.m_m[3][3] = 3.9;
	c.m_m[0][0] = 3; c.m_m[0][1] = 0.3; c.m_m[0][2] = -4.1; c.m_m[0][3] = -4;
	c.m_m[1][0] = 3; c.m_m[1][1] = 4.5; c.m_m[1][2] = 14; c.m_m[1][3] = 1.4;
	c.m_m[2][0] = 42; c.m_m[2][1] = -4.4; c.m_m[2][2] = 8; c.m_m[2][3] = 140;
	c.m_m[3][0] = 4.2; c.m_m[3][1] = 0.5; c.m_m[3][2] = 2; c.m_m[3][3] = 141;

	cout << endl << "a:" << endl;
	a.m_print();
	cout << endl << "c:" << endl;
	c.m_print();
	cout << endl << "a*c with strassen funciton:" << endl;
	matrix d = strassen(a, c, 4);	//1
	d.m_print();

	matrix b1(4, 5);
	b1.m_m[0][0] = 2; b1.m_m[0][1] = 3; b1.m_m[0][2] = 1; b1.m_m[0][3] = 5; b1.m_m[0][4] = 10;
	b1.m_m[1][0] = 6; b1.m_m[1][1] = 13; b1.m_m[1][2] = 5; b1.m_m[1][3] = 19; b1.m_m[1][4] = -7;
	b1.m_m[2][0] = 2; b1.m_m[2][1] = 19; b1.m_m[2][2] = 10; b1.m_m[2][3] = 23; b1.m_m[2][4] = 3;
	b1.m_m[3][0] = 4; b1.m_m[3][1] = 10; b1.m_m[3][2] = 11; b1.m_m[3][3] = 31; b1.m_m[3][4] = 5;


	cout << endl << "b1:" << endl;
	b1.m_print();
	double x[MAX];
	gauss_elimination(b1, 4, x);	//2
	cout << "x after gauss elimination:" << endl;
	for(int i = 0; i < 4; ++ i)
		cout << "x" << i+1 << ": " << x[i] << endl;

	cout << endl << "b1:" << endl;
	b1.m_print();
	cout << "b1 after LU decomposition:" << endl;	//3
	test_lu_decomposition(b1, 4);

	matrix b2(3, 4);
	b2.m_m[0][0] = 1; b2.m_m[0][1] = 2; b2.m_m[0][2] = 0; b2.m_m[0][3] = 3;
	b2.m_m[1][0] = 3; b2.m_m[1][1] = 4; b2.m_m[1][2] = 4; b2.m_m[1][3] = 7;
	b2.m_m[2][0] = 5; b2.m_m[2][1] = 6; b2.m_m[2][2] = 3; b2.m_m[2][3] = 8;
	
	cout << endl << "b2:" << endl;
	b2.m_print();
	cout << endl <<  "b2 after LUP decomposition:" << endl;
	test_lup_decomposition(b2, 3);

	lup(b2, 3, x);	//3
	cout << endl << "x after lup:" << endl;
	for(int i = 0; i < 3; ++ i)
		cout << "x" << i + 1 << ": " << x[i] << endl;
	return(0);
}
void test_lup_decomposition(matrix e, int n)
{
	int p[MAX];
	lup_decomposition(e, n, p);
	e.m_print();
	cout << "matrix L:" << endl;
	matrix l(n, n+ 1);
	double y[MAX];
	construct_l(e, n, p, l);
	l.m_print();
	forward_substitution(l, n, y);
	cout << "matrix U:" << endl;
	matrix u(n, n + 1);
	construct_u(e, n, y, u);
	u.m_print();
}
void test_lu_decomposition(matrix e, int n)
{
	lu_decomposition(e, n);
	e.m_print();
	cout << "matrix L:" << endl;
	matrix l(n, n + 1);
	int p[MAX];
	double y[MAX];
	construct_l(e, n, p, l);
	l.m_print();
	forward_substitution(l, n, y);
	cout << "matrix U:" << endl;
	matrix u(n, n + 1);
	construct_u(e, n, y, u);
	u.m_print();
}
