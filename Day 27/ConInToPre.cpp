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
    
    int curr=0;  
    
    TreeNode* help(vector<int>& pre,vector<int>& in,int inLeft, int inRight){
        if(inLeft > inRight)return NULL;
        auto ans= new TreeNode(pre[curr]);

        int ind= find(in.begin(),in.end(),pre[curr])- in.begin();
        curr++;
        
        ans->left= help(pre,in,inLeft, ind-1);
        ans->right= help(pre,in,ind+1, inRight);
        return ans;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return help(pre,in,0,in.size()-1);
    }