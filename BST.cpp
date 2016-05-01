#include <iostream>
//#include <cstdlib>
#include "BST.h"
#include "Stack.h"

using namespace std;

BinarySearchTree::BinarySearchTree(){
    cout<<"Constructing a Binary Search Tree"<<endl;
    root = NULL;
}

BinarySearchTree::~BinarySearchTree(){
    cout<<"Destructing a Binary Search Tree"<<endl;
    DeleteAll(root);
}

void BinarySearchTree::InsertKey(int inputKey){
    TreeNode *newNode, *nextNode;
    //cout<<"Insert Key..." <<endl;
    
    newNode = new TreeNode;
    newNode->data = inputKey;
    newNode->left = NULL;
    newNode->right = NULL;

    if(root == NULL){
        root = newNode;
        return;
    }
    
    nextNode = root;
    while(nextNode){
        //cout<<"nextNode"<<endl;
        if(newNode->data > nextNode->data){
            //cout<<"nextNode->right"<<endl;
            if(!nextNode->right){
                nextNode->right = newNode;
                break;
            }else{
                nextNode = nextNode->right;
            }
        }else{
            //cout<<"nextNode->left"<<endl;
            if(!nextNode->left){
                nextNode->left = newNode;
                break;
            }else{
                nextNode = nextNode->left;
            }
        }
    }
    
    return;
}

bool BinarySearchTree::SearchKey(int inputKey){
    TreeNode *nextNode;
    
    nextNode = root;
    while(nextNode){
        if(nextNode->data == inputKey){
            cout<< "Key was found! :"<< nextNode->data <<endl;
            return true;
        }
        
        if(inputKey > nextNode->data){
            nextNode = nextNode->right;
        }else{
            nextNode = nextNode->left;
        }
    }
    cout<< "Key was not found!"<<endl;
    return false;
}

void BinarySearchTree::PreorderTraversal(){
    cout<<"Preorder Traversal"<<endl;
    PreorderRecursive(root);
    cout<<"Preorder Iterative"<<endl;
    PreorderIterative();
    return;
}

void BinarySearchTree::PreorderRecursive(TreeNode *inputNode){
    if(inputNode == NULL) return;
    cout<<inputNode->data<<endl;
    PreorderRecursive(inputNode->left);
    PreorderRecursive(inputNode->right);    
}

void BinarySearchTree::PreorderIterative(){
    TreeNode *nextNode;
    Stack<TreeNode*> stack1;
    
    stack1.Push(root);
    while(!stack1.isEmpty()){
        if(stack1.Peek() == NULL) {
            stack1.Pop();
            continue;
        }
        
        nextNode = stack1.Pop();
        cout<<nextNode->data<<endl;
        
        stack1.Push(nextNode->right);
        stack1.Push(nextNode->left);
        
    }
}

void BinarySearchTree::InorderTraversal(){
    cout<< "Inorder Traversal" <<endl;
    InorderRecursive(root);
    cout<<"Inorder Iterative"<<endl;
    InorderIterative();
    return;
}

void BinarySearchTree::InorderRecursive(TreeNode* inputNode){
    if(inputNode == NULL) return;
    InorderRecursive(inputNode->left);
    cout<< inputNode->data <<endl;
    InorderRecursive(inputNode->right);
}

void BinarySearchTree::InorderIterative(){
    TreeNode *nextNode;
    Stack<TreeNode*> stack1, stack2, stack3;
    
    //nextNode = root;
    stack1.Push(root->left);
    stack2.Push(root);
    stack3.Push(root->right);
    while(!stack2.isEmpty()){

        if(!stack1.isEmpty()){
            if(stack1.Peek()==NULL){
                stack1.Pop();
                continue;
            }
            nextNode = stack1.Pop();
            stack1.Push(nextNode->left);
            stack2.Push(nextNode);
            stack3.Push(nextNode->right);
        }else{
            cout<<stack2.Pop()->data<<endl;
            if(stack3.Peek()==NULL){
                stack3.Pop();
                continue;
            }
            nextNode = stack3.Pop();
            stack1.Push(nextNode->left);
            stack2.Push(nextNode);
            stack3.Push(nextNode->right);
        }
        
    }
    
}

void BinarySearchTree::PostorderTraversal(){
    cout<< "Postorder Traversal"<<endl;
    PostorderRecursive(root);
    cout<<"Postorder Iterative"<<endl;
    PostorderIterative();
    return;
}

void BinarySearchTree::PostorderRecursive(TreeNode *inputNode){
    if(inputNode == NULL) return;
    PostorderRecursive(inputNode->left);
    PostorderRecursive(inputNode->right);
    cout<< inputNode->data <<endl;
}

void BinarySearchTree::PostorderIterative(){
    TreeNode *nextNode;
    Stack<TreeNode*> stack1, stack2, stack3;
    
    
    stack1.Push(root->left);
    stack2.Push(root->right);
    stack3.Push(root);
    
    while(!stack3.isEmpty()){
        if(!stack1.isEmpty()){
            if(stack1.Peek() == NULL){
                stack1.Pop();
                continue;
            }
            nextNode = stack1.Pop();
            stack1.Push(nextNode->left);
            stack2.Push(nextNode->right);
            stack3.Push(nextNode);
        }else if(!stack2.isEmpty()){
            //cout<<stack3.Pop()->data<<endl;
            if(stack2.Peek() == NULL){
                stack2.Pop();
                cout<<stack3.Pop()->data<<endl;
                continue;
            }
            nextNode = stack2.Pop();
            stack2.Push(NULL);
            stack1.Push(nextNode->left);
            stack2.Push(nextNode->right);
            stack3.Push(nextNode);
        }
        
    }
}

void BinarySearchTree::DeleteAll(TreeNode *inputNode){
    if(inputNode == NULL) return;
    DeleteAll(inputNode->left);
    DeleteAll(inputNode->right);
    delete inputNode;
}