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
    int findPosition(vector<int>& in, int element, int n){
        
        for(int i=0;i<n;i++){
            if(in[i] == element){
                return i;
            }
        }
            return -1;
    }
    
    TreeNode* solve(vector<int>& in,  vector<int>& post, int &index, int inorderStart, int inorderEnd, int n){
        
        //base case
        if(index<0 || inorderStart > inorderEnd){
            return NULL;
        }
        
        int element = post[index--];
        TreeNode* root = new TreeNode(element);
        int position = findPosition( in, element, n);
        
        // recursive call
        
        root->right= solve(in, post, index, position+1, inorderEnd ,n);
        root->left = solve( in, post, index, inorderStart, position-1, n);
        
        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postOrderIndex = n-1;
        TreeNode* ans = solve(inorder, postorder, postOrderIndex, 0, n-1, n);
        return ans;
    }
};