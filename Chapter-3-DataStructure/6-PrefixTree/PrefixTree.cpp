#include "PrefixTree.hpp"
#include <iostream>
#include <assert.h>
using namespace std;

const char *dict1[] = {
    "hello",
    "world",
    "happy",
    "ok",
    "boy",
    "dog",
    "look",
    "finally",
    "ppppppppp",
    "thisisateststring",
    "no",
    "dontworry",
    "future",
    "life",
    "is",
    "a",
    "dream",
    NULL,
};

const char *dict2[] = {
    "none",
    "noworry",
    "feature",
    "live",
    "isnt",
    "aream",
    "d",
    NULL,
};

int main()
{
    PrefixTree *t;
    
    //part 1
    t = PrefixTreeNew();
    for (int i = 0; dict1[i]; i++) {
        PrefixTreeInsert(t, dict1[i]);
    }
    for (int i = 0; dict1[i]; i++) {
        assert(PrefixTreeFind(t, dict1[i]));
    }
    for (int i = 0; dict2[i]; i++) {
        assert(!PrefixTreeFind(t, dict2[i]));
    }
    PrefixTreeFree(t);

    //part 2
    t = PrefixTreeNew();
    for (int i = 0; dict2[i]; i++) {
        PrefixTreeInsert(t, dict2[i]);
    }
    for (int i = 0; dict1[i]; i++) {
        assert(!PrefixTreeFind(t, dict1[i]));
    }
    for (int i = 0; dict2[i]; i++) {
        assert(PrefixTreeFind(t, dict2[i]));
    }
    PrefixTreeFree(t);

    //part 3
    t = PrefixTreeNew();
    for (int i = 0; dict1[i]; i++) {
        PrefixTreeInsert(t, dict1[i]);
    }
    for (int i = 0; dict2[i]; i++) {
        PrefixTreeInsert(t, dict2[i]);
    }
    for (int i = 0; dict1[i]; i++) {
        assert(PrefixTreeFind(t, dict1[i]));
    }
    for (int i = 0; dict2[i]; i++) {
        assert(PrefixTreeFind(t, dict2[i]));
    }
    PrefixTreeFree(t);

    //part 4
    t = PrefixTreeNew();
    for (int i = 0; dict1[i]; i++) {
        assert(!PrefixTreeFind(t, dict1[i]));
    }
    for (int i = 0; dict2[i]; i++) {
        assert(!PrefixTreeFind(t, dict2[i]));
    }
    PrefixTreeFree(t);

    return(0);
}
