//最近点对
//nearest neighbor

//找出一组点中最近的两点距离

//显然这个问题不能通过考察每个点 找出它和其他所有个点之间的距离的方法来求
//
//用分支策略对该问题求解
//将一组点p按照x坐标从小到大 y坐标从小到大排序 可以得到点集p所分布的平面区间
//对点集p的区间重复以下操作: 
//选取点集p的区间中x坐标在所有顶点正中间的顶点
//以它为基准设置一条垂直x轴的中线将当前区间划分为两个所含顶点数量一样的子区间
//若子区间包含的顶点数量大于3个 则继续递归的设置垂直线将子区间进行划分
//若子区间包含的顶点数量小于等于3个 则计算子区间中顶点之间的距离并找出最短距离
//考虑这样的情况相邻的左区间left与右区间right由中点p所在的垂直线划分成两部分
//通过上面递归的方法分别求出左区间和右区间中距离最近的两组点对
//比较这两个点对可以确定一对最近点对
//但无法确定是否存在这样一对点 其中一个属于左区间 另一个属于右区间
//它们之间的距离比上述已求出的最近点对更近
//因此考虑左右区间中所有点到中点p的x坐标
//若一个点与点p的x坐标或y坐标之差大于等于已求出的最近距离 则可以跳过该点
//因为两点的单x坐标或y坐标已经大于最近距离 则其实际距离必然大于等于最近距离
//若一个点与点p的x坐标和y坐标之差都小于已求出的最近距离
//则计算这两点的距离与已知最近距离比较 并进行更新


#include "general_head.h"
#include "geometry.h"
//ray.cpp
extern double node_distance(node a, node b);
bool compare_x(node a, node b);
bool compare_y(node a, node b);
double div_and_con(node *p, node *q, int beg, int end);

double nearest_neighbor(node *p, int n) 
{//一组顶点p有n个顶点 下标从0到n-1
	node q[MAX];
	sort(p, p + n, compare_x);
	return(div_and_con(p, q, 0, n - 1));
}
double div_and_con(node *p, node *q, int beg, int end) 
{//点集p有end-beg+1个节点 [beg, end]为左闭右闭区间
 //beg是子区间中最左下角的顶点下标 end是子区间中最右上角的顶点下标
 //q是顶点数组 用于支持计算垂直线两侧的点的距离的操作
	//递归终止条件
	if(beg + 1 == end)
		return(node_distance(p[beg], p[end]));
	if(beg + 2 == end)
		return(min(node_distance(p[beg], p[end]), 
					min(node_distance(p[beg], p[beg + 1]),
						node_distance(p[beg + 1], p[end]))));
	int mid = (beg + end) / 2;
	double dist = min(div_and_con(p, q, beg, mid), 
			div_and_con(p, q, mid + 1, end));
	int	n(0);
	for(int i = beg; i <= end; ++ i)
		//考虑当前子区间中的所有顶点
		if(fabs(p[i].n_x - p[mid].n_x) <= dist)
			//选择中点mid与左右两侧顶点的x坐标之差小于等于距离dist 则存储于数组q中
			//若一顶点与mid的x坐标之差大于dist 则这两点距离必然大于dist
			q[n ++] = p[i];
	//对这些与中点mid可能距离更短的顶点按y坐标从小到大排序
	sort(q, q + n, compare_y);
	for(int i = 0; i < n; ++ i)
		for(int j = i + 1; j < n; ++ j){
			//考虑这些点中所有任意两点之间距离
			if(fabs(q[i].n_y - q[j].n_y) >= dist)
				//若顶点i与顶点j的y坐标之差大于等于距离dist
				//则顶点i与j的距离必然大于dist
				//由于数组q中顶点按照y坐标从小到大排序
				//所以顶点j之后的顶点到顶点i的y坐标之差一定也大于等于dist
				//可以直接跳过
				break;
			//不相同的点之间的y坐标距离小于dist的
			//进行一次更新距离的判断
			dist = min(dist, node_distance(q[i], q[j]));
		}
	return(dist);
}
bool compare_x(node a, node b) 
{//按x坐标从小到大排序
 //若x坐标相等则按y坐标从小到大排序
	if(a.n_x != b.n_x)
		return(a.n_x < b.n_x);
	return(a.n_y < b.n_y);
}
bool compare_y(node a, node b) 
{//按y坐标从小到大排序
	return(a.n_y < b.n_y);
}
