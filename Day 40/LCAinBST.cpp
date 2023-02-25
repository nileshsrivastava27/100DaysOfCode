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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
    if(root == NULL)
        return NULL;
    
    
    if(root->val < p->val && root->val < q->val){
        return lowestCommonAncestor(root->right, p,q);
    }
    
    if(root->val > p->val && root->val >q->val){
        return lowestCommonAncestor(root->left,p, q);
    }
    return root;
    }
};