#include <iostream>
#include "Stack.h"

using namespace std;

int main(){
    Stack<int> intStack;
    
    for(int i=0;!intStack.isFull();i++){
        intStack.Push(i*i);
    }
    
    intStack.Peek();
    
    for(int i=0;!intStack.isEmpty();i++){
        intStack.Pop();
        intStack.Peek();
    }
    
    intStack.Push(100);
    intStack.Push(99);
    

    return 0;
    
}

