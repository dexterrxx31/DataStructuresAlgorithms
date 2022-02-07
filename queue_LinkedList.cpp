#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int isFull()
{
    Node *newNode = new Node;
    if (newNode == NULL)
        return 1;
    else
        return 0;
}

int isEmpty(Node *front, Node *rear)
{
    if (front == rear)
        return 1;
    else
        return 0;
}

Node *enqueue(Node *rear, int val)
{
    if (isFull())
        cout << "Queue is Full" << endl;
    else
    {
        Node *newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
        rear->next = newNode;
        return newNode;
    }
}

// int dequeue(Node **front , Node **rear)
// {
//     if (isEmpty(front , rear))
//         cout << "Node is Empty" << endl;
//     else
//     {
//         ptr->front++;
//         int deleted_item = ptr->arr[ptr->front];
//         ptr->arr[ptr->front] = 0;
//         return deleted_item;
//     }
// }

void traversal(Node *front)
{
    front = front->next;
    while (front)
    {
        cout << front->data << " ";
        front = front->next;
    }
}

int main()
{
    Node *Que = new Node;
    Node *front = Que;
    Node *rear = Que;
    front->next = NULL;
    rear->next = NULL;

    int input_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(input_arr) / sizeof(input_arr[0]);

    for (int i = 0; i < n; i++)
    {
        rear = enqueue(rear, input_arr[i]);
    }

    traversal(front);
    return 0;
}