#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#endif // DOUBLYLINKEDLIST_H
#include <iostream>
using namespace std;

template <class T>
class DoublyLinkedList
{
    typedef struct Node
    {
        Node* prev;
        Node* next;
        T data;
    } *NodePtr;

public:
    DoublyLinkedList(): _size(0) {

        _end = new Node;
        _end->prev = 0;
        _end->next = 0;
        _head = _end;

    }

    ~DoublyLinkedList(){

        while(_size)
            removeLast();
        delete _end;

    }

    bool isEmpty() const {return _size == 0;}
    int size() const {return _size;}

    void addFirst(const T& item) {

        NodePtr temp = new Node;
        temp->data = item;
        temp->prev = 0;
        temp->next = _head;
        _head->prev = temp;
        _head = temp;
        ++_size;

    }

    void addLast(const T& item) {

        NodePtr temp = new Node;
        temp->data = item;
        temp->prev = _end->prev;
        temp->next = _end;
        if(_size == 0)
            _head = temp;
        else _end->prev->next = temp;
        _end->prev = temp;
        ++_size;

    }


    T removeFirst() {
        try {

            if(_size == 0)
                throw -1;

            NodePtr temp = _head;
            T data = temp->data;
            _head = _head->next;
            delete temp;
            temp = 0;
            --_size;
            return data;

        }
        catch(int) {

            cerr << "Cannot delete element from empty deque" << endl;

        }

    }

    T removeLast() {
        try {

            if(_size == 0)
                throw -1;

            NodePtr temp = _end->prev;
            T data = temp->data;
            _end->prev = temp->prev;
            delete temp;
            temp = 0;
            --_size;
            return data;

        }
        catch(int) {

            cerr << "Cannot delete element from empty deque" << endl;

        }
    }

    bool insert(const T& item)
    {
        NodePtr temp = new Node;
        temp->data = item;

        NodePtr ptr = _head;
        while(ptr != _end->next)
        {
            if(ptr->data == item) return false;

            if( !(ptr->data < item) || ptr == _end)
            {
                if(ptr->prev)
                    ptr->prev->next = temp;
                else
                    _head = temp;

                temp->prev = ptr->prev;
                temp->next = ptr;
                ptr->prev = temp;

                ++_size;
                return true;
            }

            ptr = ptr->next;
        }

        return false;
    }

    bool remove(const T& item)
    {
        NodePtr ptr = _head;
        while(ptr != _end)
        {
            if(ptr->data == item)
            {
                if(ptr == _head)
                    _head = ptr->next;
                else
                    ptr->prev->next = ptr->next;

                ptr->next->prev = ptr->prev;
                delete ptr;

                --_size;
                return true;
            }

            ptr = ptr->next;
        }
        return false;
    }

    const T* search(const T& item) const
    {
        NodePtr ptr = _head;
        while(ptr != _end)
        {
            if(ptr->data == item)
                return &(ptr->data);
            ptr = ptr->next;
        }
        return 0;
    }

private:
    NodePtr _head;
    NodePtr _end;
    unsigned int _size;
};
