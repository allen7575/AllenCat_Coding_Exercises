#include <iostream>
#include "Stack.h"

using namespace std;

template <class T>
Stack<T>::Stack(){
    cout<<"Construct Stack."<<endl;
    nodeNum = 0;
    top = NULL;
}

template <class T>
Stack<T>::~Stack(){
    cout<<"Destruct Stack."<<endl;
    while(!isEmpty()){
        Pop();
    }
}

template <class T>
void Stack<T>::Push(T inputData){
    Node<T> *node;
    
    if(isFull()){
        cout<<"error: stack is full."<<endl;
        return;
    }
    
    node = new Node<T>;
    node->next = top;
    node->data = inputData;
    top = node;
    nodeNum +=1;
    //cout<<"push a data: "<<node->data<<endl;
}

template <class T>
T Stack<T>::Pop(){
    T data;
    Node<T> *nodeptr;
    
    if(isEmpty()){
        cout<<"error: stack is empty."<<endl;
        return 0;
    }
    
    data = top->data;
    nodeptr = top->next;
    delete top;
    top = nodeptr;
    nodeNum -=1;
    
    //cout<<"pop a data "<< data<< endl;
    return data;
}

template <class T>
T Stack<T>::Peek(){
    T temp;
    if(!isEmpty()){
        //cout<<"Peek top data: ";
        //cout<<top->data <<endl;
        return top->data;
    }
    cout<<"error: top data is empty "<<endl;
    //cout<<-1 <<endl;
    return temp;
}

template <class T>
bool Stack<T>::isFull(){
    //cout<<"Is Stack Full?"<<endl;
    return nodeNum > STACK_SIZE;
}

template <class T>
bool Stack<T>::isEmpty(){
    //cout<<"Is Stack Empty?"<<endl;
    return nodeNum <= 0;
}

//template class Stack<int>;