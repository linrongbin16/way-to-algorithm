#include "HashTable.hpp"
#include <assert.h>


#define TEST_MAX 1024

int main()
{
    HashTable *t = HashTableNew();
    assert(t);

    int tab[TEST_MAX];
    for (int i = 0; i < TEST_MAX; i++) {
        tab[i] = i;
    }
    for (int i = 0; i < TEST_MAX; i++) {
        assert(HashTableInsert(t, tab[i], tab[i]) == 0);
    }
    for (int i = 0; i < TEST_MAX; i++) {
        int p = HashTableFind(t, tab[i]);
        assert(p == tab[i]);
    }
    for (int i = 0; i < TEST_MAX; i++) {
        assert(HashTableRemove(t, tab[i]) == 0);
    }
    HashTableFree(t);

    return 0;
}
