#ifndef LEFTIST_TREE_HPP
#define LEFTIST_TREE_HPP 1

#include <algorithm>
using namespace std;
#ifndef MAX
#define MAX 64
#endif

<<<<<<< HEAD
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
	int (*compare)(LeftistNode*, LeftistNode*);
	LeftistNode *root;
	int size;
};

LeftistTree *LeftistTreeNew(int (*compare)(LeftistNode *a, LeftistNode *b))
{
	LeftistTree *t = new LeftistTree();
	if (!t) {
		return NULL;
	}
	t->compare = compare;
	t->root = NULL;
	t->size = 0;
	return t;
=======
/* 用数组来代替二叉树的数据结构 */
/* 节点下标为x的节点 其左右孩子节点的下标为 LEFT_CHILD(x) RIGHT_CHILD(x) */
#define LEFT_CHILD(x) ((x)->left)
#define RIGHT_CHILD(x) ((x)->right)

struct LeftistNode {
    int value;
    /* 节点i的距离为distance */
    int distance;
    /* 左右孩子节点 父节点 */
    LeftistNode *left;
    LeftistNode *right;
    LeftistTree *tree;
};

struct LeftistTree {
    LeftistNode *root;
    int size;
    int compare(LeftistNode*, LeftistNode*);
};

/* 将数组s[start, end]初始化为二叉树 根节点root为0 */
LeftistTree *LeftistTreeNew(int (*compare)(LeftistNode*, LeftistNode*))
{
    LeftistTree *t = new LeftistTree();
    if (!t)
        return NULL;
    t->root = NULL;
    t->size = 0;
    t->compare = compare;
    return t;
>>>>>>> 6aa39df066ec0a7250d41add4493db37782914d7
}

void LeftistNodeFree(LeftistNode *e)
{
<<<<<<< HEAD
	if (!e)
		return;
	LeftistNodeFree(e->left);
	LeftistNodeFree(e->right);
	delete e;
}

void LeftistTreeFree(LeftistTree *t)
{
	LeftistNodeFree(t->root);
	delete t;
=======
    if (!e)
        return;
    LeftistNodeFree(e->left);
    LeftistNodeFree(e->right);
    free(e);
}
void LeftistTreeFree(LeftistTree *t)
{
    LeftistNodeFree(t->root);
}

LeftistNode *LeftistNodeMerge(LeftistNode *a, LeftistNode *b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    int (*compare)(LeftistNode*, LeftistNode*) = a->tree->compare;
    if (compare(a, b) > 0) {
        return LeftistNodeMerge(b, a);
    }

    a->right = LeftistNodeMerge(a->right, b);

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
    t->compare = a->compare;
    t->size = a->size + b->size;
    t->root = LeftistNodeMerge(a->root, b->root);
    return t;
}

int LeftistTreePush(LeftistTree *t, int value)
{
    LeftistNode *e = new LeftistNode();
    if (!e)
    node->m_index = value;
    return(leftist_tree_merge(root, node));

    int mid = (left_node[root] + right_node[root]) / 2;
    if (left_node[root] >= start && right_node[root] <= end) {
        return sum[root];
    } else if (end <= mid) {
        return LeftistTreeQuery( LEFT_CHILD(root), start, end );
    } else if (start >= mid + 1) {
        return LeftistTreeQuery( RIGHT_CHILD(root), start, end );
    } else { 
        return LeftistTreeQuery( LEFT_CHILD(root), start, mid) 
            + LeftistTreeQuery( RIGHT_CHILD(root), mid + 1, end);
    }
>>>>>>> 6aa39df066ec0a7250d41add4493db37782914d7
}

LeftistNode *LeftistNodeMerge(LeftistNode *a, LeftistNode *b, LeftistTree *t)
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

	int (*compare)(LeftistNode*, LeftistNode*) = t->compare;
	if (compare(a, b) > 0) {
		return LeftistNodeMerge(b, a, t);
	}

	a->right = LeftistNodeMerge(a->right, b, t);
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

LeftistTree *LeftistTreeMerge(LeftistTree *a, LeftistTree *b)
{
	a->root = LeftistNodeMerge(a->root, b->root, a);
	b->root = NULL;
	b->size = 0;
	LeftistTreeFree(b);
	return a;
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

	t->root = LeftistNodeMerge(t->root, e, t);
	t->size += 1;

	return 0;
}

int LeftistTreePop(LeftistTree *t)
{
	if (t->size <= 0)
		return -1;

	LeftistNode *old = t->root;
	t->root = LeftistNodeMerge(t->root->left, t->root->right, t);
	t->size -= 1;

	delete old;

	return 0;
}


#endif