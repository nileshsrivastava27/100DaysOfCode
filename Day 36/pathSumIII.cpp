#include<iostream>
using namespace std;

class TreeNode{

    public:

        int val;
        TreeNode* left = NULL;
        TreeNode* right = NULL;

    
        TreeNode(int d)
        {
            this->val = d;
            this->right = NULL;
            this->left = NULL;
        }
};



    void solve(TreeNode* root, int target, long long int sum, int &count)
    {

        if(root == NULL)
            return;

        if(target == sum)
            count++;

        if(root->left!=NULL)
            solve(root->left, target, sum+root->left->val, count);

        if(root->right!=NULL)
            solve(root->right, target, sum+root->right->val, count);
    }

    int pathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL)
            return 0;

        int count = 0;

        solve(root, targetSum, root->val ,count);

        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return count;
    }