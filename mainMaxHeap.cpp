#include <iostream>
#include "MaxHeap.h"

using namespace std;

int main(){
    int A[10]={45,4,57,99,21,10,65,44,3,11};
    MaxHeap maxheap1;
    //MinHeap minheap1;
    //Heap heap1;
    
    for(int i=0;i<10;i++){
        maxheap1.Insert(A[i]);
        //minheap1.Insert(A[i]);
        //heap1.Insert(A[i]);
    }
    
    /*
    for(int i=0;i<9;i++){
        maxheap1.Delete();
        //cout<<"loop check point 1"<<endl;
    }
    
    for(int i=0;i<5;i++){
        maxheap1.Insert(A[i]);
    }
    */
    
    return 0;    
}