#include "Node.h"
#include "Linkedlist.h"

Linkedlist::Linkedlist(){
    HeadPtr = NULL;
}

Linkedlist::~Linkedlist(){
    Node *nextNode, currentNode;
    
    nextNode = HeadPtr;
    
    while(nextNode){
        currentNode = nextNode;
        nextNode = currentNode->next;
        delete currentNode;
    }
}

void Linkedlist::insertNode(int data){
    Node *node;
    
    node = new Node;
    
    node->data = data;
    node->next = NULL;
    
    if(!HeadPtr){
        HeadPtr = node;
    }else{
        searchNode(data)->next = node;
    }
}

