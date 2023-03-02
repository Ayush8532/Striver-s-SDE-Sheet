// Problem Statement: Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.

// head = [3,6,8,10]
// Result : Output = [ 10, 6, 8, 3 ]

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(vector<int> v, int n)
{
    struct Node *last, *temp;
    first = new Node;
    first->data = v[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = v[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
void display(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
void reversing(struct Node *head)
{
    Node *p = NULL, *q = NULL;
    while (head != NULL)
    {
        p = head;
        head = head->next;
        p->next = q;
        q = p;
    }
    cout << "after";
    display(p);
}
int main()
{
    vector<int> v = {3, 6, 8, 10};
    create(v, v.size());
    display(first);
    reversing(first);
    return 0;
}