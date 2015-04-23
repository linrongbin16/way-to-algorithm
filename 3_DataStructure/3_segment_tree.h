#ifndef DATASTRUCTURE_SEGMENT_TREE_H
#define DATASTRUCTURE_SEGMENT_TREE_H 1
//线段树
//segment tree

//x轴上有一条直线，多次对x轴上的一些线段进行染色，同一范围的线段可能重复染色
//求被染色的线段的长度之和

//最原始的方法是设置数组来表示x轴上直线
//每染色一个线段都标记数组中相应的坐标位置，最后累加所有染色坐标的长度之和
//该方法显然太慢了，无法快速的处理大量的染色
//
//线段树是一个二叉树，每个节点都是一段线段的左闭右闭区间[beg, end]
//线段树属于区间树的一种，每个节点都是一个区间
//线段树用于解决大量的区间覆盖问题，线段染色问题是线段树的典型应用场景
//
//线段树有元线段和非元线段两种节点
//元线段是长度只有1的线段，比如[1, 2]
//非元线段长度大于1，且该节点[beg, end]必有两个孩子节点
//其中左孩子线段为[beg, (beg+end)/2]，右孩子线段为[(beg+end)/2, end]
//对于线段树中每个节点，以它为根节点的子树中的孩子节点都在它的范围内
//比如这样：
//						[1, 6]
//				   /			  \
//			  [1, 3]			   [3, 6]
//			 /      \			 /	      \
//		  [1, 2]   [2, 3]	 [3, 4]	      [4, 6]
//										 /		\
//									  [4, 5]	[5, 6]
//
//线段范围为[1, n]的线段树深度为lg(n)+1，空间复杂度为O(n)
//本文中线段树在每个节点上都设置一个标志位cover来标记当前节点代表的区间被染色
//在构造线段树时就会生成所有节点，之后的插入，删除和统计操作只设置或读取标志位cover
//每染色一个线段即从线段树的根节点开始遍历，设置被染色的线段区间在线段树中的标志位
//统计长度时只需遍历线段树，累加被标记的节点的区间长度之和
//
//本文引用了“线段树(segment tree)”，作者“Microgoogle”


#include <iostream>
using std::cout;
using std::endl;
struct st_node
{
	int _beg;
	int _end;
	int _cover;
	st_node *_leftchild;
	st_node *_rightchild;
	st_node()
	{
		_beg = 0;
		_end = 0;
		_cover = 0;
		_leftchild = 0;
		_rightchild = 0;
	}
	st_node(const st_node& node)
	{
		_beg = node._beg;
		_end = node._end;
		_cover = node._cover;
		_leftchild = node._leftchild;
		_rightchild = node._rightchild;
	}
	~st_node()
	{ }
};

//线段树的实现使用递归技术
st_node* segment_tree_build(int beg, int end)
{//生成[beg, end]中的所有节点
 //左子树生成根节点从beg到mid的线段区域
 //右子树生成根节点从mid到end的线段区域
 //右子树通常会比左子树高一层
 //返回最终得到的线段树的根节点指针
	st_node *root = new st_node();
	root->_beg = beg;
	root->_end = end;
	if(beg + 1 < end){
		root->_leftchild = segment_tree_build(beg, (beg + end) / 2);
		root->_rightchild = segment_tree_build((beg + end) / 2, end);
	}
	return(root);
}
void segment_tree_insert(st_node *root, int beg, int end)
{//若当前节点已被染色则不必再继续向下遍历
	if(root->_cover)
		return;

	//注意这里的判断条件
	//mid指代当前节点的区域的中间点
	int mid = (root->_beg + root->_end) / 2;
	if(beg == root->_beg && end == root->_end)
		//插入区域与当前节点的区域“完全重合”
		root->_cover = 1;
	else if(end <= mid)
		//插入区域的右界在当前节点的中间点mid的左边
		//则将插入区域插入当前节点的左子树
		segment_tree_insert(root->_leftchild, beg, end);
	else if(beg >= mid)
		//插入区域的左界在当前节点的中间点mid的右边
		//则将插入区域插入当前节点的右子树
		segment_tree_insert(root->_rightchild, beg, end);
	else{
		//插入区域的一部分在当前节点的中间点mid的左边
		//另一部分在中间点mid的右边
		//将插入区域从中间点mid分成两个部分，分别继续递归插入
		segment_tree_insert(root->_leftchild, beg, mid);
		segment_tree_insert(root->_rightchild, mid, end);
	}
}
int segment_tree_length(st_node *root)
{//求当前线段树中被覆盖的线段长度之和
	if(root == NULL)
		return(0);
	if(root->_cover)
		return(root->_end - root->_beg);

	int left_length = segment_tree_length(root->_leftchild);
	int right_length = segment_tree_length(root->_rightchild);
	return(left_length + right_length);
}
void segment_tree_print(st_node *root)
{//打印线段树信息
	if(root == NULL)
		return;
	cout << "node beg:" << root->_beg << ", end:" << root->_end << ", cover:" << root->_cover;
	if(root->_leftchild){
		cout << " left child(beg:" << root->_leftchild->_beg << ",end:" << root->_leftchild->_end << ")";
	}
	if(root->_rightchild){
		cout << " right child(beg:" << root->_rightchild->_beg << ",end:" << root->_rightchild->_end << ")";
	}
	cout << endl;
	segment_tree_print(root->_leftchild);
	segment_tree_print(root->_rightchild);
}

#endif
