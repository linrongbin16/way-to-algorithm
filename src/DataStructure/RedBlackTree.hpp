// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

// TODO: fix bugs

#include <algorithm>
#include <utility>
#include <cassert>
#define RED     'R'
#define BLACK   'B'


//
// interface
//

struct Node {
  /* 节点颜色 */
  char color;
  /* 节点值 */
  int index;
  Node *left;
  Node *right;
  Node *father;
};

struct RedBlackTree {
  Node *root;
};

RedBlackTree *RedBlackTreeNew();
void RedBlackTreeFree(RedBlackTree *t);
void RedBlackTreeInsert(RedBlackTree *t, int index);
int RedBlackTreeFind(RedBlackTree *t, int index);
void RedBlackTreeErase(RedBlackTree *t, int index);


//
// implement
//

namespace detail {

  char Color(Node *e);
  int Index(Node *e);
  Node *Previous(Node *e);
  Node *Next(Node *e);
  Node *Father(Node *e);
  Node *Left(Node *e);
  Node *Right(Node *e);
  auto Uncle(Node *e) -> Node*;
  auto GrandFather(Node *e) -> Node*;
  auto Brother(Node *e) -> Node*;
  auto IsLeftChild(Node *e) -> bool;
  auto IsRightChild(Node *e) -> bool;
  auto ChildNumber(Node *e) -> int;
  auto SwapIndex(Node *a, Node *b) -> void;
  auto SwapColor(Node *a, Node *b) -> void;

  auto NodeFree(Node *e) -> void;
  auto NodeFind(RedBlackTree *t, int index, Node **father) -> Node*;
  auto InsertCase1(RedBlackTree *t, Node *e) -> void;
  auto InsertCase2(RedBlackTree *t, Node *e) -> void;
  auto InsertCase3(RedBlackTree *t, Node *e) -> void;
  auto InsertCase4(RedBlackTree *t, Node *e) -> void;
  auto InsertCase5(RedBlackTree *t, Node *e) -> void;

  auto EraseCase0(RedBlackTree *t, Node *e) -> void;
  auto EraseCase0_A(RedBlackTree *t, Node *e) -> void;
  auto EraseCase0_B(RedBlackTree *t, Node *e) -> void;
  auto EraseCase0_C(RedBlackTree *t, Node *e) -> void;
  auto EraseCase1(RedBlackTree *t, Node *e) -> void;
  auto EraseCase2(RedBlackTree *t, Node *e) -> void;
  auto EraseCase3(RedBlackTree *t, Node *e) -> void;
  auto EraseCase4(RedBlackTree *t, Node *e) -> void;
  auto EraseCase5(RedBlackTree *t, Node *e) -> void;
  auto EraseCase6(RedBlackTree *t, Node *e) -> void;

  auto RotateLeft(RedBlackTree *t, Node *e) -> void;
  auto RotateRight(RedBlackTree *t, Node *e) -> void;

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
  Node *e = new Node();
  Node *father = nullptr;
  Node *tmp;
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
  Node *e = detail::NodeFind(t, index, nullptr);
  assert(e);
  detail::EraseCase0(t, e);
}

namespace detail {

  auto NodeFree(Node *e) -> void {
    if (!e)
      return;
    NodeFree(detail::Left(e));
    NodeFree(detail::Right(e));
    delete e;
  }

  auto RotateLeft(RedBlackTree *t, Node *e) -> void {
    Node *p = e;
    Node *q = detail::Right(e);
    Node *father = detail::Father(e);

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

  auto RotateRight(RedBlackTree *t, Node *e) -> void {
    Node *p = e;
    Node *q = Left(e); /* can't be nullptr */
    Node *father = Father(p);
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

  auto NodeFind(RedBlackTree *t, int index, Node **father) -> Node* {
    Node *cur = t->root;
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

  auto InsertCase1(RedBlackTree *t, Node *e) -> void {
    if (t->root == nullptr) {
      assert(t->root == nullptr);
      assert(Father(e) == nullptr);
      e->color = BLACK;
      t->root = e;
    } else {
      InsertCase2(t, e);
    }
  }

  auto InsertCase2(RedBlackTree *t, Node *e) -> void {
    if (Color(Father(e)) == RED) {
      InsertCase3(t, e);
    }
  }

  auto InsertCase3(RedBlackTree *t, Node *e) -> void {
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

  auto InsertCase4(RedBlackTree *t, Node *e) -> void {
    if (IsRightChild(e) && IsLeftChild(Father(e))) {
      RotateLeft(t, Father(e));
      e = Left(e);
    } else if (IsLeftChild(e) && IsRightChild(Father(e))) {
      RotateRight(t, Father(e));
      e = Right(e);
    }
    InsertCase5(t, e);
  }

  auto InsertCase5(RedBlackTree *t, Node *e) -> void {
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

  auto EraseCase0(RedBlackTree *t, Node *e) -> void {
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

  auto EraseCase0_A(RedBlackTree *t, Node *e) -> void {
    if (Left(Father(e)) == e)
      Father(e)->left = nullptr;
    else if (e->father->right == e)
      Father(e)->right = nullptr;
    delete e;
  }

  auto EraseCase0_B(RedBlackTree *t, Node *e) -> void {
    Node *child = Left(e)? Left(e) : Right(e);
    SwapIndex(child, e);

    // now "child" is father of "e", while "e" is child of "child"
    child->left = child->right = nullptr;
    delete e;
    EraseCase1(t, child);
  }

  auto EraseCase0_C(RedBlackTree *t, Node *e) -> void {
    Node *next = Next(e);
    e->index = Index(next);
    EraseCase0(t, next);
  }

  auto EraseCase1(RedBlackTree *t, Node *e) -> void {
    if (t->root != e) {
      assert(t->root != e);
      assert(Father(e) != nullptr);
      EraseCase2(t, e);
    }
  }

  auto EraseCase2(RedBlackTree *t, Node *e) -> void {
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

  auto EraseCase3(RedBlackTree *t, Node *e) -> void {
    if (Color(Father(e)) == BLACK && Color(Brother(e)) == BLACK
      && Color(Left(Brother(e))) == BLACK && Color(Right(Brother(e))) == BLACK) {
      Brother(e)->color = RED;
      EraseCase1(t, Father(e));
    } else {
      EraseCase4(t, e);
    }
  }

  auto EraseCase4(RedBlackTree *t, Node *e) -> void {
    if (Color(Brother(e)) == BLACK 
		&& Color(Father(e)) == RED
		&& Color(Left(Brother(e))) == BLACK 
		&& Color(Right(Brother(e))) == BLACK) {
      SwapColor(Father(e), Brother(e));
    } else {
      EraseCase5(t, e);
    }
  }

  auto EraseCase5(RedBlackTree *t, Node *e) -> void {
	  if (IsLeftChild(e) 
		  && Color(Brother(e)) == BLACK
		  && Color(Left(Brother(e))) == RED
		  && Color(Right(Brother(e))) == BLACK) {
		  SwapColor(Brother(e), Left(Brother(e)));
		  RotateRight(t, Brother(e));
	  } else if (IsRightChild(e) 
		  && Color(Brother(e)) == BLACK
		  && Color(Right(Brother(e))) == RED
		  && Color(Left(Brother(e))) == BLACK) {
		  SwapColor(Brother(e), Right(Brother(e)));
		  RotateLeft(t, Brother(e));
	  }
	  EraseCase6(t, e);
  }

  auto EraseCase6(RedBlackTree *t, Node *e) -> void {
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

  auto SwapIndex(Node *a, Node *b) -> void {
    std::swap(a->index, b->index);
  }

  auto SwapColor(Node *a, Node *b) -> void {
    std::swap(a->color, b->color);
  }

  auto Color(Node *e) -> char {
      return e ? e->color : BLACK;
  }

  auto Index(Node *e) -> int {
    if (!e)
      return -1;
    return e->index;
  }

  auto Previous(Node *e) -> Node* {
    while (e->left)
      e = e->left;
    return e;
  }

  auto Next(Node *e) -> Node* {
    while (e->right)
      e = e->right;
    return e;
  }

  auto Father(Node *e) -> Node* {
    return e ? e->father : nullptr;
  }

  auto Uncle(Node *e) -> Node* {
    if (!GrandFather(e))
      return nullptr;
    if (GrandFather(e)->left == e)
      return GrandFather(e)->right;
    if (GrandFather(e)->right == e)
      return GrandFather(e)->left;
    return nullptr;
  }

  Node* GrandFather(Node *e)
  {
      if (!e)
          return nullptr;
      if (!e->father)
          return nullptr;
      return e->father->father;
  }
  Node* Brother(Node *e)
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
  bool IsLeftChild(Node *e)
  {
      if (!Father(e))
          return false;
      return Left(Father(e)) == e;
  }
  bool IsRightChild(Node *e)
  {
      if (!Father(e))
          return false;
      return Right(Father(e)) == e;
  }
  int ChildNumber(Node *e)
  {
      return e ? ((e->left ? 1 : 0) + (e->right ? 1 : 0)) : 0;
  }

  Node* Left(Node *e)
  {
      return e ? e->left : nullptr;
  }
  Node* Right(Node *e)
  {
      return e ? e->right : nullptr;
  }

}
