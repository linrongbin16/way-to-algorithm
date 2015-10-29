//快速凸包算法
//quick convex hull

//用快速凸包算法求一个点集的凸包

//快速凸包算法使用分而治之的策略
//初始时选取点集中最左下角和最右上角两个顶点a和b a和b一定是凸包顶点
//连接a到b得到一个向量a->b
//并且将点集划分为两个子点集 分别在向量a->b的左右两边
//设a->b右边的子点集为R 左边的子点集为L L和R都有可能是空集 即不包含顶点
//在向量a->b左边的子集L中找出一个距离a->b所在直线距离最远的顶点c
//则c是一个新的凸包顶点
//连接a到c c和b 得到两个新的向量a->c和c->b
//向量a->c将子集L又划分为新的左右两个子集L'和R' L'和R'可能是空集
//向量c->b则将子集L划分为新的左右两个子集L''和R'' L''和R''可能是空集
//注意其中R'和R''基本上是重合的 并且都在点集的内侧 其中没有凸包顶点
//而L'和L''在点集的外侧 其中包含凸包顶点
//分别继续递归的求L'和L''中距离向量a->c和c->b所在直线距离最远的顶点
//即为新的凸包顶点 直到其新的左边子集为空集
//而右边子集位于点集的内侧 不需要进行递归
//
//以上递归最终可以找出向量a->b的右边子集R的所有凸包顶点
//再反向对向量b->a进行同样的只递归右边子集的过程 即可得到所有的凸包顶点
//
//由于排版原因本文无法提供详细的图形
//读者可以参考"快速凸包算法(百度文库ppt)" 作者"孙晓鹏(博士 教授)"
//其中有比较好的一个例图
//
//本文引用了"[Poj 2187]计算几何之凸包(二){更高效的算法}" 作者"Var Bob:^Joy"
//其中有关于该算法的实现代码
//该文档中的代码试图在存储点集s的数组上"原地"改变点的位置
//将一个向量左右两边的点分开放在数组的前后两部分 并用下标记录左右两个区域
//我没有实际测试 但经过阅读我认为代码和该算法的描述并不一致 存在一些问题
//在数组s上"原地"将所有点按照相对于向量的位置进行重新摆放确实是效率最快的办法
//但需要一些比较麻烦的操作 而该文档中的代码并没有能够有效的进行操作
//本文是我自己实现的 比较易懂 读者可以同时阅读这篇文档中的代码进行比较

#include "general_head.h"
#include "geometry.h"
//cross.cpp
extern double cross(vec v1, vec v2);
//ray.cpp
extern double node_distance(node a, node b);
bool compare(node a, node b);
void quick_core(vector<node> s, node a, node b, vector<node>& con);

void quick_convex_hull(vector<node> s, vector<node>& con)
{//点集s有n个顶点 下标从0到n-1 返回凸包顶点存储于数组con中
	con.clear();
	//a是点集s中最左下角顶点 b是点集s中最右上角顶点
	node a(INF, INF), b(-INF, -INF);
	vector<node>::iterator a_pos, b_pos;
	for(vector<node>::iterator it = s.begin(); it != s.end(); ++ it){
		if(compare(*it, a)){
			//若it点在a点左下角 则将a更新为it
			a = *it;
			a_pos = it;
		}
		if(compare(b, *it)){
			//若b点在it点左下角 则将b更新为it
			b = *it;
			b_pos = it;
		}
	}
	//a和b是凸包顶点
	con.push_back(a);
	con.push_back(b);
	//从s中删除a和b点
	s.erase(a_pos);
	s.erase(b_pos);

	//lt存储点集s中所有在向量a->b左边的点
	//rt存储点集s中所有在向量a->b右边的点	
	vector<node> lt, rt;
	for(vector<node>::iterator it = s.begin(); it != s.end(); ++ it){
		double c = cross(vec(a, b), vec(a, *it));
		if(c > 0)
			lt.push_back(*it);
		if(c < 0)
			rt.push_back(*it);
	}
	//求向量a->b的左边区域的点集lt中的凸包顶点
	quick_core(lt, a, b, con);
	//求向量b->a的左边区域的点集rt中的凸包顶点 即a->b的右边区域
	quick_core(rt, b, a, con);
}
bool compare(node a, node b)
{
	if(a.n_x != b.n_x)
		return(a.n_x < b.n_x);
	return(a.n_y < b.n_y);
}
void quick_core(vector<node> s, node a, node b, vector<node>& con)
{//位于a->b的左边区域的点集s 返回该区域中的凸包顶点 存储于数组con中
	//递归终止条件
	if(s.empty())
		return;

	//找出区域s中距离向量a->b所在直线距离最远的点far_pos
	vector<node>::iterator far_pos;
	double dist(0);
	for(vector<node>::iterator it = s.begin(); it != s.end(); ++ it){
		//点it到向量a->b所在直线的距离为a->b和a->it的叉积除以a->b的长度
		double d = cross(vec(a, b), vec(a, *it)) / node_distance(a, b);
		if(dist < d){
			//若点it到a->b所在直线的距离d比dist大则更新dist
			//并用far_pos记下当前点i是距离最远的点
			far_pos = it;
			dist = d;
		}
	}
	//将far_pos点加入凸包
	con.push_back(*far_pos);
	//在s中删去far_pos 但需要保留一个备份far
	node far(*far_pos);
	s.erase(far_pos);

	vector<node> lt, rt;
	for(vector<node>::iterator it = s.begin(); it != s.end(); ++ it){
		//遍历区域s中每个点i
		//计算a->far和a->it的叉积 若为正 则点it在向量a->far的左边
		if(cross(vec(a, far), vec(a, *it)) > 0)
			lt.push_back(*it);
		//计算far->b和far->i的叉积 若为正 则点it在far->b的左边
		if(cross(vec(far, b), vec(far, *it)) > 0)
			rt.push_back(*it);
	}
	//继续递归
	//求向量a->far左边的区域中的凸包顶点
	quick_core(lt, a, far, con);
	//求向量far->b左边的区域中的凸包顶点
	quick_core(rt, far, b, con);
}
