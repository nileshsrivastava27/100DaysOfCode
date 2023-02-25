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


class Solution {
public:
    int s = 0;

    void solve(TreeNode *root)
    {
        if (root == NULL) 
            return;

        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
        {
            s += root->left->val;
        }

        solve(root->left);
        solve(root->right);
        
        return;
    }
    int sumOfLeftLeaves(TreeNode *root)
    {

        solve(root);
        return s;
    }
};