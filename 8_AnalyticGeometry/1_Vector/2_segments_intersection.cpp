//线段相交
//segments_intersection.cpp

//判断两线段是否相交

//对于一条线段和一条直线，若线段两端点在直线的不同两侧则称该线段“跨越”了直线
//线段l1和l2相交，满足下面两条件中其一或同时满足均可：
//1)两条线段l1和l2，每一条的两端点都在另一线段的不同两侧
//即l1的两端点跨越l2所在的直线，l2的两端点也跨越l1所在直线
//设l1两端点为a和b，l2两端点为c和d
//则a->b和a->c的叉积值与a->b和a->d的叉积值的正负号相反
//这时线段l1与l2相交，且l1和l2的端点都不在另一个线段上
//2)一条线段的端点在另一条线段上，边界情况
//若一条线段的一端点在另一条线段所在的直线上
//且端点a的x和y坐标在另一线段的两端点c和d的x和y坐标区间内，则端点a在另一线段l2上
//否则a不在l2上
//
//我忠实的实现了算法导论中关于两线段相交的描述

#include "general_head.h"
#include "geometry.h"
//cross.cpp
extern double cross(vec v1, vec v2);
bool on_segment(segment l, node p);

int segments_intersection(segment l1, segment l2) 
{//若l1和l2中不存在一端点在另一线段上的情况，且相交，返回1
 //若l1和l2中一端点在另一线段上，返回2
 //若l1和l2不相交返回0
	double d1 = cross(vec(l2.s_lt, l2.s_rt), vec(l2.s_lt, l1.s_lt));
	double d2 = cross(vec(l2.s_lt, l2.s_rt), vec(l2.s_lt, l1.s_rt));
	double d3 = cross(vec(l1.s_lt, l1.s_rt), vec(l1.s_lt, l2.s_lt));
	double d4 = cross(vec(l1.s_lt, l1.s_rt), vec(l1.s_lt, l2.s_rt));

	if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && 
			((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) 
		//若存在l1两端点在l2直线不同两侧，且l2两端点在l1直线不同两侧
		//即可判定l1，l2线段相交
		//该判断条件也可写作d1 * d2 < 0 && d3 * d4 < 0
		return(1);
	if(d1 == 0 && on_segment(l2, l1.s_lt))
		//若l1上左端点在l2所在直线上
		//判断该端点是否位于线段l2上，后面的判断类似
		return(2);
	if(d2 == 0 && on_segment(l2, l1.s_rt))
		return(2);
	if(d3 == 0 && on_segment(l1, l2.s_lt))
		return(2);
	if(d4 == 0 && on_segment(l1, l2.s_rt))
		return(2);
	//不属于上述情况的l1和l2不相交
	return(0);
}
bool on_segment(segment l, node p)
{//判断点p是否在线段l的x和y坐标区间内
	return(p.n_x >= min(l.s_lt.n_x, l.s_rt.n_x) &&
			p.n_x <= max(l.s_lt.n_x, l.s_rt.n_x) &&
			p.n_y >= min(l.s_lt.n_y, l.s_rt.n_y) &&
			p.n_y <= max(l.s_lt.n_y, l.s_rt.n_y));
}
