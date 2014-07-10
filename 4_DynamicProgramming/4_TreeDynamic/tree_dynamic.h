//树形动规头文件
//tree_dynamic.h

//支持树形动规一节的自定义数据结构

#include <cstring>
#ifndef NULL
#define NULL 0
#endif
#ifndef MAX
#define MAX 60
#endif

struct tree_node{
	int t_idx;					//指代当前节点下标，节点的唯一标识
	int t_value;				//指代当前节点的权值
	tree_node *t_lc;			//指代左孩子的指针
	tree_node *t_rc;			//指代右孩子的指针
	tree_node *t_fa;			//指代父节点的指针

								//以下两个成员专门支持多叉树的计算
	tree_node* t_child[MAX];	//指代当前节点的孩子们的指针
								//从0到t_cnt - 1
	int t_cnt;					//指代多叉树孩子指针的个数

	int t_f[MAX];				//该数据结构的最为特别之处是：
								//将原本动态规划中使用的f数组也存储在树中
								//t_f[i]指代以当前节点为根节点的子树上
								//保留或分配的节点数为i时最大权值
	tree_node(int cidx = 0, int cvalue = 0, tree_node *clc = NULL,
			tree_node *crc = NULL, tree_node *cfa = NULL, int ccnt = 0)
		: t_idx(cidx), t_value(cvalue), t_lc(clc), t_rc(crc), t_fa(cfa), t_cnt(ccnt){
			memset(t_child, 0, MAX * sizeof(tree_node*));
			memset(t_f, 0, MAX * sizeof(int));
	}
	tree_node(const tree_node& cr)
		: t_idx(cr.t_idx), t_value(cr.t_value), t_lc(cr.t_lc), t_rc(cr.t_rc),
		t_fa(cr.t_fa), t_cnt(cr.t_cnt){
			for(int i = 0; i < cr.t_cnt; ++ i)
				t_child[i] = cr.t_child[i];
			for(int i = 0; i < MAX; ++ i)
				t_f[i] = cr.t_f[i];
	}
};
