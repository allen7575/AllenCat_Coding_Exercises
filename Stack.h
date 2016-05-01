#ifndef __STACK_H__
#define __STACK_H__

#include "Node.h"
#define STACK_SIZE 100

template <class T>
class Stack{
    public:
        Stack();
        ~Stack();
        void Push(T);
        T Pop();
        T Peek();
        bool isFull();
        bool isEmpty();
    private:
        int nodeNum;
        Node<T>* top;
        
};

#include "Stack.cpp"
#endif

