#include "1_hash_table.h"
#include <iostream>
using namespace std;

int main()
{
    //prime hash table
    {
        cout << "hash table" << endl;
        prime_hash_table ht;
        prime_hash_init(&ht, 13);
        for(int i = 0; i < 30; ++ i)
            prime_hash_insert(&ht, i);
        prime_hash_print(&ht);
        prime_hash_node *p1 = prime_hash_find(&ht, 24);
        if(p1)
            cout << "find 24 in hash table: " << p1->m_value << endl;
        else
            cout << "can't find 24 in hash table" << endl;
        prime_hash_delete(&ht, 24);
        p1 = prime_hash_find(&ht, 24);
        cout << "after delete 24 from hash table" << endl;
        if(p1)
            cout << "find 24 in hash table: " << p1->m_value << endl;
        else
            cout << "can't find 24 in hash table" << endl;
        prime_hash_print(&ht);
    }

    //bkdr hash
    {
        cout << endl << "bkdr hash table" << endl;
        bkdr_hash_table bt;
        bkdr_hash_init(&bt, 31);
        char s1[] = "hello world";
        char s2[] = "henno hoood";
        char s3[] = "hh you wrong";
        char s4[] = "that's a test";
        int h1 = bkdr_hash(bt.m_seed, s1);
        int h2 = bkdr_hash(bt.m_seed, s2);
        int h3 = bkdr_hash(bt.m_seed, s3);
        int h4 = bkdr_hash(bt.m_seed, s4);
        cout << "string 1:" << endl << s1 << endl << "hash value: " << h1 << endl;
        cout << "string 2:" << endl << s2 << endl << "hash value: " << h2 << endl;
        cout << "string 3:" << endl << s3 << endl << "hash value: " << h3 << endl;
        cout << "string 4:" << endl << s4 << endl << "hash value: " << h4 << endl;
        cout << "insert string 1" << endl;
        bkdr_hash_insert(&bt, s1);
        if(bkdr_hash_find(&bt, s1))
            cout << "find string 1" << endl;
        else
            cout << "can't find string 1" << endl;
    }

    return 0;
}
