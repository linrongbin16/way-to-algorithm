//树形动规头文件
//tree_dynamic.h

//支持树形动规一节的自定义数据结构

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
	tree_node(int ci = 0, int cv = 0, tree_node *cl = NULL, tree_node *cr = NULL,
			tree_node *ca = NULL, int cc = 0)
		: t_idx(ci), t_value(cv), t_lc(cl), t_rc(cr), t_fa(ca), t_cnt(cc){
			for(int i = 0; i < MAX; ++ i)
				t_child[i] = NULL;
			for(int i = 0; i < MAX; ++ i)
				t_f[i] = 0;
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







