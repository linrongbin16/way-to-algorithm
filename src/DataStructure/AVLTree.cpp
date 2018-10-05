#include "AvlTree.h"
#include <algorithm>
#include <cassert>
#include <utility>

AvlNode AVLNIL = {-1, -1, &AVLNIL, &AVLNIL, &AVLNIL};

#define is_nil(e) ((e) == &AVLNIL)
#define not_nil(e) ((e) != &AVLNIL)
#define set_nil(e) ((e) = &AVLNIL)
#define get_depth(left, right) (std::max((left)->depth, (right)->depth) + 1)

AvlNode::AvlNode() {
  value = -1;
  depth = -1;
  set_nil(left);
  set_nil(right);
  set_nil(father);
}

AvlNode::AvlNode(int v, int d, AvlNode *l, AvlNode *r, AvlNode *f) {
  value = v;
  depth = d;
  left = l;
  right = r;
  father = f;
}

static void AvlNodeFree(AvlNode *e) {
  if (is_nil(e))
    return;
  AvlNodeFree(e->left);
  AvlNodeFree(e->right);
  delete e;
}

static void LL(AvlNode **e) {
  AvlNode *e1;

  e1 = (*e)->left;
  (*e)->left = e1->right;
  e1->right = (*e);

  (*e)->depth = get_depth((*e)->left, (*e)->right);
  e1->depth = get_depth(e1->left, *e);
  (*e) = e1;
}

static void RR(AvlNode **e) {
  AvlNode *e1;

  e1 = (*e)->right;
  (*e)->right = e1->left;
  e1->left = (*e);

  (*e)->depth = std::max(NodeDepth((*e)->left), NodeDepth((*e)->right)) + 1;
  e1->depth = std::max(NodeDepth(e1->right), (*e)->depth) + 1;
  (*e) = e1;
}

static void LR(AvlNode **e) {
  RR(&((*e)->left));
  LL(e);
}

static void RL(AvlNode **e) {
  LL(&((*e)->right));
  RR(e);
}

static AvlNode *AvlNodeFind(AvlNode *e, int value) {
  if (is_nil(e)) {
    return &AVLNIL;
  }
  //二分查找
  if (e->value == value) {
    return e;
  } else if (e->value > value) {
    return AvlNodeFind(e->left, value);
  } else {
    return AvlNodeFind(e->right, value);
  }
}

static void InsertFixUp(AvlNode *e, int value) {
  //叶子节点处完成插入后，沿着父结点向上的每一个节点都需要检查是否满足平衡性，若不平衡则旋转
  if (e->left->depth - e->right->depth >= 2) {
    if (e->left->value > value) {
      LL(&e);
    } else {
      LR(&e);
    }
  }
  if (e->right->depth - e->left->depth >= 2) {
    if (e->right->value < value) {
      RR(&e);
    } else {
      RL(&e);
    }
  }
  e->depth = get_depth(e->left, e->right);
}

static void AvlNodeInsert(AvlNode **e, AvlNode *father, int value) {
  assert(e);
  assert(father);

  //利用二分查找找到适合value插入的位置e
  if (not_nil(*e)) {
    if ((*e)->value > value) {
      AvlNodeInsert(&(*e)->left, *e, value);

      //叶子节点处完成插入后，沿着父结点向上的每一个节点都需要检查是否满足平衡性，若不平衡则旋转
      InsertFixUp(*e, value);
    } else {
      AvlNodeInsert(&(*e)->right, *e, value);
      InsertFixUp(*e, value);
    }
    return;
  }

  // *e is nil
  *e = new AvlNode();
  set_nil((*e)->left);
  set_nil((*e)->right);
  (*e)->father = father;
  (*e)->value = value;
  (*e)->depth = get_depth((*e)->left, (*e)->right);
  InsertFixUp(*e, value);
}

static void AvlNodeErase(AvlNode **e, int value) {
  if ((*e)->value > value) {
    AvlNodeErase(&((*e)->left), value);

    if (NodeDepth((*e)->right) - NodeDepth((*e)->left) >= 2) {
      if ((*e)->right->left != NULL &&
          ((*e)->right->left->depth > (*e)->right->right->depth)) {
        RL(e);
      } else {
        RR(e);
      }
    }
  } else if ((*e)->value < value) {
    AvlNodeErase(&((*e)->right), value);

    if (NodeDepth((*e)->left) - NodeDepth((*e)->right) >= 2) {
      if ((*e)->right->left != NULL &&
          ((*e)->left->right->depth > (*e)->left->left->depth)) {
        LR(e);
      } else {
        LL(e);
      }
    }
  } else {
    /* (*e)->value == value*/
    if ((*e)->left && (*e)->right) {
      AvlNode *temp = (*e)->right;

      /*temp指向节点的右儿子*/
      /*找到中序遍历的后继节点*/
      while (temp->left != NULL)
        temp = temp->left;

      (*e)->value = temp->value; /*调整节点数据信息*/

      /*删除边缘节点*/
      AvlNodeErase(&((*e)->right), temp->value);
      if (NodeDepth((*e)->left) - NodeDepth((*e)->right) >= 2) {
        if ((*e)->left->right != NULL &&
            (NodeDepth((*e)->left->right) > NodeDepth((*e)->left->left))) {
          LR(e);
        } else {
          LL(e);
        }
      }
    } else {
      AvlNode *temp = (*e);
      if ((*e)->left == NULL)
        (*e) = (*e)->right;
      else if ((*e)->right == NULL)
        (*e) = (*e)->left;
      delete temp;
    }
  }

  if ((*e) == NULL)
    return;

  (*e)->depth = std::max(NodeDepth((*e)->left), NodeDepth((*e)->right)) + 1;
  return;
}

AvlTree *AvlTreeNew() {
  AvlTree *t = new AvlTree();
  set_nil(t->root);
  return t;
}

void AvlTreeFree(AvlTree *t) { AvlNodeFree(t->root); }

void AvlTreeInsert(AvlTree *t, int value) {
  if (is_nil(t->root)) {
    t->root = new AvlNode();
    set_nil(t->root->left);
    set_nil(t->root->right);
    t->root->value = value;
    t->root->depth = 0;
    return;
  }
  AvlNodeInsert(&(t->root), value);
}

AvlNode *AvlTreeFind(AvlTree *t, int value) {
  return AvlNodeFind(t->root, value);
}

void AvlTreeErase(AvlTree *t, int value) { AvlNodeErase(&(t->root), value); }

int AvlTreeDepth(AvlTree *t) {
  if (!t->root)
    return 0;
  return t->root->depth;
}

