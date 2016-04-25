#include "TreeNode.h"

class Heap{
    public:
        Heap();
        ~Heap();
        void Insert(int);
        int Delete();
        friend void InvertTreeRecursive(TreeNode*);
        friend void InvertTreeIterative(TreeNode*);
    protected:
        TreeNode *root;
        int totalNodeNum;    
        TreeNode* findNodeByNumber(int);
        void swapValue(TreeNode*,TreeNode*);
        virtual void checkHeap(TreeNode*);
    private:
};

class MaxHeap:public Heap{
    public:
        MaxHeap();
        ~MaxHeap();
        //void Insert(int);
        //int Delete();
    protected:
        void checkHeap(TreeNode*);
    private:
        void checkMaxHeap(TreeNode*);  
};

class MinHeap:public Heap{
    public:
        MinHeap();
        ~MinHeap();
        //void Insert(int);
        //int Delete();
    protected:
        void checkHeap(TreeNode*);    
    private:
        void checkMinHeap(TreeNode*);
};