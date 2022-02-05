#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    class Node *next;
};

void traversalOfElements(Node *head)
{
    while (head != NULL) // head  head != 0
    {
        cout << (*head).data << " ";
        head = head->next;
    }
}

Node *insert_ele_at_begining(int ele, Node *head)
{
    Node *newNode = new Node;
    (*newNode).data = ele;
    newNode->next = head;
    head = newNode;
    return head;
}

void linear_search(Node *head, int ele)
{
    while (head != NULL)
    {
        if (head->data == ele)
        {
            cout << "Found";
            return;
        }
        head = head->next;
    }
}

Node *improved_linear_seach(Node *head, int ele)
{
    Node *p = head;
    Node *q;
    while (p)
    {
        if (p->data == ele)
        {
            cout << "Found";
            q->next = p->next;
            p->next = head;
            return p;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
}

//Deleting Dublicats from sorted linked list
void dub_delete(Node *head)
{
    Node *p = head;
    Node *q = p->next;
    while (q)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}
int main()
{
    Node *head = new Node; //head Node pointer of linked list
    head->data = 0;
    head->next = NULL;
    int arr[] = {1, 2, 2, 2, 2, 2, 3, 4, 5, 2, 2, 6, 7, 8, 9}; //taking array for input in linked list
    int n = sizeof(arr) / sizeof(arr[0]);                      //size of array

    for (int i = 0; i < n; i++)
    {
        head = insert_ele_at_begining(arr[i], head);
    }

    traversalOfElements(head);
    cout << endl;
    //head = improved_linear_seach(head, 5);
    dub_delete(head);
    cout << endl;
    traversalOfElements(head);
    return 0;
}