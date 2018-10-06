#include "AvlTree.h"
#include <algorithm>
#include <cassert>
#include <utility>

AvlNode AVLNIL = {-1, -1, &AVLNIL, &AVLNIL};

#define is_nil(e) ((e) == &AVLNIL)
#define not_nil(e) ((e) != &AVLNIL)
#define set_nil(e) ((e) = &AVLNIL)
#define get_height(left, right) (std::max((left)->height, (right)->height) + 1)
#define get_factor(e) ((e)->left->height - (e)->right->height)

AvlNode::AvlNode() {
  value = -1;
  height = -1;
  set_nil(left);
  set_nil(right);
}

AvlNode::AvlNode(int v, int h, AvlNode *l, AvlNode *r) {
  value = v;
  height = h;
  left = l;
  right = r;
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
static AvlNode *LL(AvlNode *e) {
  AvlNode *p;

  p = e->left;
  e->left = p->right;
  p->right = e;

  e->height = get_height(e->left, e->right);
  p->height = get_height(p->left, e);
  return p;
}

// right right case
// left-rotate
static AvlNode *RR(AvlNode *e) {
  AvlNode *p;

  p = e->right;
  e->right = p->left;
  p->left = e;

  e->height = get_height(e->left, e->right);
  p->height = get_height(p->right, e);
  return p;
}

// left right case
// left-rotate, right-rotate -> RR, LL
static AvlNode *LR(AvlNode *e) {
  e->left = RR(e->left);
  return LL(e);
}

// right left case
// right-rotate, left-rotate -> LL, RR
static AvlNode *RL(AvlNode *e) {
  e->right = LL(e->right);
  return RR(e);
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

static AvlNode *Insert(AvlNode *e, int value) {
  assert(e);

  if (is_nil(e)) {
    AvlNode *p = new AvlNode();
    set_nil(p->left);
    set_nil(p->right);
    p->value = value;
    p->height = get_height(p->left, p->right);
    return p;
  }

  //利用二分查找找到适合value插入的位置e

  if (e->value > value) {
    e->left = Insert(e->left, value);
  } else if (e->value < value) {
    e->right = Insert(e->right, value);
  } else {
    assert(e->value != value);
  }

  //叶子节点处完成插入后，沿着父结点向上的每一个节点都需要检查是否满足平衡性，若不平衡则旋转
  //递归函数可以对每个节点*e在插入后进行检查

  e->height = get_height(e->left, e->right);
  int factor = get_factor(e);
  if (factor > 1 && get_factor(e->left) >= 0) {
    return LL(e);
  }
  if (factor > 1 && get_factor(e->left) < 0) {
    return LR(e);
  }
  if (factor < -1 && get_factor(e->right) <= 0) {
    return RR(e);
  }
  if (factor < -1 && get_factor(e->right) > 0) {
    return RL(e);
  }

  return e;
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

static AvlNode *Erase(AvlNode *e, int value) {
  assert(value >= 0);
  assert(not_nil(e));

  if (e->value > value) {
    e->left = Erase(e->left, value);
  } else if (e->value < value) {
    e->right = Erase(e->right, value);
  } else {
    // e->value == value

    if (is_nil(e->left) || is_nil(e->right)) {
      AvlNode *temp = not_nil(e->left) ? e->left : e->right;
      if (is_nil(temp)) {
        // 若e没有孩子节点则直接删除

        temp = e;
        set_nil(e);
        delete temp;
        return e;
      } else {
        // 若e只有一个孩子节点则直接用该孩子节点替换e

        std::swap(e, temp);
        delete temp;
      }
    } else {
      // not_nil(e->left) && not_nil(e->right)

      AvlNode *next = Next(e);
      e->value = next->value;
      e->right = Erase(e->right, next->value);
    }
  }

  e->height = get_height(e->left, e->right);
  int factor = get_factor(e);
  if (factor > 1 && get_factor(e->left) >= 0) {
    return LL(e);
  }
  if (factor > 1 && get_factor(e->left) < 0) {
    return LR(e);
  }
  if (factor < -1 && get_factor(e->right) <= 0) {
    return RR(e);
  }
  if (factor < -1 && get_factor(e->right) > 0) {
    return RL(e);
  }

  return e;
}

void AvlTreeErase(AvlTree *t, int value) {
  assert(not_nil(t->root));
  t->root = Erase(t->root, value);
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
  assert(t);
  assert(value >= 0);
  t->root = Insert(t->root, value);
}

AvlNode *AvlTreeFind(AvlTree *t, int value) { return Find(t->root, value); }

