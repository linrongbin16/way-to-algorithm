//旋转卡壳
//rotating calipers

//用旋转卡壳方法求一凸多边形的直径

//旋转卡壳算法的核心思路是用一对卡壳(平行线)卡住凸多边形然后旋转一圈
//被卡壳正好卡住的两个顶点称为对踵点
//
//1)用旋转卡壳求凸多边形直径
//凸多边形直径: 
//凸多边形上相距最远的任意两点间的距离
//注意这两点不一定是凸多边形的顶点 也可以是凸多边形的边上任意一点
//
//初始时选取凸多边形上y坐标最大和最小的两个点 这两点是初始的一对对踵点
//构造两条水平平行线穿过这两个点 计算出两平行线间距离 并维护这个最大距离
//重复以下步骤: 
//按照固定一个方向同时旋转这两条线 总是保持两条线相互平行
//直到其中一条线与凸多边形上的一条边重合
//这时产生一个新的对踵点 计算两平行线间距离并于前一状态时的距离比较
//若当前的距离更大则更新最大距离
//直到两平行线再次回到凸多边形上y坐标最大和最小的两点 算法结束
//两平行线的最大距离即为凸多边形直径
//
//在旋转中 当两条平行线都不与凸多边形上的边完全重合时
//两条平行线分别与凸多边形上一个顶点相切
//
//在旋转过程中 每次平行线停留的位置总是其中一条平行线与凸多边形上一条边完全重合
//这时另一条平行线与凸多边形的位置关系可能有三种情况
//i)另一条平行线与凸多边形的一个顶点相切
//在这种情况下 两平行线间距离是多边形的一个顶点到另一条边所在直线的距离
//ii)另一条平行线与凸多边形的一条边也完全重合 即凸多边形上这两条边是相互平行的
//在这种情况下 两平行线间距离是多边形的两条平行的边所在直线的距离
//
//但在求凸多边形直径时 只需要判断其中一条平行线与凸多边形的边重合即可
//本文实现旋转卡壳求凸多边形直径
//在后一节凸包中读者可以看到其实凸多边形是一个凸包
//
//2)用旋转卡壳求凸多边形宽度
//凸多边形宽度: 
//凸多边形上相距最近的任意两点间的距离 即凸多边形直径的相反意思
//这里的两点也是凸多边形上的任意两点 不只是顶点
//
//使用旋转卡壳的方法基本一样 仍然是将一对平行线按照一定方向沿着凸多边形外围旋转一圈
//每当两条平行线中的一条与凸多边形的边重合时 就停下来
//然后计算并更新两平行线间的最小距离 直到重新回到起始的两顶点 算法结束
//
//3)用旋转卡壳求其他问题
//旋转卡壳方法还可以应用于其他很多几何问题 甚至三维或多维空间中的几何问题: 
//i)距离计算
//凸多边形的直径
//凸多边形的宽度
//两凸多边形之间的最小距离
//两凸多边形之间的最大距离
//ii)外接矩形
//凸多边形的最小面积外接矩形
//凸多边形的最小周长外接矩形
//iii)三角剖分
//洋葱三角剖分
//螺旋三角剖分
//四边形剖分
//iv)凸多边形属性
//合并两凸多边形
//两凸多边形的公切线
//两凸多边形的相交
//两凸多边形的临界切线
//两凸多边形的矢量和
//v)最薄截面
//最薄横截带
//
//本文引用了“旋转卡壳(系列文档)” 作者“ACMaker”

#include "general_head.h"
#include "geometry.h"
//ray.cpp
extern double node_distance(node a, node b);
//ray.cpp
extern double node2segment_distance(segment l, node p);
double cosine_c(node a, node b, node c);
bool get_back(node *s, int n, int low, int high, int l, int h);
void rotate(node *s, int n, int& l, int& h, vec& vl, vec& vh);

double rotating_calipers(node *s, int n)
{//凸多边形s有n个顶点 下标从0到n-1 顶点按照逆时针方向排列
 //返回凸多边形的直径
	//找出多边形上y坐标最大顶点high和最小顶点low作为旋转的起始顶点
	int low(0), high(0);
	for(int i = 0; i < n; ++ i){
		if(s[high].n_y < s[i].n_y)
				high = i;
		if(s[low].n_y > s[i].n_y)
				low = i;
	}
	//从high和low两顶点开始旋转
	int l(low), h(high);
	//水平向右向量vl指代与low点相切的平行线的初始水平状态
	//水平向左向量vh指代与high点相切的平行线的初始水平状态
	//将vl和vh两向量按照逆时针方向沿着凸多边形旋转
	//这样设置两向量的方向可以保证向量每次旋转的角度都小于180度 也可设置为相反的方向
	vec vl(1, 0), vh(-1, 0);
	//凸多边形直径
	double diam(0);
	int cnt(0);
	do{
		rotate(s, n, l, h, vl, vh);
		node l_tmp(s[l].n_x + vl.v_x, s[l].n_y + vl.v_y);
		diam = max(diam, node2segment_distance(segment(s[l], l_tmp), s[h]));
		
		//循环终止条件
		//当旋转的两顶点都再次回到起始位置时 算法结束
	}while(cnt += (int)get_back(s, n, low, high, l, h), cnt != 2);
	return(diam);
}
bool get_back(node *s, int n, int low, int high, int l, int h)
{//旋转的顶点l和h只需要旋转半圈
 //顶点l回到h的起始位置high
 //顶点h回到l的起始位置low
	if(s[h] == s[low])
		return(true);
	if(s[l] == s[high])
			return(true);
	return(false);
}
void rotate(node *s, int n, int& l, int& h, vec& vl, vec& vh)
{//将向量vl和vh逆时针旋转 顶点l和h也相应的进行挪动
	//next_l是l的下一个顶点 next_h是h的下一个顶点
	int next_l(l + 1), next_h(h + 1);
	if(next_l == n)
		next_l = 0;
	if(next_h == n)
		next_h = 0;

	//点pl是顶点l沿着向量vl移动一段正数距离得到的点
	//点ph是顶点h沿着向量vh移动一段正数距离得到的点
	//这两个点可以与凸多边形上l和h 以及它们的下一个点next_l和next_h组成两个三角形
	//从而求出向量vl和vh旋转的角度
	node pl(s[l].n_x + vl.v_x, s[l].n_y + vl.v_y);
	node ph(s[h].n_x + vh.v_x, s[h].n_y + vh.v_y);
	//余弦定理c^2 = a^2 + b^2 - 2ab*cos(C)
	//其中a b c是三角形三边长 C是边c对应的角
	//向量vl和vh绕凸多边形旋转的过程中 转过的角度总小于180度
	//余弦函数cos在0到180度上单调递减 当C=0度时cos(C)=1 C=180度时cos(C)=-1
	//计算点l和h在旋转的三角形中的角度
	double angle_l = cosine_c(pl, s[next_l], s[l]);
	double angle_h = cosine_c(ph, s[next_h], s[h]);
	if(angle_l < angle_h){
		//cos值较小的角旋转角度较大
		//每次旋转都选取转角较小的作为下一次停止的位置
		//选择next_h作为下一个h顶点
		vh.v_x = s[next_h].n_x - s[h].n_x;
		vh.v_y = s[next_h].n_y - s[h].n_y;
		h = next_h;
		vl.v_x = -1 * vh.v_x;
		vl.v_y = -1 * vh.v_y;
	}
	else if(angle_l > angle_h){
		vl.v_x = s[next_l].n_x - s[l].n_x;
		vl.v_y = s[next_l].n_y - s[l].n_y;
		l = next_l;
		vh.v_x = -1 * vl.v_x;
		vh.v_y = -1 * vl.v_y;
	}
	else if(angle_l == angle_h){
		//若两角的cos值相等则两向量旋转的角度相同
		//说明旋转到的凸多边形两边相互平行
		//顶点l和h都改变
		vh.v_x = s[next_h].n_x - s[h].n_x;
		vh.v_y = s[next_h].n_y - s[h].n_y;
		h = next_h;
		vl.v_x = s[next_l].n_x - s[l].n_x;
		vl.v_y = s[next_l].n_y - s[l].n_y;
		l = next_l;
	}
}
double cosine_c(node a, node b, node c)
{//计算三角形abc中顶点c的角度cos值
	double a_dist = node_distance(b, c);
	double b_dist = node_distance(a, c);
	double c_dist = node_distance(a, b);
	//cos(C) = (a^2 + b^2 - c^2)/(2ab)
	return((a_dist * a_dist + b_dist * b_dist - c_dist * c_dist) /
			(2 * a_dist * b_dist));
}
