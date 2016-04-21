#include "Node.h"
class Linkedlist{
    public:
        Linkedlist();
        ~Linkedlist();
        void insertNode(int);
        void deleteNode(Node*);
        Node* searchNode(int);
        void dispalyNode(Node*);
        Node* getHeadPtr() const;
    private:
        Node* HeadPtr; 
};