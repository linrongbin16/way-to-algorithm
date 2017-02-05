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

int & Index(RedBlackTreeNode *e);
int Index(const RedBlackTreeNode *e);
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
    Color(e) = RED;
    Index(e) = index;
    LeftChild(e) = NULL;
    RightChild(e) = NULL;
    Father(e) = father;
    if (father) {
        if (index < Index(father))
            LeftChild(father) = e;
        else
            RightChild(father) = e;
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
    RedBlackTreeNode *q = RightChild(e);
    RedBlackTreeNode *father = Father(e);

    if (father == NULL) {
        t->root = q;
    } else {
        if (LeftChild(father) == p)
            LeftChild(father) = q;
        else
            RightChild(father) = q;
    }

    Father(q) = father;
    Father(p) = q;

    RightChild(p) = LeftChild(q);
    if (LeftChild(q))
        Father(LeftChild(q)) = p;
    LeftChild(q) = p;
}

void RotateRight(RedBlackTree *t, RedBlackTreeNode *e)
{
    RedBlackTreeNode *p = e;
    RedBlackTreeNode *q = LeftChild(e); /* can't be NULL */
    RedBlackTreeNode *father = Father(p);

    if (father == NULL) {
        t->root = q;
    }
    else {
        if (LeftChild(father) == p)
            LeftChild(father) = q;
        else
            RightChild(father) = q;
    }
    Father(q) = father;
    Father(p) = q;

    LeftChild(p) = RightChild(q);
    if (LeftChild(p))
        Father(LeftChild(p)) = p;
    RightChild(q) = p;
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
                cur = LeftChild(cur);
            else
                cur = RightChild(cur);
        }
    }
    return NULL;
}

void InsertCase1(RedBlackTree *t, RedBlackTreeNode *e)
{
    if (t->root == NULL || Father(e) == NULL) {
        assert(t->root == NULL);
        assert(Father(e) == NULL);
        Color(e) = BLACK;
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
    if (LeftChild(Father(e)) == e)
        LeftChild(Father(e)) = NULL;
    else if (RightChild(Father(e)) == e)
        RightChild(Father(e)) = NULL;
    delete e;
}

void EraseCase0_B(RedBlackTree *t, RedBlackTreeNode *e)
{
    RedBlackTreeNode *child = LeftChild(e) ? LeftChild(e) : RightChild(e);
    SwapNode(child, e);

    // now "child" is father of "e", while "e" is child of "child"
    LeftChild(child) = RightChild(child) = NULL;
    delete e;
    EraseCase1(t, child);
}

void EraseCase0_C(RedBlackTree *t, RedBlackTreeNode *e)
{
    RedBlackTreeNode *next = Next(e);
    Index(e) = Index(next);
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
    int c = Color(a);
    Color(a) = Color(b);
    Color(b) = c;
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
    if (!e)
        return NULL;
    while (e->left)
        e = e->left;
    return (RedBlackTreeNode*)e;
}
RedBlackTreeNode* & Previous(RedBlackTreeNode *e)
{
    while (e->left)
        e = e->left;
    return e;
}
RedBlackTreeNode* Next(const RedBlackTreeNode *e)
{
    if (!e)
        return NULL;
    while (e->right)
        e = e->right;
    return (RedBlackTreeNode*)e;
}
RedBlackTreeNode* & Next(RedBlackTreeNode *e)
{
    while (e->right)
        e = e->right;
    return e;
}
RedBlackTreeNode* & Father(RedBlackTreeNode *e)
{
    return e->father;
}
RedBlackTreeNode* Father(const RedBlackTreeNode *e)
{
    return e ? e->father : NULL;
}
RedBlackTreeNode* Uncle(const RedBlackTreeNode *e)
{
    if (GrandFather(e) == NULL)
        return NULL;
    return (LeftChild(GrandFather(e)) == e) ? RightChild(GrandFather(e)) : LeftChild(GrandFather(e));
}
RedBlackTreeNode* & Uncle(RedBlackTreeNode *e)
{
    return (LeftChild(GrandFather(e)) == e) ? RightChild(GrandFather(e)) : LeftChild(GrandFather(e));
}
RedBlackTreeNode* & GrandFather(RedBlackTreeNode *e)
{
    return Father(Father(e));
}
RedBlackTreeNode* GrandFather(const RedBlackTreeNode *e)
{
    return Father(Father(e));
}
RedBlackTreeNode* & Brother(RedBlackTreeNode *e)
{
    if (LeftChild(Father(e)) == e)
        return RightChild(Father(e));
    else
        return LeftChild(Father(e));
}
RedBlackTreeNode* Brother(const RedBlackTreeNode *e)
{
    if (Father(e) == NULL)
        return NULL;
    if (LeftChild(Father(e)) == e)
        return RightChild(Father(e));
    else
        return LeftChild(Father(e));
}
RedBlackTreeNode* & LeftChild(RedBlackTreeNode *e)
{
    return e->left;
}
RedBlackTreeNode* LeftChild(const RedBlackTreeNode *e)
{
    return e ? e->left : NULL;
}
RedBlackTreeNode* & RightChild(RedBlackTreeNode *e)
{
    return e->right;
}
RedBlackTreeNode* RightChild(const RedBlackTreeNode *e)
{
    return e ? e->right : NULL;
}
bool IsLeftChild(RedBlackTreeNode *e)
{
    return e? (LeftChild(Father(e)) == e) : false;
}
bool IsRightChild(RedBlackTreeNode *e)
{
    return e? (RightChild(Father(e)) == e) : false;
}
int ChildNumber(RedBlackTreeNode *e)
{
    return e ? ((LeftChild(e) ? 1 : 0) + (RightChild(e) ? 1 : 0)) : 0;
}
int Index(const RedBlackTreeNode *e)
{
    return e ? e->index : -1;
}
int & Index(RedBlackTreeNode *e)
{
    return e->index;
}

#endif