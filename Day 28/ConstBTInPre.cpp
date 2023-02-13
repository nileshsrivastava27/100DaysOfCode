#include<iostream>
#include<vector>
using namespace std; 
 
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int findPosition(vector<int> in, int element, int n)
    {
        for(int i=0;i<n;i++){
            if(in[i] == element)
                return i;
        }

        return -1;
    }


    TreeNode* solve(vector<int> in, vector<int> pre, int &index, int inorderStart, int inorderEnd, int n)
    {
        if(index>=n || inorderStart > inorderEnd){
            return NULL;
        }

        int element = pre[index++];
        TreeNode* root = new TreeNode(element);
        int position = findPosition(in, element, n);

        root->left = solve(in, pre, index, inorderStart, position-1, n);
        root->right = solve(in, pre, index, position+1, inorderEnd, n);

        return root;
    }

    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int preorderIndex = 0;
        int n = pre.size();
        TreeNode* ans = solve(in, pre, preorderIndex, 0, n-1, n);

        return ans;
    }
};