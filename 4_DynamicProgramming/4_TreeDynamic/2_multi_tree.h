#ifndef WAY_TO_ALGORITHM_DYNAMICPROGRAMMING_TREEDYNAMIC_MULTI_TREE_H
#define WAY_TO_ALGORITHM_DYNAMICPROGRAMMING_TREEDYNAMIC_MULTI_TREE_H 1
//多叉树动规
//multi tree

//如果二叉树中的树变为多叉树 其他条件不变
//仍然求给定节点数量下的最大权值

//考虑在二叉树中分配剩余节点的情况: 
//如果左子树分配i个节点 那么右子树必然只能分配resv-i-1个节点
//根节点自己也占1个
//但在多叉树中分配节点时: 
//对于某个孩子树 若还剩余节点resv个
//那么这个孩子树可以分配的节点为i个 其中0<=i<=resv
//下一个孩子树可以分配的剩余节点数量为resv-i个
//那么总的剩余节点是resv个时
//给根节点的n个孩子树分配的方法有多少种情况呢
//如果读者还记得本书第二章搜索中的深度优先搜算法 就可以轻松解决这个问题了
//
//状态转移方程与二叉树中一样
//使用双递归技术实现对多叉树的深度搜索


#include <algorithm>
using std::max;
#ifndef MAX
#define MAX 60
#endif
struct multi_tree_node
{
    int     m_index;
    int     m_value;
    int     m_count;
    multi_tree_node*    m_child[MAX];
};

int multi_tree(multi_tree_node *r, int f[MAX][MAX], int resv);

void depth_search(multi_tree_node *r, int f[MAX][MAX], int *next_resv,
		int resv, int left_resv, int prev = 0)
{//处理对当前r的所有孩子节点的分配工作
 //给节点r分配的剩余节点为resv个
 //给r的所有孩子节点分配的节点存储在next_resv数组中
 //将r的孩子树们分配的所有情况中的最大权值挑选出来赋给f[r->m_index][resv]
 //只处理当前r节点 不会处理到下一层的节点
	//递归结束条件 深度搜索出一种组合后进行计算
	if (prev == r->m_count) {
		//更新r树的最大权值
		int sumf = 0;
		//下一层子树的最大权值又交给另一个递归去做
		for(int i = 0; i < r->m_count; ++ i)
			sumf += multi_tree( r->m_child[i], f, next_resv[i] );
		f[r->m_index][resv] = max( f[r->m_index][resv], sumf );
		return;
	}

	//对r的一个指定孩子prev
	if (prev == r->m_count - 1) {
		//如果prev是孩子节点中的最后一个 它直接分配到剩余的所有节点
		next_resv[prev] = left_resv;
		depth_search(r, f, next_resv, resv, 0, prev + 1);
	}
	else {
		//对于当前孩子prev 它可以分配的节点数从 0 到 left_resv
		for (int i = 0; i <= left_resv; ++ i) {
			//当前孩子分配 i 个节点
			next_resv[prev] = i;
			//下一个孩子 prev+1 只能分配 left_resv-i 个节点
			depth_search( r, f, next_resv, resv, left_resv - i, prev + 1 );
		}
	}
}

int multi_tree(multi_tree_node *r, int f[MAX][MAX], int resv)
{//二叉树根节点为r 初始时f为0 保留resv个节点 返回最大权值
	if(r == NULL)
		return(0);
	if(resv == 0)
		return(0);
	if(f[r->m_index][resv])
		return( f[ r->m_index ][resv] );

	//这个next_resv中存储着r的孩子们分配节点的数量
	int next_resv[MAX];
	for(int i = 0; i < r->m_count; ++ i)
		next_resv[i] = 0;
	//要对当前节点r的所有孩子分配剩余的resv-1个节点(根节点自己必须留1个)
	//用深度搜索找出所有可能 并将最大的权值赋给f[r->m_index][resv]
	depth_search( r, f, (int*)next_resv, resv, resv - 1, 0 );
	f[r->m_index][resv] += r->m_value;
	return(f[r->m_index][resv]);
}

#endif
