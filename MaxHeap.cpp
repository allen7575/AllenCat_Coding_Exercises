#include <cstdlib>
#include <iostream>
#include "MaxHeap.h"

using namespace std;

//
// class Heap
//

Heap::Heap(){
    cout<<"Heap constructor"<<endl;
    root = NULL;
    totalNodeNum = 0;
}

Heap::~Heap(){
    cout<<"Heap destructor"<<endl;
    while(totalNodeNum){
        Delete();
    }
}

void Heap::checkHeap(TreeNode* root){
    return;
}

void Heap::Insert(int inputData){
    TreeNode *tempNode1;
    
    tempNode1 = findNodeByNumber(totalNodeNum+1);
    tempNode1->data = inputData;
    tempNode1->left = NULL;
    tempNode1->right = NULL;
    
    cout<<"insert data: "<<tempNode1->data<<endl;
    cout<<"total node number: "<<totalNodeNum<<endl;
    checkHeap(root);
}

int Heap::Delete(){
    int data;
    TreeNode *tempNode1, *tempNode2;

    tempNode1 = findNodeByNumber(totalNodeNum);
    tempNode2 = findNodeByNumber(totalNodeNum/2);
    
    //cout<<"check point1"<<endl;
    
    if(tempNode1){
        data = root->data;
        root->data = tempNode1->data;
        //cout<<"check point3"<<endl;
        delete tempNode1;
        if(tempNode2){
            //cout<<"check point5 "<<endl;
            if(totalNodeNum % 2){
                tempNode2->right = NULL;
            }else{
                tempNode2->left = NULL;
            }
        }else{
            root = NULL;
        }
        totalNodeNum -= 1;
        //cout<<"total node number:"<<totalNodeNum<<endl;
    }else{
        cout<<"heap is empty"<<endl;
        return 0;
    }
    
    if(totalNodeNum){
        //cout<<"check point2"<<endl;
        checkHeap(root);
    }

    cout<<"delete data: "<<data<<endl;
    cout<<"total node number: "<<totalNodeNum<<endl;
    return data;
}

void Heap::swapValue(TreeNode* node1, TreeNode* node2){
    int tempdata;
    
    tempdata = node1->data;
    node1->data = node2->data;
    node2->data = tempdata;
}

TreeNode* Heap::findNodeByNumber(int nodeNumber){
    int tempNum1 = 0, tempNum2 = 0;
    TreeNode *tempNode1;
    
    //cout<<"find node: "<< nodeNumber<<endl;
    
    if( nodeNumber > (totalNodeNum +1) || nodeNumber <= 0){
        return NULL;
    }
    
    if(nodeNumber == 1 && !root){
        root = new TreeNode;
        totalNodeNum +=1;
        //cout<<"create a root node:"<<endl;
        return root;
    }
    
    tempNum1 = nodeNumber;
    tempNum2 = 0;
    while(tempNum1){
        //cout<<"find node check point2"<<endl;
        tempNum2 <<= 1;
        tempNum2 |= tempNum1 % 2;
        tempNum1 >>= 1;
        //cout<<"t1:"<<tempNum1<<endl;
        //cout<<"t2:"<<tempNum2<<endl;
    }
    
    //cout<<"find node check point1 "<<endl;
    
    tempNum1 = nodeNumber;
    tempNum1 >>= 1;
    tempNum2 >>= 1;
    tempNode1 = root;
    
    while(tempNum1){
        //cout<<"t1:"<<tempNum1<<endl;
        //cout<<"t2:"<<tempNum2<<endl;
        
        if(tempNum2 % 2){
            if(tempNum1 == 1 && nodeNumber == (totalNodeNum + 1) ){
                 delete tempNode1->right;
                 tempNode1->right = new TreeNode;
                 //cout<<"create a new node:"<<endl;
                 totalNodeNum +=1;
            }
            //cout<<"find node check point3"<<endl;
            tempNode1 = tempNode1->right;
        }else{
            if(tempNum1 == 1  && nodeNumber == (totalNodeNum + 1) ){
                delete tempNode1->left;
                tempNode1->left = new TreeNode;
                //cout<<"create a new node:"<<endl;
                totalNodeNum +=1;
            }
            //cout<<"find node check point4"<<endl;            
            tempNode1 = tempNode1->left;
        }

        tempNum1 >>= 1;
        tempNum2 >>= 1;
    }
    //cout<<"find node data: "<<tempNode1->data<<endl;
    return tempNode1;
}

//
// class MaxHeap
//

MaxHeap::MaxHeap():Heap(){
    cout<<"MaxHeap constructor"<<endl;  
}

MaxHeap::~MaxHeap(){
    cout<<"MaxHeap destructor"<<endl;
    while(totalNodeNum){
        Delete();
    }
}

void MaxHeap::checkHeap(TreeNode* root){
    return checkMaxHeap(root);
}

void MaxHeap::checkMaxHeap(TreeNode *root){
    if(root->left){
        checkMaxHeap(root->left);
        if(root->data < root->left->data)
            swapValue(root, root->left);
        if(root->right){
            checkMaxHeap(root->right);
            if(root->data < root->right->data)
                swapValue(root, root->right);
        }
    }
}

//
// class MinHeap
//

MinHeap::MinHeap():Heap(){
    cout<<"MinHeap constructor"<<endl;
}

MinHeap::~MinHeap(){
    cout<<"MinHeap destructor"<<endl;
    while(totalNodeNum){
        Delete();
    }
}

void MinHeap::checkHeap(TreeNode* root){
    return checkMinHeap(root);
}

void MinHeap::checkMinHeap(TreeNode *root){
    if(root->left){
        checkMinHeap(root->left);
        if(root->data > root->left->data)
            swapValue(root, root->left);
        if(root->right){
            checkMinHeap(root->right);
            if(root->data > root->right->data)
                swapValue(root, root->right);
        }
    }
}


//
//Invert Binary Tree 
//

void InvertTreeRecursive(TreeNode *root){
    TreeNode *tempNode1;
    
    if(root){
        tempNode1 = root->left;
        root->left = root->right;
        root->right = tempNode1;
    
        InvertTreeRecursive(root->left);
        InvertTreeRecursive(root->right);
    }
}

void InvertTreeIterative(TreeNode *root){
    TreeNode tempNode1;
    Queue<TreeNode*> queue1;
    
    queue1.push(root);
    
    while(!queue1.isEmpty()){
        if(!queue1.front()){
            queue1.pop();
            continue;
        }
        
        queue1.push(queue1.front()->left);
        queue1.push(queue1.front()->right);
        tempNode1 = queue1.front()->left;
        queue1.front()->left = queue1.front()->right;
        queue1.front()->right = tempNode1;
        queue1.pop();
    }
}
