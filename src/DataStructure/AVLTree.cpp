#include "AvlTree.h"
#include <algorithm>
#include <cassert>
#include <utility>

AvlNode AVLNIL = {-1, -1, &AVLNIL, &AVLNIL, &AVLNIL};

#define is_nil(e) ((e) == &AVLNIL)
#define not_nil(e) ((e) != &AVLNIL)
#define set_nil(e) ((e) = &AVLNIL)
#define get_height(left, right) (std::max((left)->height, (right)->height) + 1)

AvlNode::AvlNode() {
  value = -1;
  height = -1;
  set_nil(left);
  set_nil(right);
  set_nil(father);
}

AvlNode::AvlNode(int v, int h, AvlNode *l, AvlNode *r, AvlNode *f) {
  value = v;
  height = h;
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

// left left case
// right-rotate
static void LL(AvlNode **e) {
  AvlNode *p;

  p = (*e)->left;
  (*e)->left = p->right;
  p->right = (*e);

  (*e)->height = get_height((*e)->left, (*e)->right);
  p->height = get_height(p->left, *e);
  (*e) = p;
}

// right right case
// left-rotate
static void RR(AvlNode **e) {
  AvlNode *p;

  p = (*e)->right;
  (*e)->right = p->left;
  p->left = (*e);

  (*e)->height = get_height((*e)->left, (*e)->right);
  p->height = get_height(p->right, *e);
  (*e) = p;
}

// left right case
// left-rotate, right-rotate -> RR, LL
static void LR(AvlNode **e) {
  RR(&((*e)->left));
  LL(e);
}

// right left case
// right-rotate, left-rotate -> LL, RR
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

static void AvlNodeInsert(AvlNode **e, AvlNode *father, int value) {
  assert(e);
  assert(father);

  if (is_nil(*e)) {
    // *e is nil
    *e = new AvlNode();
    set_nil((*e)->left);
    set_nil((*e)->right);
    (*e)->father = father;
    (*e)->value = value;
    (*e)->height = get_height((*e)->left, (*e)->right);
    return;
  }

  //利用二分查找找到适合value插入的位置e

  if ((*e)->value > value) {
    AvlNodeInsert(&(*e)->left, *e, value);
  } else if ((*e)->value < value) {
    AvlNodeInsert(&(*e)->right, *e, value);
  } else {
    // (*e)->value == value
    assert((*e)->value != value);
  }

  //叶子节点处完成插入后，沿着父结点向上的每一个节点都需要检查是否满足平衡性，若不平衡则旋转
  //递归函数可以对每个节点*e在插入后进行检查

  (*e)->height = get_height((*e)->left, (*e)->right);
  int factor = (*e)->left->height - (*e)->right->height;
  if (factor > 1 && (*e)->left->value > value) {
    LL(e);
  }
  if (factor < -1 && (*e)->right->value < value) {
    RR(e);
  }
  if (factor > 1 && (*e)->left->value < value) {
    LR(e);
  }
  if (factor < -1 && (*e)->right->value > value) {
    RL(e);
  }
}

static void AvlNodeErase(AvlNode **e, int value) {
  if ((*e)->value == value) {
  }

  if ((*e)->value > value) {
    AvlNodeErase(&((*e)->left), value);

    if (NodeDepth((*e)->right) - NodeDepth((*e)->left) >= 2) {
      if ((*e)->right->left != NULL &&
          ((*e)->right->left->height > (*e)->right->right->height)) {
        RL(e);
      } else {
        RR(e);
      }
    }
  } else if ((*e)->value < value) {
    AvlNodeErase(&((*e)->right), value);

    if (NodeDepth((*e)->left) - NodeDepth((*e)->right) >= 2) {
      if ((*e)->right->left != NULL &&
          ((*e)->left->right->height > (*e)->left->left->height)) {
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

  (*e)->height = std::max(NodeDepth((*e)->left), NodeDepth((*e)->right)) + 1;
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
    t->root->height = 0;
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
  return t->root->height;
}

