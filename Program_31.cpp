// Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

//Input:List 1 = [1,3,1,2,4], List 2 = [3,2,4]
//Output:2

#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> m;
        while (headA != NULL)
        {
            m.insert(headA);
            headA = headA->next;
        }
        while (headB != NULL)
        {
            if (m.find(headB) != m.end())
                return headB;
            else
            {
                m.insert(headB);
                headB = headB->next;
            }
        }
        return NULL;
    }
};
/*Brute Force
        ListNode *temp=headA;
        while(headB!=NULL)
        {
            while(headA!=NULL)
            {
                if(headA!=headB)
                {
                    headA=headA->next;
                }
                else{
                    return headB;
                }
            }
            headA=temp;
            headB=headB->next;
        }
        return NULL;
*/
/*2nd Approach
        ListNode *p=headA,*q=headB;
        while(p!=q)
        {
            if(p==NULL)p=headA;
            else p=p->next;
            if(q==NULL)q=headB;
            else q=q->next;
        }
        return p;

*/