
#ifndef LINKED_LIST_PQ_H
#define LINKED_LIST_PQ_H

#include "PriorityQueue.h"
#include "LinkedList.h"

template<class T>
class LinkedListPQ : public PriorityQueue<T> {

private:
    LinkedList<T> *pq;


public:

    LinkedListPQ() {
       pq = new LinkedList<T>();
    }


    bool insert(T object)
    {
        if(isFull())
        {
            return false;
        }

        pq->addLast(object);
        return true;

    }

    T remove()
    {
        if(isEmpty())
            throw std::invalid_argument("Cannot remove from empty queue");

        T min = peek();
        pq->remove(peek());

        return min;
    }

    bool deleteAll(T obj){
        if(!pq->contains(obj))
        {
            return false;
        }

        pq->removeAll(obj);
        return true;
    }

    T peek(){
        if(isEmpty())
            throw std::invalid_argument("Cannot peek from empty queue");

        T min = pq->peekFirst();

        ListIterator<T> traverse = pq->first();


        while(traverse != pq->end())
        {

            if ( *traverse < min)
            {
                min = *traverse;
            }
            traverse++;

        }
        return min;

    }

    bool contains(T obj){
        return pq->contains(obj);
    }

    int size(){
        return pq->size();
    }


    void clear(){
        pq->makeEmpty();
    }

    bool isEmpty(){
        return pq->isEmpty();
    }

    bool isFull() {
        return pq->isFull();
    }

    ListIterator<T> first(){
        return pq->first();
    }

    ListIterator<T> end(){
        return pq->end();
    }




};
#endif
