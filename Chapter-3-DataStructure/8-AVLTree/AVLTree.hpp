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

int Color(const RedBlackTreeNode *e);
int & Color(RedBlackTreeNode *e);
RedBlackTreeNode* & Previous(RedBlackTreeNode *e);
RedBlackTreeNode* Previous(const RedBlackTreeNode *e);
RedBlackTreeNode* & Next(RedBlackTreeNode *e);
RedBlackTreeNode* Next(const RedBlackTreeNode *e);
RedBlackTreeNode* & Father(RedBlackTreeNode *e);
RedBlackTreeNode* Father(const RedBlackTreeNode *e);
RedBlackTreeNode* & Uncle(RedBlackTreeNode *e);
RedBlackTreeNode* Uncle(const RedBlackTreeNode *e);
RedBlackTreeNode* & GrandFather(RedBlackTreeNode *e);
RedBlackTreeNode* GrandFather(const RedBlackTreeNode *e);
RedBlackTreeNode* & Brother(RedBlackTreeNode *e);
RedBlackTreeNode* Brother(const RedBlackTreeNode *e);
RedBlackTreeNode* & LeftChild(RedBlackTreeNode *e);
RedBlackTreeNode* LeftChild(const RedBlackTreeNode *e);
RedBlackTreeNode* & RightChild(RedBlackTreeNode *e);
RedBlackTreeNode* RightChild(const RedBlackTreeNode *e);
bool IsLeftChild(RedBlackTreeNode *e);
bool IsRightChild(RedBlackTreeNode *e);
int ChildNumber(RedBlackTreeNode *e);

void SwapNode(RedBlackTreeNode *a, RedBlackTreeNode *b);
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
        if (index < father->index)
            father->left = e;
        else
            father->right = e;
    }
    // fix rbtree from e
    InsertCase1(t, e);
}

int RedBlackTreeFind(RedBlackTree *t, int index)
{
    return (NodeFind(t, index, NULL) == NULL)? 0 : 1;
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
    NodeFree(e->left);
    NodeFree(e->right);
    delete e;
}

void RotateLeft(RedBlackTree *t, RedBlackTreeNode *e)
{
    RedBlackTreeNode *p = e;
    RedBlackTreeNode *q = e->right;
    RedBlackTreeNode *father = e->father;

    if (father == NULL) {
        t->root = q;
    } else {
        if (father->left == p)
            father->left = q;
        else
            father->right = q;
    }

    q->father = father;
    p->father = q;

    p->right = q->left;
    if (q->left)
        q->left->father = p;
    q->left = p;
}

void RotateRight(RedBlackTree *t, RedBlackTreeNode *e)
{
    RedBlackTreeNode *p = e;
    RedBlackTreeNode *q = e->left; /* can't be NULL */
    RedBlackTreeNode *father = p->father;

    if (p->father == NULL) {
        t->root = q;
    }
    else {
        if (father->left == p)
            father->left = q;
        else
            father->right = q;
    }
    q->father = father;
    p->father = q;

    p->left = q->right;
    if (p->left)
        p->left->father = p;
    q->right = p;
}

RedBlackTreeNode* NodeFind(RedBlackTree *t, int index, RedBlackTreeNode **father)
{
    RedBlackTreeNode *cur = t->root;
    while (cur) {
        if (cur->index == index)
            return cur;
        else {
            if (father != NULL)
                *father = cur;
            if (index < cur->index)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }
    return NULL;
}

void InsertCase1(RedBlackTree *t, RedBlackTreeNode *e)
{
    if (t->root == NULL || e->father == NULL) {
        assert(t->root == NULL);
        assert(e->father == NULL);
        e->color = BLACK;
        t->root = e;
    } else {
        InsertCase2(t, e);
    }
}

void InsertCase2(RedBlackTree *t, RedBlackTreeNode *e)
{
    if (e->father->color != BLACK) {
        InsertCase3(t, e);
    }
}

void InsertCase3(RedBlackTree *t, RedBlackTreeNode *e)
{
    if (Color(Father(e)) == RED
        && Color(Uncle(e)) == RED) {
        Color(Father(e)) = BLACK;
        Color(Uncle(e)) = BLACK;
        Color(GrandFather(e)) = RED;
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
        InsertCase5(t, Father(e));
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
        int tmp_color = Color(Father(e));
        Color(Father(e)) = Color(GrandFather(e));
        Color(GrandFather(e)) = tmp_color;
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
    if (Father(e)->left == e)
        Father(e)->left = NULL;
    else if (Father(e)->right == e)
        Father(e)->right = NULL;
    delete e;
}

void EraseCase0_B(RedBlackTree *t, RedBlackTreeNode *e)
{
    RedBlackTreeNode *child = e->left ? e->left : e->right;
    SwapNode(child, e);

    // now "child" is father of "e", while "e" is child of "child"
    child->left = child->right = NULL;
    delete e;
    EraseCase1(t, child);
}

void EraseCase0_C(RedBlackTree *t, RedBlackTreeNode *e)
{
    RedBlackTreeNode *next = Next(e);
    e->index = next->index;
    EraseCase0(t, next);
}

void EraseCase1(RedBlackTree *t, RedBlackTreeNode *e)
{
    if (t->root != e || e->father != NULL) {
        assert(t->root != e);
        assert(e->father != NULL);
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
        && Color(LeftChild(Brother(e))) == BLACK
        && Color(RightChild(Brother(e))) == BLACK) {
        Color(Brother(e)) = RED;
        EraseCase1(t, Father(e));
    } else {
        EraseCase4(t, e);
    }
}

void EraseCase4(RedBlackTree *t, RedBlackTreeNode *e)
{
    if (Color(e) == BLACK
        && Color(Brother(e)) == BLACK
        && Color(LeftChild(Brother(e))) == BLACK
        && Color(RightChild(Brother(e))) == BLACK
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
        && Color(LeftChild(Brother(e))) == RED
        && Color(RightChild(Brother(e))) == BLACK) {
        RotateRight(t, Brother(e));
        SwapColor(Brother(e), Father(e));
        EraseCase6(t, e);
    }
}

void EraseCase6(RedBlackTree *t, RedBlackTreeNode *e)
{
    if (IsLeftChild(e)
        && Color(Brother(e)) == BLACK
        && Color(RightChild(Brother(e))) == RED) {
        RotateLeft(t, Father(e));
        SwapColor(Father(e), Father(Father(e)));
        Color(Brother(e)) = BLACK;
    }
}

void SwapNode(RedBlackTreeNode *a, RedBlackTreeNode *b)
{
    RedBlackTreeNode tmp_a = *a;
    RedBlackTreeNode tmp_b = *b;

    /*
        a_father
            |
            a
           / \
     a_left   a_right
        b_father
            |
            b
           / \
     b_left   b_right
    */

    if (LeftChild(Father(a)) == a)
        LeftChild(Father(a)) = b;
    else if (RightChild(Father(a)) == a)
        RightChild(Father(a)) = b;
    Father(a) = Father(b);
    LeftChild(a) = LeftChild(b);
    Father(LeftChild(a)) = a;
    RightChild(a) = RightChild(b);
    Father(RightChild(a)) = a;

    if (LeftChild(Father(&tmp_b)) == b)
        LeftChild(Father(&tmp_b)) = a;
    if (RightChild(Father(&tmp_b)) == b)
        RightChild(Father(&tmp_b)) = a;
    Father(b) = Father(&tmp_a);
    LeftChild(b) = LeftChild(&tmp_b);
    Father(LeftChild(b)) = b;
    RightChild(b) = RightChild(&tmp_b);
    Father(RightChild(b)) = b;
}

void SwapColor(RedBlackTreeNode *a, RedBlackTreeNode *b)
{
    int c = a->color;
    a->color = b->color;
    b->color = c;
}

int Color(const RedBlackTreeNode *e)
{
    return (e == NULL) ? BLACK : e->color;
}

int & Color(RedBlackTreeNode *e)
{
    return e->color;
}

RedBlackTreeNode* Previous(const RedBlackTreeNode *e)
{
}


RedBlackTreeNode* & Previous(RedBlackTreeNode *e)
{
}

RedBlackTreeNode* & Next(RedBlackTreeNode *e);
RedBlackTreeNode* & Father(RedBlackTreeNode *e);
RedBlackTreeNode* & Uncle(RedBlackTreeNode *e);
RedBlackTreeNode* & GrandFather(RedBlackTreeNode *e);
RedBlackTreeNode* & Brother(RedBlackTreeNode *e);
RedBlackTreeNode* & LeftChild(RedBlackTreeNode *e);
RedBlackTreeNode* & RightChild(RedBlackTreeNode *e);
bool IsLeftChild(RedBlackTreeNode *e);
bool IsRightChild(RedBlackTreeNode *e);
int ChildNumber(RedBlackTreeNode *e);

#endif