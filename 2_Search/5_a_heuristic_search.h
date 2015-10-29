#ifndef SEARCH_A_HEURISTIC_SEARCH_H
#define SEARCH_A_HEURISTIC_SEARCH_H 1
//A*启发式搜索算法
//a heuristic search

//八数码问题
//现有3*3矩阵  2  8  1
//             3  7  x
//             6  4  5
//目标是将其变换为目标状态  1  2  3
//                          4  5  6
//                          7  8  x
//每一次只能将x和其上下左右的相邻元素交换一次位置而其他数字不能随意改变位置
//使用A*启发式搜索算法求出最少交换次数的变化经过(最短路径)

//1)基础概念
//启发式搜索
//传统的dfs与bfs都是无差别的搜索所有节点的子空间
//启发式搜索类似bfs 对某节点周围的相邻节点进行进一步搜索
//但不同之处在于启发式搜索对这些待搜索的相邻节点进行一次评估
//计算出这些待搜索的相邻节点到目标节点的距离
//并按照距离将这些节点插入待搜索的节点队列中
//而每次只取出队头节点即距离目标节点最近的节点进行搜索
//启发式搜索将距离目标节点最近的节点设置为高优先级 从而降低时间复杂度
//
//A*搜索
//A*搜索是对状态空间的搜索
//所谓状态空间并不像之前的矩阵或序列这种几何空间而是时间上的状态
//比如魔方从乱序变化为有序的状态 魔方的每个步骤都是一个状态
//但是在八数码问题中有些状态可以转化为终点状态
//而有些状态可能是死循环而永远无法转化为终点状态
//
//评估函数f
//节点i的评估函数是f(i)=g(i)+h(i)
//f(i)是节点i的评估距离
//g(i)是从起点到节点i的路径的长度
//h(i)是从节点i到终点的路径的长度的估计值
//
//2)具体实现
//矩阵状态用string表示 每一个状态都可以看做空间中的一个节点
//比如"12345678x"为终点目标状态 "123"是矩阵第1行 "456"第2行 "78x"第3行
//"3124x7568"为起点初始状态 找出从起点到终点的最短变化次序
//本问题中并非所有初始状态都能经过变化转化为终点状态
//若不存在这样的变化路径则返回不存在 若存在则找出这样的最短变化路径
//
//评价函数f
//对于一个矩阵状态i的评价值f(i)=g(i)+h(i)
//g(i)
//指代起始状态到状态i的路径长度 即经过变换的次数
//可以对每次状态的变换进行累加计数
//h(i)
//指代从状态i到终点状态的估计路径长度
//在这里设置为当前状态i和终点状态的不同字符的个数之和 即两状态的差异
//比如"12345678x"和"1234567x8"的差异为2
//每次优先选取f值最小的状态进行下一次搜索
//状态也称为节点
//
//状态空间作为我们搜索的节点 也存在"已被访问"的问题
//之前几节的算法中都会使用visited数组来标记一个节点是否已被访问来避免重复访问
//当时间状态是节点时我们使用两个队列来记录未访问的节点和已访问的节点
//称这两个队列为open和close队列(open队列记录未访问节点close队列记录以访问节点)
//注意open队列是以评价值f作为队列优先级的
//开始时将起始状态插入open队列队尾 close队列初始化为空 之后重复以下步骤
//从open队头取一节点(该节点是open队列中距离目标状态最近的节点)
//若该节点就是目标状态节点则直接返回结果
//否则计算出该节点状态的所有相邻状态节点的评价值f
//并只将close中没有的(未被访问)节点新加入open队列中 close中已存在的节点不再加入
//直到open队列也没有找到目标状态则起始状态无解
//这就是"A*搜索的状态空间搜索框架"

//对于八数码或魔方这类状态空间的搜索 有一个通用的搜索框架
//维护两个队列open和close
//其中open保存当前待扩展的节点 close保存已经访问过的节点
//其中open是以评价函数f为优先级的队列 初始时open入队起点
//重复以下步骤直到open表为空
//取出open中的头节点i 将节点i加入close中
//若节点i是终点 沿着节点i的父节点指针回溯到起点即可得到最短变化路径
//若节点i不是终点 扩展它的所有邻节点(即x与上下左右四个方向进行交换)加入open中
//设它的一个邻节点为j 需要设置j的父节点指针是i从而可以从节点j回溯找回节点i
//下一次循环时会将邻节点j加入close中
//但仅仅依靠以上的操作仍然不够 状态空间中也存在"已被访问的节点"的问题
//比如魔方经过不同步骤的变化却会得到相同的状态 是因为有些变化路径饶了"弯路"
//假如close中已存在邻节点j说明节点j已被访问
//这时需要比较这个将要加入队列的邻节点j和队列中已存在的节点j的评价函数f值
//若将要加入的j比已存在的j的f值小 则将已存在的j替换为这个将要加入的j节点
//这个操作是为了选择最短的变化路径 而不选择那些冗余的路径
//重复上述步骤直到最终从open中取出的头节点是终点
//沿着父节点指针即可回溯找到最短路径
//若open为空时仍不能找到最短路径 则不存在这样的路径
//若最终找到目标状态 则根据节点中的父节点指针可以在cloes队列中回溯找到整条路径

//关于A*搜索更多内容请参考相关教材
//本文引用了"启发式搜索和A*" 作者"phylips@bmy"


#ifndef MAX
#define MAX 60
#endif
#ifndef INF
#define INF INT_MAX
#endif
#include <algorithm>
#include <deque>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <climits>
using namespace std;


struct hs_node
{
	string m_status;	//9 chars
	int m_h;
	int m_g;
	hs_node *m_father_node;

	bool operator==(const hs_node& node)
	{
		return(m_status == node.m_status && m_h == node.m_h
				&& m_g == node.m_g && m_father_node == node.m_father_node);
	}
};

bool heuristic_compare(hs_node a, hs_node b)
{
	return(a.m_g + a.m_h < b.m_g + b.m_h);
}
int x_position(hs_node a, char x)
{
	int index;
	for(index = 0; index < 9; ++index)
		if(a.m_status[index] == x)
			break;
	return(index);
}
void left_swap(hs_node& a, int pos)
{
	swap(a.m_status[pos - 1], a.m_status[pos]);
}
void right_swap(hs_node& a, int pos)
{
	swap(a.m_status[pos + 1], a.m_status[pos]);
}
void up_swap(hs_node& a, int pos)
{
	swap(a.m_status[pos - 3], a.m_status[pos]);
}
void down_swap(hs_node& a, int pos)
{
	swap(a.m_status[pos + 3], a.m_status[pos]);
}
bool left_bound(int pos)
{
	return(pos == 0 || pos == 3 || pos == 6);
}
bool right_bound(int pos)
{
	return(pos == 2 || pos == 5 || pos == 8);
}
bool up_bound(int pos)
{
	return(pos == 0 || pos == 1 || pos == 2);
}
bool down_bound(int pos)
{
	return(pos == 6 || pos == 7 || pos == 8);
}
int heuristic_difference(hs_node a, hs_node b)
{
	int diff = 0;
	for(int i = 0; i < 9; ++i)
		if(a.m_status[i] != b.m_status[i])
			++diff;
	return diff;
}
deque<hs_node>::iterator heuristic_minimum(deque<hs_node>& q, hs_node b)
{
	deque<hs_node>::iterator res;
	int minf = INF;
	for (deque<hs_node>::iterator i = q.begin(); i != q.end(); ++i) {
		int h = 0;
		//从q队列中选取差异最小的状态进行下一次搜索
		for (int j = 0; j < 9; ++j)
			if (i->m_status[j] != b.m_status[j])
				++h;
		if (minf > h + i->m_g) {
			minf = h + i->m_g;
            res = i; 
        }
	}
	return res;
}
void print_road(hs_node *pre)
{
	if(pre->m_father_node != NULL)
		print_road(pre->m_father_node);
	cout << "(status:" << pre->m_status << ",length:" << pre->m_g << ")" << endl;
}

void a_heuristic_search(hs_node beg, hs_node end)
{
    //beg是起始矩阵状态 end是目标矩阵状态
    //返回是否找到最短变化路径
    //若找到则close队列的队尾节点为目标状态 沿节点的父指针回溯找到整条路径
	deque<hs_node> open;
    deque<hs_node> close;
    close.clear();
	//搜索的总体方式采用bfs
	open.push_back(beg);
	while (!open.empty()) {
		//从open队列中选取距离end节点评价值f最小的节点minp进行搜索
		//这个操作维护open队列的优先级
		deque<hs_node>::iterator minp = heuristic_minimum(open, end);
		//若该节点为目标节点则加入close队尾并直接返回
        if (minp->m_status == end.m_status) {
            close.push_back(*minp);
            print_road(&close.back());
            return;
        }
		//否则继续搜索 close尾部加入minp open头部删除minp
		close.push_back(*minp);
		open.erase(minp);
	
		//open继续扩展minp节点的邻节点
		int pos = x_position(close.back(), 'x');
		//next是minp节点上下左右四个方向的邻节点 先初始化为minp节点
		hs_node next[4];
		for(int i = 0; i < 4; ++i)
			next[i] = close.back();

		//这里的函数指针纯粹是为了缩短代码
		//func_bound检测x的交换方向是否越界
		bool (*func_bound[4])(int);
		func_bound[0] = left_bound; func_bound[1] = right_bound;
		func_bound[2] = up_bound; func_bound[3] = down_bound;
		//func_swap进行x的交换操作
		void (*func_swap[4])(hs_node&, int);
		func_swap[0] = left_swap; func_swap[1] = right_swap;
		func_swap[2] = up_swap; func_swap[3] = down_swap;
		for (int i = 0; i < 4; ++i)
            //判断x交换的方向是否越界
			if (!func_bound[i](pos)) {
				func_swap[i](next[i], pos);
				//next[i]的父指针指向close的尾部元素
                //即刚从open中出队 刚进入close尾部的那个节点
				next[i].m_father_node = &close.back();
                //增加该节点的路径长度
				++next[i].m_g;
                //计算该节点到目标节点的距离
				next[i].m_h = heuristic_difference(next[i], end);
				//open_it为open迭代器 close_it为close迭代器
				deque<hs_node>::iterator open_it;
				deque<hs_node>::iterator close_it;
				//若close中不存在next[i]这个节点则将新节点插入open队尾
				if ( (close_it = find(close.begin(), close.end(), next[i])) == close.end() )
					open.push_back(next[i]);
			}
	}
	//经过这么多状态还没找到那就是没得解了
}

#endif
