#ifndef DATA_STRUCTURE_AVL_TREE_HPP
#define DATA_STRUCTURE_AVL_TREE_HPP 1

#include <algorithm>
#include <assert.h>

struct AVLTreeNode {
    /* 节点下标号 */
    int index;
    /* 节点高度值 */
    int depth;
    /* 左右孩子节点 */
    AVLTreeNode *left;
    AVLTreeNode *right;
};

struct AVLTree {
    AVLTreeNode *root;
};

void RotateLL(AVLTreeNode **e);
void RotateRR(AVLTreeNode **e);
void RotateLR(AVLTreeNode **e);
void RotateRL(AVLTreeNode **e);
void NodeFree(AVLTreeNode *e);
void NodeInsert(AVLTreeNode **e, int index);
int NodeFind(AVLTreeNode **e, int index);
void NodeErase(AVLTreeNode **e, int index);
int NodeDepth(AVLTreeNode *e);

AVLTree* AVLTreeNew()
{
    AVLTree *t = new AVLTree();
    if (!t)
        return NULL;
    t->root = NULL;
    return t;
}

void AVLTreeFree(AVLTree *t)
{
    NodeFree(t->root);
}

void AVLTreeInsert(AVLTree *t, int index)
{
    if (t->root) {
        NodeInsert( &(t->root), index);
        return;
    }

    t->root = new AVLTreeNode();
    t->root->left = NULL;
    t->root->right = NULL;
    t->root->index = index;
    t->root->depth = 0;
}

int AVLTreeFind(AVLTree *t, int index)
{
    return NodeFind( &(t->root), index);
}

void AVLTreeErase(AVLTree *t, int index)
{
    NodeErase( &(t->root), index);
}

int AVLTreeDepth(AVLTree *t)
{
    if (!t->root)
        return 0;
    return t->root->depth;
}

void NodeFree(AVLTreeNode *e)
{
    if (!e)
        return;
    NodeFree(e->left);
    NodeFree(e->right);
    delete e;
}

void RotateLL(AVLTreeNode **e)
{
    AVLTreeNode *e1;

    e1 = (*e)->left;
    (*e)->left = e1->right;
    e1->right = (*e);

    (*e)->depth = std::max( NodeDepth((*e)->left), NodeDepth((*e)->right) ) + 1;
    e1->depth = std::max( NodeDepth(e1->left), (*e)->depth ) + 1;
    (*e) = e1;
}

void RotateRR(AVLTreeNode **e)
{
    AVLTreeNode *e1;

    e1 = (*e)->right;
    (*e)->right = e1->left;
    e1->left = (*e);

    (*e)->depth = std::max( NodeDepth((*e)->left) , NodeDepth((*e)->right) ) + 1;
    e1->depth = std::max( NodeDepth(e1->right), (*e)->depth ) + 1;
    (*e) = e1;
}

void RotateLR(AVLTreeNode **e)
{
    RotateRR( &((*e)->left) );
    RotateLL( e );
}

void RotateRL(AVLTreeNode **e)
{
    RotateLL( &((*e)->right) );
    RotateRR( e );
}

void NodeInsert(AVLTreeNode **e, int index)
{
    assert(e);
    assert(*e);
    /* 二分插入 */
    if ( (*e)->index > index ) {
        // 若左孩子节点为空节点 创建新的节点
        if ((*e)->left == NULL) {
            (*e)->left = new AVLTreeNode();
            (*e)->left->left = NULL;
            (*e)->left->right = NULL;
            (*e)->left->index = index;
            (*e)->left->depth = 0;
        } else {
            NodeInsert( &((*e)->left), index );
        }
        if ( NodeDepth((*e)->left) - NodeDepth((*e)->right) >= 2 ) {
            if ( (*e)->left->index > index ) {
                RotateLL( e );
            } else {
                RotateLR( e );
            }
        }
    } else if ( (*e)->index < index ) {
        // 若右孩子节点为空节点 创建新的节点
        if ((*e)->right == NULL) {
            (*e)->right = new AVLTreeNode();
            (*e)->right->left = NULL;
            (*e)->right->right = NULL;
            (*e)->right->index = index;
            (*e)->right->depth = 0;
        } else {
            NodeInsert(&((*e)->right), index);
        }
        if ( NodeDepth((*e)->right) - NodeDepth((*e)->left) >= 2 ) {
            if ( (*e)->right->index < index ) {
                RotateRR( e );
            } else {
                RotateRL( e );
            }
        }
    } 

    (*e)->depth = std::max( NodeDepth((*e)->left), NodeDepth((*e)->right) ) + 1;
}

int NodeFind(AVLTreeNode **e, int index)
{
    if (*e == NULL)
        return 0;
    /* 二分查找 */
    if ( (*e)->index == index ) {
        return 1;
    } else if ( (*e)->index > index ) {
        return NodeFind( &((*e)->left), index );
    } else { 
        return NodeFind( &((*e)->right) , index );
    } 
}

void NodeErase(AVLTreeNode **e, int index)
{
    if ( (*e)->index > index ) {
        NodeErase( &((*e)->left), index );

        if ( NodeDepth((*e)->right) - NodeDepth((*e)->left) >= 2 ) {
            if ( (*e)->right->left != NULL && ((*e)->right->left->depth > (*e)->right->right->depth) ) {
                RotateRL( e );
            } else {
                RotateRR( e );
            }
        }
    } else if ( (*e)->index < index ) {
        NodeErase( &((*e)->right), index );

        if ( NodeDepth((*e)->left) - NodeDepth((*e)->right) >= 2 ) {
            if ( (*e)->right->left != NULL && ((*e)->left->right->depth >(*e)->left->left->depth) ) {
                RotateLR( e );
            } else {
                RotateLL( e );
            }
        }
    } else {
        /* (*e)->index == index */
        if ( (*e)->left && (*e)->right ) {
            AVLTreeNode* temp = (*e)->right;

            /* temp指向节点的右儿子 */
            /* 找到中序遍历的后继节点 */
            while ( temp->left != NULL )
                temp = temp->left;

            (*e)->index = temp->index; /*调整节点数据信息*/

            /* 删除边缘节点 */
            NodeErase( &((*e)->right), temp->index );
            if ( NodeDepth((*e)->left) - NodeDepth((*e)->right) >= 2 ) {
                if ( (*e)->left->right != NULL && (NodeDepth((*e)->left->right) > NodeDepth((*e)->left->left) ) ) {
                    RotateLR( e );
                } else {
                    RotateLL( e );
                }
            }
        } else {
            AVLTreeNode* temp = (*e);
            if( (*e)->left == NULL )
                (*e) = (*e)->right;
            else if ( (*e)->right == NULL )
                (*e) = (*e)->left;
            delete temp;
        }
    }

    if ( (*e) == NULL)
        return;

    (*e)->depth = std::max( NodeDepth((*e)->left), NodeDepth((*e)->right)) + 1;
    return;
}

// 空节点的高度值depth=-1
// 叶子结点的高度值depth=0
int NodeDepth(AVLTreeNode *e)
{
    return e ? e->depth : -1;
}


#endif