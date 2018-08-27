#pragma once
#ifndef MAX
#define MAX 128
#endif
#include <cassert>
#include <cstring>

struct PrefixTree {
    char letter;
    const char *word;
    /* next letter if exist */
    PrefixTree *child[26];
};

// create prefix tree
PrefixTree *PrefixTreeNew();

// free prefix tree
void PrefixTreeFree(PrefixTree *t);

// insert word to prefix tree
void PrefixTreeInsert(PrefixTree *t, const char *word);

// find word from prefix tree
int PrefixTreeFind(PrefixTree *t, const char *word);

// erase word from prefix tree
void PrefixTreeErase(PrefixTree *t, const char *word);
