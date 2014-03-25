//搜索头文件
//search.h

//支持搜索一节的自定义数据结构

#include <utility>
#include <string>
#ifndef NULL
#define NULL 0
#endif
using std::pair;
using std::string;

struct bi_node{
	//专门支持双向广度优先搜索算法的节点
	
	int b_x;					//点的x坐标
	int b_y;					//点的y坐标
	pair<int, int> b_fa;		//点的父节点坐标
								//s_fa.first为x坐标
								//s_fa.second为y坐标
	bi_node(int cx = 0, int cy = 0,
			pair<int, int> cf = pair<int, int>(-1, -1))
		//-1指代父节点默认为不存在
		: b_x(cx), b_y(cy), b_fa(cf){
	}
	bi_node(const bi_node& cr)
		: b_x(cr.b_x), b_y(cr.b_y), b_fa(cr.b_fa){
	}
	//在使用find算法需要定义operator==
	//而且这个重载需要比较严格的写法
	bool operator==(const bi_node& r) const{
		return(b_x == r.b_x && b_y == r.b_y);
	}
};
struct star_node{
	//专门支持A*启发式搜索算法的节点
	
	string s_status;			//矩阵状态用string表示
	int s_h;					//s_h指代从当前点到目标点的估计长度
								//在A*算法中相当于h(i)函数
	int s_g;					//s_g表示从起点到当前点的路径长度
								//在A*算法中相当于g(i)函数
	star_node *s_fa;			//指向当前节点的父节点
	star_node(string cs = "", int ch = 0, int cg = 0, star_node *cf = NULL)
		: s_status(cs), s_h(ch), s_g(cg), s_fa(cf){
	}
	star_node(const star_node& cr)
		//支持复制指针的操作
		: s_status(cr.s_status), s_h(cr.s_h), s_g(cr.s_g), s_fa(cr.s_fa){
	}
	bool operator==(const star_node& r) const{
		return(s_status == r.s_status);
	}
};






