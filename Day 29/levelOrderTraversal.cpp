#include<iostream>
#include<vector>
#include<queue>
using namespace std; 

 
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> ans ; 
        vector<int> output ;  

        // edge case 
        if (root == NULL)
        {
            return ans ; 
        }


        queue<TreeNode*> q; 
        q.push(root) ;   
        q.push(NULL) ;  

        while (!q.empty())
        {
            TreeNode *temp = q.front() ; 
            q.pop() ; 

            if (temp == NULL)
            {
                ans.push_back(output) ; 
                output.clear() ; 


                if (!q.empty())
                {
                    q.push(NULL) ; 
                }
            }

            else
            {

                output.push_back(temp -> val) ;
                
                if (temp -> left != NULL)
                {
                    q.push(temp -> left) ;
                }

                if (temp -> right != NULL)
                {
                    q.push(temp -> right) ; 
                }
            }
        }
        return ans ; 
    }