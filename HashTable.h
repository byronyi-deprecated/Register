#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "DoublyLinkedList.h"
#include <vector>

template< class Key,
          class T
//          class Compare = less<Key>,
//          class Alloc = allocator<pair<const Key, T> >
        >
class HashTable
{
public:
    HashTable();
    ~HashTable();

    T& operator[](const Key& key)
    {
        hash_table[hash(key) % size].search(key)
    }



private:
    typedef pair<Key, T> hash_pair;
    typedef DoublyLinkedList<hash_pair> hash_list;
    typedef vector<hash_list> hash_table;

    hash_table hashtable;
};

/*
using namespace std;

typedef unsigned int HashVal;

template<class T1, class T2 = T1>
class HashTable
{
public:
    HashTable(unsigned int size) : buckets(DoublyLinkedList<T>(), size) {}

    bool insert(const T1& item)
    {
        HashVal val = hash(item);
        return buckets[val].insert(item);
    }

    bool remove(const T2& item)
    {
        HashVal val = hash(item);
        return buckets[val].remove(item);
    }

    const T1* search(const T2& item)
    {
        HashVal val = hash(item);
        return buckets[val].search(item);
    }

private:
    HashVal hash(const T1& item) const
    {
        return item.getKey() % buckets.size();
    }
    vector<DoublyLinkedList<T1, T2> > buckets;
};
*/
#endif // HASHTABLE_H
