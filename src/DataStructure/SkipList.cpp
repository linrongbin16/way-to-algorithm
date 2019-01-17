#include "SkipList.h"
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <string>

#define MAX_LEVEL 16

static SkNode *SkNodeNew(int value, int maxlv) {
  SkNode *e = new SkNode();
  e->value = value;
  e->forward = new SkNode *[maxlv];
  for (int i = 0; i < maxlv; i++) {
    e->forward[i] = NULL;
  }
  return e;
}

static int RandomLevel() {
  int level = 1;
  while (rand() / RAND_MAX / 2 && level < MAX_LEVEL) {
    level++;
  }
  return level;
}

SkList *SkipListNew(int node_count) {
  assert(node_count > 0);

  SkList *l = new SkList();
  l->size = 0;
  l->level = 1;
  l->head = new SkNode();
  l->head->value = 0;
  l->head->forward = new SkNode *[MAX_LEVEL];
  for (int i = 0; i < MAX_LEVEL; i++) {
    l->head->forward[i] = l->head;
  }
  return l;
}

void SkipListFree(SkList *l) {
  assert(l);
  SkNode *e = l->head, *p;
  while (e) {
    p = e;
    e = e->forward[0];
    delete[] p->forward;
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
  SkNode *update[MAX_LEVEL + 1];
  SkNode *e = l->head;

  for (int i = l->level; i >= 1; i--) {
    while (e->forward[i]->value < value) {
      e = e->forward[i];
    }
    update[i] = e;
  }
  e = e->forward[1];

  // already exist
  if (value == e->value) {
    e->value = value;
    return;
  }

  int n = RandomLevel();
  if (n > l->level) {
    for (int i = l->level + 1; i <= n; i++) {
      update[i] = l->head;
    }
    l->level = n;
  }
  e = new SkNode();
  e->value = value;
  e->forward = new SkNode *[n + 1];
  for (int i = 1; i <= n; i++) {
    e->forward[i] = update[i]->forward[i];
    update[i]->forward[i] = e;
  }
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
      delete[] e->forward;
      delete e;
      std::memset(l->head, 0, l->level * sizeof(SkNode *));
      l->size = 0;
    }
    return;
  }

  SkNode *e = HighestHead(l);
  for (int i = l->level - 1; i >= 0; i--) {
    if (e->forward[i]->value == value) {
      SkNode *p = e->forward[i];
      for (int j = i; j >= 0; j--) {
        e->forward[j] = p->forward[j];
      }
      delete[] p->forward;
      delete p;
      return;
    }
    while (e->forward[i]->value < value) {
      e = e->forward[i];
    }
  }
}

SkNode *SkipListFind(SkList *l, int value) {
  assert(l);
  assert(value >= 0);

  SkNode *e = l->head;
  for (int i = l->level; i >= 1; i--) {
    while (e->forward[i]->value < value) {
      e = e->forward[i];
    }
  }

  if (e->forward[1]->value == value) {
    return e->forward[1];
  } else {
    return NULL;
  }
}

