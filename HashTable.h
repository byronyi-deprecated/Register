#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "DoublyLinkedList.h"
#include <vector>
using namespace std;

typedef unsigned int HashVal;

template<class T1, class T2>
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

#endif // HASHTABLE_H
