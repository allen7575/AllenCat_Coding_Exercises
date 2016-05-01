#include <iostream>
#include "BST.h"

using namespace std;

int main(){
    BinarySearchTree bst1;
    int A[10]={45,4,57,99,21,10,65,44,3,11};
    int B[10]={23,55,17,94,37,62,88,46,31,7};
    cout<<"program beginning..."<<endl;

    for(int i=0; i<10; i++){
        bst1.InsertKey(A[i]);
    }
    
    for(int i=0; i<10; i++){
        bst1.SearchKey(A[i]);
    }
    
    for(int i=0; i<10; i++){
        bst1.SearchKey(B[i]);
    }
    
    bst1.PreorderTraversal();
    bst1.InorderTraversal();
    bst1.PostorderTraversal();
    
}