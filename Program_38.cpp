#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *itr=head,*front=head,*deepCopy;
        while(itr!=NULL)
        {
            front=itr->next;
            Node* copy=new Node(itr->val);
            itr->next=copy;
            copy->next=front;
            itr=front;
        }
        itr=head;
        while(itr!=NULL)
        {
            if(itr->random!=NULL){
                itr->next->random=itr->random->next;
            }
            else{

            }
            itr=itr->next->next;
        }
        itr=head;
        Node *dummyHead=new Node(0);
        deepCopy=dummyHead;
        while(itr!=NULL)
        {
            front=itr->next->next;
            deepCopy->next=itr->next;
            itr->next=front;
            deepCopy=deepCopy->next;
            itr=itr->next;
        }
        return dummyHead->next;
    }
};