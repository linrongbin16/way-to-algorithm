#pragma once
#include <vector>

struct SkNode {
  int value;

  // forward[0] is lowest link, forward[max_level-1] is highest link
  // pointer to next node
  SkNode **forward;
};

struct SkList {
  int size;
  int level;
  SkNode *head;
};

// create skip list
SkList *SkipListNew(int node_count);

// delete skip list
void SkipListFree(SkList *l);

// skip list size
int SkipListSize(SkList *l);

// insert value to skip list
void SkipListInsert(SkList *l, int value);

// find value in skip list
SkNode *SkipListFind(SkList *l, int value);

// erase value from skip list
void SkipListErase(SkList *l, int value);

