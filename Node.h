
// compiler directives here
#ifndef NODE_H
#define NODE_H

template<class T>

class Node {
    public:
        T data;
        Node *next;
        
        Node(T newData) {
            data = newData;
            next = nullptr;
        }
    };

#endif
