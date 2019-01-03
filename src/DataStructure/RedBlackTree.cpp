#include "RedBlackTree.h"
#include <algorithm>
#include <cassert>
#include <utility>

#define RED 'R'
#define BLACK 'B'

RbNode RBNIL = {BLACK, -1, &RBNIL, &RBNIL, &RBNIL};

#define is_nil(e) ((e) == &RBNIL)
#define not_nil(e) ((e) != &RBNIL)
#define set_nil(e) ((e) = &RBNIL)
#define is_leaf(e) (is_nil((e)->left) && is_nil((e)->right))

// declaration

static void InsertCase1(RedBlackTree *t, RbNode *e);
static void InsertCase2(RedBlackTree *t, RbNode *e);
static void InsertCase3(RedBlackTree *t, RbNode *e);
static void InsertCase4(RedBlackTree *t, RbNode *e);
static void InsertCase5(RedBlackTree *t, RbNode *e);
static void EraseCase0(RedBlackTree *t, RbNode *e);
static void EraseCase0_A(RedBlackTree *t, RbNode *e);
static void EraseCase0_B(RedBlackTree *t, RbNode *e);
static void EraseCase0_C(RedBlackTree *t, RbNode *e);
static void EraseCase1(RedBlackTree *t, RbNode *e);
static void EraseCase2(RedBlackTree *t, RbNode *e);
static void EraseCase3(RedBlackTree *t, RbNode *e);
static void EraseCase4(RedBlackTree *t, RbNode *e);
static void EraseCase5(RedBlackTree *t, RbNode *e);
static void EraseCase6(RedBlackTree *t, RbNode *e);

// implementation

static void Swapvalue(RbNode *a, RbNode *b) { std::swap(a->value, b->value); }

static void Swapcolor(RbNode *a, RbNode *b) { std::swap(a->color, b->color); }

static RbNode *Previous(RbNode *e) {
  while (not_nil(e->left))
    e = e->left;
  return e;
}

static RbNode *Next(RbNode *e) {
  if (is_nil(e->right)) {
    return &RBNIL;
  }
  RbNode *next = e->right;
  while (not_nil(next->left)) {
    next = next->left;
  }
  return next;
}

static RbNode *GrandFather(RbNode *e) {
  if (is_nil(e))
    return &RBNIL;
  if (is_nil(e->father))
    return &RBNIL;
  return e->father->father;
}

static RbNode *Uncle(RbNode *e) {
  if (is_nil(GrandFather(e)))
    return &RBNIL;
  if (GrandFather(e)->left == e)
    return GrandFather(e)->right;
  if (GrandFather(e)->right == e)
    return GrandFather(e)->left;
  return &RBNIL;
}

static bool IsLeft(RbNode *e) {
  if (is_nil(e->father))
    return false;
  return e->father->left == e;
}

static bool IsRight(RbNode *e) {
  if (is_nil(e->father))
    return false;
  return e->father->right == e;
}

static int ChildNumber(RbNode *e) {
  return is_nil(e) ? 0
                   : ((is_nil(e->left) ? 0 : 1) + (is_nil(e->right) ? 0 : 1));
}

static RbNode *Brother(RbNode *e) {
  if (is_nil(e))
    return &RBNIL;
  if (IsLeft(e)) {
    return e->father->right;
  }
  if (IsRight(e)) {
    return e->father->left;
  }
  return &RBNIL;
}

static void Free(RbNode *e) {
  if (is_nil(e))
    return;
  Free(e->left);
  Free(e->right);
  delete e;
}

static void RedUncle(RedBlackTree *t, RbNode *e) {}

// left left case
// right-rotate
static RbNode *LL(RbNode *e) {
  RbNode *p;

  p = e->left;
  e->left = p->right;
  p->right = e;
  return p;
}

// right right case
// left-rotate
static RbNode *RR(RbNode *e) {
  RbNode *p;

  p = e->right;
  e->right = p->left;
  p->left = e;
  return p;
}

// left right case
// left-rotate, right-rotate -> RR, LL
static RbNode *LR(RbNode *e) {
  e->left = RR(e->left);
  return LL(e);
}

// right left case
// right-rotate, left-rotate -> LL, RR
static RbNode *RL(RbNode *e) {
  e->right = LL(e->right);
  return RR(e);
}

static RbNode *Find(RedBlackTree *t, int value, RbNode **father) {
  RbNode *cur = t->root;
  while (cur) {
    if (cur->value == value)
      return cur;
    else {
      if (father != NULL)
        *father = cur;
      if (value < cur->value)
        cur = cur->left;
      else if (value > cur->value)
        cur = cur->right;
      else if (value == cur->value)
        return cur;
    }
  }
  return NULL;
}

static RbNode *Insert(RbNode *e, RbNode *fa, int value) {
  assert(e);

  if (is_nil(e)) {
    RbNode *p = new RbNode();
    set_nil(p->left);
    set_nil(p->right);
    p->father = fa;
    p->color = BLACK;
    p->value = value;
    return p;
  }

  //利用二分查找找到适合value插入的位置e

  if (e->value > value) {
    e->left = Insert(e->left, e, value);
  } else if (e->value < value) {
    e->right = Insert(e->right, e, value);
  } else {
    assert(e->value != value);
  }

  //叶子节点处完成插入后，沿着父结点向上的每一个节点都需要检查是否满足红黑树特性，若不平衡则旋转
  //递归函数可以对每个节点*e在插入后进行检查

  return e;
}

static void InsertCase5(RedBlackTree *t, RbNode *e) {
  e->father->color = BLACK;
  GrandFather(e)->color = RED;
  if (IsLeft(e) && IsLeft(e->father)) {
    LL(GrandFather(e));
  } else {
    assert(IsRight(e));
    assert(IsRight(e->father));
    RR(GrandFather(e));
  }
}

static void InsertCase4(RedBlackTree *t, RbNode *e) {
  if (IsRight(e) && IsLeft(e->father)) {
    RR(e->father);
    e = e->left;
  } else if (IsLeft(e) && IsRight(e->father)) {
    LL(e->father);
    e = e->right;
  }
  InsertCase5(t, e);
}

static void InsertCase3(RedBlackTree *t, RbNode *e) {
  if (IsLeft(e->father)) {
  }
  if (Uncle(e)->color == RED) {
    e->father->color = BLACK;
    Uncle(e)->color = BLACK;
    GrandFather(e)->color = RED;
    InsertCase1(t, GrandFather(e));
  } else {
    InsertCase4(t, e);
  }
}

static void InsertCase2(RedBlackTree *t, RbNode *e) {
  if (e->father->color == RED) {
    InsertCase3(t, e);
  }
}

static void InsertCase1(RedBlackTree *t, RbNode *e) {
  if (t->root == NULL) {
    assert(t->root == NULL);
    assert(e->father == NULL);
    e->color = BLACK;
    t->root = e;
  } else {
    InsertCase2(t, e);
  }
}

static void EraseCase0(RedBlackTree *t, RbNode *e) {
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

static void EraseCase0_A(RedBlackTree *t, RbNode *e) {
  if (e->father->left == e)
    e->father->left = NULL;
  else if (e->father->right == e)
    e->father->right = NULL;
  delete e;
}

static void EraseCase0_B(RedBlackTree *t, RbNode *e) {
  RbNode *child = e->left ? e->left : e->right;
  Swapvalue(child, e);

  // now "child" is father of "e", while "e" is child of "child"
  child->left = child->right = NULL;
  delete e;
  EraseCase1(t, child);
}

static void EraseCase0_C(RedBlackTree *t, RbNode *e) {
  RbNode *next = Next(e);
  e->value = next->value;
  EraseCase0(t, next);
}

static void EraseCase1(RedBlackTree *t, RbNode *e) {
  if (t->root != e) {
    assert(t->root != e);
    assert(e->father != NULL);
    EraseCase2(t, e);
  }
}

static void EraseCase2(RedBlackTree *t, RbNode *e) {
  if (Brother(e)->color == RED) {
    e->father->color = RED;
    Brother(e)->color = BLACK;
    if (IsLeft(e)) {
      RR(e->father);
    } else if (IsRight(e)) {
      LL(e->father);
    }
    // Swapcolor(e->father, Brother(e));
  }
  EraseCase3(t, e);
}

static void EraseCase3(RedBlackTree *t, RbNode *e) {
  if (e->father->color == BLACK && Brother(e)->color == BLACK &&
      Brother(e)->left->color == BLACK && Brother(e)->right->color == BLACK) {
    Brother(e)->color = RED;
    EraseCase1(t, e->father);
  } else {
    EraseCase4(t, e);
  }
}

static void EraseCase4(RedBlackTree *t, RbNode *e) {
  if (Brother(e)->color == BLACK && e->father->color == RED &&
      Brother(e)->left->color == BLACK && Brother(e)->right->color == BLACK) {
    Swapcolor(e->father, Brother(e));
  } else {
    EraseCase5(t, e);
  }
}

static void EraseCase5(RedBlackTree *t, RbNode *e) {
  if (IsLeft(e) && Brother(e)->color == BLACK &&
      Brother(e)->left->color == RED && Brother(e)->right->color == BLACK) {
    Swapcolor(Brother(e), Brother(e)->left);
    LL(Brother(e));
  } else if (IsRight(e) && Brother(e)->color == BLACK &&
             Brother(e)->right->color == RED &&
             Brother(e)->left->color == BLACK) {
    Swapcolor(Brother(e), Brother(e)->right);
    RR(Brother(e));
  }
  EraseCase6(t, e);
}

static void EraseCase6(RedBlackTree *t, RbNode *e) {
  Swapcolor(Brother(e), e->father);
  if (IsLeft(e)) {
    assert(Brother(e)->right->color == RED);
    Brother(e)->right->color = BLACK;
    RR(e->father);
  } else {
    assert(Brother(e)->left->color == RED);
    Brother(e)->left->color = BLACK;
    LL(e->father);
  }
}

RedBlackTree *RedBlackTreeNew() {
  RedBlackTree *t = new RedBlackTree();
  if (!t)
    return NULL;
  t->root = &RBNIL;
  return t;
}

void RedBlackTreeFree(RedBlackTree *t) {
  assert(t);
  Free(t->root);
  delete t;
}

void RedBlackTreeInsert(RedBlackTree *t, int value) {
  RbNode *e = new RbNode();
  RbNode *father = NULL;
  RbNode *tmp;
  tmp = Find(t, value, &father);
  assert(tmp == NULL);
  e->color = RED;
  e->value = value;
  e->left = NULL;
  e->right = NULL;
  e->father = father;
  if (father) {
    if (value < father->value)
      father->left = e;
    else
      father->right = e;
  }
  // fix rbtree from e
  InsertCase1(t, e);
}

int RedBlackTreeFind(RedBlackTree *t, int value) {
  return Find(t, value, NULL) ? 1 : 0;
}

void RedBlackTreeErase(RedBlackTree *t, int value) {
  RbNode *e = Find(t, value, NULL);
  assert(e);
  EraseCase0(t, e);
}

