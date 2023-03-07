//Problem Statement: Given the head of a singly linked list, return true if it is a palindrome

// Input: head = [1,2,3,3,2,1]
//Output : true

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
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head;
        if(head->next==NULL ||head==NULL)
        {
            return true;
         }
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        while(slow!=NULL)
        {
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
        ListNode *reverse(ListNode *head)
        {
            ListNode *pre=NULL,*next=NULL;
            while(head!=NULL)
            {
                next=head->next;
                head->next=pre;
                pre=head;
                head=next;
            }
            return pre;
        }
        
};