#ifndef DATA_STRUCTURE_RED_BLACK_TREE_HPP
#define DATA_STRUCTURE_RED_BLACK_TREE_HPP 1

#include <algorithm>
#include <cassert>

#define RED     0
#define BLACK   1

struct RedBlackTreeNode {
    /* 节点颜色 */
    int color;
    /* 节点值 */
    int index;

    RedBlackTreeNode *left;
    RedBlackTreeNode *right;
    RedBlackTreeNode *father;
};

struct RedBlackTree {
    RedBlackTreeNode *root;
};

int Color(RedBlackTreeNode *e);
int Index(RedBlackTreeNode *e);
RedBlackTreeNode* Previous(RedBlackTreeNode *e);
RedBlackTreeNode* Next(RedBlackTreeNode *e);
RedBlackTreeNode* Father(RedBlackTreeNode *e);
RedBlackTreeNode* Left(RedBlackTreeNode *e);
RedBlackTreeNode* Right(RedBlackTreeNode *e);
RedBlackTreeNode* Uncle(RedBlackTreeNode *e);
RedBlackTreeNode* GrandFather(RedBlackTreeNode *e);
RedBlackTreeNode* Brother(RedBlackTreeNode *e);
bool IsLeftChild(RedBlackTreeNode *e);
bool IsRightChild(RedBlackTreeNode *e);
int ChildNumber(RedBlackTreeNode *e);
void SwapIndex(RedBlackTreeNode *a, RedBlackTreeNode *b);
void SwapColor(RedBlackTreeNode *a, RedBlackTreeNode *b);

void NodeFree(RedBlackTreeNode *e);
RedBlackTreeNode* NodeFind(RedBlackTree *t, int index, RedBlackTreeNode **father);
void InsertCase1(RedBlackTree *t, RedBlackTreeNode *e);
void InsertCase2(RedBlackTree *t, RedBlackTreeNode *e);
void InsertCase3(RedBlackTree *t, RedBlackTreeNode *e);
void InsertCase4(RedBlackTree *t, RedBlackTreeNode *e);
void InsertCase5(RedBlackTree *t, RedBlackTreeNode *e);

void EraseCase0(RedBlackTree *t, RedBlackTreeNode *e);
void EraseCase0_A(RedBlackTree *t, RedBlackTreeNode *e);
void EraseCase0_B(RedBlackTree *t, RedBlackTreeNode *e);
void EraseCase0_C(RedBlackTree *t, RedBlackTreeNode *e);
void EraseCase1(RedBlackTree *t, RedBlackTreeNode *e);
void EraseCase2(RedBlackTree *t, RedBlackTreeNode *e);
void EraseCase3(RedBlackTree *t, RedBlackTreeNode *e);
void EraseCase4(RedBlackTree *t, RedBlackTreeNode *e);
void EraseCase5(RedBlackTree *t, RedBlackTreeNode *e);
void EraseCase6(RedBlackTree *t, RedBlackTreeNode *e);

void RotateLeft(RedBlackTree *t, RedBlackTreeNode *e);
void RotateRight(RedBlackTree *t, RedBlackTreeNode *e);


RedBlackTree* RedBlackTreeNew()
{
    RedBlackTree *t = new RedBlackTree();
    if (!t)
        return NULL;
    t->root = NULL;
    return t;
}

void RedBlackTreeFree(RedBlackTree *t)
{
    NodeFree(t->root);
}

void RedBlackTreeInsert(RedBlackTree *t, int index)
{
    RedBlackTreeNode *e = new RedBlackTreeNode();
    RedBlackTreeNode *father;
    RedBlackTreeNode *tmp;
    tmp = NodeFind(t, index, &father);
    assert(tmp == NULL);
    e->color = RED;
    e->index = index;
    e->left = NULL;
    e->right = NULL;
    e->father = father;
    if (father) {
        if (index < Index(father))
            father->left = e;
        else
            father->right = e;
    }
    // fix rbtree from e
    InsertCase1(t, e);
}

int RedBlackTreeFind(RedBlackTree *t, int index)
{
    return NodeFind(t, index, NULL)? 1 : 0;
}

void RedBlackTreeErase(RedBlackTree *t, int index)
{
    RedBlackTreeNode *e = NodeFind(t, index, NULL);
    assert(e);
    EraseCase0(t, e);
}

void NodeFree(RedBlackTreeNode *e)
{
    if (!e)
        return;
    NodeFree(Left(e));
    NodeFree(Right(e));
    delete e;
}

void RotateLeft(RedBlackTree *t, RedBlackTreeNode *e)
{
    RedBlackTreeNode *p = e;
    RedBlackTreeNode *q = Right(e);
    RedBlackTreeNode *father = Father(e);

    if (father == NULL) {
        t->root = q;
    } else {
        if (Left(father) == p)
            father->left = q;
        else
            father->right = q;
    }

    q->father = father;
    p->father = q;

    p->right = Left(q);
    if (Left(q))
        q->left->father = p;
    q->left = p;
}

void RotateRight(RedBlackTree *t, RedBlackTreeNode *e)
{
    RedBlackTreeNode *p = e;
    RedBlackTreeNode *q = Left(e); /* can't be NULL */
    RedBlackTreeNode *father = Father(p);
    assert(q);

    if (p->father == NULL) {
        t->root = q;
    }
    else {
        if (Left(father) == p)
            father->left = q;
        else
            father->right = q;
    }
    q->father = father;
    p->father = q;

    p->left = Right(q);
    if (p->left)
        p->left->father = p;
    q->right = p;
}

RedBlackTreeNode* NodeFind(RedBlackTree *t, int index, RedBlackTreeNode **father)
{
    RedBlackTreeNode *cur = t->root;
    while (cur) {
        if (Index(cur) == index)
            return cur;
        else {
            if (father != NULL)
                *father = cur;
            if (index < Index(cur))
                cur = Left(cur);
            else
                cur = Right(cur);
        }
    }
    return NULL;
}

void InsertCase1(RedBlackTree *t, RedBlackTreeNode *e)
{
    if (t->root == NULL || Father(e) == NULL) {
        assert(t->root == NULL);
        assert(Father(e) == NULL);
        e->color = BLACK;
        t->root = e;
    } else {
        InsertCase2(t, e);
    }
}

void InsertCase2(RedBlackTree *t, RedBlackTreeNode *e)
{
    if (Color(Father(e)) != BLACK) {
        InsertCase3(t, e);
    }
}

void InsertCase3(RedBlackTree *t, RedBlackTreeNode *e)
{
    if (Color(Father(e)) == RED
        && Color(Uncle(e)) == RED) {
        Father(e)->color = BLACK;
        Uncle(e)->color = BLACK;
        GrandFather(e)->color = RED;
        InsertCase1(t, GrandFather(e));
    } else {
        InsertCase4(t, e);
    }
}

void InsertCase4(RedBlackTree *t, RedBlackTreeNode *e)
{
    if (Color(Father(e)) == RED
        && Color(Uncle(e)) == BLACK
        && IsRightChild(e)
        && IsLeftChild(Father(e))) {
        RotateLeft(t, e);
        InsertCase5(t, e->father);
    }
}

void InsertCase5(RedBlackTree *t, RedBlackTreeNode *e)
{
    if (Color(Father(e)) == RED
        && Color(Uncle(e)) == BLACK
        && IsLeftChild(e)
        && IsLeftChild(Father(e))) {
        RotateRight(t, GrandFather(e));
        //swap color of Father and GrandFather
        SwapColor(Father(e), GrandFather(e));
    }
}

void EraseCase0(RedBlackTree *t, RedBlackTreeNode *e)
{
    int child_number = ChildNumber(e);
    if (child_number == 0) {
        // 删除操作 0-a
        EraseCase0_A(t, e);
    } else if (child_number == 1) {
        // 删除操作 0-b
        EraseCase0_B(t, e);
    } else if (child_number == 2) {
        // 删除操作 0-c
        EraseCase0_C(t, e);
    }
}

void EraseCase0_A(RedBlackTree *t, RedBlackTreeNode *e)
{
    if (Left(Father(e)) == e)
        Father(e)->left = NULL;
    else if (e->father->right == e)
        Father(e)->right = NULL;
    delete e;
}

void EraseCase0_B(RedBlackTree *t, RedBlackTreeNode *e)
{
    RedBlackTreeNode *child = Left(e)? Left(e) : Right(e);
    SwapIndex(child, e);

    // now "child" is father of "e", while "e" is child of "child"
    child->left = child->right = NULL;
    delete e;
    EraseCase1(t, child);
}

void EraseCase0_C(RedBlackTree *t, RedBlackTreeNode *e)
{
    RedBlackTreeNode *next = Next(e);
    e->index = Index(next);
    EraseCase0(t, next);
}

void EraseCase1(RedBlackTree *t, RedBlackTreeNode *e)
{
    if (t->root != e || Father(e) != NULL) {
        assert(t->root != e);
        assert(Father(e) != NULL);
        EraseCase2(t, e);
    }
}

void EraseCase2(RedBlackTree *t, RedBlackTreeNode *e)
{
    if (Color(Brother(e)) == RED) {
        if (IsLeftChild(e)) {
            RotateLeft(t, e);
        } else if (IsRightChild(e)) {
            RotateRight(t, e);
        }
        SwapColor(Father(e), Brother(e));
    } else {
        EraseCase3(t, e);
    }
}

void EraseCase3(RedBlackTree *t, RedBlackTreeNode *e)
{
    if (Color(Father(e)) == BLACK
        && Color(Brother(e)) == BLACK
        && Color(Left(Brother(e))) == BLACK
        && Color(Right(Brother(e))) == BLACK) {
        Brother(e)->color = RED;
        EraseCase1(t, Father(e));
    } else {
        EraseCase4(t, e);
    }
}

void EraseCase4(RedBlackTree *t, RedBlackTreeNode *e)
{
    if (Color(e) == BLACK
        && Color(Brother(e)) == BLACK
        && Color(Left(Brother(e))) == BLACK
        && Color(Right(Brother(e))) == BLACK
        && Color(Father(e)) == RED) {
        SwapColor(Father(e), Brother(e));
    } else {
        EraseCase5(t, e);
    }
}

void EraseCase5(RedBlackTree *t, RedBlackTreeNode *e)
{
    if (IsLeftChild(e)
        && Color(Brother(e)) == BLACK
        && Color(Left(Brother(e))) == RED
        && Color(Right(Brother(e))) == BLACK) {
        RotateRight(t, Brother(e));
        SwapColor(Brother(e), Father(e));
        EraseCase6(t, e);
    }
}

void EraseCase6(RedBlackTree *t, RedBlackTreeNode *e)
{
    if (IsLeftChild(e)
        && Color(Brother(e)) == BLACK
        && Color(Right(Brother(e))) == RED) {
        RotateLeft(t, Father(e));
        SwapColor(Father(e), Father(Father(e)));
        Brother(e)->color = BLACK;
    }
}

void SwapIndex(RedBlackTreeNode *a, RedBlackTreeNode *b)
{
    int i = a->index;
    a->index = b->index;
    b->index = i;
}

void SwapColor(RedBlackTreeNode *a, RedBlackTreeNode *b)
{
    int c = a->color;
    a->color = b->color;
    b->color = c;
}

int Color(RedBlackTreeNode *e)
{
    return e ? e->color : BLACK;
}
int Index(RedBlackTreeNode *e)
{
    if (!e)
        return -1;
    return e->index;
}
RedBlackTreeNode* Previous(RedBlackTreeNode *e)
{
    while (e->left)
        e = e->left;
    return e;
}
RedBlackTreeNode* Next(RedBlackTreeNode *e)
{
    while (e->right)
        e = e->right;
    return e;
}
RedBlackTreeNode* Father(RedBlackTreeNode *e)
{
    return e ? e->father : NULL;
}
RedBlackTreeNode* Uncle(RedBlackTreeNode *e)
{
    if (!GrandFather(e))
        return NULL;
    if (GrandFather(e)->left == e)
        return GrandFather(e)->right;
    if (GrandFather(e)->right == e)
        return GrandFather(e)->left;
    return NULL;
}
RedBlackTreeNode* GrandFather(RedBlackTreeNode *e)
{
    if (!e)
        return NULL;
    if (!e->father)
        return NULL;
    return e->father->father;
}
RedBlackTreeNode* Brother(RedBlackTreeNode *e)
{
    if (!e)
        return NULL;
    if (!e->father)
        return NULL;
    if (Father(e)->left == e)
        return Father(e)->right;
    if (Father(e)->right == e)
        return Father(e)->left;
    return NULL;
}
bool IsLeftChild(RedBlackTreeNode *e)
{
    if (!Father(e))
        return false;
    return Father(e)->left == e;
}
bool IsRightChild(RedBlackTreeNode *e)
{
    if (!Father(e))
        return false;
    return Father(e)->right == e;
}
int ChildNumber(RedBlackTreeNode *e)
{
    return e ? ((e->left ? 1 : 0) + (e->right ? 1 : 0)) : 0;
}

RedBlackTreeNode* Left(RedBlackTreeNode *e)
{
    return e ? e->left : NULL;
}
RedBlackTreeNode* Right(RedBlackTreeNode *e)
{
    return e ? e->right : NULL;
}

#endif
