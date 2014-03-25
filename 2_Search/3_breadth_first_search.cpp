//广度优先搜索
//breadth_first_search.cpp

//使用广度优先搜索对一矩阵从起点beg开始进行遍历

//维护一个队列，初始时将起点压入队列，从起点beg开始重复以下步骤：
//出队一个元素，访问该元素
//并将这个元素的相邻且未被访问的元素入队
//每次入队一个元素即标记该元素已被访问(包括初始时的起点)
//直到所有节点都被访问过即完成遍历
//像这样用队列来存储节点的邻节点的操作称为扩充该队列

#include "general_head.h"
void print_elem(pair<int, int> p);

void breadth_first_search(int m, int n, pair<int, int> beg)
{//矩阵有m行，n列，行下标从0到m-1，列下标从0到n-1
 //起点beg的x坐标为beg.first(列标)，y坐标为beg.second(行标)
 //x坐标是列标，即取值范围从0到n-1
 //y坐标是行标，即取值范围从0到m-1(编程时经常容易搞混行列与xy坐标的关系)
	//visited标记节点是否被访问过
	int visited[MAX][MAX];
	memset(visited, 0, MAX * MAX *sizeof(int));
	queue<pair<int, int> > q;
	//将点进队之后就要将visit数组进行标识
	//这样做可以“保证”队列中总是存储着：“将要被访问，而且从未访问过的点”
	//何时对visited数组标记有很多种做法
	//不同的方法会有不同的效果，但它们都存在缺陷，这些缺陷在bfs中并不会体现
	//而在后面的双向广度搜索和启发式搜索中会体现出来，所以请记住这个细节
	q.push(beg);
	visited[beg.second][beg.first] = 1;
	while(!q.empty()){
		pair<int, int> p = q.front(); q.pop();
		//xy坐标的概念和数组中行列的概念总是相反的，容易搞混
		print_elem(p);
		//对p点四个方向的邻节点进行考虑
		//还需判断矩阵越界
		if(p.first - 1 >= 0 && !visited[p.first - 1][p.second]){
			q.push(pair<int, int>(p.first - 1, p.second));
			visited[p.first - 1][p.second] = 1;
		}
		if(p.first + 1 < n && !visited[p.first + 1][p.second]){
			q.push(pair<int, int>(p.first + 1, p.second));
			visited[p.first + 1][p.second] = 1;
		}
		if(p.second - 1 >= 0 && !visited[p.first][p.second - 1]){
			q.push(pair<int, int>(p.first, p.second - 1));
			visited[p.first][p.second - 1] = 1; 
		}
		if(p.second + 1 < m && !visited[p.first][p.second + 1]){
			q.push(pair<int, int>(p.first, p.second + 1));
			visited[p.first][p.second + 1] = 1;
		}
	}
}
void print_elem(pair<int, int> p)
{
	cout << "(x:" << p.first << ",y:" << p.second << ")" << endl;
}




