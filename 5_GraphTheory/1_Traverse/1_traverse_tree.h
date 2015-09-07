#ifndef WAY_TO_ALGORITHM_GRAPHTHEORY_TRAVERSE_TRAVERSE_TREE_H
#define WAY_TO_ALGORITHM_GRAPHTHEORY_TRAVERSE_TRAVERSE_TREE_H 1
//遍历树
//traverse tree

//先序遍历 中序遍历 后序遍历

//从根节点开始对树进行递归


#include <iostream>
using std::cout;
using std::endl;
#ifndef NULL
#define NULL 0
#endif

struct traverse_tree_node
{
    int     m_index;
    traverse_tree_node*     m_left;
    traverse_tree_node*     m_right;
};


void traverse_print_node(traverse_tree_node *p)
{
	if(p == NULL)
		return;
	cout << "(index:" << p->m_index << ")" << endl;
}

void preorder_traverse(traverse_tree_node *root) 
{//从根节点开始先序遍历
	//先序遍历的访问优先级是 节点>左子树>右子树
	//递归终止条件
	if(root == NULL)
		return;
	traverse_print_node(root);
	preorder_traverse(root->m_left);
	preorder_traverse(root->m_right);
}
void inorder_traverse(traverse_tree_node *root) 
{//从根节点开始中序遍历
	//中序遍历的访问优先级是 左子树>节点>右子树
	if(root == NULL)
		return;

	inorder_traverse(root->m_left);
	traverse_print_node(root);
	inorder_traverse(root->m_right);
}
void postorder_traverse(traverse_tree_node *root) 
{//从根节点开始后序遍历
	//后序遍历的访问优先级是 左子树>右子树>节点
	if(root == NULL)
		return;

	postorder_traverse(root->m_left);
	postorder_traverse(root->m_right);
	traverse_print_node(root);
}

#endif
