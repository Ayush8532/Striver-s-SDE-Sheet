//Problem Statement: Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list instead, you will be given access to the node to be deleted directly. It is guaranteed that the node to be deleted is not a tail node in the list.

// Input:Linked list : [ 1, 2, 3, 4 ] Node = 1 
//Output : Linked list : [ 2, 3, 4 ]

#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;      
    }
};

/*
       ListNode *temp=node->next,*prev=node;
        while(temp!=NULL){
            node->val=temp->val;
            temp=temp->next;
            prev=node;
            node=node->next;
        }
        prev->next=NULL;
*/
