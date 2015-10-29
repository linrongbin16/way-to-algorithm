#ifndef WAY_TO_ALGORITHM_DYNAMICPROGRAMMING_TREEDYNAMIC_BINARY_TREE_H
#define WAY_TO_ALGORITHM_DYNAMICPROGRAMMING_TREEDYNAMIC_BINARY_TREE_H 1
//二叉树动规
//binary tree

//一棵二叉树 共n个节点从1到n 根节点为1
//每个节点上都有一个权值 为方便考虑 所有权值都是正整数
//现在给定一个小于节点总数的数字m
//求出只保留m个节点的树 其余的节点都裁掉 所能保留的最大权值
//当然保留的节点必须连接着根节点 裁掉的都是边缘节点
//为了方便考虑 我们这一整章中所有节点的权值都大于0
//题目的原型是"加分二叉树" 原题中拥有权值的是树的边而非树节点
//但本文为了更方便描绘准确的数学模型 并没有把权值赋给树的边而是赋给树节点

//树型动态规划的最为不同之处是使用递归技术来遍历树空间
//而不像普通动归中使用循环技术来遍历数组那样直观
//
//设f[i][j]指代以i节点为根节点的树上 保留j个节点(包括根节点自己)的最大权值
//状态转移方程:
//f[i][j] = max( f[ left_child[i] ][k] + f[ right_child[i] ][j- k - 1] + t[k] )
//t[k]为第k个节点的权值 0<=k<=j
//left_child[i]为节点i的左孩子节点 right_child[i]为i的右节点
//即当节点i的子树保留j个节点时(包括它自己这个根节点)
//它能取得的最大权值是它的左孩子子树能取得的最大权值加右孩子子树的最大权值
//再加根节点自己的权值三者之和 但选取哪个节点作为根节点则需要枚举这j个节点进行遍历
//
//初始条件: f[i][0]=0 其中0<=i<=n 没有节点的子树权值为0
//f[i][1]=s[i] 以i为根节点的最小子树的权值等于自己根节点的权值
//
//本节引用了"不撞南墙不回头——树规总结" 作者"焦作一中信息学oy"


//1)本文第一种方法是我自己的写法
//该方法将动归常用的f数组也转化成节点的一个成员数组m_f
//请仔细体会这个数据结构 它更加完整的体现了树型动态规划中选择空间的分层本质
//最初我本来准备用这样的数据结构完成这一节的所有代码
//可是在后面的扩展问题中 该数据结构越来越成为函数接口的累赘 导致程序难以调试
//所以只用它实现本文中最简单的二叉树动规 后面不再使用这种复杂的数据结构


#include <algorithm>
using std::max;
#ifndef MAX
#define MAX 60
#endif

struct binary_tree_node1
{
    int     m_value;
    binary_tree_node1*   m_leftchild;
    binary_tree_node1*   m_rightchild;
    int     m_f[MAX];
};

int binary_tree1(binary_tree_node1 *r, int resv)
{//二叉树根节点为r 其中每个节点的权值数组m_f初始化为0 权值为m_value
 //二叉树保留resv个节点 返回二叉树最大权值
	//递归终止条件
	//处理叶子节点
	if(r == NULL)
		return(0);
	//若resv为0 则以该r节点为根节点的子树上没有孩子节点
	if(resv == 0)
		return(0);
	//用于动规记录的f[][]数组存储在节点的m_f 所有节点的m_f初始化为0
	//m_f[i]指代以当前节点r为根节点的子树上保留i个节点的最大权值
	//当前r保留resv节点的最大权值已经得到 直接返回
	//这是动态规划的核心体现: 
	//对之前已经得到的决策结果不再重复计算 而是存储起来直接查询
	if(r->m_f[resv])
		return(r->m_f[resv]);

	//枚举左子树和右子树保留节点的个数 0<=i<resv
	//左子树分配剩余的i个节点
	//右子树必然剩余resv-i-1个节点(根节点自己1个)
	for(int i = 0; i < resv; ++i){
		int left_max = binary_tree1(r->m_leftchild, i);
		int right_max = binary_tree1(r->m_rightchild, resv - i - 1);
		//left_max指代左子树保留i个节点的最大权值
		//right_max指代右子树保留resv-i-1个节点的最大权值
		//当r可以保留resv个节点 它给左子树和右子树分配节点的方法有resv-1种
		//遍历这resv-1种方法 选取最大的之和即为r分配resv个节点的最大权值
		r->m_f[resv] = max( r->m_f[resv], left_max + right_max );
	}
	//对于以r为根节点的树
	//r树最大权值 = 左子树最大权值 + 右子树最大权值 + 根节点权值
	r->m_f[resv] += r->m_value;
	return(r->m_f[resv]);
}



//2)第二种方法中使用了常规的数组f

struct binary_tree_node2
{
    int     m_index;
    int     m_value;
    binary_tree_node2*   m_leftchild;
    binary_tree_node2*   m_rightchild;
    int     m_f[MAX];
};

int binary_tree2(binary_tree_node2 *r, int f[MAX][MAX], int resv)
{//初始时二维数组f中所有成员均为0
	//递归终止条件
	if (r == NULL)
		return(0);
	if (resv == 0)
		return(0);
	//若r节点保留resv个节点的决策已经得到 直接查询返回
	if(f[r->m_index][resv])
		return(f[r->m_index][resv]);

	for (int i = 0; i < resv; ++i) {
		int left_max = binary_tree2(r->m_leftchild, f, i);
		int right_max = binary_tree2(r->m_rightchild, f, resv - i - 1);
		f[r->m_index][resv] = max( f[r->m_index][resv], left_max + right_max );
	}
	f[r->m_index][resv] += r->m_value;
	return( f[r->m_index][resv] );
}

#endif
