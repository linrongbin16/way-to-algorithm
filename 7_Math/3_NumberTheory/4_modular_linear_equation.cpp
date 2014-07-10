//模线性方程
//modular_linear_equation.cpp

//求使方程ax mod= b(mod n)成立的所有解x
//其中mod=是模等于号，a，b和n都是正整数且a和b小于n
//在书本中mod=符号写作三条横线，在本文中由于排版问题只好自行发明了mod=符号

//1)模
//模运算：
//设模为n，将原本的加减乘除计算符+-*/重新定义为模的加减乘除
//[a]指代对a求模，即a = a % n
//则有[a]+[b]=[a+b]，[a]*[b]=[a*b]，[a]-[b]=[a-b]，除法定义较复杂
//则在模为n下的模运算结果的取值范围是左闭右开区间[0, n)
//有限交换群：
//有限交换群(S,@)是在集合S上的运算@，满足下面四个特性：
//封闭性：S中的a与b进行计算后结果 a@b 仍属S
//单位元：S中存在单位元e使任何元素a与之计算后不变 a@e=a e@a=a
//结合律：S中任意a，b，c有 (a@b)@c=a@(b@c)
//逆元：S中任意a，存在且唯一存在b使 a@b=b@a=e
//整数集Z上的模运算就是一个有限交换群
//群的阶：
//对于S中某一a，计算由a及运算@所能生成的所有元素，具体的即：
//对于k>=1，定义 a^k 为a^k=a@a@a...@a，重复k次运算
//群Zn+中 a^k = ka % n，群Zn*中 a^k = a^k % n
//得到的所有解是由a生成的子群<a>，比如群Z6+中a=2，a^2={2,4,0,2,4,0...}
//群S中a的“阶”记作ord(a)，定义为满足a^t = e的最小正整数t，其中e是单位元
//对于群(S,@)中的a，有ord(a)=|<a>|，即a的阶等于它的子群的规模，即所有解的数量
//拉格朗日定理：
//有限群(S,@)有一个子群(S1,@)，则|S1|是|S|的一个约数，即|S|可以被|S1|整除
//
//(2)模线性方程
//a | b 意为a能被b整除，即a % b = 0或者a / b的余数为0
//模线性方程ax mod= b(mod n)，或写作a * x % n = b，是模运算中群Zn+的模型
//即a做x次相加运算，其中a和b都小于等于n
//可以将上式变换成ax + ny = b，其中y是非负整数，该形式有解的充分条件是gcd(a, n) | b
//有解在模运算的意义上讲只有一个解，有解的充分条件基于有限群的拉格朗日定理
//定理0：
//方程ax mod= b(mod n)如果有d = gcd(a, n)
//则在Z中有<a>=<d>={0,d,2d,...,((n/d)-1)d}，即|<a>|=n / d
//定理1：
//方程ax mod= b(mod n)对于未知量x有解，当且仅当gcd(a, n) | b，即d | b
//定理2：
//方程ax mod= b(mod n)对模n有d个不同的解，其中d = gcd(a, n)，或者无解
//定理3：
//设d = gcd(a, n)，假设有x和y使d = ax + ny(x和y可由扩展Euclid得到)
//如果d | b，则方程ax mod= b(mod n)有一个解x0，满足x0 = x*(b/d)%n
//其中x可由扩展Euclid得到
//定理4：
//假设方程 ax mod= b (mod n) 有解，即d | b，其中d = gcd(a, n)
//若存在x0为该方程的任意一个解，则该方程对模n恰有d个不同的解
//分别为xi = x0 + i*(n/d)，其中i= 1, 2, ..., d-1
//
//我忠实的实现了算法导论中关于模线性方程的论述

#include "general_head.h"
//extended_euclid.cpp
extern int extended_euclid(int a, int b, int& x, int& y);

bool modular_linear_equation(int a, int b, int n, int& d, int *x)
{//输入模线性方程ax mod= b(mod n)中的系数a，b，n
 //返回该模线性方程是否有解，若有解则存储于数组x中，解的数量是d，下标从0到d-1
	int tmp_x, tmp_y;
	d = extended_euclid(a, n, tmp_x, tmp_y);
	if(b % d == 0){
		int x0 = ((tmp_x * b / d % n) + n) % n;
		for(int i = 0; i < d; ++ i)
			x[i] = (x0 + i * n / d) % n;
		return(true);
	}
	else
		return(false);
}
