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

int solve(TreeNode* root, int sum)
    {

        if(root == NULL)
            return 0;

        sum = sum * 10 + root->data;

        if(root->left == NULL && root->right == NULL)
        {
            return sum;
        }

        return solve(root->left, sum) + solve(root->right, sum);
    }


    int sumNumbers(TreeNode* root) {
        
        if(root == NULL)    
            return 0;

        int currSum = 0;

        int ans = solve(root, currSum);

        return ans;

        
    }