// Problem Link -> https://leetcode.com/problems/merge-two-sorted-lists/description/

#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        
    if(head1 == NULL)
        return head2;

    if(head2 == NULL)
        return head1;
    
    ListNode* temp1 = head1;
    ListNode* temp2 = head2;

    ListNode* dummy = new ListNode(-1);
    ListNode* tempDummy = dummy;

    while(temp1 != NULL && temp2 != NULL) {

        if(temp1 -> val <= temp2 ->val) {
            tempDummy -> next = temp1;
            tempDummy = temp1;
            temp1 = temp1->next;
        }
        else{
            tempDummy -> next = temp2;
            tempDummy = temp2;
            temp2 = temp2->next;
        }
    }

    //it is possible that elements are left in temp1 list
    while(temp1 != NULL) {
         tempDummy -> next = temp1;
            tempDummy = temp1;
            temp1 = temp1->next;
    }

        //it is possible that elements are left in temp2 list
    while(temp2 != NULL) {
         tempDummy -> next = temp2;
            tempDummy = temp2;
            temp2 = temp2->next;
    }

    
    ListNode* head = dummy->next;
    
    //delete dummy node
    dummy->next = NULL;
    delete dummy;

    return head;
    }
};