#ifndef DATASTRUCTURE_LEFTIST_TREE_H
#define DATASTRUCTURE_LEFTIST_TREE_H 1
//左偏树
//leftist tree

//实现左偏树

//左偏树是一种能够快速合并两集合的二叉树数据结构
//它总是将所有节点按照键值key的一定顺序排列 本文按照从小到大的优先级实现左偏树
//左偏树的主要操作有
//合并 将两个左偏树合并为一个左偏树
//插入 插入一个新节点
//最小值 返回左偏树中的根节点 根节点即为最小值节点
//删除最小值 删除根节点 将其右子树合并在左子树上
//
//左偏树的核心操作是合并操作
//为了保证数据从小到大排列 总是将键值key较小的树插在键值key较大的树的右子树上
//考虑两棵左偏树A和B 当A的键值key较小时将B插在A的右子树上(否则将A插在B的右子树上)
//而将A的原右子树C再插入B的右子树上 从而将B和C合并在一起
//为了尽量保证左偏树的稳定性 每个节点都设置距离dist
//总将距离dist较大的孩子子树作为左子树
//
//读者可以参考"图解数据结构(9)——左偏树" 作者"chao_yu" 其中有很详细的图解过程
//但该文档的图中存在两个键值key相同的节点"11" 从而导致测试时出现错误
//本章最后的测试用例中将其中一个"11"节点改成了"13" 经过测试可以得到正确答案
//
//本文引用了"左偏树(维基百科)" 无作者


#include <algorithm>
#include <iostream>
using std::swap;
using std::cout;
using std::endl;
struct leftist_tree_node
{
	int m_index;
	int m_depth;
	leftist_tree_node *m_leftchild;
	leftist_tree_node *m_rightchild;
	leftist_tree_node()
	{
		m_index = 0;
		m_depth = 0;
		m_leftchild = 0;
		m_rightchild = 0;
	}
};

leftist_tree_node* leftist_tree_merge(leftist_tree_node *a, leftist_tree_node *b)
{//将以节点a为根的子树与以节点b为根的子树合并
	if(a == NULL)
		return(b);
	if(b == NULL)
		return(a);
	if(a->m_index > b->m_index)
		//总是将键值key较大的子树插入键值key较小的子树中
		//即可保证左偏树中根节点的键值key总是最小的
		return(leftist_tree_merge(b, a));

	//将节点r插在节点a的右子树上
	a->m_rightchild = leftist_tree_merge(a->m_rightchild, b);

	//将距离dist较小的孩子子树放在左边
	//尽量保证左偏树的平衡
	if(a->m_leftchild == NULL)
		swap(a->m_leftchild, a->m_rightchild);
	else{
		if(a->m_leftchild->m_depth < a->m_rightchild->m_depth)
			swap(a->m_leftchild, a->m_rightchild);
		a->m_depth = a->m_rightchild->m_depth + 1;
	}
	return(a);
}
int leftist_tree_top(leftist_tree_node *root)
{//root左偏树的根节点
	return(root->m_index);
}
leftist_tree_node* leftist_tree_push(leftist_tree_node *root, int value)
{//向root左偏树中插入值为value的节点 即为将一个value值的节点与root树合并
	leftist_tree_node *node = new leftist_tree_node();
	node->m_index = value;
	return(leftist_tree_merge(root, node));
}
leftist_tree_node* leftist_tree_pop(leftist_tree_node *root)
{//删除根节点 即为将root树的左子树和右子树合并
	return(leftist_tree_merge(root->m_leftchild, root->m_rightchild));
}
void leftist_tree_print(leftist_tree_node *root)
{//打印root左偏树
	if(root == NULL)
		return;
	cout << "(node:" << root->m_index << ",dist:" << root->m_depth << ")";
	if(root->m_leftchild){
		cout << ", left child(node:" << root->m_leftchild->m_index << ",dist:";
		cout << root->m_leftchild->m_depth << ")";
	}
	if(root->m_rightchild){
		cout << ", right child(node:" << root->m_rightchild->m_index << ",dist:";
		cout << root->m_rightchild->m_depth << ")";
	}
	cout << endl;
	leftist_tree_print(root->m_leftchild);
	leftist_tree_print(root->m_rightchild);
}

#endif
