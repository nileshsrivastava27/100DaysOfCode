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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       vector<vector<int>> result;

        if(root == NULL) 
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> km(size);
            for(int i =0;i<size;i++)
            {
                TreeNode* frontNode = q.front();
                q.pop();
                km[i] = frontNode->val;
                if(frontNode->left) 
                    q.push(frontNode->left);
                if(frontNode->right) 
                    q.push(frontNode->right);
            } 

            result.push_back(km);
        }

        reverse(result.begin(),result.end());
        return result; 
    }
};