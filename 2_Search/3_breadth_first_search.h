#ifndef SEARCH_BREADTH_FIRST_SEARCH_H
#define SEARCH_BREADTH_FIRST_SEARCH_H 1
//广度优先搜索
//breadth_first_search.cpp

//使用广度优先搜索对一矩阵从起点beg开始进行遍历

//维护一个队列，初始时将起点压入队列，从起点beg开始重复以下步骤：
//出队一个元素，访问该元素
//并将这个元素的相邻且未被访问的元素入队
//每次入队一个元素即标记该元素已被访问(包括初始时的起点)
//直到所有节点都被访问过即完成遍历
//像这样用队列来存储节点的邻节点的操作称为扩充该队列


#include <iostream>
#include <deque>
#include <string.h>
#ifndef MAX
#define MAX 500
#endif

void breadth_first_search_print(std::pair<int, int> p)
{
	std::cout << "(row:" << p.first << ",column:";
	std::cout << p.second << ")" << std::endl;
}
void breadth_first_search(int m, int n, std::pair<int, int> beg)
{//矩阵有m行，n列，行下标从0到m-1，列下标从0到n-1
 //起点beg的行下标为beg.first(对应m行)，列下标为beg.seocnd(对应n列)
	//visited标记节点是否被访问过
	int visited[MAX][MAX];
	memset(visited, 0, MAX * MAX *sizeof(int));
	int beg_row = beg.first, beg_col = beg.second;

	std::deque<std::pair<int, int> > q;
	//将点进队之后就要将visit数组进行标识
	//这样做可以“保证”队列中总是存储着：“将要被访问，而且从未访问过的点”
	//何时对visited数组标记有很多种做法
	//不同的方法会有不同的效果，但它们都存在缺陷，这些缺陷在bfs中并不会体现
	//而在后面的双向广度搜索和启发式搜索中会体现出来，所以请记住这个细节
	q.push_back(beg);
	visited[beg_row][beg_col] = 1;
	while(!q.empty()){
		std::pair<int, int> p = q.front();
		q.pop_front();
		int p_row = p.first;
		int p_col = p.second;

		breadth_first_search_print(p);
		//对p点四个方向的邻节点进行考虑
		//还需判断矩阵越界
		if(p_row - 1 >= 0 && !visited[p_row - 1][p_col]){
			q.push_back(std::pair<int, int>(p_row - 1, p_col));
			visited[p_row - 1][p_col] = 1;
		}
		if(p_row + 1 < m && !visited[p_row + 1][p_col]){
			q.push_back(std::pair<int, int>(p_row + 1, p_col));
			visited[p_row + 1][p_col] = 1;
		}
		if(p_col - 1 >= 0 && !visited[p_row][p_col - 1]){
			q.push_back(std::pair<int, int>(p_row, p_col - 1));
			visited[p_row][p_col - 1] = 1; 
		}
		if(p_col + 1 < n && !visited[p_row][p_col + 1]){
			q.push_back(std::pair<int, int>(p_row, p_col + 1));
			visited[p_row][p_col + 1] = 1;
		}
	}
}



#endif
