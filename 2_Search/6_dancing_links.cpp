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
//实际比赛中链表的实现一般不使用指针而是使用数组下标，但本文使用指针
//集合s中每个成员都是一个头节点，每个头节点的邻节点则是矩阵中的1
//每个节点有上下左右四个指针
//
//本文引用了“dancing links详解”， 作者“sunny606”

#include "general_head.h"
#include "search.h"

void dancing_links(int *s, int n,
		vector<vector<int> > sub, vector<int> &choose)
{

}
bool dance(int k)
{
	int p = right[head];
	if(p == head){
		return(true);
	}
	remove(p);
	for(int i = down[p]; i != p; i = down[i]){
		ans[k] = high[i];
		for(int j = right[i]; j != i; j = right[j])
			remove(c[j]);
		if(dance(k + 1))
			return(true);
		for(int j = left[i], j != i; j = left[j])
			resume(c[j]);
	}
	resume(p);
	return(false);
}
void remove(int p)
{
	left[right[p]] = left[p];
	right[left[p]] = right[p];
	for(int i = down[p]; i != p; i = down[i])
		for(int j = right[i]; j != i; j = right[j]){
			up[down[j]] = up[j];
			down[up[j]] = down[j];
		}
}
void resume(int p)
{
	left[right[p]] = p;
	right[left[p]] = p;
	for(int i = up[p]; i != p; i = up[i])
		for(int j = right[i]; j != i; j = right[j]){
			up[down[j]] = j;
			down[up[j]] = i;
		}
}
