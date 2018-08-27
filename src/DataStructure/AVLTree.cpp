#include "AVLTree.h"
#include <algorithm>
#include <cassert>

/*空节点的高度值depth=-1*/
/*叶子节点的高度值depth=0*/
static int NodeDepth(Node *e) { return e ? e->depth : -1; }

static void NodeFree(Node *e) {
    if (!e) return;
    NodeFree(e->left);
    NodeFree(e->right);
    delete e;
}

static void RotateLL(Node **e) {
    Node *e1;

    e1 = (*e)->left;
    (*e)->left = e1->right;
    e1->right = (*e);

    (*e)->depth = std::max(NodeDepth((*e)->left), NodeDepth((*e)->right)) + 1;
    e1->depth = std::max(NodeDepth(e1->left), (*e)->depth) + 1;
    (*e) = e1;
}

static void RotateRR(Node **e) {
    Node *e1;

    e1 = (*e)->right;
    (*e)->right = e1->left;
    e1->left = (*e);

    (*e)->depth = std::max(NodeDepth((*e)->left), NodeDepth((*e)->right)) + 1;
    e1->depth = std::max(NodeDepth(e1->right), (*e)->depth) + 1;
    (*e) = e1;
}

static void RotateLR(Node **e) {
    RotateRR(&((*e)->left));
    RotateLL(e);
}

static void RotateRL(Node **e) {
    RotateLL(&((*e)->right));
    RotateRR(e);
}

static void NodeInsert(Node **e, int index) {
    assert(e);
    assert(*e);
    /*二分插入*/
    if ((*e)->index > index) {
        /*若做孩子节点为空节点 创建新的节点*/
        if ((*e)->left == nullptr) {
            (*e)->left = new Node();
            (*e)->left->left = nullptr;
            (*e)->left->right = nullptr;
            (*e)->left->index = index;
            (*e)->left->depth = 0;
        } else {
            NodeInsert(&((*e)->left), index);
        }
        if (NodeDepth((*e)->left) - NodeDepth((*e)->right) >= 2) {
            if ((*e)->left->index > index) {
                RotateLL(e);
            } else {
                RotateLR(e);
            }
        }
    } else if ((*e)->index < index) {
        /*若右孩子节点为空节点 创建新的节点*/
        if ((*e)->right == nullptr) {
            (*e)->right = new Node();
            (*e)->right->left = nullptr;
            (*e)->right->right = nullptr;
            (*e)->right->index = index;
            (*e)->right->depth = 0;
        } else {
            NodeInsert(&((*e)->right), index);
        }
        if (NodeDepth((*e)->right) - NodeDepth((*e)->left) >= 2) {
            if ((*e)->right->index < index) {
                RotateRR(e);
            } else {
                RotateRL(e);
            }
        }
    }

    (*e)->depth = std::max(NodeDepth((*e)->left), NodeDepth((*e)->right)) + 1;
}

static int NodeFind(Node **e, int index) {
    if (*e == nullptr) return 0;
    /*二分查找*/
    if ((*e)->index == index) {
        return 1;
    } else if ((*e)->index > index) {
        return NodeFind(&((*e)->left), index);
    } else {
        return NodeFind(&((*e)->right), index);
    }
}

static void NodeErase(Node **e, int index) {
    if ((*e)->index > index) {
        NodeErase(&((*e)->left), index);

        if (NodeDepth((*e)->right) - NodeDepth((*e)->left) >= 2) {
            if ((*e)->right->left != nullptr &&
                ((*e)->right->left->depth > (*e)->right->right->depth)) {
                RotateRL(e);
            } else {
                RotateRR(e);
            }
        }
    } else if ((*e)->index < index) {
        NodeErase(&((*e)->right), index);

        if (NodeDepth((*e)->left) - NodeDepth((*e)->right) >= 2) {
            if ((*e)->right->left != nullptr &&
                ((*e)->left->right->depth > (*e)->left->left->depth)) {
                RotateLR(e);
            } else {
                RotateLL(e);
            }
        }
    } else {
        /* (*e)->index == index */
        if ((*e)->left && (*e)->right) {
            Node *temp = (*e)->right;

            /*temp指向节点的右儿子*/
            /*找到中序遍历的后继节点*/
            while (temp->left != nullptr) temp = temp->left;

            (*e)->index = temp->index; /*调整节点数据信息*/

            /*删除边缘节点*/
            NodeErase(&((*e)->right), temp->index);
            if (NodeDepth((*e)->left) - NodeDepth((*e)->right) >= 2) {
                if ((*e)->left->right != nullptr &&
                    (NodeDepth((*e)->left->right) >
                     NodeDepth((*e)->left->left))) {
                    RotateLR(e);
                } else {
                    RotateLL(e);
                }
            }
        } else {
            Node *temp = (*e);
            if ((*e)->left == nullptr)
                (*e) = (*e)->right;
            else if ((*e)->right == nullptr)
                (*e) = (*e)->left;
            delete temp;
        }
    }

    if ((*e) == nullptr) return;

    (*e)->depth = std::max(NodeDepth((*e)->left), NodeDepth((*e)->right)) + 1;
    return;
}

AVLTree *AVLTreeNew() {
    AVLTree *t = new AVLTree();
    if (!t) return nullptr;
    t->root = nullptr;
    return t;
}

void AVLTreeFree(AVLTree *t) { NodeFree(t->root); }

void AVLTreeInsert(AVLTree *t, int index) {
    if (t->root) {
        NodeInsert(&(t->root), index);
        return;
    }

    t->root = new Node();
    t->root->left = nullptr;
    t->root->right = nullptr;
    t->root->index = index;
    t->root->depth = 0;
}

int AVLTreeFind(AVLTree *t, int index) { return NodeFind(&(t->root), index); }

void AVLTreeErase(AVLTree *t, int index) { NodeErase(&(t->root), index); }

int AVLTreeDepth(AVLTree *t) {
    if (!t->root) return 0;
    return t->root->depth;
}
