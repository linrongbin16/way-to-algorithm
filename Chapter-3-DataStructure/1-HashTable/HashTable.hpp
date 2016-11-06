#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP 1

#ifndef MAX
#define MAX 1024
#endif
#include <cstring>

struct HashTableNode {
    void *key;
    void *value;
    HashTableNode *next;
};

struct HashTable {
    HashTableNode *tab[MAX];
    unsigned int(*hash)(const void *, int, unsigned int);
};


HashTable *HashTableNew(unsigned int (*hash)(const void *, int, unsigned int))
{
    HashTable *t = new HashTable();

    if (t == NULL) {
        return NULL;
    }

    memset(t->tab, 0, MAX * sizeof(HashTableNode*));
    t->hash = hash;

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

int HashTableInsert(HashTable *t, void *key, void *value)
{
    HashTableNode *newNode = new HashTableNode();
    if (newNode == NULL) {
        return -1;
    }

    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    unsigned int index = t->hash(key, sizeof(key), 0) % MAX;
    HashTableNode *p = t->tab[index];

    if (p) {
        HashTableNode *q = p->next;

        while (q) {
            p = q;
            q = q->next;
        }

        p->next = newNode;
    } else {
        t->tab[index] = newNode;
    }

    return 0;
}

HashTableNode *HashTableFind(HashTable *t, void *key)
{
    unsigned int index = t->hash(key, sizeof(key), 0) % MAX;
    HashTableNode *p = t->tab[index];

    while (p) {
        if (p->key == key) {
            return p;
        }
        p = p->next;
    }

    return NULL;
}

int HashTableRemove(HashTable *t, void *key)
{
    unsigned int index = t->hash(key, sizeof(key), 0) % MAX;
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
