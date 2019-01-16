#pragma once
#include <vector>

struct SkNode {
  int value;

  // link[0] is lowest link, link[max_level-1] is highest link
  // pointer to next node
  SkNode **link;
};

struct SkList {
  int size;
  int max_level;
  SkNode head;
};

extern SkNode SKNIL;

#define is_nil(e) ((e) == &SKNIL)
#define not_nil(e) (!is_nil(e))
#define set_nil(e) ((e) = &SKNIL)

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

