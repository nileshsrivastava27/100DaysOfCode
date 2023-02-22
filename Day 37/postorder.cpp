#include<iostream>
#include<vector>
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

    vector<int> ans;
    
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(root == NULL)
            return ans;

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);

        return ans;
    }

