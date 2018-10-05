#include "AvlTree.h"
#include <algorithm>
#include <cassert>
#include <utility>

AvlNode AVLNIL = {-1, -1, &AVLNIL, &AVLNIL, &AVLNIL};

#define is_nil(e) ((e) == &AVLNIL)
#define not_nil(e) ((e) != &AVLNIL)
#define set_nil(e) ((e) = &AVLNIL)
#define get_height(left, right) (std::max((left)->height, (right)->height) + 1)

AvlNode::AvlNode() {
  value = -1;
  height = -1;
  set_nil(left);
  set_nil(right);
  set_nil(father);
}

AvlNode::AvlNode(int v, int h, AvlNode *l, AvlNode *r, AvlNode *f) {
  value = v;
  height = h;
  left = l;
  right = r;
  father = f;
}

static void Free(AvlNode *e) {
  if (is_nil(e))
    return;
  Free(e->left);
  Free(e->right);
  delete e;
}

// left left case
// right-rotate
static void LL(AvlNode **e) {
  AvlNode *p;

  p = (*e)->left;
  (*e)->left = p->right;
  p->right = (*e);

  (*e)->height = get_height((*e)->left, (*e)->right);
  p->height = get_height(p->left, *e);
  (*e) = p;
}

// right right case
// left-rotate
static void RR(AvlNode **e) {
  AvlNode *p;

  p = (*e)->right;
  (*e)->right = p->left;
  p->left = (*e);

  (*e)->height = get_height((*e)->left, (*e)->right);
  p->height = get_height(p->right, *e);
  (*e) = p;
}

// left right case
// left-rotate, right-rotate -> RR, LL
static void LR(AvlNode **e) {
  RR(&((*e)->left));
  LL(e);
}

// right left case
// right-rotate, left-rotate -> LL, RR
static void RL(AvlNode **e) {
  LL(&((*e)->right));
  RR(e);
}

static AvlNode *Find(AvlNode *e, int value) {
  if (is_nil(e)) {
    return &AVLNIL;
  }
  //二分查找
  if (e->value == value) {
    return e;
  } else if (e->value > value) {
    return Find(e->left, value);
  } else {
    return Find(e->right, value);
  }
}

static void Fix(AvlNode *e) {
  e->height = get_height(e->left, e->right);
  int factor = e->left->height - e->right->height;
  if (factor > 1 && e->left->value > e->value) {
    LL(&e);
  }
  if (factor < -1 && e->right->value < e->value) {
    RR(&e);
  }
  if (factor > 1 && e->left->value < e->value) {
    LR(&e);
  }
  if (factor < -1 && e->right->value > e->value) {
    RL(&e);
  }
}

static void Insert(AvlNode **e, AvlNode *father, int value) {
  assert(e);
  assert(father);

  if (is_nil(*e)) {
    // *e is nil
    *e = new AvlNode();
    set_nil((*e)->left);
    set_nil((*e)->right);
    (*e)->father = father;
    (*e)->value = value;
    (*e)->height = get_height((*e)->left, (*e)->right);
    return;
  }

  //利用二分查找找到适合value插入的位置e

  if ((*e)->value > value) {
    Insert(&(*e)->left, *e, value);
  } else if ((*e)->value < value) {
    Insert(&(*e)->right, *e, value);
  } else {
    // (*e)->value == value
    assert((*e)->value != value);
  }

  //叶子节点处完成插入后，沿着父结点向上的每一个节点都需要检查是否满足平衡性，若不平衡则旋转
  //递归函数可以对每个节点*e在插入后进行检查

  Fix(*e);
}

static AvlNode *Next(AvlNode *e) {
  if (is_nil(e->right)) {
    return &AVLNIL;
  }
  AvlNode *next = e->right;
  while (not_nil(next->left)) {
    next = next->left;
  }
  return next;
}

static AvlNode *Prev(AvlNode *e) { return e->left; }

void AvlTreeErase(AvlTree *t, int value) {
  assert(not_nil(t->root));
  AvlNode *e = Find(t->root, value);
  assert(not_nil(e));

  AvlNode *fix;
  set_nil(fix);

  if (not_nil(e->right)) {
    //用后继节点next代替e

    AvlNode *next = Next(e);
    e->value = next->value;
    if (next->father->left == next) {
      next->father->left = next->right;
    } else if (next->father->right == next) {
      next->father->right = next->right;
    } else {
      assert(next->father->left != next && next->father->right != next);
    }
    next->right->father = next->father;
    delete next;
    fix = e;
  } else if (not_nil(e->left)) {

    AvlNode *prev = Prev(e);
    e->value = prev->value;
    e->left = prev->left;
    if (not_nil(e->left)) {
      e->left->father = e;
    }
    e->right = prev->right;
    if (not_nil(e->right)) {
      e->right->father = e;
    }
    delete prev;
    fix = e;
  } else {
    //直接删除叶子节点e

    if (not_nil(e->father)) {
      if (e->father->left == e) {
        set_nil(e->father->left);
      } else if (e->father->right == e) {
        set_nil(e->father->right);
      } else {
        assert(e->father->left != e && e->father->right != e);
      }
    } else {
      set_nil(t->root);
    }
    delete e;
    fix = e->father;
  }

  while (not_nil(fix)) {
    Fix(fix);
    fix = fix->father;
  }
}

AvlTree *AvlTreeNew() {
  AvlTree *t = new AvlTree();
  set_nil(t->root);
  return t;
}

void AvlTreeFree(AvlTree *t) {
  assert(t);
  Free(t->root);
  delete t;
}

void AvlTreeInsert(AvlTree *t, int value) {
  Insert(&(t->root), &AVLNIL, value);
}

AvlNode *AvlTreeFind(AvlTree *t, int value) { return Find(t->root, value); }

