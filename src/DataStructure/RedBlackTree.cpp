#include "RedBlackTree.h"
#include <algorithm>
#include <cassert>
#include <utility>

// declaration

static RbNode *Left(RbNode *e);
static RbNode *Right(RbNode *e);
static RbNode *Father(RbNode *e);
static void SwapIndex(RbNode *a, RbNode *b);
static void SwapColor(RbNode *a, RbNode *b);
static char Color(RbNode *e);
static int Index(RbNode *e);
static RbNode *GrandFather(RbNode *e);
static RbNode *Previous(RbNode *e);
static RbNode *Next(RbNode *e);
static RbNode *Uncle(RbNode *e);
static RbNode *Brother(RbNode *e);
static bool IsLeftChild(RbNode *e);
static bool IsRightChild(RbNode *e);
static int ChildNumber(RbNode *e);
static void RbNodeFree(RbNode *e);
static void RotateLeft(RedBlackTree *t, RbNode *e);
static void RotateRight(RedBlackTree *t, RbNode *e);
static RbNode *RbNodeFind(RedBlackTree *t, int value, RbNode **father);
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

static RbNode *Left(RbNode *e) { return e ? e->left : NULL; }

static RbNode *Right(RbNode *e) { return e ? e->right : NULL; }

static RbNode *Father(RbNode *e) { return e ? e->father : NULL; }

static void SwapIndex(RbNode *a, RbNode *b) { std::swap(a->value, b->value); }

static void SwapColor(RbNode *a, RbNode *b) { std::swap(a->color, b->color); }

static char Color(RbNode *e) { return e ? e->color : BLACK; }

static int Index(RbNode *e) {
  if (!e)
    return -1;
  return e->value;
}

static RbNode *GrandFather(RbNode *e) {
  if (!e)
    return NULL;
  if (!e->father)
    return NULL;
  return e->father->father;
}

static RbNode *Previous(RbNode *e) {
  while (e->left)
    e = e->left;
  return e;
}

static RbNode *Next(RbNode *e) {
  while (e->right)
    e = e->right;
  return e;
}

static RbNode *Uncle(RbNode *e) {
  if (!GrandFather(e))
    return NULL;
  if (GrandFather(e)->left == e)
    return GrandFather(e)->right;
  if (GrandFather(e)->right == e)
    return GrandFather(e)->left;
  return NULL;
}

static RbNode *Brother(RbNode *e) {
  if (!e)
    return NULL;
  if (!e->father)
    return NULL;
  if (Left(Father(e)) == e)
    return Right(Father(e));
  if (Right(Father(e)) == e)
    return Left(Father(e));
  return NULL;
}

static bool IsLeftChild(RbNode *e) {
  if (!Father(e))
    return false;
  return Left(Father(e)) == e;
}

static bool IsRightChild(RbNode *e) {
  if (!Father(e))
    return false;
  return Right(Father(e)) == e;
}

static int ChildNumber(RbNode *e) {
  return e ? ((e->left ? 1 : 0) + (e->right ? 1 : 0)) : 0;
}

static void RbNodeFree(RbNode *e) {
  if (!e)
    return;
  RbNodeFree(Left(e));
  RbNodeFree(Right(e));
  delete e;
}

static void RotateLeft(RedBlackTree *t, RbNode *e) {
  RbNode *p = e;
  RbNode *q = Right(e);
  RbNode *father = Father(e);

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
    Left(q)->father = p;
  q->left = p;
}

static void RotateRight(RedBlackTree *t, RbNode *e) {
  RbNode *p = e;
  RbNode *q = Left(e); /* can't be NULL */
  RbNode *father = Father(p);
  assert(q);

  if (p->father == NULL) {
    t->root = q;
  } else {
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

static RbNode *RbNodeFind(RedBlackTree *t, int value, RbNode **father) {
  RbNode *cur = t->root;
  while (cur) {
    if (Index(cur) == value)
      return cur;
    else {
      if (father != NULL)
        *father = cur;
      if (value < Index(cur))
        cur = Left(cur);
      else if (value > Index(cur))
        cur = Right(cur);
      else if (value == Index(cur))
        return cur;
    }
  }
  return NULL;
}

static void InsertCase5(RedBlackTree *t, RbNode *e) {
  Father(e)->color = BLACK;
  GrandFather(e)->color = RED;
  if (IsLeftChild(e) && IsLeftChild(Father(e))) {
    RotateRight(t, GrandFather(e));
  } else {
    assert(IsRightChild(e));
    assert(IsRightChild(Father(e)));
    RotateLeft(t, GrandFather(e));
  }
}

static void InsertCase4(RedBlackTree *t, RbNode *e) {
  if (IsRightChild(e) && IsLeftChild(Father(e))) {
    RotateLeft(t, Father(e));
    e = Left(e);
  } else if (IsLeftChild(e) && IsRightChild(Father(e))) {
    RotateRight(t, Father(e));
    e = Right(e);
  }
  InsertCase5(t, e);
}

static void InsertCase3(RedBlackTree *t, RbNode *e) {
  if (IsLeftChild(Father(e))) {
  }
  if (Color(Uncle(e)) == RED) {
    Father(e)->color = BLACK;
    Uncle(e)->color = BLACK;
    GrandFather(e)->color = RED;
    InsertCase1(t, GrandFather(e));
  } else {
    InsertCase4(t, e);
  }
}

static void InsertCase2(RedBlackTree *t, RbNode *e) {
  if (Color(Father(e)) == RED) {
    InsertCase3(t, e);
  }
}

static void InsertCase1(RedBlackTree *t, RbNode *e) {
  if (t->root == NULL) {
    assert(t->root == NULL);
    assert(Father(e) == NULL);
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
  if (Left(Father(e)) == e)
    Father(e)->left = NULL;
  else if (e->father->right == e)
    Father(e)->right = NULL;
  delete e;
}

static void EraseCase0_B(RedBlackTree *t, RbNode *e) {
  RbNode *child = Left(e) ? Left(e) : Right(e);
  SwapIndex(child, e);

  // now "child" is father of "e", while "e" is child of "child"
  child->left = child->right = NULL;
  delete e;
  EraseCase1(t, child);
}

static void EraseCase0_C(RedBlackTree *t, RbNode *e) {
  RbNode *next = Next(e);
  e->value = Index(next);
  EraseCase0(t, next);
}

static void EraseCase1(RedBlackTree *t, RbNode *e) {
  if (t->root != e) {
    assert(t->root != e);
    assert(Father(e) != NULL);
    EraseCase2(t, e);
  }
}

static void EraseCase2(RedBlackTree *t, RbNode *e) {
  if (Color(Brother(e)) == RED) {
    Father(e)->color = RED;
    Brother(e)->color = BLACK;
    if (IsLeftChild(e)) {
      RotateLeft(t, Father(e));
    } else if (IsRightChild(e)) {
      RotateRight(t, Father(e));
    }
    // SwapColor(Father(e), Brother(e));
  }
  EraseCase3(t, e);
}

static void EraseCase3(RedBlackTree *t, RbNode *e) {
  if (Color(Father(e)) == BLACK && Color(Brother(e)) == BLACK &&
      Color(Left(Brother(e))) == BLACK && Color(Right(Brother(e))) == BLACK) {
    Brother(e)->color = RED;
    EraseCase1(t, Father(e));
  } else {
    EraseCase4(t, e);
  }
}

static void EraseCase4(RedBlackTree *t, RbNode *e) {
  if (Color(Brother(e)) == BLACK && Color(Father(e)) == RED &&
      Color(Left(Brother(e))) == BLACK && Color(Right(Brother(e))) == BLACK) {
    SwapColor(Father(e), Brother(e));
  } else {
    EraseCase5(t, e);
  }
}

static void EraseCase5(RedBlackTree *t, RbNode *e) {
  if (IsLeftChild(e) && Color(Brother(e)) == BLACK &&
      Color(Left(Brother(e))) == RED && Color(Right(Brother(e))) == BLACK) {
    SwapColor(Brother(e), Left(Brother(e)));
    RotateRight(t, Brother(e));
  } else if (IsRightChild(e) && Color(Brother(e)) == BLACK &&
             Color(Right(Brother(e))) == RED &&
             Color(Left(Brother(e))) == BLACK) {
    SwapColor(Brother(e), Right(Brother(e)));
    RotateLeft(t, Brother(e));
  }
  EraseCase6(t, e);
}

static void EraseCase6(RedBlackTree *t, RbNode *e) {
  SwapColor(Brother(e), Father(e));
  if (IsLeftChild(e)) {
    assert(Color(Right(Brother(e))) == RED);
    Right(Brother(e))->color = BLACK;
    RotateLeft(t, Father(e));
  } else {
    assert(Color(Left(Brother(e))) == RED);
    Left(Brother(e))->color = BLACK;
    RotateRight(t, Father(e));
  }
}

RedBlackTree *RedBlackTreeNew() {
  RedBlackTree *t = new RedBlackTree();
  if (!t)
    return NULL;
  t->root = NULL;
  return t;
}

void RedBlackTreeFree(RedBlackTree *t) { RbNodeFree(t->root); }

void RedBlackTreeInsert(RedBlackTree *t, int value) {
  RbNode *e = new RbNode();
  RbNode *father = NULL;
  RbNode *tmp;
  tmp = RbNodeFind(t, value, &father);
  assert(tmp == NULL);
  e->color = RED;
  e->value = value;
  e->left = NULL;
  e->right = NULL;
  e->father = father;
  if (father) {
    if (value < Index(father))
      father->left = e;
    else
      father->right = e;
  }
  // fix rbtree from e
  InsertCase1(t, e);
}

int RedBlackTreeFind(RedBlackTree *t, int value) {
  return RbNodeFind(t, value, NULL) ? 1 : 0;
}

void RedBlackTreeErase(RedBlackTree *t, int value) {
  RbNode *e = RbNodeFind(t, value, NULL);
  assert(e);
  EraseCase0(t, e);
}

