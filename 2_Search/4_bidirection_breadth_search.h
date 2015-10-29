#ifndef SEARCH_BIDIRECTION_BREADTH_SEARCH_H
#define SEARCH_BIDIRECTION_BREADTH_SEARCH_H 1
//双向广度搜索
//bidirection breadth search

//用双向广度搜索在一矩阵空间中从起始点beg开始搜索一条最短到达目标点end的路径

//双向广度搜索方法是广度优先搜索bfs的扩展
//双向广搜相比bfs占用内存少很多 而且总能保证得到的路径是最短路径
//
//使用两个队列(bfs只有一个队列) 分别存储搜索起始点beg和目标点end
//分别从起始点和目标点进行广搜 他们一定会在某条路径中间相遇
//任何时候都需要保持两队列中存储的节点数量一致
//这是为了防止两个队列中的点数量相差太大而退化成单一队列的bfs
//两个队列每次要新加入一个节点时都要判断该节点是否已经存在在另一个队列中
//若对方队列已经访问过这个点 则两个队列搜索到了相同的点 即两个队列在这个点碰面
//在每次新加入一个点时都需要记录下该节点的父节点 即将该节点加入队列的那个邻节点
//当两个队列碰面时 从碰面点沿着两个队列中的父节点指针就可以找回起点和终点
//该路径即所求最短路径
//
//本文引用了"双向广度优先搜索算法框架及八数码问题例程" 作者"~纯净的天空~"

#ifndef MAX
#define MAX 60
#endif
#include <algorithm>
#include <cstring>
#include <utility>
#include <deque>
#include <iostream>
using namespace std;

struct bbs_node
{
	int m_row;
	int m_col;
	int m_father_row;
	int m_father_col;

	bbs_node() { }
    bbs_node(int row, int col, int father_row, int father_col)
    {
		m_row = row;
		m_col = col;
		m_father_row = father_row;
		m_father_col = father_col;
    }
	bool operator==(const bbs_node& node) const
	{
		return(m_row == node.m_row && m_col == node.m_col);
	}
	bool operator!=(const bbs_node& node) const
	{
		return(m_row != node.m_row || m_col != node.m_col);
	}
};

bbs_node invalid_node(-1, -1, -1, -1);
pair<bbs_node, bbs_node> invalid_pair(invalid_node, invalid_node);

pair<bbs_node, bbs_node> expand_queue(deque<bbs_node> &q_expand, deque<bbs_node> &q_exist,
		bbs_node s[MAX][MAX], int m, int n, int visited[MAX][MAX])
{
    //扩展q_expand队列的头节点到周围的邻节点
    //在将某个邻节点加入队列q_expand之前 
    //先检查该点是否已经被q_expand队列访问过
    //或者查找该点是否已经存在于q_exist队列中
    //若已经存在 则q_expand的头节点与q_exist中该邻节点是相邻的 即两队列相遇
	deque<bbs_node>::iterator pos;
	bbs_node p = q_expand.front();
	q_expand.pop_front();
	//扩展q_expand头节点的四个方向上的邻节点
	if ( p.m_row-1 >= 0 && !visited[p.m_row-1][p.m_col] ) {
		//判断矩阵边界与是否已经被访问过	
		//C++find需要结构体bbs_node提供比较操作operator==
		//该操作操作定义两节点的xy坐标相等即为同一点 不考虑父节点指针
		if ( ( pos = find(q_exist.begin(), q_exist.end(), s[p.m_row-1][p.m_col]) ) != q_exist.end() )
			//若在q_exist中找到q_expand头节点的该邻节点
            //则返回相遇的两节点 返回的pair中
            //first是q_expand队列的待扩展节点p
            //second是q_exist队列中节点
			return pair<bbs_node, bbs_node>(p, *pos);
		//若没有在q_exist中找到该邻节点则两队列未在此节点处相遇
		//将q_expand队列扩展至该邻节点，并标记其父节点指针
		s[p.m_row-1][p.m_col].m_father_row = p.m_row;
		s[p.m_row-1][p.m_col].m_father_col = p.m_col;
		q_expand.push_back(s[p.m_row - 1][p.m_col]);
		visited[p.m_row - 1][p.m_col] = 1;
	}
	if ( p.m_row+1 < m && !visited[p.m_row+1][p.m_col] ) {
		if ( (pos = find(q_exist.begin(), q_exist.end(), s[p.m_row+1][p.m_col]) ) != q_exist.end() )
			return pair<bbs_node, bbs_node>(p, *pos);
		s[p.m_row+1][p.m_col].m_father_row = p.m_row;
		s[p.m_row+1][p.m_col].m_father_col = p.m_col;
		q_expand.push_back( s[p.m_row + 1][p.m_col] );
		visited[p.m_row + 1][p.m_col] = 1;
	}
	if ( p.m_col-1 >= 0 && !visited[p.m_row][p.m_col-1] ) {
		if ( (pos = find(q_exist.begin(), q_exist.end(), s[p.m_row][p.m_col-1]) ) != q_exist.end() )
			return pair<bbs_node, bbs_node>(p, *pos);
		s[p.m_row][p.m_col-1].m_father_row = p.m_row;
		s[p.m_row][p.m_col-1].m_father_col = p.m_col;
		q_expand.push_back(s[p.m_row][p.m_col - 1]);
		visited[p.m_row][p.m_col - 1] = 1;
	}
	if ( p.m_col+1 < n && !visited[p.m_row][p.m_col+1] ) {
		if ( (pos = find(q_exist.begin(), q_exist.end(), s[p.m_row][p.m_col+1])) != q_exist.end() )
			return pair<bbs_node, bbs_node>(p, *pos);
		s[p.m_row][p.m_col+1].m_father_row = p.m_row;
		s[p.m_row][p.m_col+1].m_father_col = p.m_col;
		q_expand.push_back(s[p.m_row][p.m_col + 1]);
		visited[p.m_row][p.m_col + 1] = 1;
	}
	//一次扩展只是从q_expand队列的头节点向外扩展四个邻节点
	//若这次扩展中两队列未相遇则返回两个bbs_node(-1, -1, -1, -1)
    return(invalid_pair);
}
void print_forward(bbs_node f, bbs_node s[MAX][MAX])
{//从点f向终点输出路径
	cout << " (row:" << f.m_row << ",col:" << f.m_col << ")" << endl;
	if ( f.m_father_row != -1 && f.m_father_col != -1 )
		print_forward(s[f.m_father_row][f.m_father_col], s);
}
void print_backward(bbs_node b, bbs_node s[MAX][MAX])
{//从点b向起点反向输出路径
 //注意这里递归的使用 输出的顺序是从起点到终点的顺序
	if ( b.m_father_row != -1 && b.m_father_col != -1 )
		print_backward(s[b.m_father_row][b.m_father_col], s);		
	cout << " (row:" << b.m_row << ",col:" << b.m_col << ")" << endl;
}
void print_road(pair<bbs_node, bbs_node> meet_pos, bbs_node s[MAX][MAX])
{//meet_pos中是两队列相遇处的两节点
 //其中first是q_beg队列中的节点 second是q_end队列中的节点 这两个点是相邻的
 //输出路径时向后递归逆序输出q_beg的路径 向前顺序输出q_end的路径
	print_backward(s[meet_pos.first.m_row][meet_pos.first.m_col], s);
	print_forward(s[meet_pos.second.m_row][meet_pos.second.m_col], s);
}

void bidirection_breadth_search(bbs_node s[MAX][MAX],
		int m, int n, bbs_node beg, bbs_node end)
{//矩阵s有m行n列 行下标从0到m-1 列下标从0到n-1
	//visit_beg记录beg队列访问过的点
	//visit_end记录end队列访问过的点
    int visit_beg[MAX][MAX];
    int visit_end[MAX][MAX];
    memset(visit_beg, 0, MAX * MAX * sizeof(int));
    memset(visit_end, 0, MAX * MAX * sizeof(int));

	//q_beg是从起点bfs的队列
	//q_end是从终点bfs的队列
	deque<bbs_node> q_beg, q_end;
	//起点终点分别进入两个队列
	q_beg.push_back(beg);
	q_end.push_back(end);
	visit_beg[beg.m_row][beg.m_col] = 1;
	visit_end[end.m_row][end.m_col] = 1;
	//meet_pos返回q_beg和q_end中相遇的点
	//这两个点是相邻的 即这两个点相遇
	pair<bbs_node, bbs_node> meet_pos;
	int flag = 0;
	while (1) {
		if (q_beg.size() > q_end.size()) {
			//扩展q_end 检查要加入q_end的点是否已存在于q_beg中
			meet_pos = expand_queue(q_end, q_beg, s, m, n, visit_end);
			if (meet_pos != invalid_pair) {
				//找到了相遇点
                //flag=2表示被扩展的队列是q_end
				flag = 2;
				break;
			}
		}
		else{
			//扩展q_beg
            //检查要加入q_beg的点是否已存在于q_end中
			meet_pos = expand_queue(q_beg, q_end, s, m, n, visit_beg);
			if (meet_pos != invalid_pair) {
                //flag=1表示被扩展的队列是q_beg
				flag = 1;
				break;
			}
		}
	}
	//若找到相遇的两点则用print_road函数输出路径
	if (flag == 2)
		//若flag为2说明在扩展q_end队列时 待扩展的q_end节点与q_beg中某节点相遇
		//meet_pos.first是q_end队列中节点 meet_pos.second是q_beg队列中节点
		//交换位置是因为print_road函数将first看作q_beg中节点second看作q_end中节点
		swap(meet_pos.first, meet_pos.second);
	print_road(meet_pos, s);
}

#endif
