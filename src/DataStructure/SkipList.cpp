#include "SkipList.h"
#include <cassert>
#include <cmath>
#include <string>

#define MIN_LEVEL 4
SkNode SKNIL = {-1, NULL};

static void SkNodeInit(SkNode *e, int value, int maxlv) {
  e->value = value;
  e->link = new SkNode *[maxlv];
  for (int i = 0; i < maxlv; i++) {
    set_nil(e->link[i]);
  }
}

SkList *SkipListNew(int node_count) {
  assert(node_count > 0);
  int maxlv = std::log2(node_count);

  SkList *l = new SkList();
  l->size = 0;
  l->max_level = (maxlv > MIN_LEVEL) ? maxlv : MIN_LEVEL;
  SkNodeInit(&l->head, -1, maxlv);
  return l;
}

void SkipListFree(SkList *l) {
  assert(l);
  SkNode *e = l->head.link[0], *p;
  while (not_nil(e)) {
    p = e;
    e = e->link[0];
    delete p->link;
    delete p;
  }
  delete l;
}

int SkipListSize(SkList *l) { return l->size; }

void SkipListInsert(SkList *l, int value) {
  SkNode *e = new SkNode();
  SkNodeInit(e, value, l->max_level);

  SkNode *p = l->head.link[l->max_level - 1];
  for (int i = l->max_level - 1; i >= 0; i--) {
    while (not_nil(p) && p->value > value) {
      p = p->link[i];
    }
  }
}

SkNode *SkipListFind(SkList *l, int value);

void SkipListErase(SkList *l, int value);

