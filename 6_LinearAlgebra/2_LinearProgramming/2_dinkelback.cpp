//Dinkelbach算法
//dinkelback.cpp

//考虑两个n维整数向量A和B，A=(a1, a2, ..., an)，B=(b1, b2, ..., bn)
//所有元素都是正整数
//未知量x是n维向量(x1, x2, ..., xn)，未知量x只能取0或1
//最小化目标函数z = (a1*x1 + a2*x2 + ... + an*xn)/(b1*x1 + b2*x2 + ... + bn*xn)
//最优解z是实数，这类问题称为01分数规划

//01分数规划是Dinkelbach算法的典型应用场景
//将01分数规划问题简单的表述为求目标函数z = Ax/Bx的最小化，其中A，B和x是n维向量
//设Amax是向量A中最大值，由A，B和x中所有元素都是正整数可知
//目标函数z的取值范围是[-Amax*n, Amax*n]
//该问题可以通过设计一个子问题来求解：
//求目标函数z(L) = Ax - L*Bx的最小化
//设z_min是z(L)的最小值，x*是z(L)的最优方案，L* = Ax*/Bx*，则有以下规则：
//z_min > 0，当且仅当L < L*
//z_min = 0，当且仅当L = L*
//z_min < 0，当且仅当L > L*
//z(L*)的最优解也能使原目标函数z = Ax/Bx取得最优解
//且z(-Amax*n) < 0，z(Amax*n) > 0
//则原问题可以转化为求一个L满足L = L*，使z_min = 0，从而得到z = Ax/Bx的最优解
//具体求出L的过程有多种方法，其中二分法是一种常见的方法
//本书第4章图论第2节最小生成中的最优比率生成树就采用了二分法
//另一种常见的就是Dinkelbach算法，在实际应用中它比二分法的效率更高
//该算法的本质是通过迭代的求解z(L) = Ax - L*Bx的切线来解决
//POJ2976 Dropping tests问题中规定了x中取0的个数和取1的个数，求目标函数的最大化
//而本文中并未规定x中元素取0或1的数量，而且求目标函数最小化
//但通过修改原题目的算法可以得到求最小化目标函数的更一般性的算法
//
//本文引用了“对于0-1分数规划的Dinkelbach算法的分析”，作者“武钢三中 吴豪[译]”
//“poj Dropping tests 01分数规划---Dinkelbach算法”，作者“xiaozhuaixifu”

#include "general_head.h"
#include "matrix.h"
struct xnode{
	double x_value;
	int x_idx;
};
double k_dinkelback(double *a, double *b, int n, int k);
bool compare(xnode a, xnode b);

double dinkelback(double *a, double *b, int n)
{//数组c和d有n个，下标从0到n-1
	double ratio(100);
	for(int k = 1; k <= n; ++ k)
		//k指代未知量x中取1的个数，为了不出现除0的情况至少有一个x取1
		ratio = min(ratio, k_dinkelback(a, b, n, k));
	return(ratio);
}
double k_dinkelback(double *a, double *b, int n, int k)
{//数组a和b有n个元素，下标从0到n-1，未知量x中有k个取1，n-k个取0
	xnode x[MAX]; 
	double l(0.5), ratio;
	do{
		ratio = l;
		for(int i = 0; i < n; ++ i){
			x[i].x_value = a[i] - ratio * b[i];
			x[i].x_idx = i;
		}
		//“poj Dropping tests 01分数规划---Dinkelbach算法”中
		//按照从大到小排序，为了最大化目标函数
		//本文中的排序相反是从小到大的，为了最小化目标函数
		sort(x, x + n, compare);
		double p(0), q(0);
		for(int i = 0; i < k; ++ i){
			//选择排序后的前k个x元素
			p += a[x[i].x_idx];
			q += b[x[i].x_idx];
		}
		l = p / q;
	}while(fabs(ratio - l) > 0);
	return(ratio);
}
bool compare(xnode a, xnode b)
{
	return(a.x_value < b.x_value);
}
