// Problem Statement: Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

//Input:head = [1,2,3,4,3,6,10]
//Output:tail connects to node index 2

#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head, *entry = head;
        if (head == NULL)
            return NULL;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                while (entry != slow)
                {
                    slow = slow->next;
                    entry = entry->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
/*
        unordered_set<ListNode*>s;
        while(head!=NULL)
        {
            if(s.find(head)!=s.end())return head;
            s.insert(head);
            head=head->next;
        }
        return NULL;
*/