#ifndef DATA_STRUCTURE_AVL_TREE_HPP
#define DATA_STRUCTURE_AVL_TREE_HPP 1


#include <algorithm>

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

void AVLTreeNodeFree(AVLTreeNode *e);
void RotateLL(AVLTreeNode **e);
void RotateRR(AVLTreeNode **e);
void RotateLR(AVLTreeNode **e);
void RotateRL(AVLTreeNode **e);
void AVLTreeNodeInsert(AVLTreeNode **e, int index);
int AVLTreeNodeFind(AVLTreeNode **e, int index);
void AVLTreeNodeErase(AVLTreeNode **e, int index);

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
    AVLTreeNodeFree(t->root);
}

void AVLTreeInsert(AVLTree *t, int index)
{
    if (t->root) {
        AVLTreeNodeInsert( &(t->root), index);
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
    return AVLTreeNodeFind( &(t->root), index);
}

void AVLTreeErase(AVLTree *t, int index)
{
    AVLTreeNodeErase( &(t->root), index);
}

void AVLTreeNodeFree(AVLTreeNode *e)
{
    if (!e)
        return;
    AVLTreeNodeFree(e->left);
    AVLTreeNodeFree(e->right);
    delete e;
}

void RotateLL(AVLTreeNode **e)
{
    AVLTreeNode *e1;

    e1 = (*e)->left;
    (*e)->left = e1->right;
    e1->right = (*e);

    (*e)->depth = std::max( (*e)->left->depth, (*e)->right->depth ) + 1;
    e1->depth = std::max( e1->left->depth, (*e)->depth ) + 1;
    (*e) = e1;
}

void RotateRR(AVLTreeNode **e)
{
    AVLTreeNode *e1;

    e1 = (*e)->right;
    (*e)->right = e1->left;
    e1->left = (*e);

    (*e)->depth = std::max( (*e)->left->depth, (*e)->right->depth ) + 1;
    e1->depth = std::max( e1->right->depth, (*e)->depth ) + 1;
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

void AVLTreeNodeInsert(AVLTreeNode **e, int index)
{
    /* 如果节点为空 就在此节点处加入x信息 */
    if ( (*e) == NULL ) {
        (*e) = new AVLTreeNode();
        (*e)->index = index;
        return;
    }

    /* 二分插入 */
    if ( (*e)->index > index ) {
        AVLTreeNodeInsert( &((*e)->left), index );
        if ( (*e)->left->depth - (*e)->right->depth >= 2 ) {
            if ( (*e)->left->index > index ) {
                RotateLL( e );
            } else {
                RotateLR( e );
            }
        }
    } else if ( (*e)->index < index ) {
        AVLTreeNodeInsert( &((*e)->right) , index );
        if ( (*e)->right->depth - (*e)->left->depth >= 2 ) {
            if ( (*e)->right->index < index ) {
                RotateRR( e );
            } else {
                RotateRL( e );
            }
        }
    } 

    (*e)->depth = std::max( (*e)->left->depth, (*e)->right->depth ) + 1;
}

int AVLTreeNodeFind(AVLTreeNode **e, int index)
{
    /* 二分查找 */
    if ( (*e)->index == index ) {
        return 1;
    } else if ( (*e)->index > index ) {
        return AVLTreeNodeFind( &((*e)->left), index );
    } else { 
        return AVLTreeNodeFind( &((*e)->right) , index );
    } 
}

void AVLTreeNodeErase(AVLTreeNode **e, int index)
{
    if ( (*e)->index > index ) {
        AVLTreeNodeErase( &((*e)->left), index );

        if ( (*e)->right->depth - (*e)->left->depth >= 2 ) {
            if ( (*e)->right->left != NULL && ((*e)->right->left->depth > (*e)->right->right->depth) ) {
                RotateRL( e );
            } else {
                RotateRR( e );
            }
        }
    } else if ( (*e)->index < index ) {
        AVLTreeNodeErase( &((*e)->right), index );

        if ( (*e)->left->depth - (*e)->right->depth >= 2 ) {
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
            AVLTreeNodeErase( &((*e)->right), temp->index );
            if ( (*e)->left->depth - (*e)->right->depth >= 2 ) {
                if ( (*e)->left->right != NULL && ((*e)->left->right->depth > (*e)->left->left->depth) ) {
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
    (*e)->depth = std::max( (*e)->left->depth, (*e)->right->depth ) + 1;
    return;
}


#endif
