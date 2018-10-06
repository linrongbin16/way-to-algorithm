#include "BinarySearchTree.h"
#include <cassert>
#include <cstddef>
#include <deque>
#include <utility>
#include <vector>

BsNode BSNIL = {-1, &BSNIL, &BSNIL};

#define is_nil(e) ((e) == &BSNIL)
#define not_nil(e) ((e) != &BSNIL)
#define set_nil(e) ((e) = &BSNIL)
#define is_leaf(e) (is_nil((e)->left) && is_nil((e)->right))

BsNode::BsNode() {
  value = -1;
  set_nil(left);
  set_nil(right);
}

BsNode::BsNode(int v, BsNode *l, BsNode *r) {
  value = v;
  left = l;
  right = r;
}

static BsNode *Insert(BsNode *e, int value) {
  assert(e);
  if (is_nil(e)) {
    BsNode *p = new BsNode();
    set_nil(p->left);
    set_nil(p->right);
    p->value = value;
    return p;
  }
  //二分查找
  if (e->value > value) {
    e->left = Insert(e->left, value);
  } else if (e->value < value) {
    e->right = Insert(e->right, value);
  } else {
    assert(e->value != value);
  }
  return e;
}

static BsNode *Find(BsNode *e, int value) {
  if (is_nil(e)) {
    return &BSNIL;
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

static void Free(BsNode *e) {
  if (is_nil(e)) {
    return;
  }
  Free(e->left);
  Free(e->right);
  delete e;
}

static void PreOrder(BsNode *e, std::vector<int> &result) {
  if (is_nil(e)) {
    return;
  }
  result.push_back(e->value);
  PreOrder(e->left, result);
  PreOrder(e->right, result);
}

static void PostOrder(BsNode *e, std::vector<int> &result) {
  if (is_nil(e)) {
    return;
  }
  PostOrder(e->left, result);
  PostOrder(e->right, result);
  result.push_back(e->value);
}

static void InOrder(BsNode *e, std::vector<int> &result) {
  if (is_nil(e)) {
    return;
  }
  InOrder(e->left, result);
  result.push_back(e->value);
  InOrder(e->right, result);
}

BinarySearchTree *BinarySearchTreeNew() {
  BinarySearchTree *t = new BinarySearchTree();
  set_nil(t->root);
  return t;
}

void BinarySearchTreeFree(BinarySearchTree *t) {
  assert(t);
  Free(t->root);
  delete t;
}

void BinarySearchTreeInsert(BinarySearchTree *t, int value) {
  assert(t);
  assert(value >= 0);
  t->root = Insert(t->root, value);
}

BsNode *BinarySearchTreeFind(BinarySearchTree *t, int value) {
  assert(t);
  assert(value >= 0);
  return Find(t->root, value);
}

static BsNode *Next(BsNode *e) {
  if (is_nil(e->right)) {
    return &BSNIL;
  }
  BsNode *next = e->right;
  while (not_nil(next->left)) {
    next = next->left;
  }
  return next;
}

static BsNode *Erase(BsNode *e, int value) {
  assert(value >= 0);
  assert(not_nil(e));

  if (e->value > value) {
    e->left = Erase(e->left, value);
  } else if (e->value < value) {
    e->right = Erase(e->right, value);
  } else {
    // e->value == value

    if (is_nil(e->left) || is_nil(e->right)) {
      BsNode *temp = not_nil(e->left) ? e->left : e->right;
      if (is_nil(temp)) {
        // 若e没有孩子节点则直接删除

        temp = e;
        set_nil(e);
        delete temp;
      } else {
        // 若e只有一个孩子节点则直接用该孩子节点替换e

        std::swap(e, temp);
        delete temp;
      }
    } else {
      // not_nil(e->left) && not_nil(e->right)

      BsNode *next = Next(e);
      e->value = next->value;
      e->right = Erase(e->right, next->value);
    }
  }

  return e;
}

void BinarySearchTreeErase(BinarySearchTree *t, int value) {
  assert(t);
  assert(not_nil(t->root));
  assert(value >= 0);
  t->root = Erase(t->root, value);
}

std::vector<int> BinarySearchTreePreOrder(BinarySearchTree *t) {
  std::vector<int> result;
  PreOrder(t->root, result);
  return result;
}

std::vector<int> BinarySearchTreePostOrder(BinarySearchTree *t) {
  std::vector<int> result;
  PostOrder(t->root, result);
  return result;
}

std::vector<int> BinarySearchTreeInOrder(BinarySearchTree *t) {
  std::vector<int> result;
  InOrder(t->root, result);
  return result;
}

std::vector<int> BinarySearchTreeLevelOrder(BinarySearchTree *t) {
  std::vector<int> result;
  std::deque<BsNode *> q;
  q.push_back(t->root);

  while (!q.empty()) {
    BsNode *e = q.front();
    q.pop_front();
    if (is_nil(e)) {
      continue;
    }
    result.push_back(e->value);
    q.push_back(e->left);
    q.push_back(e->right);
  }
  return result;
}

