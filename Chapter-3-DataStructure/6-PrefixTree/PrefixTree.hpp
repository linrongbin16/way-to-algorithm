#ifndef PREFIX_TREE_HPP
#define PREFIX_TREE_HPP 1

#include <string.h>
#ifndef MAX
#define MAX 64
#endif

struct PrefixTree {
    char letter;
    const char *word;
    /* next letter if exist */
    PrefixTree *child[26];
};

int ChildIndex(char letter)
{
    return (int)(letter - 'a');
}

PrefixTree *PrefixTreeNew()
{
    PrefixTree *t = new PrefixTree();
    if (!t)
        return NULL;
    t->letter = (char)-1;
    t->word = NULL;
    memset(t->child, 0, sizeof(t->child));
    return t;
}

void PrefixTreeInsert(PrefixTree *t, const char *word)
{
    int n = strlen(word);
    PrefixTree *e = t;
    for (int i = 0; i < n; i++) {
        int index = ChildIndex(word[i]);
        if (e->child[index] == NULL) {
            e->child[index] = new PrefixTree();
        }
        e = e->child[index];
        e->letter = word[i];
        e->word = NULL;
        memset(e->child, 0, sizeof(e->child));
        if (i == n - 1 && e->word == NULL) {
            e->word = word;
        }
    }
}
int PrefixTreeFind(PrefixTree *t, const char *word)
{
    PrefixTree *e = t;
    int n = strlen(word);
    for (int i = 0; i < n; i++) {
        int index = ChildIndex(word[i]);
        e = e->child[index];
        if (i == n - 1 && strcmp(e->word, word) == 0)
            return 1;
    }
    return 0;
}
void PrefixTreeErase(PrefixTree *t, const char *word)
{
    //我们不处理该字符串str不存在的异常情况，认为该字符串str一定存在并且删除
    PrefixTree *e = t;
    int n = strlen(word);
    for (int i = 0; i < n; i++) {
        int index = ChildIndex(word[i]);
        e = e->child[index];
        if (i == n-1) {
            e->word = NULL;
            return;
        }
    }
}


#endif
