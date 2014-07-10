//解析几何头文件
//geometry.h

//支持解析计算几何一章的自定义数据结构

#include <iostream>
using std::cout;
using std::endl;

struct node{
	//二维坐标系顶点
	
	double n_x;			//点的x坐标
	double n_y;			//点的y坐标

						//专门支持扫除线算法
	int n_idx;			//n_idx指代点所在线段的所在数组的下标号
	int n_lt;			//n_lt指代点是所在的线段的左端点(1)或右端点(0)
	node(double cx = 0, double cy = 0, double cidx = 0, double clt = 0)
		: n_x(cx), n_y(cy), n_idx(cidx), n_lt(clt){
	}
	node(const node& cr)
		: n_x(cr.n_x), n_y(cr.n_y), n_idx(cr.n_idx), n_lt(cr.n_lt){
	}
	bool operator==(const node& cr) const{
		return(n_x == cr.n_x && n_y == cr.n_y &&
				n_idx == cr.n_idx && n_lt == cr.n_lt);
	}
	void n_print(){
		cout << "node (x:" << n_x << ",y:" << n_y << ")";
	}
};
struct vec{
	//二维坐标系向量

	double v_x;			//v_x指代向量的x坐标
	double v_y;			//v_y指代向量的y坐标
	vec(double cx = 0, double cy = 0)
		: v_x(cx), v_y(cy){ 
	}
	vec(const node& cbeg, const node& cend)
		//cbeg为向量起点，cend为向量终点
		: v_x(cend.n_x - cbeg.n_x), v_y(cend.n_y - cbeg.n_y){
	}
	vec(const vec& cr)
		: v_x(cr.v_x), v_y(cr.v_y){ 
	}
};
struct segment{
	//二维坐标系线段

	node s_lt;			//s_lt指代当前线段的左端点，即x坐标较小的点
	node s_rt;			//s_rt指代当前线段的右端点，即x坐标较大的点
	segment()
		: s_lt(), s_rt(){
	}
	segment(const node& cl, const node& cr)
		: s_lt(cl), s_rt(cr){ 
	}
	segment(const segment& cs)
		: s_lt(cs.s_lt), s_rt(cs.s_rt){ 
	}
	void s_print(){
		cout << "segment  left ";
		s_lt.n_print();
		cout << "  right ";
		s_rt.n_print();
		cout << endl;
	}
};
