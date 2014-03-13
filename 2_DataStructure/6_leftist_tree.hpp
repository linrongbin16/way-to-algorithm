//左偏树
//leftist_tree.hpp

//实现左偏树

//左偏树是一种能够快速合并两集合的二叉树数据结构
//它总是将所有节点按照键值key的一定顺序排列，本文按照从小到大的优先级实现左偏树
//左偏树的主要操作有：
//合并：将两个左偏树合并为一个左偏树
//插入：插入一个新节点
//最小值：返回左偏树中的根节点，根节点即为最小值节点
//删除最小值：删除根节点，将其右子树合并在左子树上
//
//左偏树的核心操作是合并操作
//为了保证数据从小到大排列，总是将键值key较小的树插在键值key较大的树的右子树上
//考虑两棵左偏树A和B，当A的键值key较小时将B插在A的右子树上(否则将A插在B的右子树上)
//而将A的原右子树C再插入B的右子树上，从而将B和C合并在一起
//为了尽量保证左偏树的稳定性，每个节点都设置距离dist
//总将距离dist较大的孩子子树作为左子树
//
//读者可以参考“图解数据结构(9)——左偏树”，作者“chao_yu”，其中有很详细的图解过程
//但该文档的图中存在两个键值key相同的节点“11”，从而导致测试时出现错误
//本章最后的测试用例中将其中一个“11”节点改成了“13”，经过测试可以得到正确答案
//
//本文引用了“左偏树(维基百科)”，无作者

#include "general_head.h"

struct left_node{
	int l_idx;
	int l_dist;
	left_node *l_lc;
	left_node *l_rc;
	left_node(int ci = 0, int cd = 0)
		: l_idx(ci), l_dist(cd), l_lc(NULL), l_rc(NULL){
	}
};
struct leftist_tree{
public:
	left_node *l_root;
private:
	void l_rec_print(left_node *r){
		if(r == NULL)
			return;
		cout << "(node:" << r->l_idx << ",dist:" << r->l_dist << ")";
		if(r->l_lc){
			cout << ", left child(node:" << r->l_lc->l_idx << ",dist:";
			cout << r->l_lc->l_dist << ")";
		}
		if(r->l_rc){
			cout << ", right child(node:" << r->l_rc->l_idx << ",dist:";
			cout << r->l_rc->l_dist << ")";
		}
		cout << endl;
		l_rec_print(r->l_lc);
		l_rec_print(r->l_rc);
	}
	left_node* t_rec_merge(left_node *a, left_node *b){
		//将节点a与节点b合并
		if(a == NULL)
			return(b);
		if(b == NULL)
			return(a);
		if(a->l_idx > b->l_idx)
			//总是将键值key较大的子树插入键值key较小的子树中
			//即可保证左偏树中根节点的键值key总是最小的
			return(t_rec_merge(b, a));

		//将节点r插在节点a的右子树上
		a->l_rc = t_rec_merge(a->l_rc, b);

		//将距离dist较小的孩子子树放在左边
		//尽量保证左偏树的平衡
		if(a->l_lc == NULL)
			swap(a->l_lc, a->l_rc);
		else{
			if(a->l_lc->l_dist < a->l_rc->l_dist)
				swap(a->l_lc, a->l_rc);
			a->l_dist = a->l_rc->l_dist + 1;
		}
		return(a);
	}
public:
	leftist_tree()
		: l_root(NULL){
	}
	void l_merge(leftist_tree *r){
		l_root = t_rec_merge(l_root, r->l_root);
	}
	int l_top(){
		return(l_root->l_idx);
	}
	void l_push(int r){
		//插入值为r的节点
		l_root = t_rec_merge(l_root, new left_node(r));
	}
	void l_pop(){
		//删除根节点
		l_root = t_rec_merge(l_root->l_lc, l_root->l_rc);
	}
	void l_print(){
		l_rec_print(l_root);
	}
};



