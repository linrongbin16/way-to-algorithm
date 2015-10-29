//Strassen算法
//strassen.cpp

//用Strassen算法计算两个n阶矩阵相乘

//1)基础概念
//矩阵：m*n个数字组成的m行n列的表格，第i行第j列的元素为a(i,j)，其中1<=i<=m，1<=j<=n
//零矩阵：所有元素都是0的矩阵
//矩阵相等：矩阵A=B当且仅当A和B的行列数相等，且对应的每一个元素都相等
//n阶矩阵：n*n的矩阵
//n阶矩阵的主对角线：即所有元素a(i,i)，其中1<=i<=n
//上三角矩阵：主对角线以下(不包括主对角线)的元素都为0
//下三角矩阵：主对角线以上(不包括主对角线)的元素都为0
//单位矩阵：n阶矩阵中，主对角线上的元素都是1，其余元素都是0，称为n阶单位矩阵，简写作E
//转置矩阵：矩阵A的转置矩阵是n*m矩阵AT，AT中的每个元素at(j,i)等于矩阵A中的元素a(i,j)
//对称矩阵：若A的转置矩阵AT = A，则A是对称矩阵
//反对称矩阵：若A的转置矩阵AT = -A，即at(j,i) = -a(i,j)，则A为反对称矩阵
//对角矩阵：n阶矩阵A中主对角线以外的其余元素都是0，则A为对角矩阵
//线性无关，线性有关：
//矩阵中某一行无法经过其他行的加减乘除运算变换得到，则该行与其他行线性无关
//若某一行出现这样的情况：第i行可以由第j,k...行乘除常数，相加减得到
//则称该矩阵可以经过初等变换，可以转化为拥有全为0的一行，该行与其他行是线性有关的
//矩阵的秩：矩阵中任意行或列之间线性无关的行数或列数即为矩阵的秩，记作r
//经过有限次初等变换矩阵中线性有关的行或列可以被转化为全为0的行或列
//不全为0的行和列的数量即为矩阵的秩，经过初等变换不存在全0的行或列的矩阵称为满秩矩阵
//逆矩阵：n阶矩阵A存在一个对应的n阶矩阵B，使得AB = BA = E
//则称A是可逆矩阵，B是A的逆矩阵，且A的逆矩阵B唯一，记为A(-1)
//正定矩阵：
//设A是n阶矩阵，x是任意n维向量，xt是x的转置，若对于任意的x != 0都有 xt*A*x > 0
//则称A是正定矩阵
//
//矩阵加减：
//能够进行加减运算的两矩阵必须有相等的行和列，m*n的矩阵A+B=C(或A-B=C)
//C中元素c(i,j) = a(i,j) + b(i,j)(或c(i,j)=a(i,j)-b(i,j))，其中1<=i<=m，1<=j<=n
//矩阵数乘：
//矩阵A与常数c相乘得到矩阵B，B中元素b(i,j) = c*a(i,j)
//矩阵乘：
//能够进行乘运算的矩阵A和B必须A的列与B的行相等
//即A是m*s的矩阵，B是s*n的矩阵，A*B=C，得到的矩阵C是m*n的矩阵
//C中元素c(i,j) = a(i,1)*b(1,j) + a(i,2)*b(2,j) + ... + a(i,s)*b(s,j)
//其中1<=i<=m，1<=j<=n
//
//2)具体实现
//Strassen算法用于求解两n阶矩阵相乘，时间复杂度比普通的数学方法低
//该算法主要使用了分而治之的算法思想，以及对矩阵相乘中的计算进行巧妙的优化
//考虑两n阶矩阵X和Y相乘得到Z，即Z=XY，假设n为偶数，将XYZ都划分为n/2*n/2的矩阵
//则这三个矩阵可转化为： |r  s| = |a  b|*|e  f|
//						 |t  u|	  |c  d| |g  h|
//其中每个元素都是一个n/2*n/2的子矩阵，按照普通的矩阵乘法规则可知：
//r = ae + bg
//s = af + bh
//t = ce + dg
//u = cf + dh
//从上式可以看出，求解rstu中每一个子矩阵，都需要计算两次矩阵相乘
//比如r = ae + bg需要计算a*e和b*g，因此得到一个矩阵需要计算8次子矩阵的相乘
//通过递归的求解每个矩阵的子矩阵，是分而治之策略，该方法的时间复杂度是O(n^3)
//但Strassen算法只需要递归的计算7个子矩阵，使得时间复杂度下降到O(n^2.81)
//设置7个中间矩阵，从P1到P7，其中：
//P1 = af - ah = a(f - h)
//P2 = ah + bh = (a + b)h
//P3 = ce + de = (c + d)e
//P4 = dg - de = d(g - e)
//P5 = ae + ah + de + dh = (a + d)(e + h)
//P6 = bg + bh - dg - dh = (b - d)(g + h)
//P7 = ae + af - ce - cf = (a - c)(e + f)
//又有：
//r = P5 + P4 - P2 + P6
//s = P1 + P2
//t = P3 + p4
//u = P1 + P5 - P3 - P7
//由此，添加了若干子矩阵的加减运算，但得到一个矩阵只需要进行7次子矩阵的相乘
//为了方便本文中只考虑n为偶数的矩阵相乘，若n为奇数则子矩阵的划分总是多出一行一列
//实际中该算法由于增加了过多的矩阵加减运算，其实际效率并不高
//
//本节引用了“数学复习全书(2013年李永乐李正元考研数学 数学一)”，作者“李永乐”“李正元”

#include "general_head.h"
#include "matrix.h"
void construct_xy(matrix& a, matrix& b, matrix& c, matrix& d,
		matrix& e, matrix& f, matrix& g, matrix& h,
		matrix x, matrix y, int n);
void construct_z(matrix r, matrix s, matrix t, matrix u, matrix& z, int n);

matrix strassen(matrix x, matrix y, int n)
{//矩阵X和Y是n阶矩阵，元素下标从0到n-1，n是偶数
 //返回相乘的结果矩阵Z
	matrix a(n / 2, n / 2), b(n / 2, n / 2), c(n / 2, n / 2), d(n / 2, n / 2);
	matrix e(n / 2, n / 2), f(n / 2, n / 2), g(n / 2, n / 2), h(n / 2, n / 2);
	matrix r(n / 2, n / 2), s(n / 2, n / 2), t(n / 2, n / 2), u(n / 2, n / 2);
	matrix p[8];
	for(int i = 0; i < 8; ++ i)
		p[1].m_row = n / 2, p[1].m_col = n / 2;
		
	//递归终止条件，当子矩阵是2阶矩阵时递归到达最后一层，不再向下
	if(n == 2)
		//计算2阶矩阵X和Y相乘
		return(x * y);

	//初始化X和Y的8个子矩阵abcdefgh
	construct_xy(a, b, c, d, e, f, g, h, x, y, n);

	//求P1到P7这7个中间矩阵
	//P1 = af - ah = a(f - h)
	p[1] = strassen(a, f - h, n / 2);
	//P2 = ah + bh = (a + b)h
	p[2] = strassen(a + b, h, n / 2);
	//P3 = ce + de = (c + d)e
	p[3] = strassen(c + d, e, n / 2);
	//P4 = dg - de = d(g - e)
	p[4] = strassen(d, g - e, n / 2);
	//P5 = ae + ah + de + dh = (a + d)(e + h)
	p[5] = strassen(a + d, e + h, n / 2);
	//P6 = bg + bh - dg - dh = (b - d)(g + h)
	p[6] = strassen(b - d, g + h, n / 2);
	//P7 = ae + af - ce - cf = (a - c)(e + f)
	p[7] = strassen(a - c, e + f, n / 2);

	//求Z的四个子矩阵rstu
	r = p[5] + p[4] - p[2] + p[6];
	s = p[1] + p[2];
	t = p[3] + p[4];
	u = p[1] + p[5] - p[3] - p[7];

	matrix z(n, n);
	//将rstu这4个子矩阵构造为矩阵Z
	construct_z(r, s, t, u, z, n);
	return(z);
}
void construct_xy(matrix& a, matrix& b, matrix& c, matrix& d,
		matrix& e, matrix& f, matrix& g, matrix& h,
		matrix x, matrix y, int n)
{
	for(int i = 0; i < n / 2; ++ i)
		for(int j = 0; j < n / 2; ++ j){
			a.m_m[i][j] = x.m_m[i][j];
			b.m_m[i][j] = x.m_m[i][j + n / 2];
			c.m_m[i][j] = x.m_m[i + n / 2][j];
			d.m_m[i][j] = x.m_m[i + n / 2][j + n / 2];
			e.m_m[i][j] = y.m_m[i][j];
			f.m_m[i][j] = y.m_m[i][j + n / 2];
			g.m_m[i][j] = y.m_m[i + n / 2][j];
			h.m_m[i][j] = y.m_m[i + n / 2][j + n / 2];
		}
}
void construct_z(matrix r, matrix s, matrix t, matrix u, matrix& z, int n)
{
	for(int i = 0; i < n / 2; ++ i)
		for(int j = 0; j < n / 2; ++ j){
			z.m_m[i][j] = r.m_m[i][j];
			z.m_m[i][j + n / 2] = s.m_m[i][j];
			z.m_m[i + n / 2][j] = t.m_m[i][j];
			z.m_m[i + n / 2][j + n / 2] = u.m_m[i][j];
		}
}
