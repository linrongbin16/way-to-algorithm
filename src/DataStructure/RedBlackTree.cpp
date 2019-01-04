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

static void LeftRotate(RbNode *&father, RbNode *&e) {
  RbNode *p_right = e->right;
  e->right = p_right->left;

  if (not_nil(e->right)) {
    e->right->father = e;
  }

  p_right->father = e->father;

  if (is_nil(e->father)) {
    father = p_right;
  } else if (e == e->father->left) {
    e->father->left = p_right;
  } else {
    e->father->right = p_right;
  }

  p_right->left = e;
  e->father = p_right;
}

static void RightRotate(RbNode *&father, RbNode *&e) {
  RbNode *p_left = e->left;
  e->left = p_left->right;

  if (not_nil(e->left)) {
    e->left->father = e;
  }

  p_left->father = e->father;

  if (is_nil(e->father)) {
    father = p_left;
  } else if (e == e->father->left) {
    e->father->left = p_left;
  } else {
    e->father->right = p_left;
  }

  p_left->right = e;
  e->father = p_left;
}

void FixInsert(RbNode *&root, RbNode *&e) {
  RbNode *e_father, *e_grand_father;
  set_nil(e_father);
  set_nil(e_grand_father);

  while ((e != root) && (e->color != BLACK) && (e->father->color == RED)) {
    e_father = e->father;
    e_grand_father = e->father->father;

    // case A
    if (e_father == e_grand_father->left) {
      RbNode *e_uncle = e_grand_father->right;

      // case 1: Red Uncle
      if (not_nil(e_uncle) && e_uncle->color == RED) {
        e_grand_father->color = RED;
        e_father->color = BLACK;
        e_uncle->color = BLACK;
        e = e_grand_father;
      } else {

        // case 2: Black Uncle, left-right-case
        if (e == e_father->right) {
          LeftRotate(root, e_father);
          e = e_father;
          e_father = e->father;
        }

        // case 3: Black Uncle, left-left-case
        RightRotate(root, e_grand_father);
        std::swap(e_father->color, e_grand_father->color);
        e = e_father;
      }
    }

    // case B
    else {
      RbNode *e_uncle = e_grand_father->right;

      // case 1: Red Uncle
      if (not_nil(e_uncle) && (e_uncle->color == RED)) {
        e_grand_father->color = RED;
        e_father->color = BLACK;
        e_uncle->color = BLACK;
        e = e_grand_father;
      } else {

        // case 4: Black Uncle, left-right-case
        if (e == e_father->left) {
          RightRotate(root, e_father);
          e = e_father;
          e_father = e->father;
        }

        // case 5: Black Uncle, right-right-case
        LeftRotate(root, e_grand_father);
        std::swap(e_father->color, e_grand_father->color);
        e = e_father;
      }
    }
  } // while

  root->color = BLACK;
} // FixInsert

static RbNode *Replace(RbNode *e) {
  if (not_nil(e->left) && not_nil(e->right)) {
    return Next(e->right);
  }
  if (is_nil(e->left) && is_nil(e->right)) {
    return &RBNIL;
  }
  if (not_nil(e->left)) {
    return e->left;
  } else {
    return e->right;
  }
}

static void FixErase(RbNode *&root, RbNode *&e) {
  // reach root
  if (e == root) {
    return;
  }

  RbNode *e_brother = &RBNIL;
  RbNode *e_father = &RBNIL;

  while (true) {
    e_brother = Brother(e);
    e_father = e->father;

    RbNode *e_brother = Brother(e);
    RbNode *e_father = e->father;

    if (is_nil(e_brother)) {
      // no brother
      // double black pushed up
      FixErase(root, e_father);

    } else {
      if (e_brother->color == RED) {
        // brother red
        e_father->color = RED;
        e_brother->color = BLACK;
        if (IsLeft(e_brother)) {
          // left case
          RightRotate(root, e_father);
        } else {
          // right case
          LeftRotate(root, e_father);
        }
        FixErase(root, e);
      } else {
        // brother black
        if (e_brother->left->color == RED || e_brother->right->color == RED) {
          // at least 1 red children
          if (not_nil(e_brother->left) && e_brother->left->color == RED) {
            if (IsLeft(e_brother)) {
              // left left
              e_brother->left->color = e_brother->color;
              e_brother->color = e_father->color;
              RightRotate(root, e_father);
            } else {
              // right left
              e_brother->left->color = e_father->color;
              RightRotate(root, e_brother);
              LeftRotate(root, e_father);
            }
          } else {
            if (IsLeft(e_brother)) {
              // left right
              e_brother->right->color = e_father->color;
              LeftRotate(root, e_brother);
              RightRotate(root, e_father);
            } else {
              // right right
              e_brother->right->color = e_brother->color;
              e_brother->color = e_father->color;
              LeftRotate(root, e_father);
            }
          }
          e_father->color = BLACK;
        } else {
          // 2 black children
          e_brother->color = RED;
          if (e_father->color == BLACK) {
            FixErase(root, e_father);
          } else {
            e_father->color = BLACK;
          }
        }
      }
    }
  } // while
} // FixErase

static void Erase(RbNode *&root, RbNode *&e) {
  RbNode *p = Replace(e);
  bool pe_black = ((is_nil(p) || p->color == BLACK) && (e->color == BLACK));
  RbNode *e_father = e->father;

  if (is_nil(p)) {
    if (e == root) {
      set_nil(root);
    } else {
      if (pe_black) {
        FixErase(root, e);
      } else {
        if (not_nil(Uncle(e))) {
          Uncle(e)->color = RED;
        }
      }
      if (IsLeft(e)) {
        set_nil(e_father->left);
      } else {
        set_nil(e_father->right);
      }
    }

    delete e;
    return;
  } // if (is_nil(p))

  if (is_nil(e->left) || is_nil(e->right)) {
    if (e == root) {
      e->value = p->value;
      set_nil(e->left);
      set_nil(e->right);
      delete p;
    } else {
      if (IsLeft(e)) {
        e_father->left = p;
      } else {
        e_father->right = p;
      }
      delete e;
      p->father = e_father;
      if (pe_black) {
        FixErase(root, e);
      } else {
        p->color = BLACK;
      }
    }
    return;
  } // if (is_nil(e->left) || is_nil(e->right))

  std::swap(p->color, e->color);
  Erase(root, e);
} // Erase

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
  FixInsert(t->root, e);
}

RbNode *RedBlackTreeFind(RedBlackTree *t, int value) {
  return Find(t->root, value);
}

void RedBlackTreeErase(RedBlackTree *t, int value) {
  RbNode *e = Find(t->root, value);
  if (is_nil(e)) {
    return;
  }
  Erase(t->root, e);
}

