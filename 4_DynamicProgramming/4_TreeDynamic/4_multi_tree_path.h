#ifndef WAY_TO_ALGORITHM_DYNAMICPROGRAMMING_TREEDYNAMIC_MULTI_TREE_PATH_H
#define WAY_TO_ALGORITHM_DYNAMICPROGRAMMING_TREEDYNAMIC_MULTI_TREE_PATH_H 1
//多叉树动规路径
//multi tree path

//仍然是多叉树中求最大权值的问题 
//还需要输出最终的动规方案 即动规路径

//求多叉树动规方案的方法 是在执行完多叉树动规之后再对f数组的结果进行分析得到的
//分析数组f的过程是和之前的多叉树动规类似的一个动态规划的过程
//从多叉树根节点开始递归的进行分析
//根节点保留节点若为resv resv>0 根节点自己一定被选取
//它的孩子子树们保留的节点之和为resv-1
//在孩子子树的方案中找出一种使得权值最大的 再进行下一轮递归
//而根节点给孩子子树们分配resv-1节点的方法 仍旧用深搜法找出所有组合
//和之前多叉树动规的方法基本一样 但是更简单点

#include <iostream>
#include "2_multi_tree.h"
using std::cout;
using std::endl;


void depth_search_path(multi_tree_node *r, int f[MAX][MAX], 
        int *next_resv, int *max_next, int resv, int left_resv, int prev);

void multi_tree_path(multi_tree_node *r, int f[MAX][MAX], int resv)
{
	//递归结束条件
	if(r == NULL)
		return;
	if(resv == 0)
		return;

	//next_resv[i]指代r的孩子节点i分配的节点数量
	//max_next[i]指代r给孩子节点分配的所有组合中让r权值最大的分配方案
	int next_resv[MAX], max_next[MAX];
	for(int i = 0; i < r->m_count; ++ i)
		next_resv[i] = 0, max_next[i] = 0;
	depth_search_path(r, f, (int*)next_resv, (int*)max_next,
			resv, resv - 1, 0);
	for(int i = 0; i < r->m_count; ++ i)
		//通过深搜找出所有方案中让r权值最大的方案
		//即给每个孩子节点分配的节点数量 存储在max_next数组中
		//若某孩子分配的节点数量max_next[i]为0 会在递归式开始终止
		multi_tree_path(r->m_child[i], f, max_next[i]);
	//当前节点必被选择
	cout << "(index:" << r->m_index << ",fmax:" << f[r->m_index][resv] << ")" << endl;
}
void depth_search_path(multi_tree_node *r, int f[MAX][MAX], 
        int *next_resv, int *max_next, int resv, int left_resv, int prev = 0)
{
	if(prev == r->m_count){
		int sumf(0), fmax(0);
		//计算当前孩子节点分配的方案的最大权值
		for(int i = 0; i < r->m_count; ++ i)
			sumf += f[ r->m_child[i]->m_index ][ next_resv[i] ];
		//计算之前已知的最大权值的方案的权值
		for(int i = 0; i < r->m_count; ++ i)
			fmax += f[ r->m_child[i]->m_index ][ max_next[i] ];
		if(fmax < sumf)
			//如果已知的最大权值的方案 其权值比当前这种组合的权值之和小
			//那么更新最大权值方案
			for(int i = 0; i < r->m_count; ++ i)
				max_next[i] = next_resv[i];
		return;
	}

	//深搜的过程基本和之前的多叉树动规中的一样
	if (prev == r->m_count - 1) {
		next_resv[prev] = left_resv;
		depth_search_path(r, f, next_resv, max_next, resv, 0, prev + 1);
	}
	else {
		for (int i = 0; i <= left_resv; ++ i) {
			next_resv[prev] = i;
			depth_search_path(r, f, next_resv, max_next,
					resv, left_resv - i, prev + 1);
		}
	}
}


#endif
