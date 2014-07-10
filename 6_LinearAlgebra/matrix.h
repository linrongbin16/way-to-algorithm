//矩阵头文件
//matrix.h

//支持线性规划一章的自定义数据结构

#include <iostream>
#include <cstring>
#ifndef MAX
#define MAX 60
#endif
using std::cout;
using std::endl;

struct matrix{
	double m_m[MAX][MAX];
	int m_row, m_col;
	matrix(int crow = 0, int ccol = 0)
		: m_row(crow), m_col(ccol){
			memset(m_m, 0, MAX * MAX * sizeof(double));
	}
	matrix(const matrix& cr)
		: m_row(cr.m_row), m_col(cr.m_col){
			for(int i = 0; i < MAX; ++ i)
				for(int j = 0; j < MAX; ++ j)
					m_m[i][j] = cr.m_m[i][j];
	}
	matrix operator+(matrix cr){
		matrix t(*this);
		for(int i = 0; i < cr.m_row; ++ i)
			for(int j = 0; j < cr.m_col; ++ j)
				t.m_m[i][j] += cr.m_m[i][j];
		return(t);
	}
	matrix operator-(matrix cr){
		matrix t(*this);
		for(int i = 0; i < cr.m_row; ++ i)
			for(int j = 0; j < cr.m_col; ++ j)
				t.m_m[i][j] -= cr.m_m[i][j];
		return(t);
	}
	matrix operator*(matrix cr){
		matrix t(m_row, cr.m_col);
		for(int i = 0; i < m_row; ++ i)
			for(int j = 0; j < cr.m_col; ++ j)
				for(int k = 0; k < m_col; ++ k)
					t.m_m[i][j] += m_m[i][k] * cr.m_m[k][j];
		return(t);
	}
	void m_print()
	{
		for(int i = 0; i < m_row; ++ i){
			for(int j = 0; j < m_col; ++ j)
				cout << m_m[i][j] << '\t';
			cout << endl;
		}
	}
};
