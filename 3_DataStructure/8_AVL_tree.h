#ifndef DATASTRUCTURE_AVL_TREE_H
#define DATASTRUCTURE_AVL_TREE_H 1
//平衡二叉树
//avl tree

//AVL树是一种所有的树的左右高度相差不大于1的平衡二叉树 各种操作效率为O(lgN)
//测试pat1066 http://www.patest.cn/contests/pat-a-practise/1066

//旋转一共分为下面四种情况
//
//          A               B
//
//          6               6
//       /     \
//      3       7
//    /   \
//   1     4
//    \
//     2
//
//******** A ********** B ************** C ********************* D ***************************
//********************************************************************************************
//*****    6   ****     6    ************2***********************2****************************
//*****   / \  ****    / \   ***********/*\*********************/*\***************************
//*****  3   7 ****   2   7  **********1***5*******************1***4**************************
//***** / \    ****  / \     *************/*\*********************/*\*************************
//*****1   4   **** 1   4    ************3***6*******************3***6************************
//***** \      ****    /     *************\*************************/*************************
//*****  2     ****   3      **************4***********************5**************************
//********************************************************************************************
//********************************************************************************************
//********************************************************************************************
//********************************************************************************************
//********************************************************************************************
/*********************************************************************************************
 *A、6节点的左子树3节点高度比右子树7节点大2，左子树3节点的左子树1节点高度大于右子树4节点，这种情况成为左左。
 *B、6节点的左子树2节点高度比右子树7节点大2，左子树2节点的左子树1节点高度小于右子树4节点，这种情况成为左右。
 *C、2节点的左子树1节点高度比右子树5节点小2，右子树5节点的左子树3节点高度大于右子树6节点，这种情况成为右左。
 *D、2节点的左子树1节点高度比右子树4节点小2，右子树4节点的左子树3节点高度小于右子树6节点，这种情况成为右右。
 */


#include <iostream>
using std::cout;
using std::endl;

/*AVL树节点信息*/
template <typename T>
struct TreeNode
{
	T data ;/*值*/
	int hgt;/*以此节点为根的树的高度*/
	unsigned int freq;/*频率*/
	TreeNode *lchild, *rchild;/*左右孩子*/
	TreeNode()
	{
		hgt = 0;
		freq = 1;
		lchild = NULL;
		rchild = NULL;
	}
};

/*AVL树类的属性和方法声明*/
template <typename T>
class AVLTree
{
private :
	TreeNode<T> *root;								/*根节点*/

	void InsertPri(TreeNode<T> * &node, T x);		/*插入x*/
	TreeNode <T>* FindPri(TreeNode<T> *node ,T x);	/*查找x*/
	void InSubTree(TreeNode<T> *node);				/*中序遍历*/
	void DeletePri(TreeNode<T> * &node, T x);		/*删除*/
	int height(TreeNode<T> *node);					/*树的高度*/
	void SingRotateLeft(TreeNode<T> * &k2);			/*左左情况下的旋转*/
	void SingRotateRight(TreeNode<T> * &k2);		/*右右情况的旋转*/
	void DoubleRotateLR(TreeNode<T> * &k3);			/*左右情况的旋转*/
	void DoubleRotateRL(TreeNode<T> * &k3);			/*左右情况的旋转*/
	int Max(int cmpa,int cmpb);						/*求最大值*/


public :
	AVLTree():root(NULL){}
	void insert(T x);								/*插入接口*/
	TreeNode<T> * Find(T x);						/*查找接口*/
	void Delete(T x);								/*删除接口*/
	void Treversal();								/*遍历接口*/
};


/*计算以节点为根的树的高度*/
template <typename T>
int AVLTree <T>::height(TreeNode<T>* node)
{
	return node!=NULL? node->hgt:-1;
}

/*求最大值*/
template <typename T>
int AVLTree<T>::Max(int cmpa,int cmpb)
{
	return cmpa>cmpb ? cmpa :cmpb;
}

/************************************************************************/
/*	单旋转    单旋转是针对于左左和右右这两种情况的解决方案，这两种情况是
 *对称的，只要解决了左左这种情况，右右就很好办了。图3是左左情况的解决方案，
 *节点k2不满足平衡特性，因为它的左子树k1比右子树Z深2层，而且k1子树中，更深
 *的一层的是k1的左子树X子树，所以属于左左情况    (左左情况下的选择)      */
/*为使树恢复平衡，我们把k2变成这棵树的根节点，因为k2大于k1，把k2置于k1的右
 *子树上，而原本在k1右子树的Y大于k1，小于k2，就把Y置于k2的左子树上，这样既
 *********************满足了二叉查找树的性质，又满足了平衡二叉树的性质。*/
/************************************************************************/
//****************k2******************************k1**********************
//***************/*\*****************************/*\**********************
//**************k1**z****--------->*************x***k2********************
//*************/*\*********************************/*\********************
//************x***y*******************************y***z*******************
/*这样的操作只需要一部分指针改变，结果我们得到另外一颗二叉查找树，它是一棵AVL树，因为X向
 *上一移动了一层，Y还停留在原来的层面上，Z向下移动了一层。整棵树的新高度和之前没有在左子
 *树上插入的高度相同，插入操作使得X高度长高了。因此，由于这颗子树高度没有变化，所以通往根
 *节点的路径就不需要继续旋转了。***********************************************/


/*左左旋转*/
template <typename T>
void AVLTree<T>::SingRotateLeft(TreeNode<T> * &k2)
{
	TreeNode<T> *k1;

	k1=k2->lchild;
	k2->lchild=k1->rchild;
	k1->rchild=k2;

	k2->hgt=Max(height(k2->lchild),height(k2->rchild))+1;
	k1->hgt=Max(height(k1->lchild),k2->hgt)+1;
	k2=k1;/*最后一定要更新根节点*/
}
/*右右旋转*/
template <typename T>
void AVLTree<T>::SingRotateRight(TreeNode<T> * &k2)
{
	TreeNode<T> *k1;

	k1=k2->rchild;
	k2->rchild=k1->lchild;
	k1->lchild=k2;

	k2->hgt=Max(height(k2->lchild),height(k2->rchild))+1;
	k1->hgt=Max(height(k1->rchild),k2->hgt)+1;
	k2=k1;/*最后一定要更新根节点*/
}
/**************************双旋转(左右情况下的双旋转)************************/
//************************************************************************
//*************k3******************k3**********************k2*************
//************/*\*****************/*\*********************/**\************
//**********k1***d*---->********k2***d*****---->********k1****k3**********
//*********/**\*****************/*\********************/*\***/*\**********
//********a****k2*************k1***c******************a***b*c***d*********
//************/*\************/*\******************************************
//***********b***c**********a***b*****************************************
//************************************************************************
//************************************************************************
//************************************************************************
/************************************************************************/
/*
 *左右旋转
 *为使树恢复平衡，我们需要进行两步，第一步，把k1作为根，进行一次右右旋转，旋转之后就变成
 *了左左情况，所以第二步再进行一次左左旋转，最后得到了一棵以k2为根的平衡二叉树树。
 */
template <typename T>
void AVLTree<T>::DoubleRotateLR(TreeNode<T> * &k3)
{
	SingRotateRight(k3->lchild);
	SingRotateLeft(k3);
}
/*右左旋转*/
template <typename T>
void AVLTree<T>::DoubleRotateRL(TreeNode<T> * &k3)
{
	SingRotateLeft(k3->rchild);
	SingRotateRight(k3);
}
/*************************************************************************
 *插入的方法和二叉查找树基本一样，区别是，插入完成后需要从插入的节点开始维护
 *一个到根节点的路径，每经过一个节点都要维持树的平衡。
 *维持树的平衡要根据高度差的特点选择不同的旋转算法。
 *insert
 *************************************************************************/
template <typename T>
void AVLTree<T>::InsertPri(TreeNode<T>* &node, T x)
{
	if(node==NULL)/*如果节点为空,就在此节点处加入x信息*/
	{
		node = new TreeNode<T>();
		node->data = x;
		return ;
	}
	if (node->data>x)/*如果X小于节点的值，就继续再节点的左子树中插入*/
	{
		InsertPri(node->lchild,x);
		if (2==height(node->lchild)-height(node->rchild))
		{
			if (x<node->lchild->data)
			{
				SingRotateLeft(node);
			}
			else
				DoubleRotateLR(node);
		}
	}
	else if (node->data<x)/*如果X大于节点的值，就继续再节点的右子树中插入*/
	{
		InsertPri(node->rchild,x);
		if (2==height(node->rchild)-height(node->lchild))
		{
			if (x>node->rchild->data)
			{
				SingRotateRight(node);
			}
			else
				DoubleRotateRL(node);
		}
	}
	else
		node->freq++;/*如果相等，频率加1*/
	node->hgt=Max(height(node->lchild),height(node->rchild))+1;
}

/************************************************************************/
/*                         插入接口                                      */
/************************************************************************/

template <typename T>
void AVLTree<T>::insert(T x)
{
	InsertPri(root,x);
}

/************************************************************************/
/* 查找                                                                  */
/*和二叉查找树相比，查找方法没有变法，不过根据存储的特性，
 *AVL树能维持在一个O(logN)的稳定的时间，而二叉查找树则相当不稳定。 */
/************************************************************************/

template<typename T>
TreeNode<T>* AVLTree<T>::FindPri(TreeNode<T> *node ,T x)
{
	if(node==NULL)/*如果节点为空说明没找到,返回NULL*/
		return NULL;
	if(node->data>x)/*如果x小于节点的值,就继续在节点的左子树中查找x*/
		return FindPri(node->lchild,x);
	if (node->data<x)/*如果x大于节点的值,就继续在节点的左子树中查找x*/
		return FindPri(node->rchild,x);
	return node;/*如果相等,就找到了此节点*/
}

/*查找接口*/
template<typename T>
TreeNode<T>* AVLTree<T>::Find(T x)
{
	return FindPri(root,x);
}

/************************************************************************/
/*   删除                                                                */
/*删除的方法也和二叉查找树的一致，区别是，删除完成后，
 *需要从删除节点的父亲开始向上维护树的平衡一直到根节点。				*/
/************************************************************************/
template<typename T>
void AVLTree<T>::DeletePri(TreeNode<T> * &node, T x)
{
	if(node==NULL)/*空*/
		return ;
	if(x<node->data)
	{/*如果x小于节点的值,就继续在节点的左子树中删除x，删除完成后，需要调整树，使之保持平衡*/
		DeletePri(node->lchild,x);

		if (2==height(node->rchild)-height(node->lchild))
		{
			if(node->rchild->lchild!=NULL &&
				(height(node->rchild->lchild)>height(node->rchild->rchild))
				)
				DoubleRotateRL(node);
			else
				SingRotateRight(node);
		}
	}
	else if (x>node->data)
	{/*如果大于节点的值,就继续在节点的右子树中删除x，删除完成后，需要调整树，使之保持平衡*/
		DeletePri(node->rchild,x);

		if (2==height(node->lchild)-height(node->rchild))
		{
			if(node->rchild->lchild!=NULL &&
				(height(node->lchild->rchild)>height(node->lchild->lchild))
				)
				DoubleRotateLR(node);
			else
				SingRotateLeft(node);
		}
	}
	else/*相等，删除，然后调整，使之平衡*/
	{
		if (node->lchild && node->rchild)/*此节点有两个儿子*/
		{
			TreeNode<T>* temp=node->rchild;/*temp指向节点的右儿子*/
			while(temp->lchild!=NULL)
				temp=temp->lchild;/*找到中序遍历的后继节点，必定在最左边那个*/

			node->data=temp->data;/*调整节点数据信息*/
			node->freq=temp->freq;

			DeletePri(node->rchild,temp->data);/*删除边缘节点*/
			if (2==height(node->lchild)-height(node->rchild))
			{
				if (node->lchild->rchild!=NULL &&
					(height(node->lchild->rchild)>height(node->lchild->lchild))
					)
					DoubleRotateLR(node);
				else
					SingRotateLeft(node);
			}
		}
		else/*此节点有1个或0个儿子*/
		{
			TreeNode<T> *temp=node;
			if(node->lchild==NULL)/*有右儿子或者没有儿子*/
				node=node->rchild;
			else if(node->rchild==NULL)/*有左儿子*/
				node=node->lchild;
			delete(temp);
			temp=NULL;
		}
	}
	if(node==NULL)
		return ;
	node->hgt=Max(height(node->lchild),height(node->rchild))+1;
	return ;
}
/*删除接口*/
template<typename T>
void AVLTree<T>::Delete(T x)
{
	DeletePri(root,x);
}

/*中序遍历函数*/
template<typename T>
void AVLTree<T>::InSubTree(TreeNode<T> *node)
{
	if(node==NULL)
		return ;
	InSubTree(node->lchild);/*先遍历左子树*/
	cout<<node->data<<" ";/*输出根节点*/
	InSubTree(node->rchild);/*再遍历右子树*/
}
/*中序遍历接口*/
template<typename T>
void AVLTree<T>::Treversal()
{
	//cout<<root->data;
	InSubTree(root);
}
#endif//avl.h
