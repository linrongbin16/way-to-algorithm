//多叉树动规
//multi_tree.cpp

//如果二叉树中的树变为多叉树，其他条件不变
//仍然求给定节点数量下的最大权值

//考虑在二叉树中分配剩余节点的情况：
//如果左子树分配i个节点，那么右子树必然只能分配 resv-i-1 个节点
//根节点自己也占 1 个
//但在多叉树中分配节点时：
//对于某个孩子树，若还剩余节点resv个
//那么这个孩子树可以分配的节点为i个，0<=i<=resv
//下一个孩子树可以分配的剩余节点数量为 resv-i 个
//那么总的剩余节点是 resv 个时
//给根节点的 n 个孩子树分配的方法有多少种情况呢
//如果读者还记得本书第一章搜索中第二节搜索中的深度优先搜算法，就可以轻松解决这个问题了
//
//状态转移方程与二叉树中一样
//我通过使用双递归技术，实现了对多叉树的深度搜索，请注意这个细节的实现

#include "general_head.h"
#include "tree_dynamic.h"
void depth_search(tree_node *r, int **f, int *next_resv,
		int resv, int left_resv, int prev);

int multi_tree(tree_node *r, int **f, int resv)
{//二叉树根节点为r，初始时f为0，保留resv个节点，返回最大权值
	if(r == NULL)
		return(0);
	if(resv == 0)
		return(0);
	if(f[r->t_idx][resv])
		return(f[r->t_idx][resv]);

	//这个next_resv中存储着r的孩子们分配节点的数量
	int next_resv[MAX];
	for(int i = 0; i < r->t_cnt; ++ i)
		next_resv[i] = 0;
	//要对当前节点r的所有孩子分配剩余的 resv-1 个节点(根节点自己必须留1个)
	//用深度搜索找出所有可能，并将最大的权值赋给f[r->t_idx][resv]
	depth_search(r, f, (int*)next_resv, resv, resv - 1, 0);
	f[r->t_idx][resv] += r->t_value;
	return(f[r->t_idx][resv]);
}
void depth_search(tree_node *r, int **f, int *next_resv,
		int resv, int left_resv, int prev = 0)
{//处理对当前r的所有孩子节点的分配工作
 //给节点r分配的剩余节点为resv个
 //给r的所有孩子节点分配的节点存储在next_resv数组中
 //将r的孩子树们分配的所有情况中的最大权值挑选出来赋给f[r->t_idx][resv]
 //只处理当前r节点，不会处理到下一层的节点
	//递归结束条件，深度搜索出一种组合后进行计算
	if(prev == r->t_cnt){
		//更新r树的最大权值
		int sumf(0);
		//下一层子树的最大权值又交给另一个递归去做
		for(int i = 0; i < r->t_cnt; ++ i)
			sumf += multi_tree(r->t_child[i], f, next_resv[i]);
		f[r->t_idx][resv] = max(f[r->t_idx][resv], sumf);
		return;
	}

	//对r的一个指定孩子prev
	if(prev == r->t_cnt - 1){
		//如果prev是孩子节点中的最后一个，它直接分配到剩余的所有节点
		next_resv[prev] = left_resv;
		depth_search(r, f, next_resv, resv, 0, prev + 1);
	}
	else{
		//对于当前孩子prev，它可以分配的节点数从 0 到 left_resv
		for(int i = 0; i <= left_resv; ++ i){
			//当前孩子分配 i 个节点
			next_resv[prev] = i;
			//下一个孩子 prev+1 只能分配 left_resv-i 个节点
			depth_search(r, f, next_resv, resv, left_resv - i, prev + 1);
		}
	}
}




