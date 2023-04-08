#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class TreeNode{

    public:

        int val;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int data)
    {
        this->val = data;
        this->right = NULL;
        this->left = NULL;
    }
};


    bool checkTree(TreeNode* root) {
        
        if(root == NULL)
            return false;

        if(root->left->val + root->right->val == root->val)
            return true;

        else
            return false;
    }