#pragma once
#include <algorithm>
#include <cassert>
#include <utility>

struct SkNode {
  int value;
};

SkNode *SkipListNew();
void SkipListFree(SlNode *l);
void SkipListInsert(SlNode *l, int value);
SlNode *SkipListFind(SlNode *l, int value);
void SkipListErase(SlNode *l, int value);

