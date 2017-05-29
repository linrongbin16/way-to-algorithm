#ifndef DATASTRUCTURE_RED_BLACK_TREE_H
#define DATASTRUCTURE_RED_BLACK_TREE_H 1
/*****************************************************************************
 * ���ɫ��
 * ������һ�ſ�����������һ�Ŷ�������������������
 *1.�ڵ�Ǻ켴�ڡ�
 *2.���ڵ��Ǻ�ɫ��
 *3.����NULL����ΪҶ�ӽڵ㣬����Ϊ��ɫΪ�ڡ�
 *4.���к�ڵ���ӽڵ㶼Ϊ��ɫ��
 *5.����һ�ڵ㵽��Ҷ�ӽڵ������·���϶�������ͬ��Ŀ�ĺڽڵ㡣
 *
 *��������нϺõ���ƽ���ԣ���������BST�����ǵ���AVL����linux�������ڴ����
 *
 *��˺��ɫ�ڲ���ڵ��Ȼ�Ǻ�ڵ㣬��Ϊ�ڽڵ���ƻ�����5�����ǻ������������
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

/**************ÿ���ڵ����Ϣ***********************/
class Node
{
public:
    int value;/******�ڵ��ŵ�ֵ******/
    bool color;/***�ڵ���ɫ****/
    Node *leftTree, *rightTree, *parent;/*******�������������ڵ�**********/

    Node(void):value(0),color(RED),leftTree(NULL),rightTree(NULL),parent(NULL) {}
    /**********��ȡ�游�ڵ�************/
    Node* grandparent(void)
    {
        return parent==NULL?NULL:parent->parent;
    }
    /***********��ȡ��ڵ�***********/
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
    /******��ȡ�ֵܽڵ�*********/
    Node* sibling(void)
    {
        return parent->leftTree==this?parent->rightTree:parent->leftTree;
    }

};

/******************���ɫ��*********************/
class RedBlackTree
{
private:

    void rotate_right(Node *p);/*******����********/
    void rotate_left(Node *p);/*******����********/
    void inorder(Node *p);/********�������***********/
    string outputColor(bool color);/********�����ɫ**********/
    Node* getSmallestChild(Node *p);/**********��ȡ��С����***********/
    bool delete_child(Node *p, int data);/*********ɾ������************/
    void delete_one_child(Node *p);/*********ɾ��һ������************/
    void delete_case(Node *p);/*********ɾ�����************/
    void insert(Node *p, int data);/********����*********/
    void insert_case(Node *p);/********�������***********/
    void DeleteTree(Node *p);/********ɾ����***********/
    bool find_data(Node* p,int data);/*********���ҽڵ�************/

public:

    RedBlackTree(void);/********����ӿ�***********/
    ~RedBlackTree();/********���ٽӿ�***********/
    void InOrderTraverse();/********�����ӿ�***********/
    void Insert(int x);/********����ӿ�***********/
    bool Delete(int data);/********ɾ���ӿ�***********/
    bool Find(int data);/********���ҽӿ�***********/
private:
    Node *root, *NIL;
};

//*******************************************************************
// Method:    rotate_right
// FullName:  RedBlackTree::rotate_right
// Access:    private
// Returns:   void
// Qualifier: ����ת
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

    if (gp != NULL)/******�ж����ڵ����游�ڵ�Ĺ�ϵ���Ӷ��޸���ϵ********/
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
// Qualifier: ����
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

    if (gp != NULL)/******�ж����ڵ����游�ڵ�Ĺ�ϵ���Ӷ��޸���ϵ********/
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
// Qualifier: ��������ڵ�
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
// Qualifier: �����ɫ
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
// Qualifier: ��ȡ��С����
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
// Qualifier: ɾ������
// Parameter: Node * p
// Parameter: int data
//************************************
bool RedBlackTree::delete_child(Node *p, int data)
{
    if (p->value > data)/*****�����*******/
    {
        if (p->leftTree == NIL)/*****û���ҵ�Ԫ��*******/
        {
            return false;
        }
        return delete_child(p->leftTree, data);
    }
    else if (p->value < data)/*****���ұ�*******/
    {
        if (p->rightTree == NIL)
        {
            return false;
        }
        return delete_child(p->rightTree, data);
    }
    else if (p->value == data)/*****�ҵ�*******/
    {
        if (p->rightTree == NIL)
        {
            /******����ڵ����������ˣ��������ֻ��һ�����ӣ�������Ҫ�滻�ڵ㣬�ٽ��뵥�ڵ�ɾ��*******/
            delete_one_child(p);
            return true;
        }
        Node *smallest = getSmallestChild(p->rightTree);/*�Ҵ��̽ڵ㣬Ȼ�󽻻�����ɾ��*/
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
// Qualifier: ɾ�����ֻ��һ�����ӵĽڵ�
// Parameter: Node * p
//************************************
void RedBlackTree::delete_one_child(Node *p)
{
    Node *child = p->leftTree == NIL ? p->rightTree : p->leftTree;
    if (p->parent == NULL and p->leftTree == NIL and p->rightTree == NIL)
    {
        /****ֻ�и��ڵ�*******/
        p = NULL;
        root = p;
        return;
    }

    if (p->parent == NULL)/****���ڵ�****/
    {
        delete  p;
        child->parent = NULL;/**���ø��ڵ�*/
        root = child;
        root->color = BLACK;
        return;
    }

    if (p->parent->leftTree == p)/**�滻���ýڵ�**/
    {
        p->parent->leftTree = child;
    }
    else
    {
        p->parent->rightTree = child;
    }
    child->parent = p->parent;

    if (p->color == BLACK)
    {
        /*****���ɾ���Ľڵ��Ǻڽڵ㣬��Ҫ������������Ǻ�ڵ㣬��ô����Ҳ�ǲ���ͻ�ģ���ֱ��ɾ������********/
        if (child->color == RED)/****�����Ǻ�ڵ�Ļ�����ֱ���˻��ɺڽڵ㣬��������û���⵽�ƻ�****/
        {
            child->color = BLACK;
        }
        else/*******������Ҫ��������*******/
            delete_case(child);
    }
    delete p;
}
//************************************
// Method:    delete_case
// FullName:  RedBlackTree::delete_case
// Access:    private
// Returns:   void
// Qualifier: ɾ�����
// Parameter: Node * p
//************************************
void RedBlackTree::delete_case(Node *p)
{
    if (p->parent == NULL)/***Ϊ���ڵ㣬ֱ��Ⱦ��ɫ***/
    {
        p->color = BLACK;
        return;
    }
    if (p->sibling()->color == RED)/****���1������ֵܽڵ��Ǻ�ɫ�Ļ���������ɫ����ת�������2,3,4����****/
    {
        p->parent->color = RED;
        p->sibling()->color = BLACK;
        if (p == p->parent->leftTree)
            rotate_left(p->sibling());
        else
            rotate_right(p->sibling());
    }
    if (p->parent->color == BLACK and p->sibling()->color == BLACK
            and p->sibling()->leftTree->color == BLACK and p->sibling()->rightTree->color == BLACK)
    {
        /****���2.1�����ڵ��ɫ���ֵܽڵ��Ǻ�ɫ�������ֵ���������ɫ���ӽڵ㣬��������Ⱦ���ֵܣ�Ȼ��������ڵ�****/
        p->sibling()->color = RED;
        delete_case(p->parent);
    }
    else if (p->parent->color == RED and p->sibling()->color == BLACK
             and p->sibling()->leftTree->color == BLACK and p->sibling()->rightTree->color == BLACK)
    {
        /****���2.2������ֵܽڵ��Ǻ�ɫ�Ļ��������ֵ���������ɫ���ӽڵ㣬��������Ⱦ���ֵܣ�Ȼ��������ڵ�****/
        p->sibling()->color = RED;
        p->parent->color = BLACK;
    }
    else
    {
        if (p->sibling()->color == BLACK)
        {
            /****���3.1������ֵܽڵ��Ǻ�ɫ�Ļ��������ֵ����Ӻ�ɫ���Һ��Ӻ�ɫ�������ֵܽڵ��������ɫ��ɵڵ��������****/
            if (p == p->parent->leftTree and p->sibling()->leftTree->color == RED
                    and p->sibling()->rightTree->color == BLACK)
            {
                p->sibling()->color = RED;
                p->sibling()->leftTree->color = BLACK;
                rotate_right(p->sibling()->leftTree);
            }
            else if (p == p->parent->rightTree and p->sibling()->leftTree->color == BLACK
                     and p->sibling()->rightTree->color == RED)
            {
                /****���3.2������ֵܽڵ��Ǻ�ɫ�Ļ��������ֵ����Ӻ�ɫ���Һ��Ӻ�ɫ****/
                p->sibling()->color = RED;
                p->sibling()->rightTree->color = BLACK;
                rotate_left(p->sibling()->rightTree);
            }
        }
        /****���4������ֵܽڵ��Ǻ�ɫ�Ļ��������ֵܶ���ڵ㺢��Ϊ��ɫ****/
        p->sibling()->color = p->parent->color;
        p->parent->color = BLACK;
        if (p == p->parent->leftTree)
        {
            /****���4.1���ڵ�Ϊ����������ô�ֵ��Һ���Ϊ��ɫ****/
            p->sibling()->rightTree->color = BLACK;
            rotate_left(p->sibling());
        }
        else
        {
            /****���4.2���ڵ�Ϊ����������ô�ֵ�����Ϊ��ɫ****/
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
// Qualifier: ��������
// Parameter: Node * p
// Parameter: int data
//************************************
void RedBlackTree::insert(Node *p, int data)
{
    if (p->value >= data)/**�������ݱ�dataС�������ڣ��Ļ���������ߣ���������ұ�**/
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
// Qualifier: ���������һ�����������
// Parameter: Node * p
//************************************
void RedBlackTree::insert_case(Node *p)
{
    if (p->parent == NULL)/****����1��ֱ��Ⱦ��ɫ*****/
    {
        root = p;
        p->color = BLACK;
        return;
    }
    if (p->parent->color == RED)
    {
        if (p->uncle()->color == RED)
        {
            /*����3�����ڵ����ڵ㶼�Ǻ�ɫ�����游��������ȫ��ɫ�����ݹ鴦���游�ڵ�*/
            p->parent->color = p->uncle()->color = BLACK;
            p->grandparent()->color = RED;
            insert_case(p->grandparent());
        }
        else/*���ڵ����ڵ㶼�Ǻ�ɫ������ڵ��ɫ*/
        {
            if (p->parent->rightTree == p and p->grandparent()->leftTree == p->parent)
            {
                /**����4��p�Ǹ��ڵ���Һ��ӣ����ڵ����游�ڵ������**/
                /********��������ȵ������ڵ㣬ʹ������游�͸��׾���һ�����ϣ�ע�⣬������ת��p���µĸ��ڵ�********/
                rotate_left(p);
                rotate_right(p);
                p->color = BLACK;
                p->leftTree->color = p->rightTree->color = RED;
            }
            else if (p->parent->leftTree == p and p->grandparent()->rightTree == p->parent)
            {
                /**����5��p�Ǹ��ڵ�����ӣ����ڵ����游�ڵ���Һ���**/
                /********��������ȵ������ڵ㣬ʹ������游�͸��׾���һ�����ϣ�ע�⣬������ת��p���µĸ��ڵ�********/
                rotate_right(p);
                rotate_left(p);
                p->color = BLACK;
                p->leftTree->color = p->rightTree->color = RED;
            }
            else if (p->parent->leftTree == p and p->grandparent()->leftTree == p->parent)
            {
                /**����5.2��p�Ǹ��ڵ���Һ��ӣ����ڵ����游�ڵ������**/
                p->parent->color = BLACK;
                p->grandparent()->color = RED;
                rotate_right(p->parent);
            }
            else if (p->parent->rightTree == p and p->grandparent()->rightTree == p->parent)
            {
                /**����4.2��p�Ǹ��ڵ���Һ��ӣ����ڵ����游�ڵ������**/
                p->parent->color = BLACK;
                p->grandparent()->color = RED;
                rotate_left(p->parent);
            }
        }
    }
    /*******�����case2���������Ϊ���ڵ��Ǻ�ɫ�����Կ���ֱ���˳�********/
}
//************************************
// Method:    DeleteTree
// FullName:  RedBlackTree::DeleteTree
// Access:    private
// Returns:   void
// Qualifier: ɾ����
// Parameter: Node * p
//************************************
void RedBlackTree::DeleteTree(Node *p)
{
    if (!p or p == NIL)
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
// Qualifier: ����ֵ
// Parameter: int data
//************************************
bool RedBlackTree::find_data(Node* p,int data)
{
    if(p==NULLorp==NIL)
        return false;
    if(data>p->value)
        return find_data(p->rightTree,data);
    else if(data<p->value)
        return find_data(p->leftTree,data);
    return true;
}


/**************************************�ӿڲ���********************************/

//************************************
// Method:    RedBlackTree
// FullName:  RedBlackTree::RedBlackTree
// Access:    public
// Returns:
// Qualifier: ��ʼ��
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
// Qualifier: �����ڵ�
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
// Qualifier: ����ֵ
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
// Qualifier: ɾ��ֵ
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
// Qualifier: ����ֵ
// Parameter: int data
//************************************
bool RedBlackTree::Find(int data)
{
    return find_data(root,data);
}
#endif /*redblaock.h*/

