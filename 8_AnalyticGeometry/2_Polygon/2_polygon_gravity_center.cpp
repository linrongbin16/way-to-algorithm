//多边形重心
//polygon_gravity_center.cpp

//求多边形重心

//1)三角形重心
//顶点为a，b，c的三角形重心为x = (xa + xb + xc) / 3，y = (ya + yb + yc) / 3
//2)多边形重心
//显然多边形重心不能像三角形一样求多边形的所有顶点的x和y坐标的平均值
//
//将多边形划分为多个三角形，求每个三角形的重心和面积
//设所有的三角形的重心和面积分别为o1，o2，...，on和s1，s2，...，sn
//多边形重心是这些三角形的重心坐标的面积加权平均值
//x = sum(xi * si) / sum(si)，y = sum(yi * si) / sum(si)
//其中1 <= i <= n
//
//具体的实现中选取二维坐标系中的原点作为一个划分点p
//按照逆时针方向依次遍历多边形的每条边，重复以下操作：
//多边形上一条边的两端点分别是s1和s2，其中s2在s1的逆时针方向
//该边的两端点与划分点p组成一个三角形，计算该三角形的重心及面积

#include "general_head.h"
#include "geometry.h"
//polygon_area.cpp
extern double triangle_area(node a, node b, node c);
pair<double, double> triangle_gravity_center(node a, node b, node c);

pair<double, double> polygon_gravity_center(node *s, int n)
{//多边形s有n个顶点，下标从0到n-1，顶点按逆时针方向排列
 //返回多边形重心，pair.first是x坐标，pair.second是y坐标
	node p(0, 0);
	//数组o指代三角形重心，数组area指代三角形面积
	pair<double, double> o[MAX];
	double area[MAX];
	for(int i = 0; i < n; ++ i){
		if(i != n - 1){
			o[i] = triangle_gravity_center(p, s[i], s[i + 1]);
			area[i] = triangle_area(p, s[i], s[i + 1]);
		}
		else{
			o[i] = triangle_gravity_center(p, s[i], s[0]);
			area[i] = triangle_area(p, s[i], s[0]);
		}
	}
	double a_sum(0);
	pair<double, double> o_sum(0, 0);
	for(int i = 0; i < n; ++ i)
		a_sum += area[i];
	for(int i = 0; i < n; ++ i){
		o_sum.first += o[i].first * area[i];
		o_sum.second += o[i].second * area[i];
	}
	return(make_pair(o_sum.first / a_sum, o_sum.second / a_sum));
}
pair<double, double> triangle_gravity_center(node a, node b, node c)
{//三角形顶点是a，b，c三点，返回三角形重心
	return(make_pair((a.n_x + b.n_x + c.n_x) / 3,
				(a.n_y + b.n_y + c.n_y) / 3));
}
