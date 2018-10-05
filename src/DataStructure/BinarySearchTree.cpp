#include "BinarySearchTree.h"
#include <cassert>
#include <cstddef>
#include <deque>
#include <iostream>
#include <vector>

BsNode BSNIL = {-1, &BSNIL, &BSNIL, &BSNIL};

#define is_nil(e) ((e) == &BSNIL)
#define not_nil(e) ((e) != &BSNIL)
#define set_nil(e) ((e) = &BSNIL)
#define is_leaf(e) (is_nil((e)->left) && is_nil((e)->right))

BsNode::BsNode() {
  value = -1;
  set_nil(left);
  set_nil(right);
  set_nil(father);
}

BsNode::BsNode(int v, BsNode *l, BsNode *r, BsNode *f) {
  value = v;
  left = l;
  right = r;
  father = f;
}

static void BsNodeInsert(BsNode **e, BsNode *father, int value) {
  assert(e);
  assert(father);
  if (is_nil(*e)) {
    *e = new BsNode();
    set_nil((*e)->left);
    set_nil((*e)->right);
    (*e)->father = father;
    (*e)->value = value;
    return;
  }
  //二分查找
  if ((*e)->value > value) {
    BsNodeInsert(&((*e)->left), *e, value);
  } else if ((*e)->value < value) {
    BsNodeInsert(&((*e)->right), *e, value);
  } else {
    // (*e)->value == value
    assert((*e)->value != value);
  }
}

static BsNode *BsNodeFind(BsNode *e, int value) {
  if (is_nil(e)) {
    return &BSNIL;
  }
  //二分查找
  if (e->value == value) {
    return e;
  } else if (e->value > value) {
    return BsNodeFind(e->left, value);
  } else {
    return BsNodeFind(e->right, value);
  }
}

static void BsNodeFree(BsNode *e) {
  if (is_nil(e)) {
    return;
  }
  BsNodeFree(e->left);
  BsNodeFree(e->right);
  delete e;
}

static void PreOrderBsNode(BsNode *e, std::vector<int> &result) {
  if (is_nil(e)) {
    return;
  }
  result.push_back(e->value);
  PreOrderBsNode(e->left, result);
  PreOrderBsNode(e->right, result);
}

static void PostOrderBsNode(BsNode *e, std::vector<int> &result) {
  if (is_nil(e)) {
    return;
  }
  PostOrderBsNode(e->left, result);
  PostOrderBsNode(e->right, result);
  result.push_back(e->value);
}

static void InOrderBsNode(BsNode *e, std::vector<int> &result) {
  if (is_nil(e)) {
    return;
  }
  InOrderBsNode(e->left, result);
  result.push_back(e->value);
  InOrderBsNode(e->right, result);
}

BinarySearchTree *BinarySearchTreeNew() {
  BinarySearchTree *t = new BinarySearchTree();
  set_nil(t->root);
  return t;
}

void BinarySearchTreeFree(BinarySearchTree *t) {
  assert(t);
  BsNodeFree(t->root);
  delete t;
}

void BinarySearchTreeInsert(BinarySearchTree *t, int value) {
  BsNodeInsert(&(t->root), t->root, value);
}

BsNode *BinarySearchTreeFind(BinarySearchTree *t, int value) {
  return BsNodeFind(t->root, value);
}

static BsNode *BsNodeNext(BsNode *e) {
  if (is_nil(e->right)) {
    return &BSNIL;
  }
  BsNode *next = e->right;
  while (not_nil(next->left)) {
    next = next->left;
  }
  return next;
}

static BsNode *BsNodePrev(BsNode *e) { return e->left; }

void BinarySearchTreeErase(BinarySearchTree *t, int value) {
  assert(not_nil(t->root));
  BsNode *e = BsNodeFind(t->root, value);
  assert(not_nil(e));

  if (not_nil(e->right)) {
    //用后继节点next代替e

    BsNode *next = BsNodeNext(e);
    e->value = next->value;
    if (next->father->left == next) {
      next->father->left = next->right;
    } else if (next->father->right == next) {
      next->father->right = next->right;
    } else {
      assert(next->father->left != next && next->father->right != next);
    }
    next->right->father = next->father;
    delete next;
  } else if (not_nil(e->left)) {
    BsNode *prev = BsNodePrev(e);
    e->value = prev->value;
    e->left = prev->left;
    if (not_nil(e->left)) {
      e->left->father = e;
    }
    e->right = prev->right;
    if (not_nil(e->right)) {
      e->right->father = e;
    }
    delete prev;
  } else {
    //直接删除叶子节点e

    if (not_nil(e->father)) {
      if (e->father->left == e) {
        set_nil(e->father->left);
      } else if (e->father->right == e) {
        set_nil(e->father->right);
      } else {
        assert(e->father->left != e && e->father->right != e);
      }
    } else {
      set_nil(t->root);
    }
    delete e;
  }
}

std::vector<int> BinarySearchTreePreOrder(BinarySearchTree *t) {
  std::vector<int> result;
  PreOrderBsNode(t->root, result);
  return result;
}

std::vector<int> BinarySearchTreePostOrder(BinarySearchTree *t) {
  std::vector<int> result;
  PostOrderBsNode(t->root, result);
  return result;
}

std::vector<int> BinarySearchTreeInOrder(BinarySearchTree *t) {
  std::vector<int> result;
  InOrderBsNode(t->root, result);
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

