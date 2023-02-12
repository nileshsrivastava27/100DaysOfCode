#include<iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

    int height(TreeNode* root){

        if(root== NULL)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        int ans = max(left, right)+1;

        return ans;
        
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = height(root->right)+height(root->left);

        int ans = max(op1, max(op2, op3));

        return ans;
    }