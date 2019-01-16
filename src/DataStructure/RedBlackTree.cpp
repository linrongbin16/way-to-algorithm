#include "RedBlackTree.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <utility>

#define RED 'R'
#define BLACK 'B'

static RbNode *Next(RbTree *t, RbNode *e) {
  RbNode *p = e->right;
  while (not_nil(t, p->left)) {
    p = p->left;
  }
  return p;
}

static RbNode *Uncle(RbNode *e) {
  if (e->father->father->left == e->father)
    return e->father->father->right;
  if (e->father->father->right == e->father)
    return e->father->father->left;
  assert(false);
}

static bool IsLeft(RbNode *e) { return e->father->left == e; }

static bool IsRight(RbNode *e) { return e->father->right == e; }

static RbNode *Brother(RbNode *e) {
  if (IsLeft(e)) {
    return e->father->right;
  }
  if (IsRight(e)) {
    return e->father->left;
  }
  assert(false);
}

static void Free(RbTree *t, RbNode *e) {
  if (e == NULL || is_nil(t, e))
    return;
  Free(t, e->left);
  Free(t, e->right);
  delete e;
}

static void LeftRotate(RbTree *t, RbNode *e) {
  RbNode *p = e->right;

  e->right = p->left;
  if (not_nil(t, p->left)) {
    p->left->father = e;
  }

  if (not_nil(t, p)) {
    p->father = e->father;
  }
  if (not_nil(t, e->father)) {
    if (e == e->father->left) {
      e->father->left = p;
    } else {
      e->father->right = p;
    }
  } else {
    t->root = p;
  }

  p->left = e;
  if (not_nil(t, e)) {
    e->father = p;
  }
}

static void RightRotate(RbTree *t, RbNode *e) {
  RbNode *p = e->left;

  e->left = p->right;
  if (not_nil(t, p->right)) {
    p->right->father = e;
  }

  if (not_nil(t, p)) {
    p->father = e->father;
  }
  if (not_nil(t, e->father)) {
    if (e == e->father->right) {
      e->father->right = p;
    } else {
      e->father->left = p;
    }
  } else {
    t->root = p;
  }

  p->right = e;
  if (not_nil(t, e)) {
    e->father = p;
  }
}

static void FixInsert(RbTree *t, RbNode *e) {
  assert(t->NIL.color == BLACK);
  while ((e != t->root) && (e->father->color == RED)) {
    // case A: e.father is e.grand_father's left child
    if (IsLeft(e->father)) {
      RbNode *e_uncle = Uncle(e);

      // case 1: Red Uncle, e.uncle is red
      if (e_uncle->color == RED) {
        e->father->color = BLACK;
        e_uncle->color = BLACK;
        e->father->father->color = RED;
        e = e->father->father; // next loop from e.grand_father

      } else {
        // case 2: Black Uncle, left-right-case
        if (IsRight(e)) {
          e = e->father;
          LeftRotate(t, e);
        }

        // case 3: Black Uncle, left-left-case
        e->father->color = BLACK;
        e->father->father->color = RED;
        RightRotate(t, e->father->father);
      }
    }

    // case B: e.father is e.grand_father's right child
    else {
      RbNode *e_uncle = Uncle(e);

      // case 1: Red Uncle
      if (e_uncle->color == RED) {
        e->father->color = BLACK;
        e_uncle->color = BLACK;
        e->father->father->color = RED;
        e = e->father->father; // next loop from e.grand_father
      } else {

        // case 4: Black Uncle, left-right-case
        if (IsLeft(e)) {
          e = e->father;
          RightRotate(t, e);
        }

        // case 5: Black Uncle, right-right-case
        e->father->color = BLACK;
        e->father->father->color = RED;
        LeftRotate(t, e->father->father);
      }
    }
  } // while

  t->root->color = BLACK;
}

static void FixErase(RbTree *t, RbNode *e) {
  assert(t->NIL.color == BLACK);
  while ((e != t->root) && (e->color == BLACK)) {
    // case A: e is left child
    if (IsLeft(e)) {
      RbNode *e_brother = Brother(e);

      if (e_brother->color == RED) {
        e_brother->color = BLACK;
        e->father->color = RED;
        LeftRotate(t, e->father);
        e_brother = e->father->right;
      }

      if (e_brother->left->color == BLACK && e_brother->right->color == BLACK) {
        e_brother->color = RED;
        e = e->father;
      } else {
        if (e_brother->right->color == BLACK) {
          e_brother->left->color = BLACK;
          e_brother->color = RED;
          RightRotate(t, e_brother);
          e_brother = e->father->right;
        }
        e_brother->color = e->father->color;
        e->father->color = BLACK;
        e_brother->right->color = BLACK;
        LeftRotate(t, e->father);
        e = t->root; // break loop
      }
    }

    // case B: e is right child
    else {
      RbNode *e_brother = Brother(e);

      if (e_brother->color == RED) {
        e_brother->color = BLACK;
        e->father->color = RED;
        RightRotate(t, e->father);
        e_brother = e->father->left;
      }

      if (e_brother->right->color == BLACK && e_brother->left->color == BLACK) {
        e_brother->color = RED;
        e = e->father;
      } else {
        if (e_brother->left->color == BLACK) {
          e_brother->right->color = BLACK;
          e_brother->color = RED;
          LeftRotate(t, e_brother);
          e_brother = e->father->left;
        }
        e_brother->color = e->father->color;
        e->father->color = BLACK;
        e_brother->left->color = BLACK;
        RightRotate(t, e->father);
        e = t->root; // break loop
      }
    }
  }

  e->color = BLACK;
}

static void Erase(RbTree *t, RbNode *e) {
  assert(t->NIL.color == BLACK);
  RbNode *p, *q;

  if (is_nil(t, e)) {
    return;
  }

  // p is the real node will be delete
  if (is_nil(t, e->left) || is_nil(t, e->right)) {
    p = e;
  } else {
    p = Next(t, e);
  }

  if (not_nil(t, p->left)) {
    q = p->left;
  } else {
    q = p->right;
  }

  // q can be NIL
  // to avoid making NIL a global variable, we put NIL in RbTree
  q->father = p->father;
  if (not_nil(t, p->father)) {
    if (IsLeft(p)) {
      p->father->left = q;
    } else {
      p->father->right = q;
    }
  } else {
    t->root = q;
  }

  if (p != e) {
    e->value = p->value;
  }

  if (p->color == BLACK) {
    FixErase(t, q);
  }

  delete p;
}

static RbNode *Find(RbTree *t, int value) {
  assert(t->NIL.color == BLACK);
  RbNode *p = t->root;
  while (not_nil(t, p)) {
    if (p->value == value) {
      return p;
    } else {
      p = (p->value > value) ? p->left : p->right;
    }
  }
  return p;
}

static void Insert(RbTree *t, RbNode *e) {
  assert(t->NIL.color == BLACK);
  assert(e);

  if (is_nil(t, t->root)) {
    t->root = e;
    return;
  }

  //利用二分查找找到适合value插入的位置e
  RbNode *fp, *p = t->root;
  while (not_nil(t, p)) {
    if (p->value > e->value) {
      fp = p;
      p = p->left;
    } else if (p->value < e->value) {
      fp = p;
      p = p->right;
    } else {
      // same value already exist
      assert(false);
    }
  }

  if (fp->value > e->value) {
    fp->left = e;
  } else {
    fp->right = e;
  }
  e->father = fp;
}

RbTree *RedBlackTreeNew() {
  RbTree *t = new RbTree();
  if (!t)
    return NULL;

  t->NIL.color = BLACK;
  t->NIL.value = -1;
  set_nil(t, t->NIL.left);
  set_nil(t, t->NIL.right);
  set_nil(t, t->NIL.father);
  set_nil(t, t->root);
  return t;
}

void RedBlackTreeFree(RbTree *t) {
  assert(t);
  Free(t, t->root);
  delete t;
}

void RedBlackTreeInsert(RbTree *t, int value) {
  assert(t);
  assert(value >= 0);

  RbNode *e = new RbNode();
  set_nil(t, e->left);
  set_nil(t, e->right);
  set_nil(t, e->father);
  e->color = RED; // new node is red
  e->value = value;

  Insert(t, e);
  FixInsert(t, e);
  assert(t->NIL.color == BLACK);
}

RbNode *RedBlackTreeFind(RbTree *t, int value) { return Find(t, value); }

void RedBlackTreeErase(RbTree *t, int value) {
  RbNode *e = Find(t, value);
  Erase(t, e);
  assert(t->NIL.color == BLACK);
}

