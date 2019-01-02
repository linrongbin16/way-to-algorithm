#pragma once
#ifndef MAX
#define MAX 128
#endif
#ifndef CHILD_MAX
#define CHILD_MAX 26
#endif
#include <cassert>
#include <cstring>

struct PtNode {
  char letter;
  const char *word;
  PtNode *child[CHILD_MAX];
};

// create prefix tree
PtNode *PrefixTreeNew();

// free prefix tree
void PrefixTreeFree(PtNode *t);

// insert word to prefix tree
void PrefixTreeInsert(PtNode *t, const char *word);

// find word from prefix tree
int PrefixTreeFind(PtNode *t, const char *word);

// erase word from prefix tree
void PrefixTreeErase(PtNode *t, const char *word);

