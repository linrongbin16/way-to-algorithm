#include "PrefixTree.h"
#include <cassert>
#include <cstring>

#define child_index(c) ((int)(c) - (int)'a')

PtNode *PrefixTreeNew() {
  PtNode *t = new PtNode();
  t->letter = (char)(-1);
  t->word = NULL;
  memset(t->child, 0, sizeof(t->child));
  return t;
}

void PrefixTreeFree(PtNode *t) {
  if (!t)
    return;
  for (int i = 0; i < 26; i++)
    PrefixTreeFree(t->child[i]);
  delete t;
}

void PrefixTreeInsert(PtNode *t, const char *word) {
  int n = strlen(word);
  PtNode *e = t;
  for (int i = 0; i < n; i++) {
    int index = child_index(word[i]);
    if (e->child[index] == NULL) {
      e->child[index] = new PtNode();
      // initialize e->child[index]
      PtNode *he = e->child[index];
      he->letter = word[i];
      he->word = NULL;
      memset(he->child, 0, sizeof(he->child));
    }
    e = e->child[index];
    if (i == n - 1) {
      e->word = word;
    }
  }
}

int PrefixTreeFind(PtNode *t, const char *word) {
  PtNode *e = t;
  int n = strlen(word);
  for (int i = 0; i < n; i++) {
    int index = child_index(word[i]);
    if (!e)
      return 0;
    e = e->child[index];
    if (!e)
      return 0;
    if (i == n - 1 && e->word && strcmp(e->word, word) == 0)
      return 1;
  }
  return 0;
}

void PrefixTreeErase(PtNode *t, const char *word) {
  PtNode *e = t;
  int n = strlen(word);
  for (int i = 0; i < n; i++) {
    int index = child_index(word[i]);
    e = e->child[index];
    if (i == n - 1) {
      e->word = NULL;
      return;
    }
  }
}

