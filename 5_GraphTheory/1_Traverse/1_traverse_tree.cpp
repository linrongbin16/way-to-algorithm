//遍历树
//traverse tree

//先序遍历 中序遍历 后序遍历

//从根节点开始对树进行递归


#include "general_head.h"
#include "graph.h"
#ifndef NULL
#define NULL 0
#endif


void print_node(tree_node *p)
{
	if(p == NULL)
		return;
	cout << "(index:" << p->t_idx << ")" << endl;
}
void print_node(graph_node *p)
{
	if(p == NULL)
		return;
	cout << "(index:" << p->g_idx << ")" << endl;
}

void preorder_traverse(tree_node *root) 
{//从根节点开始先序遍历
	//先序遍历的访问优先级是节点>左子树>右子树
	//递归终止条件
	if(root == NULL)
		return;
	print_node(root);
	preorder_traverse(root->t_lc);
	preorder_traverse(root->t_rc);
}
void inorder_traverse(tree_node *root) 
{//从根节点开始中序遍历
	//中序遍历的访问优先级是左子树>节点>右子树
	if(root == NULL)
		return;

	inorder_traverse(root->t_lc);
	print_node(root);
	inorder_traverse(root->t_rc);
}
void postorder_traverse(tree_node *root) 
{//从根节点开始后序遍历
	//后序遍历的访问优先级是左子树>右子树>节点
	if(root == NULL)
		return;

	postorder_traverse(root->t_lc);
	postorder_traverse(root->t_rc);
	print_node(root);
}
