// Problem Statement: Given two singly linked lists that are sorted in increasing order of node values, merge two sorted linked lists and return them as a sorted list. The list should be made by splicing together the nodes of the first two lists.

// Input Format :l1 = {3,7,10}, l2 = {1,2,5,8,10}
// Output :{1,2,3,5,7,8,10,10}

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *temp = NULL, *tail;
        temp = new ListNode;
        tail = temp;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }
        }
        if (list1 != NULL)
        {
            tail->next = list1;
        }
        else
        {
            tail->next = list2;
        }
        return temp->next;
    }
};