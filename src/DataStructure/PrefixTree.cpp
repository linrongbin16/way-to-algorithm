#include "PrefixTree.h"
#include <cassert>
#include <cstring>

static int ChildIndex(char letter) { return (int)(letter - 'a'); }

PreNode *PrefixTreeNew() {
  PreNode *t = new PreNode();
  if (!t)
    return NULL;
  t->letter = (char)(-1);
  t->word = NULL;
  memset(t->child, 0, sizeof(t->child));
  return t;
}

void PrefixTreeFree(PreNode *t) {
  if (!t)
    return;
  for (int i = 0; i < 26; i++)
    PrefixTreeFree(t->child[i]);
  delete t;
}

void PrefixTreeInsert(PreNode *t, const char *word) {
  int n = strlen(word);
  PreNode *e = t;
  for (int i = 0; i < n; i++) {
    int index = ChildIndex(word[i]);
    if (e->child[index] == NULL) {
      e->child[index] = new PreNode();
      // initialize e->child[index]
      PreNode *he = e->child[index];
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

int PrefixTreeFind(PreNode *t, const char *word) {
  PreNode *e = t;
  int n = strlen(word);
  for (int i = 0; i < n; i++) {
    int index = ChildIndex(word[i]);
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

void PrefixTreeErase(PreNode *t, const char *word) {
  PreNode *e = t;
  int n = strlen(word);
  for (int i = 0; i < n; i++) {
    int index = ChildIndex(word[i]);
    e = e->child[index];
    if (i == n - 1) {
      e->word = NULL;
      return;
    }
  }
}

