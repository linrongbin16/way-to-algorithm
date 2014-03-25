//A*启发式搜索算法
//a_heuristic_search.cpp

//八数码问题：
//现有3*3矩阵： 2  8  1
//              3  7  x
//              6  4  5
//目标是将其变换为目标状态： 1  2  3
//                           4  5  6
//                           7  8  x
//每一次只能将x和其上下左右的相邻元素交换一次位置，而其他数字不能随意改变位置
//使用A*启发式搜索算法求出最少交换次数的变化经过，即最短路径

//1)基础概念
//启发式搜索：
//传统的深搜与广搜都是无差别的搜索所有节点的子空间
//而启发式搜索会对每个当前节点进行一次评估
//评估当前节点到目标节点的路径长度，选取评价距离最短的节点进行下一次搜索
//而不是无差别的对所有节点搜索其子空间
//A*搜索：
//A*搜索是对状态空间的搜索
//所谓状态空间并不像之前的矩阵或序列这种几何空间，而是时间上的空间
//比如魔方从乱序变化为有序的状态，魔方的每个步骤都是一个时间点处的魔方状态
//但是在八数码问题中有些状态可以转化为终点状态
//而有些状态可能无法转化为终点状态
//评估函数f：
//节点i的评估函数是：f(i)=g(i)+h(i)，其中：
//f(i)是一条经过节点i的路径的距离评价值
//g(i)是一条从起点到节点i的路径的长度
//h(i)是一条从节点i到终点的路径的估计长度
//在较为大型的应用场景中可以设置一个评价阈值threshold
//只搜索所有f值小于threshold的节点，而不用搜索其他节点从而达到节省时间复杂度
//在本文中不必使用这么繁杂的技术
//
//2)具体实现
//矩阵状态用string表示，每一个状态都可以看做空间中的一个节点
//比如"12345678x"为终点目标状态，"123"是矩阵第1行，"456"第2行,"78x"第3行
//"3124x7568"为起点初始状态，找出从起点到终点的最短变化次序
//在本问题中，并非所有初始状态都能经过变化转化为终点状态
//若不存在这样的变化路径则返回不存在，若存在则找出这样的最短变化路径
//评价函数f：
//对于一个矩阵状态i的评价值f(i) = g(i) + h(i)，其中
//g(i)：
//指代起始状态到状态i的路径长度，即经过变换的次数
//可以对每次状态的变换进行累加计数
//h(i)：
//指代从状态i到终点状态的估计路径长度
//在这里设置为当前状态i和终点状态的不同字符的个数之和，即两状态的差异
//比如"12345678x"和"1234567x8"的差异为 2
//每次优先选取f值最小的状态进行下一次搜索
//以后为了方便，将一个状态也称为一个节点
//A*搜索，即状态空间搜索框架：
//对于八数码或魔方这类状态空间的搜索，有一个通用的搜索框架
//维护两个队列open和close
//其中open保存当前待扩展的节点，close保存已经访问过的节点
//其中open是以评价函数f为优先级的队列，初始时open入队起点
//重复以下步骤，直到open表为空：
//取出open中的头节点i，将节点i加入close中
//若节点i是终点，沿着节点i的父节点指针回溯到起点即可得到最短变化路径
//若节点i不是终点，扩展它的所有邻节点(即x与上下左右四个方向进行交换)，加入open中
//设它的一个邻节点为j，需要设置j的父节点指针是i，从而可以从节点j回溯找回节点i
//下一次循环时会将邻节点j加入close中
//但仅仅依靠以上的操作仍然不够，状态空间中也存在“已被访问”的问题
//比如魔方经过不同步骤的变化却会得到相同的状态，是因为有些变化路径饶了“弯路”
//假如open或close中已存在邻节点j，说明节点j已被访问
//这时需要比较这个将要加入队列的邻节点j和队列中已存在的节点j的评价函数f值
//若将要加入的j比已存在的j的f值小，则将已存在的j替换为这个将要加入的j节点
//这个操作是为了选择最短的变化路径，而不选择那些冗余的路径
//重复上述步骤直到最终从open中取出的头节点是终点，沿着父节点指针即可回溯找到最短路径
//若open为空时仍不能找到最短路径，则不存在这样的路径
//
//A*搜索属于人工智能中的概念，本文只做了最易懂的描述，更多内容请参考相关教材
//我忠实的实现了关于A*启发式搜索的描述
//
//本文引用了“启发式搜索和A*”，作者“phylips@bmy”

#include "general_head.h"
#include "search.h"
bool heuristic_search(star_node beg, star_node end, deque<star_node>& close);
void print_road(star_node *pre);
bool compare(star_node a, star_node b);
deque<star_node>::iterator min_f(deque<star_node>& q,
		star_node end);
int x_position(star_node a, char x);
void left_swap(star_node& a, int pos);
void right_swap(star_node& a, int pos);
void up_swap(star_node& a, int pos);
void down_swap(star_node& a, int pos);
bool left_bound(int pos);
bool right_bound(int pos);
bool up_bound(int pos);
bool down_bound(int pos);
int difference_h(star_node a, star_node end);

void a_heuristic_search(star_node beg, star_node end)
{
	deque<star_node> close;
	if(heuristic_search(beg, end, close))
		print_road(&close[close.size() - 1]);
	else
		cout << "no solution" << endl;
}
bool heuristic_search(star_node beg, star_node end, deque<star_node>& close)
{//beg是起始矩阵状态，end是目标矩阵状态
 //返回是否找到最短变化路径
 //若找到则close队列的尾节点为目标状态，沿状态的父指针回溯找到整条变化序列
	//close队列存储所有已经访问过的矩阵状态
	//open队列存储将要访问而尚未访问的矩阵状态
	//若找到最短路径则close的尾节点为终点
	deque<star_node> open;
	//搜索的总体方式采用bfs
	open.push_back(beg);
	while(!open.empty()){
		//从open队列中选取f值最小的节点mp进行搜索
		//这个操作维护open队列的优先级
		deque<star_node>::iterator mp = min_f(open, end);
		//close尾部加入mp，open中删除mp
		close.push_back(*mp);
		open.erase(mp);
		//这时若close队列的尾部节点是终点则直接返回
		if(close[(int)close.size() - 1].s_status == end.s_status)
			return(true);
	
		//否则open继续扩展p节点的邻节点
		int pos = x_position(close[(int)close.size() - 1], 'x');
		//next是p节点上下左右四个方向的邻节点，先初始化为p节点
		star_node next[4];
		for(int i = 0; i < 4; ++ i)
			next[i] = close[(int)close.size() - 1];

		//这里的函数指针纯粹是为了不用顺序的重复四遍邻节点操作，而用循环来缩短代码
		//func_bound检测x交换的方向是否越界
		bool (*func_bound[4])(int);
		func_bound[0] = left_bound; func_bound[1] = right_bound;
		func_bound[2] = up_bound; func_bound[3] = down_bound;
		//func_swap进行x的交换操作
		void (*func_swap[4])(star_node&, int);
		func_swap[0] = left_swap; func_swap[1] = right_swap;
		func_swap[2] = up_swap; func_swap[3] = down_swap;
		for(int i = 0; i < 4; ++ i)
			if(!func_bound[i](pos)){
				//判断x交换的方向是否越界，若没有则x与相邻数字进行交换，得到相邻节点
				func_swap[i](next[i], pos);
				//设置相邻节点next[i]的父节点指针s_fa，路径长度s_g，和差异值s_h
				//next[i]的父指针指向close的尾部元素
				//即刚从open中出队，刚进入close尾部的那个元素
				//能够使用这个操作依赖于C++中deque容器的特性
				//其迭代器方向，下标方向与deque队列头尾的顺序三者是一致的
				next[i].s_fa = &close[(int)close.size() - 1];
				++ next[i].s_g;
				next[i].s_h = difference_h(next[i], end);
				//ot为open迭代器，ct为close迭代器
				deque<star_node>::iterator ot;
				deque<star_node>::iterator ct;
				//查询open中是否存在next[i]这个节点
				if((ot = find(open.begin(),
						open.end(),
						next[i])) != open.end())
					//若存在该节点则选择g值较小的节点
					if(ot->s_g > next[i].s_g)
						*ot = next[i];
				//查询close中是否存在next[i]这个节点
				if((ct = find(close.begin(),
						close.end(),
						next[i])) != close.end())
					//若存在该节点则选择g值较小的节点
					if(ct->s_g > next[i].s_g)
						*ct = next[i];
				if(ot == open.end() && ct == close.end())
					//若两队列中都不存在则加入open中作为之后的搜索
					open.push_back(next[i]);
			}
	}
	//经过这么多状态还没找到那就是没得解了
	return(false);
}
void print_road(star_node *pre)
{
	if(pre->s_fa != NULL)
		print_road(pre->s_fa);
	cout << "(status:" << pre->s_status << ",length:" << pre->s_g << ")" << endl;
}
deque<star_node>::iterator min_f(deque<star_node>& q,
		star_node end)
{
	deque<star_node>::iterator pos;
	int mf(INF);
	for(deque<star_node>::iterator it = q.begin(); it != q.end(); ++ it){
		int h(0);
		//从q队列中选取差异最小的状态进行下一次搜索
		for(int i = 0; i < (int)end.s_status.size(); ++ i)
			if(it->s_status[i] != end.s_status[i])
				++ h;
		if(mf > h + it->s_g)
			mf = h + it->s_g, pos = it; 
	}
	return(pos);
}

int x_position(star_node a, char x)
{
	int index;
	for(index = 0; index < (int)a.s_status.size(); ++ index)
		if(a.s_status[index] == x)
			break;
	return(index);
}
int difference_h(star_node a, star_node end)
{
	int diff(0);
	for(size_t i = 0; i < a.s_status.size(); ++ i)
		if(a.s_status[i] != end.s_status[i])
			++ diff;
	return(diff);
}
bool compare(star_node a, star_node b)
{
	return(a.s_g + a.s_h < b.s_g + b.s_h);
}
void left_swap(star_node& a, int pos)
{
	swap(a.s_status[pos - 1], a.s_status[pos]);
}
void right_swap(star_node& a, int pos)
{
	swap(a.s_status[pos + 1], a.s_status[pos]);
}
void up_swap(star_node& a, int pos)
{
	swap(a.s_status[pos - 3], a.s_status[pos]);
}
void down_swap(star_node& a, int pos)
{
	swap(a.s_status[pos + 3], a.s_status[pos]);
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










