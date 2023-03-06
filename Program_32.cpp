//Problem Statement: Given head, the head of a linked list, determine if the linked list has a cycle in it. There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
//Return true if there is a cycle in the linked list. Otherwise, return false

//Input:Head = [1,2,3,4]
//Output:true

#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
                                   
};
    class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        if (head == NULL || head->next == NULL)
            return false;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
