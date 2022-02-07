//We can delete or add on either side of Queue
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

int isEmpty(Node *front)
{
    if (front == NULL)
        return 1;
    else
        return 0;
}

void enqueue_from_rear(Node **front, Node **rear, int val)
{
    if (isFull())
        cout << "Queue is Full" << endl;
    else
    {
        Node *newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
        if (*front == NULL)
            *front = *rear = newNode;
        else
        {
            (*rear)->next = newNode;
            *rear = newNode;
        }
    }
}

void enqueue_from_front(Node **front, Node **rear, int val)
{
    if (isFull())
        cout << "Queue is Full" << endl;
    else
    {   
            Node *newNode = new Node;
            newNode->data = val;
            newNode->next = NULL;
        if (*front == NULL)
            *front = *rear = newNode;
        else
        {   
            newNode->next = *front ;
            *front = newNode;
        }
    }
}

int dequeue_from_front(Node **front)
{
    if (isEmpty(*front))
        cout << "Node is Empty" << endl;
    else
    {
        Node *newNode = *front;
        int deleted_item = newNode->data;
        *front = (*front)->next;
        delete newNode;
        return deleted_item;
    }
}

void traversal(Node *front)
{
    while (front)
    {
        cout << front->data << " ";
        front = front->next;
    }
    cout<<endl;
}

int main()
{
    Node *Que = new Node;
    Node *front = NULL;
    Node *rear = NULL;

    int input_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(input_arr) / sizeof(input_arr[0]);

    for (int i = 0; i < n; i++)
    {
        enqueue_from_rear(&front, &rear, input_arr[i]);
    }

    traversal(front);

    enqueue_from_front(&front , &rear , 69);
    cout << endl << "Deleted Element " << dequeue_from_front(&front) << endl;
    traversal(front);

    return 0;
}