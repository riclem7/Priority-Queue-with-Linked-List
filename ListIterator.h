// Ricardo Lemus
// class account number: cssc0329
// Student ID: 821687094
// ListIterator.h

// compiler directives here
#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include "Node.h"

template<class T>
class ListIterator {

private:
    Node<T> *itptr; //Pointer to traverse the linked list

public:
    //No arg constructor initializes the iterators internal pointer to nullptr
    ListIterator() { itptr = nullptr; }

    //The next constructor initializes the iterator’s internal pointer to the passed in argument’s internal
    //pointer.

    ListIterator (const ListIterator<T>& q) { itptr = q.itptr; }


    //The third constructor initializes the iterator’s internal pointer to a Node<T> object.

    ListIterator (Node<T> *q) { itptr = q;}

    //Type conversions performed on both argumentsA prefix increment, ++p, first advances the pointer
    //to the next object in the list before returning it’s value

    ListIterator& operator++ () { // prefix, ++p
        itptr = itptr->next;
        return *this;
    }

    //The current value is saved, the pointer incremented, then the
    //saved (old) value is returned.

    ListIterator operator++ (int) { // postfix, p++
        ListIterator<T> tmp = *this; // make a copy of current state
        ++*this; // call prefix to update the state, ++(*this)
        return tmp; // return the copy of the now former state
    }

    //To compare two ListIterators, we check the internal pointers.

    bool operator== (ListIterator<T> q) {return itptr == q.itptr; }
    bool operator != (ListIterator<T> q) {return itptr != q.itptr; }

    //Here we access the data element of the current node
    //referenced by itptr when the ListIterator object is dereferenced.

    T& operator* () {return itptr->data; }

};
#endif