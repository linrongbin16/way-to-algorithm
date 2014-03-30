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
	
	int b_row;					//点的行下标
	int b_col;					//点的列下标
	pair<int, int> b_fa;		//点的父节点坐标
								//s_fa.first为行下标
								//s_fa.second为列下标
	bi_node(int cr = 0, int cc = 0, pair<int, int> cf = pair<int, int>(-1, -1))
		//-1指代父节点默认为不存在
		: b_row(cr), b_col(cc), b_fa(cf){
	}
	bi_node(const bi_node& cr)
		: b_row(cr.b_row), b_col(cr.b_col), b_fa(cr.b_fa){
	}
	//在使用find算法需要定义operator==
	bool operator==(const bi_node& r) const{
		return(b_row == r.b_row && b_col == r.b_col);
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






