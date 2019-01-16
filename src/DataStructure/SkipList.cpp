#include "SkipList.h"
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <string>

#define MIN_LEVEL 4
#define P 0.5F

static SkNode *SkNodeNew(int value, int maxlv) {
  SkNode *e = new SkNode();
  e->value = value;
  e->link = new SkNode *[maxlv];
  for (int i = 0; i < maxlv; i++) {
    e->link[i] = NULL;
  }
  return e;
}

SkList *SkipListNew(int node_count) {
  assert(node_count > 0);
  int maxlv = std::log2(node_count) + 1;

  SkList *l = new SkList();
  l->size = 0;
  l->max_level = (maxlv > MIN_LEVEL) ? maxlv : MIN_LEVEL;
  l->head = new SkNode *[maxlv];
  for (int i = 0; i < maxlv; i++) {
    l->head[i] = NULL;
  }
  return l;
}

void SkipListFree(SkList *l) {
  assert(l);
  SkNode *e = l->head[0], *p;
  while (e) {
    p = e;
    e = e->link[0];
    delete[] p->link;
    delete p;
  }
  delete l;
}

int SkipListSize(SkList *l) {
  assert(l);
  return l->size;
}

void SkipListInsert(SkList *l, int value) {
  assert(l);
  assert(value >= 0);
  SkNode *e = SkNodeNew(value, l->max_level);
  int n = 0;
  for (int i = 0; i < l->max_level; i++) {
    if (((float)rand() / (float)RAND_MAX) < P) {
      break;
    }
    n++;
  }

  // 头节点为空或链表第一个值（最小值）比value大
  // 直接将value插入头节点后

  if (!l->head[0] || l->head[0]->value > value) {
    for (int i = 0; i < n; i++) {
      e->link[i] = l->head[i];
      l->head[i] = e;
    }
    l->size++;
    return;
  }

  SkNode *p = l->head[l->max_level - 1];
  for (int i = l->max_level - 1; i >= 0; i--) {
    while (p->link[i] && (p->link[i]->value < value)) {
      p = p->link[i];
    }
  }

  for (int i = 0; i < n; i++) {
    e->link[i] = p->link[i];
    p->link[i] = e;
  }
  l->size++;
}

void SkipListErase(SkList *l, int value) {
  assert(l);
  assert(value >= 0);

  if (l->size <= 0) {
    return;
  }
  if (l->size == 1) {
    if (l->head[0]->value == value) {
      SkNode *e = l->head[0];
      delete[] e->link;
      delete e;
      std::memset(l->head, 0, l->max_level * sizeof(SkNode *));
      l->size = 0;
    }
    return;
  }

  SkNode *e = l->head[l->max_level - 1];
  for (int i = l->max_level - 1; i >= 0; i--) {
    if (e->link[i]->value == value) {
      SkNode *p = e->link[i];
      for (int j = i; j >= 0; j--) {
        e->link[j] = p->link[j];
      }
      delete[] p->link;
      delete p;
      return;
    }
    while (e->link[i]->value < value) {
      e = e->link[i];
    }
  }
}

SkNode *SkipListFind(SkList *l, int value) {
  assert(l);
  assert(value >= 0);

  if (l->size <= 0) {
    return NULL;
  }
  if (l->size == 1) {
    return (l->head[0]->value == value) ? l->head[0] : NULL;
  }

  SkNode *e = l->head[l->max_level - 1];
  for (int i = l->max_level - 1; i >= 0; i--) {
    if (e->value == value) {
      return e;
    }
    while (e->value < value) {
      e = e->link[i];
    }
  }
  return NULL;
}

