#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP 1

#ifndef MAX
#define MAX 1024
#endif
#include <stdint.h>
#include <string.h>
#include <vector>
using namespace std;

struct HashTableNode {
    int key;
    int value;
    HashTableNode *next;
};

struct HashTable {
    HashTableNode* tab[MAX];
};


HashTable *HashTableNew()
{
    HashTable *t = new HashTable();

    if (t == NULL) {
        return NULL;
    }
    memset(t->tab, 0, sizeof(t->tab));
    return t;
}

void HashTableFree(HashTable *t)
{
    for (int i = 0; i < MAX; i++) {
        HashTableNode *p = t->tab[i];
        while (p) {
            HashTableNode *q = p->next;
            delete p;
            p = q;
        }
    }
    delete t;
}

uint32_t UIntMix(uint32_t key)
{
    key += ~(key << 15);
    key ^=  (key >> 10);
    key +=  (key << 3);
    key ^=  (key >> 6);
    key += ~(key << 11);
    key ^=  (key >> 16);
    return key;
}

int HashTableInsert(HashTable *t, int key, int value)
{
    HashTableNode *newnode = new HashTableNode();
    if (newnode == NULL) {
        return -1;
    }

    newnode->key = key;
    newnode->value = value;
    newnode->next = NULL;

    unsigned int index = UIntMix(key) % MAX;
    HashTableNode *p = t->tab[index];

    if (p) {
        HashTableNode *q = p->next;

        while (q) {
            p = q;
            q = q->next;
        }

        p->next = newnode;
    } else {
        t->tab[index] = newnode;
    }

    return 0;
}

int HashTableFind(HashTable *t, int key)
{
    unsigned int index = UIntMix(key) % MAX;
    HashTableNode *p = t->tab[index];

    while (p) {
        if (p->key == key) {
            return p->value;
        }
        p = p->next;
    }

    return -1;
}

int HashTableRemove(HashTable *t, int key)
{
    unsigned int index = UIntMix(key) % MAX;
    HashTableNode *p = t->tab[index];

    if (!p) {
        return -1;
    }

    if (p->key == key) {
        t->tab[index] = p->next;
        delete p;
        return 0;
    }

    HashTableNode *q = p->next;
    while (q && q->key != key) {
        p = p->next;
        q = p->next;
    }
    if (q && q->key == key) {
        p->next = q->next;
        delete q;
        return 0;
    }

    return -1;
}

#endif
