#include "RedBlackTree.h"
#include <algorithm>
#include <cassert>
#include <utility>

// declaration

static Node *Left(Node *e);
static Node *Right(Node *e);
static Node *Father(Node *e);
static void SwapIndex(Node *a, Node *b);
static void SwapColor(Node *a, Node *b);
static char Color(Node *e);
static int Index(Node *e);
static Node *GrandFather(Node *e);
static Node *Previous(Node *e);
static Node *Next(Node *e);
static Node *Uncle(Node *e);
static Node *Brother(Node *e);
static bool IsLeftChild(Node *e);
static bool IsRightChild(Node *e);
static int ChildNumber(Node *e);
static void NodeFree(Node *e);
static void RotateLeft(RedBlackTree *t, Node *e);
static void RotateRight(RedBlackTree *t, Node *e);
static Node *NodeFind(RedBlackTree *t, int index, Node **father);
static void InsertCase1(RedBlackTree *t, Node *e);
static void InsertCase2(RedBlackTree *t, Node *e);
static void InsertCase3(RedBlackTree *t, Node *e);
static void InsertCase4(RedBlackTree *t, Node *e);
static void InsertCase5(RedBlackTree *t, Node *e);
static void EraseCase0(RedBlackTree *t, Node *e);
static void EraseCase0_A(RedBlackTree *t, Node *e);
static void EraseCase0_B(RedBlackTree *t, Node *e);
static void EraseCase0_C(RedBlackTree *t, Node *e);
static void EraseCase1(RedBlackTree *t, Node *e);
static void EraseCase2(RedBlackTree *t, Node *e);
static void EraseCase3(RedBlackTree *t, Node *e);
static void EraseCase4(RedBlackTree *t, Node *e);
static void EraseCase5(RedBlackTree *t, Node *e);
static void EraseCase6(RedBlackTree *t, Node *e);

// implementation

static Node *Left(Node *e) { return e ? e->left : NULL; }

static Node *Right(Node *e) { return e ? e->right : NULL; }

static Node *Father(Node *e) { return e ? e->father : NULL; }

static void SwapIndex(Node *a, Node *b) { std::swap(a->index, b->index); }

static void SwapColor(Node *a, Node *b) { std::swap(a->color, b->color); }

static char Color(Node *e) { return e ? e->color : BLACK; }

static int Index(Node *e) {
  if (!e)
    return -1;
  return e->index;
}

static Node *GrandFather(Node *e) {
  if (!e)
    return NULL;
  if (!e->father)
    return NULL;
  return e->father->father;
}

static Node *Previous(Node *e) {
  while (e->left)
    e = e->left;
  return e;
}

static Node *Next(Node *e) {
  while (e->right)
    e = e->right;
  return e;
}

static Node *Uncle(Node *e) {
  if (!GrandFather(e))
    return NULL;
  if (GrandFather(e)->left == e)
    return GrandFather(e)->right;
  if (GrandFather(e)->right == e)
    return GrandFather(e)->left;
  return NULL;
}

static Node *Brother(Node *e) {
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

static bool IsLeftChild(Node *e) {
  if (!Father(e))
    return false;
  return Left(Father(e)) == e;
}

static bool IsRightChild(Node *e) {
  if (!Father(e))
    return false;
  return Right(Father(e)) == e;
}

static int ChildNumber(Node *e) {
  return e ? ((e->left ? 1 : 0) + (e->right ? 1 : 0)) : 0;
}

static void NodeFree(Node *e) {
  if (!e)
    return;
  NodeFree(Left(e));
  NodeFree(Right(e));
  delete e;
}

static void RotateLeft(RedBlackTree *t, Node *e) {
  Node *p = e;
  Node *q = Right(e);
  Node *father = Father(e);

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

static void RotateRight(RedBlackTree *t, Node *e) {
  Node *p = e;
  Node *q = Left(e); /* can't be NULL */
  Node *father = Father(p);
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

static Node *NodeFind(RedBlackTree *t, int index, Node **father) {
  Node *cur = t->root;
  while (cur) {
    if (Index(cur) == index)
      return cur;
    else {
      if (father != NULL)
        *father = cur;
      if (index < Index(cur))
        cur = Left(cur);
      else if (index > Index(cur))
        cur = Right(cur);
      else if (index == Index(cur))
        return cur;
    }
  }
  return NULL;
}

static void InsertCase5(RedBlackTree *t, Node *e) {
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

static void InsertCase4(RedBlackTree *t, Node *e) {
  if (IsRightChild(e) && IsLeftChild(Father(e))) {
    RotateLeft(t, Father(e));
    e = Left(e);
  } else if (IsLeftChild(e) && IsRightChild(Father(e))) {
    RotateRight(t, Father(e));
    e = Right(e);
  }
  InsertCase5(t, e);
}

static void InsertCase3(RedBlackTree *t, Node *e) {
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

static void InsertCase2(RedBlackTree *t, Node *e) {
  if (Color(Father(e)) == RED) {
    InsertCase3(t, e);
  }
}

static void InsertCase1(RedBlackTree *t, Node *e) {
  if (t->root == NULL) {
    assert(t->root == NULL);
    assert(Father(e) == NULL);
    e->color = BLACK;
    t->root = e;
  } else {
    InsertCase2(t, e);
  }
}

static void EraseCase0(RedBlackTree *t, Node *e) {
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

static void EraseCase0_A(RedBlackTree *t, Node *e) {
  if (Left(Father(e)) == e)
    Father(e)->left = NULL;
  else if (e->father->right == e)
    Father(e)->right = NULL;
  delete e;
}

static void EraseCase0_B(RedBlackTree *t, Node *e) {
  Node *child = Left(e) ? Left(e) : Right(e);
  SwapIndex(child, e);

  // now "child" is father of "e", while "e" is child of "child"
  child->left = child->right = NULL;
  delete e;
  EraseCase1(t, child);
}

static void EraseCase0_C(RedBlackTree *t, Node *e) {
  Node *next = Next(e);
  e->index = Index(next);
  EraseCase0(t, next);
}

static void EraseCase1(RedBlackTree *t, Node *e) {
  if (t->root != e) {
    assert(t->root != e);
    assert(Father(e) != NULL);
    EraseCase2(t, e);
  }
}

static void EraseCase2(RedBlackTree *t, Node *e) {
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

static void EraseCase3(RedBlackTree *t, Node *e) {
  if (Color(Father(e)) == BLACK && Color(Brother(e)) == BLACK &&
      Color(Left(Brother(e))) == BLACK && Color(Right(Brother(e))) == BLACK) {
    Brother(e)->color = RED;
    EraseCase1(t, Father(e));
  } else {
    EraseCase4(t, e);
  }
}

static void EraseCase4(RedBlackTree *t, Node *e) {
  if (Color(Brother(e)) == BLACK && Color(Father(e)) == RED &&
      Color(Left(Brother(e))) == BLACK && Color(Right(Brother(e))) == BLACK) {
    SwapColor(Father(e), Brother(e));
  } else {
    EraseCase5(t, e);
  }
}

static void EraseCase5(RedBlackTree *t, Node *e) {
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

static void EraseCase6(RedBlackTree *t, Node *e) {
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

void RedBlackTreeFree(RedBlackTree *t) { NodeFree(t->root); }

void RedBlackTreeInsert(RedBlackTree *t, int index) {
  Node *e = new Node();
  Node *father = NULL;
  Node *tmp;
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

int RedBlackTreeFind(RedBlackTree *t, int index) {
  return NodeFind(t, index, NULL) ? 1 : 0;
}

void RedBlackTreeErase(RedBlackTree *t, int index) {
  Node *e = NodeFind(t, index, NULL);
  assert(e);
  EraseCase0(t, e);
}

