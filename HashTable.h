#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "DoublyLinkedList.h"
#include <vector>
using namespace std;

typedef unsigned int HashVal;

template<class T>
class HashTable
{
public:
    HashTable() {}

    ~HashTable() {}

    bool insert(const T& item)
    {
        HashVal val = hash(item);
        return buckets[val].insert(item);
    }

    bool remove(const T& item)
    {
        HashVal val = hash(item);
        return buckets[val].remove(item);
    }

    T* search(const T& item) const
    {
        HashVal val = hash(item);
        return buckets[val].search(item);
    }

private:
    HashVal hash(const T& item) const
    {
        return item.getKey() % 19;
    }
    DoublyLinkedList<T> buckets[19];
};

#endif // HASHTABLE_H
