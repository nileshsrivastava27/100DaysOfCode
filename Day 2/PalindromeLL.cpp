#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool palindromeCheck(vector<int> &arr){

        int s=0;
        int n = arr.size();
        int e= n-1;

        while(s<=e){
            if(arr[s] != arr[e]){
                return 0;
            }
            s++; e--;
        }
            return 1;
    }

    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;

        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp= temp->next;
        }

        return palindromeCheck(arr);
    }
};