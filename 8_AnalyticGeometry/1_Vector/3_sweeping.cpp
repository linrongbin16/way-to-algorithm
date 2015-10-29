//扫除算法
//sweeping.cpp

//判断一组线段中是否存在相交的线段

//显然这个问题不能通过考察每条边，判断它和其他所有条线段是否相交的方法来求
//
//1)扫除技术
//在平面中设置垂直扫除线s，垂直于x轴，平行于y轴，从左向右依次经过所有线段
//若当垂直扫除线s位于x坐标时，线段a和b同时与s相交
//若此时a与s的交点y坐标大于b与s的交点y坐标，则称在x处，a > b，这是一个全序关系
//若a，b线段相交，则s从左向右经过此交点时
//a与b的全序关系会变化(a > b变为a < b)，即
//s在a和b的交点左边时，a与s的交点y坐标大于b与s的交点y坐标
//s在a和b的交点右边时，a与s的交点y坐标小于b与s的交点y坐标
//2)扫除线的移动
//事件点调度：
//将所有线段的两端点按照其x坐标从小到大排序
//若x坐标相同，则以此端点为线段左端点的优先，再以此端点的y坐标较小的优先
//排序之后的所有端点组成事件点序列
//扫除线状态(T)：
//垂直扫除线s可以从左到右依次经过线段上的每一个端点，维护一个映射T
//垂直扫除线s在移动中遇到左端点时将该端点所在的线段加入T中
//遇到右端点时将该端点所在的线段从T中删除
//扫除线s的状态T维护的信息是当s位于某个x坐标时
//s当前穿过了哪些线段，这些线段与s相交的点的y坐标
//当s经过某个x坐标时有两线段a和b的全序关系发生了变化，则认为a和b线段相交
//T需要实现操作：insert(p)，delete(p)，above(p)，below(p)
//insert(p)：把线段p插入T中
//delete(p)：从T中删除线段p
//above(p)：返回T中紧靠线段p上面的线段
//below(p)：返回T中紧靠线段p下面的线段
//通过红黑树实现T结构，T中的线段按照线段与扫除线交点的y坐标大小排序
//
//我忠实的实现了算法导论中关于扫除法判断线段相交的描述

#include "general_head.h"
#include "geometry.h"
//segments_intersection.cpp
extern bool segments_intersection(segment l1, segment l2);
bool compare(node a, node b);
multimap<double, node, less<double> >::iterator find_node(
		multimap<double, node, less<double> >& t, node p);

bool sweeping(segment *l, int n) 
{//线段集l有n条线段，下标从0到n-1，判断线段集中是否存在相交线段
	multimap<double,			//键值double指代点的y坐标
		node,					//映射node指代y坐标所在点
		less<double> > T;		//以键值从小到大排序
								//T维护垂直扫除线当前穿过的线段
								//T按照扫除线与线段的交点的y坐标从小到大排列
								//因为需要查找扫除线某个交点的上下距离最近的交点

	node s[MAX];				//s是线段集l的点集
	for(int i = 0; i < 2 * n; i += 2) 
		s[i] = l[i / 2].s_lt, s[i + 1] = l[i / 2].s_rt;
	//将所有端点按照x坐标从小到大，是否左端点，y坐标从小到大进行排序
	sort(s, s + 2 * n, compare);
	//从左至右进行扫除
	for(int i = 0; i < 2 * n; ++ i){
		//扫除线从左向右依次经过
		node p = s[i];
		if(p.n_lt){
			//如果p点是其所在线段的左端点，将p点插入T中
			T.insert(make_pair(p.n_y, p));
			//above指代T中pos之上距离最近的点
			multimap<double, node, less<double> >::iterator above = T.end();
			//below指代T中pos之下距离最近的点
			multimap<double, node, less<double> >::iterator below = T.end();
			
			//pos指代T中刚刚插入的左端点p
			multimap<double, node, less<double> >::iterator pos = find_node(T, p);
			//考虑左端点p和它之上的点above
			if(pos != T.begin())
				above = -- pos;
			if(above != T.end() && 
					segments_intersection(l[(above->second).n_idx], 
						l[((++ pos)->second).n_idx]))
				//若T中pos所在的线段上有线段，并且pos和above所在的两线段相交
				return(true);

			//考虑左端点p和它之下的点below
			pos = find_node(T, p);
			if(pos != T.end() && pos != (-- T.end()))
				below = ++ pos;
			if(below != T.end() && 
					segments_intersection(l[(below->second).n_idx], 
						l[((-- pos)->second).n_idx]))
				//若T中pos所在的线段下有线段，并且pos与below所在的两线段相交
				return(true);
		}
		else{
			//如果p点是线段右端点，找出p点所在线段
			map<double, node, less<double> >::iterator above = T.end();
			map<double, node, less<double> >::iterator below = T.end();

			//找出这个右端点p所在线段的左端点，这个左端点已经属于T
			map<double, node, less<double> >::iterator pos = find_node(T, l[p.n_idx].s_lt);
			//若p所在线段的左端点pos之上有线段above
			if(pos != T.begin())
				above = -- pos;

			pos = find_node(T, l[p.n_idx].s_lt);
			//若p所在线段的左端点pos之下有线段below
			if(pos != T.end() && pos != (-- T.end()))
				below = ++ pos;

			if((above != T.end() && below != T.end()) &&
					segments_intersection(l[(above->second).n_idx], 
						l[(below->second).n_idx]))
				//若pos上下都有线段，且above与below两线段相交
				return(true);
			//删除左端点pos
			T.erase(pos);
		}
	}
	return(false);
}
bool compare(node a, node b) 
{
	if(a.n_x != b.n_x)	
		//两点x坐标不一致时，取x坐标较小者为先
		return(a.n_x < b.n_x);
	if(a.n_lt != b.n_lt)
		//若两点不都是线段左端点或右端点，取左端点者为先
		return((a.n_lt == 1) ? true : false);
	if(a.n_y != b.n_y)	
		//两点y坐标不一致时，最后取y坐标较小者为先
		return(a.n_y < b.n_y);
	//以上三种情况皆不成立
	//即x坐标与y坐标都相同，且都是所在线段的左端点或右端点，可以判断存在相交
	return(false);
}
multimap<double, node, less<double> >::iterator find_node(
		multimap<double, node, less<double> >& t, node p)
{//找出扫除线的节点p的迭代器
	for(multimap<double, node, less<double> >::iterator it = t.begin();
			it != t.end(); ++ it)
		if(it->first == p.n_y && it->second == p)
			//迭代器的键值y坐标相等，所映射的点的xy坐标也相等
			return(it);
	return(t.end());
}
