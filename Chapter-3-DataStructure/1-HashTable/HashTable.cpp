#include "HashTable.hpp"
#include "MurmurHash2.hpp"
#include <cassert>


#define TEST_MAX 1024

int main()
{
    HashTable *t = HashTableNew(MurmurHash2);
    assert(t);

    int *tab[TEST_MAX];
    for (int i = 0; i < TEST_MAX; i++) {
        tab[i] = new int(i);
    }
    for (int i = 0; i < TEST_MAX; i++) {
        assert(HashTableInsert(t, tab[i], tab[i]) == 0);
    }
    for (int i = 0; i < TEST_MAX; i++) {
        HashTableNode *p = HashTableFind(t, tab[i]);
        assert(p);
        assert((int*)p->key == tab[i]);
        assert((int*)p->value == tab[i]);
    }
    for (int i = 0; i < TEST_MAX; i++) {
        assert(HashTableRemove(t, tab[i]) == 0);
    }
    HashTableFree(t);

    return 0;
}
