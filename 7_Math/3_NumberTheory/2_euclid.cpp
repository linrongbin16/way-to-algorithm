//Euclid算法
//euclid.cpp

//求两正整数的最大公约数(Greatest Common Divisor)和最小公倍数(Least Common Multiple)

//欧几里德(Euclid)算法也成为辗转相除法，通过两个数字递归的相除求出最大公约数
//最小公倍数可由最大公约数求出
//最大公约数常记作gcd，最小公倍数常记作lcm

#include "general_head.h"

int euclid(int a, int b) 
{//返回a，b两数的最大公约数
	//递归终止条件
	if(b == 0)
		return(a);
	return(euclid(b, a % b));
}
int least_common_multiple(int a, int b)
{//返回a，b两数的最小公倍数
	int greatest_common_divisor = euclid(a, b);
	int ta = a / greatest_common_divisor;
	int tb = b / greatest_common_divisor;
	return(ta * tb * greatest_common_divisor);
}
