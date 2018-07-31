// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

#ifndef MAX
#define MAX 128
#endif
#include <cstring>
#include <cassert>


//
// interface
//

struct PrefixTree {
  char letter;
  const char *word;
  /* next letter if exist */
  PrefixTree *child[26];
};

PrefixTree *PrefixTreeNew();
void PrefixTreeFree(PrefixTree *t);
void PrefixTreeInsert(PrefixTree *t, const char *word);
int PrefixTreeFind(PrefixTree *t, const char *word);
void PrefixTreeErase(PrefixTree *t, const char *word);


//
// implement
//

namespace detail {

  int ChildIndex(char letter);

}

PrefixTree *PrefixTreeNew() {
  PrefixTree *t = new PrefixTree();
  if (!t) return nullptr;
  t->letter = (char)(-1);
  t->word = nullptr;
  memset(t->child, 0, sizeof(t->child));
  return t;
}

void PrefixTreeFree(PrefixTree *t) {
  if (!t)
    return;
  for (int i = 0; i < 26; i++)
    PrefixTreeFree(t->child[i]);
  delete t;
}

void PrefixTreeInsert(PrefixTree *t, const char *word) {
  int n = strlen(word);
  PrefixTree *e = t;
  for (int i = 0; i < n; i++) {
    int index = detail::ChildIndex(word[i]);
    if (e->child[index] == nullptr) {
      e->child[index] = new PrefixTree();
      // initialize e->child[index]
      PrefixTree *he = e->child[index];
      he->letter = word[i];
      he->word = nullptr;
      memset(he->child, 0, sizeof(he->child));
    }
    e = e->child[index];
    if (i == n - 1) {
      e->word = word;
    }
  }
}

int PrefixTreeFind(PrefixTree *t, const char *word) {
  PrefixTree *e = t;
  int n = strlen(word);
  for (int i = 0; i < n; i++) {
    int index = detail::ChildIndex(word[i]);
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

void PrefixTreeErase(PrefixTree *t, const char *word) {
  PrefixTree *e = t;
  int n = strlen(word);
  for (int i = 0; i < n; i++) {
    int index = detail::ChildIndex(word[i]);
    e = e->child[index];
    if (i == n-1) {
      e->word = nullptr;
      return;
    }
  }
}

namespace detail {

  int ChildIndex(char letter) {
    return (int)(letter - 'a');
  }

}
