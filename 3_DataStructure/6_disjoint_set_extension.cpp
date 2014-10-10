//并查集扩展
//disjoint_set_extension.cpp

//前一篇的并查集是原始模型，若给出n条鱼，下标号从1到n，属于3个种族a，b和c
//其中a吃b，b吃c，c吃a，再给出k个结论，其中可能有真话也可能有假话
//比如i和j两条鱼属于同一个种族的鱼，或者i是吃j的鱼
//以下三种情况是假话：
//1)若某句话与之前的话冲突
//2)若某句话提到的鱼的下标号大于n
//3)若某句话提到鱼i吃i自己
//请判断k个结论中有多少假话
//题目原型为“PKU1182 食物链”

//本题的扩展主要在于不是直接的给出两个成员属于同一个集合这样直接的条件
//而是有些结论是两条鱼属于同一个集合，有些是两条鱼不属于同一个集合(相互吃)
//PKU1703 Find them, Catch them也是一个类似的题目：
//有n个成员，属于2个家族，给出k个结论(每一句都是真话)
//每个结论声明两个成员，他们属于同一个家族，或者不属于同一个家族
//
//这类题目的解法中会设置一个数组relation来标记每个成员与其父节点的关系
//在原始的并查集模型中成员和其父节点总是同属于一个家族的
//但在扩展问题中通过relation来标记成员与其父节点的关系
//因此在设置父节点时还需要额外的设置relation的值
//
//本文引用了“POJ-1182 食物链”，作者“飘过的小牛”

#include "general_head.h"
//数组father[i]指代成员i的父节点
//数组relation[i]指代成员i与其父节点father[i]的关系
int _disjoint_set_extension_father[MAX];
int _disjoint_set_extension_relation[MAX];

void disjoint_set_extension_init()
{
	for(int i = 0; i < MAX; ++ i){
		_disjoint_set_extension_father[i] = i;
		_disjoint_set_extension_relation[i] = 0;
	}
}
void disjoint_set_extension_find_father(int p)
{//与之前的find_father操作的不同之处在于增加了relation数组的标记
	if(_disjoint_set_extension_father[p] == p)
		return(p);
	int tmp = _disjoint_set_extension_father[p];
	_disjoint_set_extension_father[p] =
		_disjoint_set_extension_find_father(tmp);
	//更新成员p及其父节点tmp的关系
	_disjoint_set_extension_relation[p] =
		(_disjoint_set_extension_relation[p] +
		 _disjoint_set_extension_relation[tmp]) % 3;
	return(_disjoint_set_extension_father[p]);
}
