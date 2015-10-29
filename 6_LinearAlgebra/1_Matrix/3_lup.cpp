//LUP分解
//lup.cpp

//用LUP算法求解有唯一解的满秩线性方程组

//1)LUP算法
//LUP算法通过构造出三个特殊的矩阵来减少线性方程组的求解时间，其中：
//L是一个单位下三角矩阵
//U是一个上三角矩阵
//P是一个置换矩阵，即单位矩阵通过任意初等变幻得到的矩阵，也可以是单位矩阵
//它的每行每列只有一个元素为1，其他为0，但不一定是在主对角线上
//矩阵LUP必须满足的性质是：PA = LU
//由Ax = b，两边同乘以P，得到PAx = Pb
//PAx = Pb结合PA = LU，得到LUx = Pb
//设y = Ux，得到Ly = Pb，通过“正向替换”的方法求解Ly = Pb得到y
//再通过“逆向替换”的方法求解Ux = y得到x，由Ax = P(-1)LUx = P(-1)Ly = P(-1)Pb = b
//可知此x即为Ax = b方程组的唯一解
//
//2)正向代入和逆向代入
//求解Ly = Pb中y的过程是一个正向代入的过程，L是单位下三角矩阵，则该方程组是这样的：
//y1										= pb1
//l(2,1)y1 + y2								= pb2
//l(3,1)y1 + l(3,2)y2 + y3					= pb3
//......
//l(n,1)y1 + l(n,2)y2 + l(n,3)y3 + ... + yn = pbn
//第1行方程可以直接求得y1，然后依次向下代入每一行方程即可求得一组y的解，即为正向代入
//求解Ux = y中x的过程是一个逆向代入，U是上三角矩阵：
//u(1,1)x1 + u(1,2)x2 + ... + u(1,n-1)xn-1	 + u(1,n)xn   = y1
//			 u(2,2)x2 + ... + u(2,n-1)xn-1	 + u(2,n)xn	  = y2
//...
//							+ u(n-1,n-1)xn-1 + u(n-1,n)xn = yn-1
//											   u(n,n)xn	  = yn
//最后一行方程可以直接求出xn，然后依次向上代入每一行即可求得一组x的解，即逆向代入
//构造出LUP三个矩阵后使用两次代入即可得到方程组的唯一一组解x
//
//3)LU分解和Schur补
//将增广矩阵中左边的n阶矩阵A像这样从第1行和第1列划分开：
//| a(1,1) | a(1,2)  ...  (1,n) |
//|--------|--------------------|
//| a(2,1) | a(2,2)  ...  (2,n) |
//| a(3,1) | a(3,2)  ...  (3,n) |
//| ...	   | ...				|
//| a(n,1) | a(n,2)  ...  (n,n) |
//即得到A = | a(1,1)  WT |，经变形得A = | 1         0    || a(1,1)  WT            |
//          | v       A' |              | v/a(1,1)  En-1 || 0       A'-vWT/a(1,1) |
//其中En-1是n-1阶的单位矩阵E
//上式中将等式右边的两个矩阵设为L和U
//则A = LU，且L是下三角矩阵，U是上三角矩阵
//而对于n-1阶子矩阵 A'-vWT/a(1,1)，也可以类似的分解得到：A'-vWT/a(1,1) = L'U'
//当然如果(子)矩阵中左上角的元素a(1,1) = 0，就无法使用这个方法因为出现了除以0的情况
//只有正定矩阵满足主对角线上的所有元素都不为0
//代码的实现中通过巧妙的设置循环方式，可以求出矩阵L和U
//
//4)LUP分解
//通过选主元的方式保证(子)矩阵中左上角的元素a(1,1)不等于0
//选取(子)矩阵中第1列中元素绝对值最大的一行，将该行与第1行交换
//总是选取绝对值最大的元素也有助于保证计算的数值稳定性
//矩阵P正是选主元的体现
//P*A正是对A进行初等变换，使其保证所有(子)矩阵的主元都是绝对值最大的元素
//现在对于n阶矩阵A有：PA = LU
//只需要在每一次进行LU分解之前先对当前(子)矩阵进行一次选主元的操作即可
//LUP分解实际是一种原地进行的高斯消元法，但相比于高斯消元法的效率高很多
//
//设置数组p来描述置换数组P，其中p[i] = j指代矩阵P中的i行j列元素为1，其他元素都为0
//
//我忠实的实现了算法导论中关于LU分解和LUP分解的伪伪语言描述

#include "general_head.h"
#include "matrix.h"
//guass_elimination.cpp
double select_pivot(matrix e, int n, int p, int& index);
//guass_elimination.cpp
void backward_substitution(matrix e, int n, double *x);
//guass_elimination.cpp
void forward_substitution(matrix e, int n, double *x);
void lu_decomposition(matrix& e, int n);
void lup_decomposition(matrix& e, int n, int *p);
void construct_l(matrix e, int n, int *p, matrix& l);
void construct_u(matrix e, int n, double *y, matrix& u);

void lup(matrix e, int n, double *x)
{//增广矩阵e是n行n+1列的，最后一列是方程组的系数向量b
 //返回方程组的唯一解x
	//p[i] = j指代矩阵P中的i行j列元素为1，其他元素都为0
	int p[MAX];
	lup_decomposition(e, n, p);
	//如果增广矩阵e中左边的矩阵A是正定矩阵
	//可以保证主对角线上所有元素都不为0，则可以使用LU分解
	matrix l(n, n + 1), u(n, n + 1);
	construct_l(e, n, p, l);
	double y[MAX];
	//正向代入求出y解
	forward_substitution(l, n, y);
	construct_u(e, n, y, u);
	//逆向代入求出x解
	backward_substitution(u, n, x);
}
void lu_decomposition(matrix& e, int n)
{//增广矩阵e是n行n+1列的，当增广矩阵e中左边的矩阵A是正定矩阵时LU分解不需要选主元
	for(int k = 0; k < n; ++ k){
		//k是主对角线上元素
		//l数组记录v列向量，u数组记录WT行向量
		//没有这两个数组也可以进行循环，l和u是为了更好地说明LU分解的过程
		double l[MAX], u[MAX];
		u[k] = e.m_m[k][k];
		for(int i = k + 1; i < n; ++ i){
			e.m_m[i][k] /= u[k];
			l[i] = e.m_m[i][k];
			u[i] = e.m_m[k][i];
		}
		for(int i = k + 1; i < n; ++ i)
			for(int j = k + 1; j < n; ++ j)
				e.m_m[i][j] -= l[i] * u[j];
	}	
}
void lup_decomposition(matrix& e, int n, int *p)
{//增广矩阵e是n行n+1列的，通过选主元操作保证主对角线上的元素都为0
	for(int i = 0; i < n; ++ i)
		p[i] = i;
	for(int k = 0; k < n; ++ k){
		int index;
		double pivot = select_pivot(e, n, k, index);
		if(pivot != e.m_m[k][k])
			//这里交换index行和k行时，列必须从0列到n-1列
			//而不能像高斯消元中从k列开始到n列
			//第一因为原地的操作不能保证之前从0列到k-1列的元素都为0
			//第二因为最后一列即n列是系数向量b
			//由于lup操作中只交换index行和k行，暂时不能改变系数向量b
			for(int i = 0; i < n; ++ i)
				swap(e.m_m[index][i], e.m_m[k][i]);
		//对置换矩阵P进行相应的转化
		swap(p[index], p[k]);
		//在本循环中没有设置l和u数组
		for(int i = k + 1; i < n; ++ i){
			e.m_m[i][k] /= e.m_m[k][k];
			for(int j = k + 1; j < n; ++ j)
				e.m_m[i][j] -= e.m_m[i][k] * e.m_m[k][j];
		}
	}
}
void construct_l(matrix e, int n, int *p, matrix& l)
{
	for(int i = 0; i < n; ++ i)
		l.m_m[i][i] = 1;
	for(int i = 0; i < n; ++ i)
		for(int j = 0; j < i; ++ j)
			l.m_m[i][j] = e.m_m[i][j];
	for(int i = 0; i < n; ++ i)
		l.m_m[i][n] = e.m_m[p[i]][n];
}
void construct_u(matrix e, int n, double *y, matrix& u)
{
	for(int i = 0; i < n; ++ i)
		for(int j = i; j < n; ++ j)
			u.m_m[i][j] = e.m_m[i][j];
	for(int i = 0; i < n; ++ i)
		u.m_m[i][n] = y[i];
}
