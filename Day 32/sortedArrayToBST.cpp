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

TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
    
    TreeNode* solve(vector<int>& nums, int left, int right){
        

        if(left > right){
            return NULL;
        }
        

        int mid = (left + right) / 2;
        TreeNode* temp = new TreeNode(nums[mid]);
        

        temp->left = solve(nums, left, mid-1);
        

        temp->right = solve(nums, mid+1 , right);
        return temp;
    }