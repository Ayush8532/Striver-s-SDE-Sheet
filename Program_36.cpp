//Problem Statement: Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
//(i) a next pointer to the next node,
//(ii) a bottom pointer to a linked list where this node is head.
//Each of the sub-linked-list is in sorted order.
//Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
//Note: The flattened list will be printed using the bottom pointer instead of the next pointer.

// Input: [5,7,8,30,10,19,22,50,28]
// output:[5,7,8,10,19,22,28,30,50]

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *mergeSort(Node *a, Node *b)
{
    Node *dummy = new Node(0);
    Node *temp = dummy;
    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            dummy->bottom = a;
            dummy = dummy->bottom;
            a = a->bottom;
        }
        else
        {
            dummy->bottom = b;
            dummy = dummy->bottom;
            b = b->bottom;
        }
        if (a != NULL)
            dummy->bottom = a;
        else
        {

            dummy->bottom = b;
        }
    }
    return temp->bottom;
}
Node *flatten(Node *root)
{
    // Your code here
    if (root == NULL || root->next == NULL)
        return root;
    root->next = flatten(root->next);
    root = mergeSort(root, root->next);
    return root;
}