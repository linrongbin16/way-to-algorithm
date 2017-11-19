// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

// TODO: fix bugs

#include <algorithm>
#include <utility>
#include <cassert>
using namespace std;

#define RED     'R'
#define BLACK   'B'

struct RedBlackTreeNode {
  /* 节点颜色 */
  char color;
  /* 节点值 */
  int index;
  RedBlackTreeNode *left;
  RedBlackTreeNode *right;
  RedBlackTreeNode *father;
};

struct RedBlackTree {
  RedBlackTreeNode *root;
};

auto RedBlackTreeNew() -> RedBlackTree*;
auto RedBlackTreeFree(RedBlackTree *t) -> void;
auto RedBlackTreeInsert(RedBlackTree *t, int index) -> void;
auto RedBlackTreeFind(RedBlackTree *t, int index) -> int;
auto RedBlackTreeErase(RedBlackTree *t, int index) -> void;


//
// implement
//

namespace detail {

  auto Color(RedBlackTreeNode *e) -> char;
  auto Index(RedBlackTreeNode *e) -> int;
  auto Previous(RedBlackTreeNode *e) -> RedBlackTreeNode*;
  auto Next(RedBlackTreeNode *e) -> RedBlackTreeNode*;
  auto Father(RedBlackTreeNode *e) -> RedBlackTreeNode*;
  auto Left(RedBlackTreeNode *e) -> RedBlackTreeNode*;
  auto Right(RedBlackTreeNode *e) -> RedBlackTreeNode*;
  auto Uncle(RedBlackTreeNode *e) -> RedBlackTreeNode*;
  auto GrandFather(RedBlackTreeNode *e) -> RedBlackTreeNode*;
  auto Brother(RedBlackTreeNode *e) -> RedBlackTreeNode*;
  auto IsLeftChild(RedBlackTreeNode *e) -> bool;
  auto IsRightChild(RedBlackTreeNode *e) -> bool;
  auto ChildNumber(RedBlackTreeNode *e) -> int;
  auto SwapIndex(RedBlackTreeNode *a, RedBlackTreeNode *b) -> void;
  auto SwapColor(RedBlackTreeNode *a, RedBlackTreeNode *b) -> void;

  auto NodeFree(RedBlackTreeNode *e) -> void;
  auto NodeFind(RedBlackTree *t, int index, RedBlackTreeNode **father) -> RedBlackTreeNode*;
  auto InsertCase1(RedBlackTree *t, RedBlackTreeNode *e) -> void;
  auto InsertCase2(RedBlackTree *t, RedBlackTreeNode *e) -> void;
  auto InsertCase3(RedBlackTree *t, RedBlackTreeNode *e) -> void;
  auto InsertCase4(RedBlackTree *t, RedBlackTreeNode *e) -> void;
  auto InsertCase5(RedBlackTree *t, RedBlackTreeNode *e) -> void;

  auto EraseCase0(RedBlackTree *t, RedBlackTreeNode *e) -> void;
  auto EraseCase0_A(RedBlackTree *t, RedBlackTreeNode *e) -> void;
  auto EraseCase0_B(RedBlackTree *t, RedBlackTreeNode *e) -> void;
  auto EraseCase0_C(RedBlackTree *t, RedBlackTreeNode *e) -> void;
  auto EraseCase1(RedBlackTree *t, RedBlackTreeNode *e) -> void;
  auto EraseCase2(RedBlackTree *t, RedBlackTreeNode *e) -> void;
  auto EraseCase3(RedBlackTree *t, RedBlackTreeNode *e) -> void;
  auto EraseCase4(RedBlackTree *t, RedBlackTreeNode *e) -> void;
  auto EraseCase5(RedBlackTree *t, RedBlackTreeNode *e) -> void;
  auto EraseCase6(RedBlackTree *t, RedBlackTreeNode *e) -> void;

  auto RotateLeft(RedBlackTree *t, RedBlackTreeNode *e) -> void;
  auto RotateRight(RedBlackTree *t, RedBlackTreeNode *e) -> void;

}

auto RedBlackTreeNew() -> RedBlackTree* {
  RedBlackTree *t = new RedBlackTree();
  if (!t)
    return nullptr;
  t->root = nullptr;
  return t;
}

auto RedBlackTreeFree(RedBlackTree *t) -> void {
  detail::NodeFree(t->root);
}

auto RedBlackTreeInsert(RedBlackTree *t, int index) -> void {
  RedBlackTreeNode *e = new RedBlackTreeNode();
  RedBlackTreeNode *father = nullptr;
  RedBlackTreeNode *tmp;
  tmp = detail::NodeFind(t, index, &father);
  assert(tmp == nullptr);
  e->color = RED;
  e->index = index;
  e->left = nullptr;
  e->right = nullptr;
  e->father = father;
  if (father) {
    if (index < detail::Index(father))
      father->left = e;
    else
      father->right = e;
  }
  // fix rbtree from e
  detail::InsertCase1(t, e);
}

auto RedBlackTreeFind(RedBlackTree *t, int index) -> int {
  return detail::NodeFind(t, index, nullptr)? 1 : 0;
}

auto RedBlackTreeErase(RedBlackTree *t, int index) -> void {
  RedBlackTreeNode *e = detail::NodeFind(t, index, nullptr);
  assert(e);
  detail::EraseCase0(t, e);
}

namespace detail {

  auto NodeFree(RedBlackTreeNode *e) -> void {
    if (!e)
      return;
    NodeFree(detail::Left(e));
    NodeFree(detail::Right(e));
    delete e;
  }

  auto RotateLeft(RedBlackTree *t, RedBlackTreeNode *e) -> void {
    RedBlackTreeNode *p = e;
    RedBlackTreeNode *q = detail::Right(e);
    RedBlackTreeNode *father = detail::Father(e);

    if (father == nullptr) {
      t->root = q;
    } else {
      if (detail::Left(father) == p)
        father->left = q;
      else
        father->right = q;
    }

    q->father = father;
    p->father = q;

    p->right = detail::Left(q);
    if (detail::Left(q))
      detail::Left(q)->father = p;
    q->left = p;
  }

  auto RotateRight(RedBlackTree *t, RedBlackTreeNode *e) -> void {
    RedBlackTreeNode *p = e;
    RedBlackTreeNode *q = Left(e); /* can't be nullptr */
    RedBlackTreeNode *father = Father(p);
    assert(q);

    if (p->father == nullptr) {
      t->root = q;
    }
    else {
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

  auto NodeFind(RedBlackTree *t, int index, RedBlackTreeNode **father) -> RedBlackTreeNode* {
    RedBlackTreeNode *cur = t->root;
    while (cur) {
      if (Index(cur) == index)
        return cur;
      else {
        if (father != nullptr)
          *father = cur;
        if (index < Index(cur))
          cur = Left(cur);
        else if (index > Index(cur))
          cur = Right(cur);
        else if (index == Index(cur))
          return cur;
      }
    }
    return nullptr;
  }

  auto InsertCase1(RedBlackTree *t, RedBlackTreeNode *e) -> void {
    if (t->root == nullptr) {
      assert(t->root == nullptr);
      assert(Father(e) == nullptr);
      e->color = BLACK;
      t->root = e;
    } else {
      InsertCase2(t, e);
    }
  }

  auto InsertCase2(RedBlackTree *t, RedBlackTreeNode *e) -> void {
    if (Color(Father(e)) == RED) {
      InsertCase3(t, e);
    }
  }

  auto InsertCase3(RedBlackTree *t, RedBlackTreeNode *e) -> void {
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

  auto InsertCase4(RedBlackTree *t, RedBlackTreeNode *e) -> void {
    if (IsRightChild(e) and IsLeftChild(Father(e))) {
      RotateLeft(t, Father(e));
      e = Left(e);
    } else if (IsLeftChild(e) and IsRightChild(Father(e))) {
      RotateRight(t, Father(e));
      e = Right(e);
    }
    InsertCase5(t, e);
  }

  auto InsertCase5(RedBlackTree *t, RedBlackTreeNode *e) -> void {
    Father(e)->color = BLACK;
    GrandFather(e)->color = RED;
    if (IsLeftChild(e) and IsLeftChild(Father(e))) {
      RotateRight(t, GrandFather(e));
    } else {
      assert(IsRightChild(e));
      assert(IsRightChild(Father(e)));
      RotateLeft(t, GrandFather(e));
    }
  }

  auto EraseCase0(RedBlackTree *t, RedBlackTreeNode *e) -> void {
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

  auto EraseCase0_A(RedBlackTree *t, RedBlackTreeNode *e) -> void {
    if (Left(Father(e)) == e)
      Father(e)->left = nullptr;
    else if (e->father->right == e)
      Father(e)->right = nullptr;
    delete e;
  }

  auto EraseCase0_B(RedBlackTree *t, RedBlackTreeNode *e) -> void {
    RedBlackTreeNode *child = Left(e)? Left(e) : Right(e);
    SwapIndex(child, e);

    // now "child" is father of "e", while "e" is child of "child"
    child->left = child->right = nullptr;
    delete e;
    EraseCase1(t, child);
  }

  auto EraseCase0_C(RedBlackTree *t, RedBlackTreeNode *e) -> void {
    RedBlackTreeNode *next = Next(e);
    e->index = Index(next);
    EraseCase0(t, next);
  }

  auto EraseCase1(RedBlackTree *t, RedBlackTreeNode *e) -> void {
    if (t->root != e) {
      assert(t->root != e);
      assert(Father(e) != nullptr);
      EraseCase2(t, e);
    }
  }

  auto EraseCase2(RedBlackTree *t, RedBlackTreeNode *e) -> void {
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

  auto EraseCase3(RedBlackTree *t, RedBlackTreeNode *e) -> void {
    if (Color(Father(e)) == BLACK and Color(Brother(e)) == BLACK
      and Color(Left(Brother(e))) == BLACK and Color(Right(Brother(e))) == BLACK) {
      Brother(e)->color = RED;
      EraseCase1(t, Father(e));
    } else {
      EraseCase4(t, e);
    }
  }

  auto EraseCase4(RedBlackTree *t, RedBlackTreeNode *e) -> void {
    if (Color(Brother(e)) == BLACK and Color(Father(e)) == RED
      and Color(Left(Brother(e))) == BLACK and Color(Right(Brother(e))) == BLACK) {
      SwapColor(Father(e), Brother(e));
    } else {
      EraseCase5(t, e);
    }
  }

  auto EraseCase5(RedBlackTree *t, RedBlackTreeNode *e) -> void {
    if (IsLeftChild(e) and Color(Brother(e)) == BLACK
      and Color(Left(Brother(e))) == RED and Color(Right(Brother(e))) == BLACK) {
      SwapColor(Brother(e), Left(Brother(e)));
      RotateRight(t, Brother(e));
    } else if (IsRightChild(e) and Color(Brother(e)) == BLACK
      and Color(Right(Brother(e))) == RED and Color(Left(Brother(e))) == BLACK) {
      SwapColor(Brother(e), Right(Brother(e)));
      RotateLeft(t, Brother(e));
    }
    EraseCase6(t, e);
  }

  auto EraseCase6(RedBlackTree *t, RedBlackTreeNode *e) -> void {
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

  auto SwapIndex(RedBlackTreeNode *a, RedBlackTreeNode *b) -> void {
    swap(a->index, b->index);
  }

  auto SwapColor(RedBlackTreeNode *a, RedBlackTreeNode *b) -> void {
    swap(a->color, b->color);
  }

  auto Color(RedBlackTreeNode *e) -> char {
      return e ? e->color : BLACK;
  }

  auto Index(RedBlackTreeNode *e) -> int {
    if (!e)
      return -1;
    return e->index;
  }

  auto Previous(RedBlackTreeNode *e) -> RedBlackTreeNode* {
    while (e->left)
      e = e->left;
    return e;
  }

  auto Next(RedBlackTreeNode *e) -> RedBlackTreeNode* {
    while (e->right)
      e = e->right;
    return e;
  }

  auto Father(RedBlackTreeNode *e) -> RedBlackTreeNode* {
    return e ? e->father : nullptr;
  }

  auto Uncle(RedBlackTreeNode *e) -> RedBlackTreeNode* {
    if (!GrandFather(e))
      return nullptr;
    if (GrandFather(e)->left == e)
      return GrandFather(e)->right;
    if (GrandFather(e)->right == e)
      return GrandFather(e)->left;
    return nullptr;
  }

  RedBlackTreeNode* GrandFather(RedBlackTreeNode *e)
  {
      if (!e)
          return nullptr;
      if (!e->father)
          return nullptr;
      return e->father->father;
  }
  RedBlackTreeNode* Brother(RedBlackTreeNode *e)
  {
      if (!e)
          return nullptr;
      if (!e->father)
          return nullptr;
      if (Left(Father(e)) == e)
          return Right(Father(e));
      if (Right(Father(e)) == e)
          return Left(Father(e));
      return nullptr;
  }
  bool IsLeftChild(RedBlackTreeNode *e)
  {
      if (!Father(e))
          return false;
      return Left(Father(e)) == e;
  }
  bool IsRightChild(RedBlackTreeNode *e)
  {
      if (!Father(e))
          return false;
      return Right(Father(e)) == e;
  }
  int ChildNumber(RedBlackTreeNode *e)
  {
      return e ? ((e->left ? 1 : 0) + (e->right ? 1 : 0)) : 0;
  }

  RedBlackTreeNode* Left(RedBlackTreeNode *e)
  {
      return e ? e->left : nullptr;
  }
  RedBlackTreeNode* Right(RedBlackTreeNode *e)
  {
      return e ? e->right : nullptr;
  }

}
