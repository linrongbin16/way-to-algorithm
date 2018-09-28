#include "PrefixTree.h"
#include <cassert>
#include <cstring>

static int ChildIndex(char letter) { return (int)(letter - 'a'); }

PreNode *PrefixTreeNew() {
  PreNode *root = new PreNode();
  if (!root)
    return NULL;
  root->letter = (char)(-1);
  root->word = NULL;
  memset(root->child, 0, sizeof(root->child));
  return root;
}

void PrefixTreeFree(PreNode *root) {
  if (!root)
    return;
  for (int i = 0; i < 26; i++)
    PrefixTreeFree(root->child[i]);
  delete root;
}

void PrefixTreeInsert(PreNode *root, const char *word) {
  int n = strlen(word);
  PreNode *e = root;
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

int PrefixTreeFind(PreNode *root, const char *word) {
  PreNode *e = root;
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

void PrefixTreeErase(PreNode *root, const char *word) {
  PreNode *e = root;
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

