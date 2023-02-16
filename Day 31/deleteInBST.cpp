#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class TreeNode{

    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){

        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

TreeNode*inordersucc(TreeNode *root)
    {
        TreeNode *curr=root;
        while(curr && curr->left !=NULL)
        {
            curr=curr->left;
        }
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        {
            return root;
        }
        if(root->data>key)
        {
            root->left=deleteNode(root->left,key);
        }
        else if(root->data<key)
        {
            root->right=deleteNode(root->right,key);
        }
        else{
            if(root->left==NULL)
            {
                TreeNode *temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL)
            {
                TreeNode *temp=root->left;
                delete root;
                return temp;
            }
            TreeNode *temp=inordersucc(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
        return root;
    }