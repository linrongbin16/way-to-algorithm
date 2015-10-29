/*
 *
 *局部文件，存放函数的声明
 */

#ifndef combination_head_h
#define combination_head_h


#include "general_head.h"

 void full_permutation(int *s, int n, int& cnt, int prev = 0);	//1
 void combination1(int *s, int n, int m, int prev = 0);	//2
 void combination2(int *s, int n, int m, int prev = 0);	//3
 void combination3(int *, int , int );	//4
 void permutation_group(int *, int , int *, int , int *);	//5
 void print_status(int *, int , int );
 void calculus_number_diverse(int argc,char** argv);
 void catalan(int**a,int* b);

 #endif // combination_head_h
