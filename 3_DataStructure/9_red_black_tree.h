#ifndef DATASTRUCTURE_RED_BLACK_TREE_H
#define DATASTRUCTURE_RED_BLACK_TREE_H 1
/*****************************************************************************
 * 红黑色：
 * 或者是一颗空树，或者是一颗二叉树，满足以下性质
 *1.节点非红即黑。
 *2.根节点是黑色。
 *3.所有NULL结点称为叶子节点，且认为颜色为黑。
 *4.所有红节点的子节点都为黑色。
 *5.从任一节点到其叶子节点的所有路径上都包含相同数目的黑节点。
 *
 *红黑树具有较好的自平衡性，性能优于BST，但是低于AVL，在linux中用于内存管理
 *
 *因此红黑色在插入节点必然是红节点，因为黑节点会破坏性质5，但是会出现下列问题
 *****************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::swap;
#ifndef BLACK
#define BLACK 1
#endif
#ifndef RED
#define RED 0
#endif

/**************每个节点的信息***********************/
class Node
{
public:
    int value;/******节点存放的值******/
    bool color;/***节点颜色****/
    Node *leftTree, *rightTree, *parent;/*******左右子树，父节点**********/

    Node(void):value(0),color(RED),leftTree(NULL),rightTree(NULL),parent(NULL){}
	/**********获取祖父节点************/
    Node* grandparent(void)
    {
        return parent==NULL?NULL:parent->parent;
    }
	/***********获取叔节点***********/
    Node* uncle(void)
    {
        if (grandparent() == NULL)
        {
            return NULL;
        }
        if (parent == grandparent()->rightTree)
            return grandparent()->leftTree;
        else
            return grandparent()->rightTree;
    }
	/******获取兄弟节点*********/
    Node* sibling(void)
    {
        return parent->leftTree==this?parent->rightTree:parent->leftTree;
    }

};

/******************红黑色类*********************/
class RedBlackTree
{
private:

    void rotate_right(Node *p);/*******右旋********/
    void rotate_left(Node *p);/*******左旋********/
    void inorder(Node *p);/********先序遍历***********/
    string outputColor(bool color);/********输出颜色**********/
    Node* getSmallestChild(Node *p);/**********获取最小子树***********/
    bool delete_child(Node *p, int data);/*********删除子树************/
    void delete_one_child(Node *p);/*********删除一个孩子************/
    void delete_case(Node *p);/*********删除情况************/
    void insert(Node *p, int data);/********插入*********/
    void insert_case(Node *p);/********插入情况***********/
    void DeleteTree(Node *p);/********删除树***********/
	bool find_data(Node* p,int data);/*********查找节点************/

public:

    RedBlackTree(void);/********构造接口***********/
    ~RedBlackTree();/********销毁接口***********/
    void InOrderTraverse();/********遍历接口***********/
    void Insert(int x);/********插入接口***********/
    bool Delete(int data);/********删除接口***********/
	bool Find(int data);/********查找接口***********/
private:
    Node *root, *NIL;
};

//*******************************************************************
// Method:    rotate_right
// FullName:  RedBlackTree::rotate_right
// Access:    private
// Returns:   void
// Qualifier: 右旋转
// Parameter: Node * p
//*******************************************************************
//*******************GP********************GP************************
//******************/**\******************/**\***********************
//****************FA****x****************P****X**********************
//***************/**\****--->***********/*\**************************
//*************P*****U*****************L**FA*************************
//************/*\************************Y**\************************
//***********L***Y***************************U***********************
//*******************************************************************
void RedBlackTree::rotate_right(Node *p)
{
    Node *gp = p->grandparent();
    Node *fa = p->parent;
    Node *y = p->rightTree;

    fa->leftTree = y;

    if (y != NIL)
        y->parent = fa;
    p->rightTree = fa;
    fa->parent = p;

    if (root == fa)
        root = p;
    p->parent = gp;

    if (gp != NULL)/******判读父节点与祖父节点的关系，从而修复关系********/
    {
        if (gp->leftTree == fa)
            gp->leftTree = p;
        else
            gp->rightTree = p;
    }
}
//*******************************************************************
// Method:    rotate_left
// FullName:  RedBlackTree::rotate_left
// Access:    private
// Returns:   void
// Qualifier: 左旋
// Parameter: Node * p
//*******************************************************************
//*******************************************************************
//*******************GP********************GP************************
//******************/**\******************/**\***********************
//****************FA****x****************P****X**********************
//***************/**\****--->***********/*\**************************
//**************X****P*****************FA**R*************************
//******************/*\***************/**\***************************
//*****************Y***R*************X****Y**************************
//*******************************************************************
void RedBlackTree::rotate_left(Node *p)
{
    if (p->parent == NULL)
    {
        root = p;
        return;
    }
    Node *gp = p->grandparent();
    Node *fa = p->parent;
    Node *y = p->leftTree;

    fa->rightTree = y;

    if (y != NIL)
        y->parent = fa;
    p->leftTree = fa;
    fa->parent = p;

    if (root == fa)
        root = p;
    p->parent = gp;

    if (gp != NULL)/******判读父节点与祖父节点的关系，从而修复关系********/
    {
        if (gp->leftTree == fa)
            gp->leftTree = p;
        else
            gp->rightTree = p;
    }
}
//************************************
// Method:    inorder
// FullName:  RedBlackTree::inorder
// Access:    private
// Returns:   void
// Qualifier: 中序遍历节点
// Parameter: Node * p
//************************************
void RedBlackTree::inorder(Node *p)
{
    if (p == NIL)
        return;

    if (p->leftTree)
        inorder(p->leftTree);

    cout << p->value << " ";

    if (p->rightTree)
        inorder(p->rightTree);
}

//************************************
// Method:    outputColor
// FullName:  RedBlackTree::outputColor
// Access:    private
// Returns:   std::string
// Qualifier: 输出颜色
// Parameter: bool color
//************************************
string RedBlackTree::outputColor(bool color)
{
    return color ? "BLACK" : "RED";
}
//************************************
// Method:    getSmallestChild
// FullName:  RedBlackTree::getSmallestChild
// Access:    private
// Returns:   Node*
// Qualifier: 获取最小孩子
// Parameter: Node * p
//************************************
Node* RedBlackTree::getSmallestChild(Node* p)
{
    if (p->leftTree == NIL)
        return p;
    return getSmallestChild(p->leftTree);
}
//************************************
// Method:    delete_child
// FullName:  RedBlackTree::delete_child
// Access:    private
// Returns:   bool
// Qualifier: 删除孩子
// Parameter: Node * p
// Parameter: int data
//************************************
bool RedBlackTree::delete_child(Node *p, int data)
{
    if (p->value > data)/*****在左边*******/
    {
        if (p->leftTree == NIL)/*****没有找到元素*******/
        {
            return false;
        }
        return delete_child(p->leftTree, data);
    }
    else if (p->value < data)/*****在右边*******/
    {
        if (p->rightTree == NIL)
        {
            return false;
        }
        return delete_child(p->rightTree, data);
    }
    else if (p->value == data)/*****找到*******/
    {
        if (p->rightTree == NIL)
        {/******如果节点右子树空了，这样最多只有一个孩子，否则需要替换节点，再进入单节点删除*******/
            delete_one_child(p);
            return true;
        }
        Node *smallest = getSmallestChild(p->rightTree);/*找打后继节点，然后交换，后删除*/
        swap(p->value, smallest->value);
        delete_one_child(smallest);

        return true;
    }
    return false;
}
//************************************
// Method:    delete_one_child
// FullName:  RedBlackTree::delete_one_child
// Access:    private
// Returns:   void
// Qualifier: 删除最多只有一个孩子的节点
// Parameter: Node * p
//************************************
void RedBlackTree::delete_one_child(Node *p)
{
    Node *child = p->leftTree == NIL ? p->rightTree : p->leftTree;
    if (p->parent == NULL && p->leftTree == NIL && p->rightTree == NIL)
    {/****只有根节点*******/
        p = NULL;
        root = p;
        return;
    }

    if (p->parent == NULL)/****根节点****/
    {
        delete  p;
        child->parent = NULL;/**重置根节点*/
        root = child;
        root->color = BLACK;
        return;
    }

    if (p->parent->leftTree == p)/**替换掉该节点**/
    {
        p->parent->leftTree = child;
    }
    else
    {
        p->parent->rightTree = child;
    }
    child->parent = p->parent;

    if (p->color == BLACK)
    {/*****如果删除的节点是黑节点，需要调整树，如果是红节点，那么子树也是不冲突的，则直接删除即可********/
        if (child->color == RED)/****子树是红节点的话，则直接退换成黑节点，并且性质没有遭到破坏****/
        {
            child->color = BLACK;
        }
        else/*******否则需要调整性质*******/
            delete_case(child);
    }
    delete p;
}
//************************************
// Method:    delete_case
// FullName:  RedBlackTree::delete_case
// Access:    private
// Returns:   void
// Qualifier: 删除情况
// Parameter: Node * p
//************************************
void RedBlackTree::delete_case(Node *p)
{
    if (p->parent == NULL)/***为根节点，直接染黑色***/
    {
        p->color = BLACK;
        return;
    }
    if (p->sibling()->color == RED)/****情况1：如果兄弟节点是红色的话，调整颜色后旋转，最后按照2,3,4处理****/
    {
        p->parent->color = RED;
        p->sibling()->color = BLACK;
        if (p == p->parent->leftTree)
            rotate_left(p->sibling());
        else
            rotate_right(p->sibling());
    }
    if (p->parent->color == BLACK && p->sibling()->color == BLACK
            && p->sibling()->leftTree->color == BLACK && p->sibling()->rightTree->color == BLACK)
    {/****情况2.1：父节点黑色，兄弟节点是黑色，而且兄弟有两个黑色的子节点，这样可以染红兄弟，然后调整父节点****/
        p->sibling()->color = RED;
        delete_case(p->parent);
    }
    else if (p->parent->color == RED && p->sibling()->color == BLACK
             && p->sibling()->leftTree->color == BLACK && p->sibling()->rightTree->color == BLACK)
    {/****情况2.2：如果兄弟节点是红色的话，而且兄弟有两个黑色的子节点，这样可以染红兄弟，然后调整父节点****/
        p->sibling()->color = RED;
        p->parent->color = BLACK;
    }
    else
    {
        if (p->sibling()->color == BLACK)
        {/****情况3.1：如果兄弟节点是黑色的话，而且兄弟左孩子红色，右孩子黑色，交换兄弟节点和左孩子颜色变成第第四种情况****/
            if (p == p->parent->leftTree && p->sibling()->leftTree->color == RED
                    && p->sibling()->rightTree->color == BLACK)
            {
                p->sibling()->color = RED;
                p->sibling()->leftTree->color = BLACK;
                rotate_right(p->sibling()->leftTree);
            }
            else if (p == p->parent->rightTree && p->sibling()->leftTree->color == BLACK
                     && p->sibling()->rightTree->color == RED)
            {/****情况3.2：如果兄弟节点是黑色的话，而且兄弟左孩子黑色，右孩子红色****/
                p->sibling()->color = RED;
                p->sibling()->rightTree->color = BLACK;
                rotate_left(p->sibling()->rightTree);
            }
        }
		/****情况4：如果兄弟节点是黑色的话，而且兄弟对面节点孩子为红色****/
        p->sibling()->color = p->parent->color;
        p->parent->color = BLACK;
        if (p == p->parent->leftTree)
        {/****情况4.1：节点为左子树，那么兄弟右孩子为红色****/
            p->sibling()->rightTree->color = BLACK;
            rotate_left(p->sibling());
        }
        else
        {/****情况4.2：节点为右子树，那么兄弟左孩子为红色****/
            p->sibling()->leftTree->color = BLACK;
            rotate_right(p->sibling());
        }
    }
}

//************************************
// Method:    insert
// FullName:  RedBlackTree::insert
// Access:    private
// Returns:   void
// Qualifier: 插入数据
// Parameter: Node * p
// Parameter: int data
//************************************
void RedBlackTree::insert(Node *p, int data)
{
    if (p->value >= data)/**插入数据比data小（含等于）的话，进入左边，否则进入右边**/
    {
        if (p->leftTree != NIL)
            insert(p->leftTree, data);
        else
        {
            Node *tmp = new Node();
            tmp->value = data;
            tmp->leftTree = tmp->rightTree = NIL;
            tmp->parent = p;
            p->leftTree = tmp;
            insert_case(tmp);
        }
    }
    else
    {
        if (p->rightTree != NIL)
            insert(p->rightTree, data);
        else
        {
            Node *tmp = new Node();
            tmp->value = data;
            tmp->leftTree = tmp->rightTree = NIL;
            tmp->parent = p;
            p->rightTree = tmp;
            insert_case(tmp);
        }
    }
}

//************************************
// Method:    insert_case
// FullName:  RedBlackTree::insert_case
// Access:    private
// Returns:   void
// Qualifier: 插入情况，一共有五种情况
// Parameter: Node * p
//************************************
void RedBlackTree::insert_case(Node *p)
{
    if (p->parent == NULL)/****情形1：直接染黑色*****/
    {
        root = p;
        p->color = BLACK;
        return;
    }
    if (p->parent->color == RED)
    {
        if (p->uncle()->color == RED)
        {/*情形3：父节点和叔节点都是红色，将祖父，父、叔全换色，最后递归处理祖父节点*/
            p->parent->color = p->uncle()->color = BLACK;
            p->grandparent()->color = RED;
            insert_case(p->grandparent());
        }
        else/*父节点和叔节点都是红色，叔叔节点黑色*/
        {
            if (p->parent->rightTree == p && p->grandparent()->leftTree == p->parent)
            {/**情形4：p是父节点的右孩子，父节点是祖父节点的左孩子**/
			/********这种情况先调整父节点，使得其和祖父和父亲均在一条线上，注意，这里旋转后p成新的父节点********/
                rotate_left(p);
                rotate_right(p);
                p->color = BLACK;
                p->leftTree->color = p->rightTree->color = RED;
            }
            else if (p->parent->leftTree == p && p->grandparent()->rightTree == p->parent)
            {/**情形5：p是父节点的左孩子，父节点是祖父节点的右孩子**/
			/********这种情况先调整父节点，使得其和祖父和父亲均在一条线上，注意，这里旋转后p成新的父节点********/
                rotate_right(p);
                rotate_left(p);
                p->color = BLACK;
                p->leftTree->color = p->rightTree->color = RED;
            }
            else if (p->parent->leftTree == p && p->grandparent()->leftTree == p->parent)
            {/**情形5.2：p是父节点的右孩子，父节点是祖父节点的左孩子**/
                p->parent->color = BLACK;
                p->grandparent()->color = RED;
                rotate_right(p->parent);
            }
            else if (p->parent->rightTree == p && p->grandparent()->rightTree == p->parent)
            {/**情形4.2：p是父节点的右孩子，父节点是祖父节点的左孩子**/
                p->parent->color = BLACK;
                p->grandparent()->color = RED;
                rotate_left(p->parent);
            }
        }
    }
	/*******最后考虑case2：情况，因为父节点是黑色，所以可以直接退出********/
}
//************************************
// Method:    DeleteTree
// FullName:  RedBlackTree::DeleteTree
// Access:    private
// Returns:   void
// Qualifier: 删除树
// Parameter: Node * p
//************************************
void RedBlackTree::DeleteTree(Node *p)
{
    if (!p || p == NIL)
    {
        return;
    }
    DeleteTree(p->leftTree);
    DeleteTree(p->rightTree);
    delete p;
}
//************************************
// Method:    find_data
// FullName:  RedBlackTree::find_data
// Access:    public
// Returns:   bool
// Qualifier: 查找值
// Parameter: int data
//************************************
bool RedBlackTree::find_data(Node* p,int data)
{
	if(p==NULL||p==NIL)
		return false;
	if(data>p->value)
		return find_data(p->rightTree,data);
	else if(data<p->value)
		return find_data(p->leftTree,data);
	return true;
}


/**************************************接口部分********************************/

//************************************
// Method:    RedBlackTree
// FullName:  RedBlackTree::RedBlackTree
// Access:    public
// Returns:
// Qualifier: 初始化
// Parameter: void
//************************************
RedBlackTree::RedBlackTree(void)
{
    NIL = new Node();
    NIL->color = BLACK;
    root = NULL;
}

RedBlackTree::~RedBlackTree(void)
{
    if (root)
        DeleteTree(root);
    delete NIL;
}

//************************************
// Method:    inorder
// FullName:  RedBlackTree::inorder
// Access:    public
// Returns:   void
// Qualifier: 遍历节点
// Parameter: void
//************************************
void RedBlackTree::InOrderTraverse(void)
{
    if (root == NULL)
        return;
    inorder(root);
    cout << endl;
}
//************************************
// Method:    insert
// FullName:  RedBlackTree::insert
// Access:    public
// Returns:   void
// Qualifier: 插入值
// Parameter: int x
//************************************
void RedBlackTree::Insert(int x)
{
    if (root == NULL)
    {
        root = new Node();
        root->color = BLACK;
        root->leftTree = root->rightTree = NIL;
        root->value = x;
    }
    else
    {
        insert(root, x);
    }
}

//************************************
// Method:    delete_value
// FullName:  RedBlackTree::delete_value
// Access:    public
// Returns:   bool
// Qualifier: 删除值
// Parameter: int data
//************************************
bool RedBlackTree::Delete(int data)
{
    return delete_child(root, data);
}

//************************************
// Method:    Find
// FullName:  RedBlackTree::Find
// Access:    public
// Returns:   bool
// Qualifier: 查找值
// Parameter: int data
//************************************
bool RedBlackTree::Find(int data)
{
	return find_data(root,data);
}
#endif /*redblaock.h*/

