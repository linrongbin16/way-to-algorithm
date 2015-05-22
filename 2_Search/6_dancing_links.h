#ifndef SEARCH_DANCING_LINKS_H
#define SEARCH_DANCING_LINKS_H 1
//舞蹈链
//dancing links

//集合s有从0到n-1的n个成员，又有m个子集，每个子集包含集合s上的一些成员
//比如子集{0, 1, 3}包含集合s的0, 1, 3三个成员
//在m个子集中选择若干集合，使这些集合可以精确覆盖/重复覆盖集合s
//精确覆盖：集合s中每个成员属于且只属于一个子集，即s中每个成员只出现一次
//重复覆盖：集合s中每个成员至少属于一个子集，即s中每个成员至少出现一次

//重复覆盖很简单，本文只讲用于求解精确覆盖的舞蹈链算法
//舞蹈链算法涉及到X算法和十字链表两个部分
//
//1)求解精确覆盖的X算法
//给出集合s={a, b, c, d, e, f, g}和它的子集
//s1={c, e, f}, s2={a, d, g}, s3={b, c, f}
//s4={a, d}, s5={b, g}, s6={d, e, g}
//显然s1, s4, s5是一个选择，即一组解，将这些集合表示为一个矩阵：
//   a  b  c  d  e  f  g
//s1 0  0  1  0  1  1  0
//s2 1  0  0  1  0  0  1
//s3 0  1  1  0  0  1  0
//s4 1  0  0  1  0  0  0
//s5 0  1  0  0  0  0  1
//s6 0  0  0  1  1  0  1
//这个问题也可以表达为在s1-s6这6行中选择若干行，使得每一列包含且只包含一个1
//X算法使用一种递归的深度优先搜索的回溯法来求解该问题：
//if matrix is empty, problem solved and end
//else choose a column c in matrix
//choose a row r such that m[r, c] = 1(第r行子集sr包含第c列成员)
//include row r in the solution
//for each column j which m[r, j] = 1
//	for each row i which m[i, j] = 1
//		delete row i
//	delete column j
//repeat this recursively on this matrix
//伪代码的意思大概是在深度搜索的框架下，每次对一列进行如下操作
//找出一行，使得m[r, c] = 1，比如上面的集合s中m[s2, a] = 1
//则将子集s2加入选择的集合中，s2={a, d, g}中三个成员都已出现，删除这三列
//并且将包含a, d, g三个成员的其他子集也删除，s4, s5, s6
//即选择了s2子集后，s4, s5, s6这三个子集不能再选，否则一个成员会重复出现
//将这些行和列删除后，剩余的矩阵为：
//   b  c  e  f
//s1 0  1  1  1
//s3 1  1  0  1
//继续在b列中找出一行s3使得m[s3, b] = 1，然后b, c, f出现，s1被删除
//此时所有行(子集)都被使用或删除了，即矩阵为空，但是成员e仍然未出现
//此时选择的子集集合{s2, s3}不符合精确覆盖
//递归回上一层继续选择，即不选择s2，而选择s4，直到得到一个精确覆盖
//
//2)十字链表
//在递归的过程中使用链表这种数据结构来进行删除和添加的操作十分适合X算法
//舞蹈链算法就是这种使用双向十字链表数据结构实现X算法的
//实际比赛中链表的实现一般不使用指针而是使用数组下标
//集合s中每个成员都是一个头节点，每个头节点的邻节点则是矩阵中的1
//每个节点有上下左右四个指针
//最终将矩阵中为1的元素作为节点，并把第一行的a, b, c...作为链表的头节点
//并且在第一行之前还需要一个头节点作为判断矩阵是否为空
//上下左右四个方向连接成一个十字链表
//
//本文引用了“dancing links详解”， 作者“sunny606”
//“dancing links算法解Sudoku”，作者“囧囧有神”

#include "general_head.h"
#include "search.h"
struct link_node
{

};

void make_link(int n, int **sub, int m, int *cnt,
		link_node &head, link_node *nodes);
bool dance(int r, link_node *head, int n, int *choose);
void remove(int u);
void resume(int u);

bool dancing_links(int n, int **sub, int m, int *cnt, int *choose)
{//集合s有n个成员从0到n-1，可选子集sub有m个从0到m-1
 //子集sub[i]包含cnt[i]个成员，sub[i][j]为包含的成员下标号
 //存在解决方案返回真，否则返回否，被选的子集在数组choose中标记1，未选为0
	memset(choose, 0, MAX * sizeof(int));
	//head为头节点，nodes数组为其余所有节点
	//rows数组为行节点，cols数组为列节点
	link_node head, nodes[MAX];
	make_link(n, sub, m, cnt, head, nodes);
	return(dance(0, head, n, choose));
}
void make_link(int n, int **sub, int m, int *cnt,
		link_node &head, link_node *nodes)
{
	//初始化矩阵，将节点中无效或表示边界的指针指向自己
	//所有节点的上下左右四个方向指针指向自己，从而最终得到一个闭环的矩阵
	//即最底部(左边界)的节点与最顶部(右边界)的节点相连
	head.l_up = head.l_down
		= head.l_left = head.l_right = &head;
	head.l_idx = -1;
	//总节点数量
	int total_cnt = n;
	for(int i = 0; i < m; ++ i)
		total_cnt += cnt[i];
	for(int i = 0; i < total_cnt; ++ i){
		nodes[i].l_idx = i;
		nodes[i].l_up = nodes[i].l_down
			= nodes[i].l_left = nodes[i].l_right = &nodes[i];
	}
	for(int i = 0; i < n; ++ i){
		nodes[i].l_row = 0;
		nodes[i].l_col = i;
	}
	head.l_left = &nodes[n - 1];
	nodes[n - 1].l_right = &head;
	//同一行(子集)的节点左右连接
	int nodes_cnt = n;
	for(int i = 0; i < m; ++ i){
		for(int j = 1; j < cnt[i] - 1; ++ j){
			nodes[nodes_cnt + j].l_left = &nodes[nodes_cnt + j - 1];
			nodes[nodes_cnt + j].l_left->l_right = &nodes[nodes_cnt + j];
			nodes[nodes_cnt + j].l_right = &nodes[nodes_cnt + j + 1];
			nodes[nodes_cnt + j].l_right->l_left = &nodes[nodes_cnt + j];
			nodes[nodes_cnt + j].l_row = i;
		}
		nodes[nodes_cnt].l_left = &nodes[nodes_cnt + cnt[i] - 1];
		nodes[nodes_cnt + cnt[i] - 1].l_right = &nodes[nodes_cnt];
		nodes_cnt += cnt[i];
	}
	nodes_cnt = n;
	//同一列(头节点)的节点上下连接
	for(int i = 0; i < m; ++ i){
		for(int j = 0; j < cnt[i]; ++ j){
			//找出下标为sub[i][j]的头节点的尾部
			//连接子集sub[i]的对应成员
			link_node *p = &nodes[sub[i][j]];
			while(p->l_down)
				p = p->l_down;
			p->l_down = &nodes[nodes_cnt + j];
			nodes[nodes_cnt + j].l_up = p;
			nodes[nodes_cnt + j].l_col = sub[i][j];
		}
		nodes[sub[i][j]].l_up = &nodes[nodes_cnt + cnt[i] - 1];
		nodes[nodes_cnt + cnt[i] - 1].l_down = &nodes[sub[i][j]];
		nodes_cnt += cnt[i];
	}
}
bool dance(int r, int n, link_node &head, link_node *nodes, int *choose)
{
	int u = head.l_left->l_idx;
	if(u == head.l_idx){
		return(true);
	}
	remove(u);
	link_node *p1 = &nodes[u];
	while(p1->l_down->l_idx != u){
		int tmp1 = p1->l_down->l_idx;
		choose[r] = nodes[tmp1].l_up->l_idx;
		link_node *p2 = &nodes[tmp1];
		while(p2->l_right->l_idx != tmp1){
			int tmp2 = p2->l_right->l_idx;
			remove(nodes[tmp2].l_col);
		}
		if(dance(r + 1))
			return(true);
		p2 = &nodes[tmp1];
		while(p2->l_left->l_idx != tmp1){
			int tmp2 = p2->l_left->l_idx;
			resume(nodes[tmp2].l_col);
		}
	}
	resume(u);
	return(false);
}
void remove(int u)
{//删除节点u
	nodes[u].l_right->l_left = nodes[u].l_left;
	nodes[u].l_left->l_right = nodes[u].l_right;
	link_node *p1 = &nodes[u];
	while(p1->l_down->l_idx != u){
		int tmp1 = p1->l_down->l_idx;
		link_node *p2 = &nodes[tmp1];
		while(p2->l_right->l_idx != tmp1){
			int tmp2 = p2->l_right->l_idx;
			nodes[tmp2].l_down->l_up = nodes[tmp2].l_up;
			nodes[tmp2].l_up->l_down = nodes[tmp2].l_down;
		}
	}
}
void resume(int u)
{//恢复节点u
	nodes[u].l_right->l_left = &nodes[u];
	nodes[u].l_left->l_right = &nodes[u];
	link_node *p1 = &nodes[u];
	while(p1->l_up->l_idx != u){
		int tmp1 = p1->l_up->l_idx;
		link_node *p2 = &nodes[tmp1];
		while(p2->l_right->l_idx != tmp1){
			int tmp2 = p2->l_right->l_idx;
			nodes[tmp2].l_down->l_up = &nodes[tmp2];
			nodes[tmp2].l_up->l_down = &nodes[tmp2];
		}
	}
}
#endif
