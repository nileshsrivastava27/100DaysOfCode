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
    
    vector<int> preorderTraversal(TreeNode* root) { //nlr
        
        
        if(root == NULL)
            return ans;

        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);

        return ans;
    }