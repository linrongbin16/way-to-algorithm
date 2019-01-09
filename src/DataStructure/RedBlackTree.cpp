#include "RedBlackTree.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <utility>

#define RED 'R'
#define BLACK 'B'

RbNode RBNIL = {BLACK, -1, &RBNIL, &RBNIL, &RBNIL};

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

static RbNode *Uncle(RbNode *e) {
  if (is_nil(e->father->father))
    return &RBNIL;
  if (e->father->father->left == e->father)
    return e->father->father->right;
  if (e->father->father->right == e->father)
    return e->father->father->left;
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

static void DumpNode(RbNode *e) {
  assert(e);
  if (is_nil(e)) {
    std::cout << " [nil B]" << std::endl;
  } else {
    std::cout << " [" << e->value << " " << (e->color == RED ? "R" : "B")
              << " left:"
              << (is_nil(e->left) ? "nil" : std::to_string(e->left->value))
              << " right:"
              << (is_nil(e->right) ? "nil" : std::to_string(e->right->value))
              << " father:"
              << (is_nil(e->father) ? "nil" : std::to_string(e->father->value))
              << "]" << std::endl;
    if (not_nil(e->left)) {
      DumpNode(e->left);
    }
    if (not_nil(e->right)) {
      DumpNode(e->right);
    }
  }
}

static void DumpTree(RedBlackTree *t, const char *msg) {
  assert(t);
  std::cout << std::endl << std::endl << msg << std::endl;
  DumpNode(t->root);
}

static void Free(RbNode *e) {
  if (is_nil(e))
    return;
  Free(e->left);
  Free(e->right);
  delete e;
}

static void LeftRotate(RbNode *&root, RbNode *&e) {
  RbNode *p = e->right;

  e->right = p->left;
  if (not_nil(p->left)) {
    p->left->father = e;
  }

  if (not_nil(p)) {
    p->father = e->father;
  }
  if (not_nil(e->father)) {
    if (e == e->father->left) {
      e->father->left = p;
    } else {
      e->father->right = p;
    }
  } else {
    root = p;
  }

  p->left = e;
  if (not_nil(e)) {
    e->father = p;
  }
}

static void RightRotate(RbNode *&root, RbNode *&e) {
  RbNode *p = e->left;

  e->left = p->right;
  if (not_nil(p->right)) {
    p->right->father = e;
  }

  if (not_nil(p)) {
    p->father = e->father;
  }
  if (not_nil(e->father)) {
    if (e == e->father->right) {
      e->father->right = p;
    } else {
      e->father->left = p;
    }
  } else {
    root = p;
  }

  p->right = e;
  if (not_nil(e)) {
    e->father = p;
  }
}

void FixInsert(RbNode *&root, RbNode *&e) {
  while ((e != root) && (e->father->color == RED)) {
    // case A: e_father is e_grand_father's left child
    if (IsLeft(e->father)) {
      RbNode *e_uncle = Uncle(e);

      // case 1: Red Uncle, e e_uncle is red
      if (not_nil(e_uncle) && e_uncle->color == RED) {
        e->father->father->color = RED;
        e->father->color = BLACK;
        e_uncle->color = BLACK;
        e = e->father->father; // next loop from e_grand_father

      } else {
        // case 2: Black Uncle, left-right-case
        if (IsRight(e)) {
          e = e->father;
          LeftRotate(root, e);
        }

        // case 3: Black Uncle, left-left-case
        e->father->color = BLACK;
        e->father->father->color = RED;
        RightRotate(root, e->father->father);
      }
    }

    // case B: e_father is e_grand_father's right child
    else {
      RbNode *e_uncle = Uncle(e);

      // case 1: Red Uncle
      if (not_nil(e_uncle) && (e_uncle->color == RED)) {
        e->father->father->color = RED;
        e->father->color = BLACK;
        e_uncle->color = BLACK;
        e = e->father->father; // next loop from e_grand_father
      } else {

        // case 4: Black Uncle, left-right-case
        if (IsLeft(e)) {
          e = e->father;
          RightRotate(root, e);
        }

        // case 5: Black Uncle, right-right-case
        e->father->color = BLACK;
        e->father->father->color = RED;
        LeftRotate(root, e->father->father);
      }
    }
  } // while

  root->color = BLACK;
}

static void FixErase(RbNode *&root, RbNode *&e) {
  while ((e != root) && (e->color == BLACK)) {
    // case A: e is left child
    if (IsLeft(e)) {
      RbNode *e_brother = Brother(e);

      if (e_brother->color == RED) {
        e->color = BLACK;
        e->father->color = RED;
        LeftRotate(root, e->father);
        e_brother = e->father->right;
      }

      if (e_brother->left->color == BLACK && e->right->color == BLACK) {
        e->color = RED;
        e = e->father;
      } else {
        if (e_brother->right->color == BLACK) {
          e_brother->left->color = BLACK;
          e_brother->color = RED;
          RightRotate(root, e_brother);
          e_brother = e->father->right;
        }
        e_brother->color = e->father->color;
        e->father->color = BLACK;
        e_brother->right->color = BLACK;
        LeftRotate(root, e->father);
        e = root; // break loop
      }
    }

    // case B: e is right child
    else {
      RbNode *e_brother = Brother(e);

      if (e_brother->color == RED) {
        e->color = BLACK;
        e->father->color = RED;
        LeftRotate(root, e->father);
        e_brother = e->father->left;
      }

      if (e_brother->right->color == BLACK && e->left->color == BLACK) {
        e->color = RED;
        e = e->father;
      } else {
        if (e_brother->left->color == BLACK) {
          e_brother->right->color = BLACK;
          e_brother->color = RED;
          LeftRotate(root, e_brother);
          e_brother = e->father->left;
        }
        e_brother->color = e->father->color;
        e->father->color = BLACK;
        e_brother->left->color = BLACK;
        RightRotate(root, e->father);
        e = root; // break loop
      }
    }
  }

  e->color = BLACK;
}

static void Erase(RbNode *&root, RbNode *&e) {
  RbNode *p, *q;

  if (is_nil(e->left) && is_nil(e->right)) {
    p = e;
  } else {
    p = Next(e);
  }

  if (not_nil(p->left)) {
    q = p->left;
  } else {
    q = p->right;
  }

  e->father = p->father;
  if (not_nil(p->father)) {
    if (IsLeft(p)) {
      p->father->left = e;
    } else {
      p->father->right = e;
    }
  } else {
    root = e;
  }

  if (p != q) {
    e->value = p->value;
  }
  if (p->color == BLACK) {
    FixErase(root, e);
  }

  delete p;
}

static RbNode *Find(RbNode *e, int value) {
  if (is_nil(e)) {
    return &RBNIL;
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

static RbNode *Insert(RbNode *father, RbNode *e) {
  assert(father);
  assert(e);

  if (is_nil(father)) {
    return e;
  }

  //利用二分查找找到适合value插入的位置e

  if (father->value > e->value) {
    father->left = Insert(father->left, e);
    father->left->father = father;
  } else if (father->value < e->value) {
    father->right = Insert(father->right, e);
    father->right->father = father;
  } else {
    assert(father->value != e->value);
  }
  return father;
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
  assert(t);
  assert(value >= 0);

  RbNode *e = new RbNode();
  set_nil(e->left);
  set_nil(e->right);
  set_nil(e->father);
  e->color = RED; // new node is red
  e->value = value;

  t->root = Insert(t->root, e);
  DumpTree(t, "before fix insert");
  FixInsert(t->root, e);
  DumpTree(t, "after fix insert");
}

RbNode *RedBlackTreeFind(RedBlackTree *t, int value) {
  return Find(t->root, value);
}

void RedBlackTreeErase(RedBlackTree *t, int value) {
  RbNode *e = Find(t->root, value);
  if (e == NULL || is_nil(e)) {
    return;
  }
  Erase(t->root, e);
  DumpTree(t, "erase");
}

