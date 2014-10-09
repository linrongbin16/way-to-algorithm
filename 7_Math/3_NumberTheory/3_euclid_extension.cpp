//Euclid扩展
//euclid_extension.cpp

//求两数a，b的最大公约数以及使下式满足的系数x，y
//gcd(a, b) = d = ax + by

//递归求出最底层的x、y，反向回溯向上求出每一层x、y直至最上一层
//对于相邻的两次递归，对下一层有d2 = gcd(b, a % b)
//即有d2 = b * x2 + (a % b) * y2
//对于上一层有d1 = gcd(a, b)，即d1 = a * x1 + b * y1
//由于d1 = d2，则a * x1 + b * y1 = b * x2 + (a % b) * y2，将等式右边化为
//d2 = a * y2 + b * (x2 - (a / b) * y2)
//将系数对齐则有x1 = y2，y1 = x2 - (a / b) * y2
//
//我忠实的实现了算法导论中关于Euclid扩展的描述

#include "general_head.h"

int euclid_extension(int a, int b, int& x, int& y)
{//返回a，b的最大公约数以及a，b的系数x和y
 //使得等式gcd(a, b) = d = ax + by成立
	//递归终止条件
	if(b == 0){
		int gcd = a;
		x = 1;
		y = 0;
		return(gcd);
	}
	int gcd = euclid_extension(b, a % b, x, y);
	int tmp = x;
	x = y;
	y = tmp - (a / b) * y;
	return(gcd);
}
