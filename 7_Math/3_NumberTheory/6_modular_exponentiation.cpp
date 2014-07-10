//模幂运算
//modular_exponentiation.cpp

//求a^b mod n，或者写作a^b % n

//1)基础概念
//由于文本排版的原因无法规范的描述概念与定理中的相关符号，读者可以参考相关数论的书籍
//欧拉phi函数：群Zn*的规模|Zn*|表示为$(n) = n(*(1-1/p))
//其中p包括能整除n的所有素数
//欧拉定理：对于任意整数n > 1，a^($(n)) mod= 1(mod n)对所有Zn*中的a都成立
//费马定理：若p为素数，则a^(p-1) mod= 1(mod n)对所有Zn*中的a都成立
//若存在g使得ord(g)=|Zn*|，则对模n，Zn*中每个元素都是g的幂，称g是Zn*的原根或生成元
//离散对数定理：若g是Zn*的一个原根，则等式g^x mod= g^y(mod n)成立
//当且仅当x mod= y(mod $(n))成立
//
//2)具体实现
//通过求幂运算法(详见本章第1节求幂运算)求解a^b mod n

#include "general_head.h"

int modular_exponentiation(int a, int b, int n)
{//求a^b mod n
    int d(1);
    while(b > 0){  
         if((b & 1) == 1)
            d = (d * a) % n;
         a = (a * a) % n;
         b >>= 1;	//b除以2
    }
    return(d);
}
