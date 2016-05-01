#include "TreeNode.h"
class BinarySearchTree{
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void InsertKey(int);
        //int DeleteKey();
        bool SearchKey(int);
        void PreorderTraversal();
        void InorderTraversal();
        void PostorderTraversal();
    private:
        TreeNode *root;
        void PreorderRecursive(TreeNode*);
        void InorderRecursive(TreeNode*);
        void PostorderRecursive(TreeNode*);
        void PreorderIterative();
        void InorderIterative();
        void PostorderIterative();
        void DeleteAll(TreeNode*);
};