//射线判别法
//ray.cpp

//判断点p是否位于给定的多边形内

//1)叉乘判别法
//按照逆时针方向遍历多边形上的所有端点
//对于每条边的端点pi和pj，其中pj在pi的逆时针方向
//计算两端点与点p组成的向量p->pi和p->pj的叉积
//在端点按照逆时针排列的情况下，所有的向量叉积都是正值
//在端点按照顺时针排列的情况下，所有的向量叉积都是负值
//无论按照顺时针或逆时针，所有的向量叉积的正负号都不变
//该方法只适用于判断点在凸多边形中
//2)面积和判别法
//按照顺时针或逆时针方向遍历多边形上的所有边
//对于每条边，计算这条边与点p组成的三角形的面积
//像这样累加每条边与点p组成的三角形的面积得到所有三角形面积之和
//比较三角形面积之和与多边形面积是否相等
//若相等则点p在多边形内或在多边形上，否则在多边形外
//该方法只适用于判断点在凸多边形中
//3)角度判别法
//计算p与多边形上的每条边的两端点组成两个向量之间的夹角
//累加所有两向量之间的夹角
//若夹角角度之和等于360度则点p在多边形内
//多夹角角度之和等于180度则点p在多边形上
//否则点p在多边形外
//可以通过三角形的余弦公式计算两向量的夹角
//4)射线判别法
//若点p在多边形内，则点p的水平向左射线与多边形所有边交点数之和为奇数
//若点p在多边形上，或在多边形外，则交点数为偶数
//按逆时针方向依次判断点p的水平向左射线与多边形的每条边是否相交，并累加这个相交的次数
//若累加和为奇数则点p在多边形内，若累加和为偶数则点p在多边形上或多边形外
//
//但也存在边界情况
//若点p在多边形外，点p的水平向左射线与多边形的一个顶点相切
//则点p与多边形有奇数个交点，但点p在多边形外
//若点p在多边形外，点p的水平向左射线与多边形的一条边完全重合
//则点p与多边形有无穷多交点
//若点p在多边形内，点p的水平向左射线与多边形的一条边有一个正常的交点
//而且与多边形中的一个凹部分的顶点相切
//则点p与多边形有偶数个交点，但点p在多边形内
//
//因此射线判别法无法判定当点p出现类似上述边界情况时点p与多边形的位置
//但可以通过一些辅助的方法来尝试解决这个问题，比如一种扰动技术
//对于一条边，判断射线与该边相交之后，再轻微的上下挪动射线的y坐标
//再次判断射线与该边是否相交，从而得到该边是否恰好与该边相交与端点
//
//本文实现的射线判别法不考虑上述的边界情况，只实现最基础的射线判别算法
//
//在上述算法中可以再增加一处预判断
//多边形所有顶点的x和y坐标分别有两个最值，即最大最小的x坐标和最大最小的y坐标
//若点p的x和y坐标明显在多边形的x和y坐标的最值的区域之外，则可直接判断点p不在多边形内

#include "general_head.h"
#include "geometry.h"
//cross.cpp
extern double cross(vec v1, vec v2);
//segments_intersection.cpp
extern bool on_segment(segment l, node p);
//segments_intersection.cpp
extern int segments_intersection(segment l1, segment l2);
bool faraway(node *s, int n, node p);
double node2segment_distance(segment l, node p);
double node_distance(node a, node b);

int ray(node *s, int n, node p)
{//多边形s有n个顶点，下标从0到n-1，顶点按照逆时针排列
 //判断点p是否在多边形s内
 //若p点在多边形内返回0，若在多边形上返回1，若在多边形外返回2
	//预判断
	if(faraway(s, n, p))
		return(2);

	//累加次数
	int cnt(0);
	//r是p的水平向左射线，实作为一条左端点x坐标为无穷小的线段
	segment r(node(-INF, p.n_y), p);	
	for(int i = 0; i < n; ++ i){
		//遍历多边形的每条边i，判断该边与点p射线是否相交，并累加次数
		segment l(s[i], s[i + 1]);
		if(i == n - 1)
			l.s_rt = s[0];
		
		if(node2segment_distance(l, p) == 0 && on_segment(l, p))
			//计算点p到该边所在直线的距离，若为0则点p在该边所在直线上
			//再判断点p是否在该边的区域内，若在则点p在该边上
			return(1);
		if(segments_intersection(l, r))
			//若点p射线与该边相交
			++ cnt;
	}
	if(cnt % 2)
		//若相交的次数累加和为奇数则在多边形内
		return(0);
	else
		//若相交的次数累加和为偶数则在多边形外
		return(2);
}
bool faraway(node *s, int n, node p)
{//判断点p是否在多边形区域外
	double x_min(INF), x_max(-INF), y_min(INF), y_max(-INF);
	for(int i = 0; i < n; ++ i){
		x_min = min(x_min, s[i].n_x);
		x_max = max(x_max, s[i].n_x);
		y_min = min(y_min, s[i].n_y);
		y_max = max(y_max, s[i].n_y);
	}
	if(p.n_x < x_min || p.n_x > x_max || p.n_y < y_min || p.n_y > y_max)
		return(true);
	else
		return(false);
}
double node_distance(node a, node b) 
{
	return(sqrt(pow((double)b.n_x - a.n_x, (double)2) + 
				pow((double)b.n_y - a.n_y, (double)2)));
}
double node2segment_distance(segment l, node p)
{//计算点p到线段l所在直线的距离
	if(l.s_lt.n_y == l.s_rt.n_y)
		//若线段l所在直线与x轴平行，则点p到该直线的距离即为y坐标之差
		return(fabs(p.n_y - l.s_lt.n_y));
	if(l.s_lt.n_x == l.s_rt.n_x)
		//若线段l所在直线与y轴平行，则点p到该直线的距离即为x坐标之差
		return(fabs(p.n_x - l.s_lt.n_x));
	//点p到线段l所在直线的距离为lt->p和lt->rt的叉积除以线段l的长度
	return(fabs(cross(vec(l.s_lt, p), vec(l.s_lt, l.s_rt)) /
			node_distance(l.s_lt, l.s_rt)));
}
