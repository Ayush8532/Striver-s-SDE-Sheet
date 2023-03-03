// Problem Statement: Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.

// Input: head = [1,2,3,4,5,6]
// Result: [4,5,6]

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(vector<int> &v, int n)
{
    struct Node *temp, *last;
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

void middle(struct Node *head)
{
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    display(slow);
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int n = v.size();
    create(v, n);
    middle(first);
    return 0;
}