#ifndef SEARCH_DANCING_LINKS_H
#define SEARCH_DANCING_LINKS_H 1
//舞蹈链
//dancing links

//TODO: 该算法尚未完成
//集合s有从0到n-1的n个成员 又有m个子集 每个子集包含集合s上的一些成员
//比如子集{0 1 3}包含集合s的0 1 3三个成员
//在m个子集中选择若干集合 使这些集合可以精确覆盖/重复覆盖集合s
//精确覆盖 集合s中每个成员属于且只属于一个子集 即s中每个成员只出现一次
//重复覆盖 集合s中每个成员至少属于一个子集 即s中每个成员至少出现一次

//重复覆盖很简单 本文只讲用于求解精确覆盖的舞蹈链算法
//舞蹈链算法涉及到X算法和十字链表两个部分
//
//1)求解精确覆盖的X算法
//给出集合s={a b c d e f g}和它的子集
//s1={c e f} s2={a d g} s3={b c f}
//s4={a d} s5={b g} s6={d e g}
//显然s1 s4 s5是一个选择 即一组解 将这些集合表示为如下矩阵
//   a  b  c  d  e  f  g
//s1 0  0  1  0  1  1  0
//s2 1  0  0  1  0  0  1
//s3 0  1  1  0  0  1  0
//s4 1  0  0  1  0  0  0
//s5 0  1  0  0  0  0  1
//s6 0  0  0  1  1  0  1
//这个问题也可以表达为在s1-s6这6行中选择若干行 使得每一列包含且只包含一个1
//X算法使用一种回溯法来求解该问题 或者说深度优先搜索的方法
//我个人觉得他们都差不多 因为实质都是一种递归遍历
//if matrix is empty
//problem solved and end
//else
//choose a column c in matrix
//choose a row r such that m[r,c]=1 (第r行子集s包含第c列成员)
//include row r in the solution
//for each column j which m[r,j]=1
//	for each row i which m[i,j]=1
//		delete row i
//	delete column j
//repeat this recursively on this matrix
//伪代码的意思大概是在深度搜索的框架下每次对一列进行如下操作
//找出一行使得m[r,c]=1 比如上面的集合s中m[s2,a]=1
//则将子集s2加入选择的集合中 s2={a d g}中三个成员都已出现 删除这三列
//并且将包含a d g三个成员的其他子集也删除 即s4 s5 s6
//即选择了s2子集后 s4 s5 s6这三个子集不能再选否则一个成员会重复出现
//将这些行和列删除后 剩余的矩阵为
//   b  c  e  f
//s1 0  1  1  1
//s3 1  1  0  1
//继续在b列中找出一行s3使得m[s3,b]=1 然后b c f出现 s1被删除
//此时所有行(子集)都被使用或删除了 即矩阵为空 但是成员e仍然未出现
//此时选择的子集集合{s2 s3}不符合精确覆盖
//递归回上一层继续选择 即不选择s2而选择s4 直到得到一个精确覆盖
//
//2)十字链表
//在递归的过程中使用链表这种数据结构来进行删除和添加的操作十分适合X算法
//舞蹈链算法就是这种使用双向十字链表数据结构实现X算法的
//我们这里为了方便使用数组下标作为链表节点的指针
//集合s中每个成员都是一个头节点 每个头节点的邻节点则是矩阵中的1
//每个节点有上下左右四个指针
//最终将矩阵中为1的元素作为节点 并把第一行的a b c...作为链表的头节点
//并且在第一行之前还需要一个头节点作为判断矩阵是否为空
//上下左右四个方向连接成一个十字链表
//
//本文引用了"dancing links详解" 作者"sunny606"
//"dancing links算法解Sudoku" 作者"囧囧有神"


#ifndef MAX
#define MAX 60
#endif
#include <cstring>


//up_node[i]表示节点i的up指针所指的节点下标
//相应的down_node[i] left_node[i] right_node[i]表示节点i的对应指针的节点下标
int up_node[MAX], down_node[MAX], left_node[MAX], right_node[MAX];
//row[i] column[i]表示节点i的行号和列号
int row[MAX], column[MAX];

void make_link(int n, int sub[MAX][MAX], int m, int cnt[MAX])
{
	//初始化矩阵 将节点中无效或表示边界的指针指向自己
	//所有节点的上下左右四个方向指针指向自己 从而最终得到一个闭环的矩阵
	//即最底部(左边界)的节点与最顶部(右边界)的节点相连
	//总节点数量为矩阵中所有节点的数量
	int total_cnt = n;
	int i, j;
	for (i = 1; i <= m; ++i)
		total_cnt += cnt[i];
	memset(up_node, 0, MAX * sizeof(int));
	memset(down_node, 0, MAX * sizeof(int));
	memset(left_node, 0, MAX * sizeof(int));
	memset(right_node, 0, MAX * sizeof(int));
	memset(row, 0, MAX * sizeof(int));
	memset(column, 0, MAX * sizeof(int));
	//特别的将0设置为头节点head
	//从1到n为集合中的所有成员
	for (i = 0; i <= total_cnt; ++i) {
		up_node[i] = i;
		down_node[i] = i;
		left_node[i] = i;
		right_node[i] = i;
	}
	//第一行节点
	for (i = 1; i <= n; ++i) {
		left_node[i] = i - 1;
		right_node[i] = i + 1;
		row[i] = 0;
		column[i] = i;
	}
	//头节点0的左边是节点n
	//节点n的右边是头节点0
	//构成一个回环
	left_node[0] = n;
	right_node[0] = 1;
	left_node[n] = n - 1;
	right_node[n] = 0;

	//第1到第m行节点左右连接
	int nodes_cnt = n+1;
	for (i = 1; i <= m; ++i) {
		for (j = 1; j < cnt[i] - 1; ++j) {
			left_node[nodes_cnt + j] = nodes_cnt + j - 1;
			right_node[nodes_cnt + j - 1] = nodes_cnt + j;
			right_node[nodes_cnt + j] = nodes_cnt + j + 1;
			left_node[nodes_cnt + j + 1] = nodes_cnt + j;
			row[nodes_cnt + j] = i;
		}
		left_node[nodes_cnt] = nodes_cnt + cnt[i] - 1;
		right_node[nodes_cnt] = nodes_cnt + 1;
		left_node[nodes_cnt + cnt[i] - 1] = nodes_cnt + cnt[i] - 2;
		right_node[nodes_cnt + cnt[i] - 1] = nodes_cnt;
		row[nodes_cnt] = i;
		row[nodes_cnt + cnt[i] - 1] = i;
		nodes_cnt += cnt[i];
	}

	nodes_cnt = n;
	//将同一列的节点上下连接
	for (i = 1; i <= m; ++i) {
		for (j = 1; j <= cnt[i]; ++j) {
			//找出下标为sub[i][j]的头节点的尾部
			//连接子集sub[i]的对应成员
			int p = sub[i][j];
			while (down_node[p] != sub[i][j])
				p = down_node[p];
			down_node[p] = nodes_cnt + j;
			up_node[nodes_cnt + j] = p;
			down_node[nodes_cnt + j] = sub[i][j];
			up_node[ sub[i][j] ] = nodes_cnt + j;
			column[nodes_cnt + j] = p;
		}
		nodes_cnt += cnt[i];
	}
}
void remove_node(int u)
{
	//删除节点u
	left_node[ right_node[u] ] = left_node[u];
	right_node[ left_node[u] ] = right_node[u];

	//将节点u所在一列的所有行都remove掉
	for (int p1 = down_node[u]; down_node[p1] != u; p1 = down_node[p1]) {
		for (int p2 = right_node[p1]; right_node[p2] != p1; p2 = right_node[p2]) {
			up_node[ down_node[p2] ] = up_node[p2];
			down_node[ up_node[p2] ] = down_node[p2];
		}
	}
}
void resume_node(int u)
{
	//恢复节点u
	left_node[ right_node[u] ] = u;
	right_node[ left_node[u] ] = u;

	//将节点u所在的同一行都恢复
	for (int p1 = up_node[u]; up_node[p1] != u; p1 = up_node[p1]) {
		for (int p2 = right_node[p1]; right_node[p2] != p1; p2 = right_node[p2]) {
			up_node[down_node[p2]] = p2;
			down_node[up_node[p2]] = p2;
		}
	}
}
bool dance(int r, int choose[MAX])
{
	int u = right_node[0];
	//r从0开始把所有节点都需要remove掉
	//若head节点的右边节点也是head
	//则该矩阵已经全部都remove掉了 则说明dance成功
	if (u == 0)
		return true;

	//节点u从1开始remove
	//若head节点的右边仍然有节点
	//则remove该节点u
	remove_node(u);

	for (int p1 = down_node[u]; down_node[p1] != u; p1 = down_node[p1]) {
		choose[r] = row[p1];
		//remove掉节点u后 对于和u在同一列的所有节点
		//也都remove掉包括这些节点的子集
		for (int p2 = right_node[p1]; right_node[p2] != p1; p2 = right_node[p2]) {
			remove_node(column[p2]);
		}

		if (dance(r + 1, choose))
			return true;

		for (int p2 = left_node[p1]; left_node[p2] != p1; p2 = left_node[p2]) {
			resume_node(column[p2]);
		}
	}

	resume_node(u);
	return false;
}

bool dancing_links(int n, int sub[MAX][MAX], int m, int cnt[MAX], int choose[MAX])
{
	//集合s有n个成员从1到n 可选子集sub有m个从1到m
	//子集sub[i]包含cnt[i]个成员，sub[i][j]为包含的成员下标号
	//存在解决方案返回真，否则返回否，被选的子集在数组choose中标记1，未选为0
	memset(choose, 0, MAX * sizeof(int));
	make_link(n, sub, m, cnt);
	return(dance(0, choose));
}

#endif

