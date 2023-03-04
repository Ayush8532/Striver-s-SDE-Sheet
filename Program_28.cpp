// Problem Statement: Given a linked list, and a number N. Find the Nth node from the end of this linked list and delete it. Return the head of the new modified linked list.

// Input: head = [1,2,3,4,5], n = 2
//Output : [ 1, 2, 3, 5 ]

#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
    class Solution
    {
        public:
            ListNode *removeNthFromEnd(ListNode *head, int n)
            {
                ListNode *start, *fast, *slow;
                start = new ListNode;
                start->next = head;
                fast = start, slow = start;
                for (int i = 1; i <= n; i++)
                {
                    fast = fast->next;
            }
            while (fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
            slow->next = slow->next->next;
            return start->next;
    }
};