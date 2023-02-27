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

        int best_sum(int &ans,TreeNode* root)
        {
            if(root==NULL) return 0;
            
            int left_best=best_sum(ans,root->left);
            int right_best=best_sum(ans,root->right);
            int curr=root->val;
            ans=max({ans,
                     curr,               //best can be only curr 
                     left_best +curr,     // using left and curr
                     right_best + curr,    // using right and curr
                     left_best+right_best+curr}); //using both
            return max({curr,left_best+curr,right_best+curr});
        }


    int maxPathSum(TreeNode* root) {
        int ans=-1e9;
        best_sum(ans,root);
        return ans;
    }
