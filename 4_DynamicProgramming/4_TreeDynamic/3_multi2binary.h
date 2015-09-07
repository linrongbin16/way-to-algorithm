#ifndef WAY_TO_ALGORITHM_DYNAMICPROGRAMMING_TREEDYNAMIC_MULTI2BINARY_H
#define WAY_TO_ALGORITHM_DYNAMICPROGRAMMING_TREEDYNAMIC_MULTI2BINARY_H 1

//多叉树转二叉树动规
//multi to binary

//仍然是同一个多叉树求最大权值的问题

//将多叉树动规问题转化为二叉树动规来求解：
//将多叉树转化为一个二叉树森林
//对于原本多叉树中的每个节点
//其左孩子是当前节点的所有孩子中的第一个孩子节点指针
//其右孩子是当前节点的所有兄弟
//对这样的森林中的每个二叉树递归调用二叉树动规的方法
//就可以求出多叉树的最大权值

#endif
