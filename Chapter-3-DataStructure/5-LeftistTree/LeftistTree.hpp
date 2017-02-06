#ifndef LEFTIST_TREE_HPP
#define LEFTIST_TREE_HPP 1

#include <algorithm>
using namespace std;
#ifndef MAX
#define MAX 64
#endif

struct LeftistTree;

struct LeftistNode {
    /* 节点下标号 */
    int index;
    /* 节点i的距离为distance[i] */
    int distance;
    LeftistNode *left;
    LeftistNode *right;
    LeftistTree *tree;
};

struct LeftistTree {
    LeftistNode *root;
    int size;
    int (*cmp)(LeftistNode*, LeftistNode*);
};

LeftistTree *LeftistTreeNew(int (*Compare)(LeftistNode *a, LeftistNode *b))
{
    LeftistTree *t = new LeftistTree();
    if (!t) {
        return NULL;
    }
    t->cmp = Compare;
    t->root = NULL;
    t->size = 0;
    return t;
}

void NodeFree(LeftistNode *e)
{
    if (!e)
        return;
    NodeFree(e->left);
    NodeFree(e->right);
    delete e;
}

void LeftistTreeFree(LeftistTree *t)
{
    NodeFree(t->root);
    delete t;
}

LeftistNode *NodeMerge(LeftistNode *a, LeftistNode *b, LeftistTree *t)
{
    if (!a && !b) {
        return NULL;
    }
    if (!a) {
        b->tree = t;
        return b;
    }
    if (!b) {
        a->tree = t;
        return a;
    }

    if (t->cmp(a, b) > 0) {
        return NodeMerge(b, a, t);
    }

    a->right = NodeMerge(a->right, b, t);
    a->right->tree = t;

    if (!a->left) {
        swap(a->left, a->right);
    } else {
        if (a->left->distance < a->right->distance)
            swap(a->left, a->right);
        a->distance = a->right->distance + 1;
    }

    return a;
}

/* 合并 */
LeftistTree *LeftistTreeMerge(LeftistTree *a, LeftistTree *b)
{
    LeftistTree *t = new LeftistTree();
    if (!t)
        return NULL;
    t->cmp = a->cmp;
    t->size = a->size + b->size;
    t->root = NodeMerge(a->root, b->root, a);
    return t;
}


int LeftistTreeTop(LeftistTree *t)
{
    return t->root ? t->root->index : -1;
}

int LeftistTreePush(LeftistTree *t, int index)
{
    LeftistNode *e = new LeftistNode();
    if (!e)
        return -1;
    e->distance = 0;
    e->index = index;
    e->left = NULL;
    e->right = NULL;
    e->tree = NULL;

    t->root = NodeMerge(t->root, e, t);
    t->size += 1;

    return 0;
}

int LeftistTreePop(LeftistTree *t)
{
    if (t->size <= 0)
        return -1;

    LeftistNode *old = t->root;
    t->root = NodeMerge(t->root->left, t->root->right, t);
    t->size -= 1;

    delete old;

    return 0;
}


#endif