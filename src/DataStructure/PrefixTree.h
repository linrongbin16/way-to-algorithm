#pragma once
#ifndef MAX
#define MAX 128
#endif
#ifndef CHILD_MAX
#define CHILD_MAX 26
#endif
#include <cassert>
#include <cstring>

struct PreNode {
  char letter;
  const char *word;
  /* next letter if exist */
  PreNode *child[CHILD_MAX];
};

// create prefix tree
PreNode *PrefixTreeNew();

// free prefix tree
void PrefixTreeFree(PreNode *root);

// insert word to prefix tree
void PrefixTreeInsert(PreNode *root, const char *word);

// find word from prefix tree
int PrefixTreeFind(PreNode *root, const char *word);

// erase word from prefix tree
void PrefixTreeErase(PreNode *root, const char *word);

