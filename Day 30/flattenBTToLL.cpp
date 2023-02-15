#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){

        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

//classical application of morris traversal... it is a special type of traversal in which 
//TC is O(n) but SC is O(1)

// all the other traversal like level order, inorder, preorder, postorder have SC:- O(n)

void flatten(Node *root)
    {
        Node* curr = root;
        
        while(curr!=NULL)
        {
            
            if(curr->left)
            {
                Node* pred = curr->left;
                while(pred->right)
                {
                    pred = pred->right;
                }
                
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            
            curr = curr->right;
        }
    }