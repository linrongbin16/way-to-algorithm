//并查集
//disjoint_set.hpp

//一个集合中的成员分为若干个家族
//多次声明一对成员属于同一个家族之后
//再给出多对成员，查询它们是否属于同一家族

//并查集用于处理大量不相交集合的合并及查询，在使用中常以森林来表示
//集合中成员的分组是并查集的典型应用场景
//
//初始时将集合中每个点都设置为只包含自己的集合，然后每次合并都将两个集合合并为一个
//在并查集中的节点中设置一个父节点指针
//属于同一集合的节点父指针指向同一个父节点，而不属于同一集合的点指向不同的父节点
//并查集的两个操作是合并和查询
//初始化：将集合中每个节点的父指针指向自己
//查询：判断两节点的父节点是否相同
//合并：将两节点的父节点指针设置为相同的父节点

#include "general_head.h"

struct dis_node{
	int d_idx;
	dis_node *d_fa;
	dis_node(int ci = 0)
		: d_idx(ci), d_fa(NULL){
	}
};
struct disjoint_set{
private:
	dis_node d_set[MAX];
	dis_node* d_find_father(dis_node *p){
		//查询节点p的父节点
		if(p->d_fa != p)
			//属于同一集合的所有节点拥有相同的父节点
			//若节点p的父节点是p自己则该节点为所在集合的父节点
			//若节点p的父节点不是p自己，则递归的将p的父节点设置为自己父节点的父节点
			//这样的设置将查询的路径缩短了，使用了压缩路径技术
			p->d_fa = d_find_father(p->d_fa);
		return(p->d_fa);
	}
public:
	disjoint_set(){
		for(int i = 0; i < MAX; ++ i)
			//每个节点的父节点都指向自己，即该节点自己单独是一个集合
			d_set[i].d_idx = i, d_set[i].d_fa = &d_set[i];
	}
	void d_union(int p1, int p2){
		//将p2的家族合并入p1的家族，最早的祖先节点是p1家族的
		//pf1是p1的父节点，pf2是p2的父节点
		dis_node *pf1 = d_find_father(&d_set[p1]);
		dis_node *pf2 = d_find_father(&d_set[p2]);
		//将pf1设置为pf2的父节点
		//以后d_find_father操作会使p2家族中的所有节点的父节点最终都指向p1的父节点
		pf2->d_fa = pf1;
	}
	bool d_query(int p1, int p2){
		if(d_find_father(&d_set[p1]) ==
				d_find_father(&d_set[p2]))
			//如果它们的父节点是同一节点则属同一家族，否则不是
			return(true);
		else
			return(false);
	}
	void d_print(){
		for(int i = 0; i < MAX; ++ i){
			cout << "(node:" << i << ",set:";
			cout << d_set[i].d_fa->d_idx << ")" << endl;
		}
	}
};









