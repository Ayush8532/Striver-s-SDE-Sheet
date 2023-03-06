//Problem Statement: Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list. k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

//Input:head = [1,2,3,4,5,6,7,8] k=3
//Output:head = [3,2,1,6,5,4,7,8]

#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
    int length(ListNode* head)
    {
        int len=0;
        while(head!=NULL)
        {
            len+=1;
            head=head->next;
        }
        return len;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummyHead=new ListNode(0);
        dummyHead->next=head;
        ListNode *pre=dummyHead,*curr=head,*nxt=head->next;
        int size=length(head);
        while(size>=k)
        {
            curr=pre->next;
            nxt=curr->next;
            for(int i=1;i<k;i++)
            {
                curr->next=nxt->next;
                nxt->next=pre->next;
                pre->next=nxt;
                nxt=curr->next;
            }
            pre=curr;
            size-=k;
        }
        return dummyHead->next;
    }
};