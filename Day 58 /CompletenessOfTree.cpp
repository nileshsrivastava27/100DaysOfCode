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



bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool gotNullSoFar = false;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node==NULL){
                gotNullSoFar = true;
            }else{
                if(gotNullSoFar==true) 
                    return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }