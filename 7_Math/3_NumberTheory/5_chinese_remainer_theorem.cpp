//中国剩余定理
//chinese_remainer_theorem.cpp

//给出一组除数n和余数a，其中一组除数n中任意两除数是互质的
//求这样一个最小的正整数x
//使x对除数n中的每个数字n[i]求模等于余数a中对应的数字a[i]
//即满足a[i] = x % n[i]，每一组数字中余数a[i]小于除数n[i]
//特别的还要求出所有这样的正整数x使得上式对于所有除数和余数成立

//以上问题的数学化描述是这样的一组模线性方程组：
//x mod= a1(mod n1)
//x mod= a2(mod n2)
//......
//x mod= ak(mod nk)
//其中a1到ak即上面问题中的余数a中的数字，n1到nk即除数n中的数字
//求所有的x使得该模线性方程组成立
//以上的n1到nk更加数学化的叫法是模数，本文中为了方便理解就称为除数
//
//中国剩余定理，也称同余定理，提供了求解x的方法
//假设除数n中的所有数字n1到nk两两互质
//设m = n1*n2*...*nk，m1 = m/n1，m2=m/n2，...，mk=m/nk
//显然m1到mk中任意一个mi是除过ni的其他所有除数的乘积
//由于所有除数n1到nk两两互质，mi即是除过ni的其他所有除数的最小公倍数
//显然如果没有所有除数两两互质的条件，mi不一定是“最小”的公倍数
//再设ti是mi在模ni下的数论倒数，即满足ti*mi mod= 1(mod ni)
//则模线性方程组中的x的一个解是x0 = a1*t1*m1 + a2*t2*m2 + ... + ak*tk*mk
//x的所有解是x0 + y*m，其中y是任意非负整数，即x0再加任意倍的所有除数的乘积m
//而x的最小正整数解x_min = x0 % m
//求数论倒数ti只能够通过重复的迭代计算，求出一个满足ti*mi mod= 1(mod ni)的倒数ti
//
//我忠实的实现了算法导论中关于中国剩余定理的描述
//
//本文引用了“中国剩余定理(维基百科)”，无作者

#include "general_head.h"

int chinese_remainer_theorem(int *a, int *n, int k)
{//数组a和n是余数和除数数组，共k个数字，下标从0到k-1
 //返回最小的正整数解x满足所有x mod= ai(mod ni)
	//m[i]指代除过n[i]以外所有的除数乘积，m[k]指代所有除数的乘积
	//t[i]指代m[i]在模n[i]下的数论倒数，满足t[i]*m[i] mod= 1(mod n[i])
	int m[MAX], t[MAX];
	m[k] = 1;
	for(int i = 0; i < k; ++ i)
		m[k] *= n[i];
	for(int i = 0; i < k; ++ i)
		m[i] = m[k] / n[i];
	for(int i = 0; i < k; ++ i)
		//求m[i]的数论倒数t[i]
		for(int j = 1; ; ++ j)
			//从1开始判断数字j是否m[i]的数论倒数
			if(j * m[i] % n[i] == 1){
				t[i] = j;
				break;
			}
	//上面的循环
	//for(int i = 0; i < k; ++ i)
	//	for(int j = 1; ; ++ j)
	//时间复杂度为k的平方级，可以作进一步的优化，写作循环：
	//for(int j = 1; ; ++ j)
	//	for(int i = 0; i < k; ++ i)
	//对于每个j，都判断这个j是否是m[i]的数论倒数，则不会对于同一个j作多余的重复判断
	
	int x0(0);
	for(int i = 0; i < k; ++ i)
		x0 += a[i] * t[i] * m[i];
	x0 %= m[k];
	return(x0);
}
