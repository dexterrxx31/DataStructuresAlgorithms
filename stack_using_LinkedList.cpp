#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

int isEmpty(Node *ptr)
{
    if (ptr == NULL)
        return 1;
    else
        return 0;
}

int isFull()
{
    Node *newNode = (class Node *)malloc(sizeof(class Node));
    if (newNode == NULL)
        return 1;
    else
        return 0;
}

Node *push(Node *top, int value)
{
    if (isFull())
        cout << "Stack Overflow" << endl;
    else
    {
        //class Node *newNode = (class Node *)malloc(sizeof(class Node));
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        return top;
    }
}

void linkedListTraversal(Node *ptr)
{
    while (ptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int pop(Node **top)
{
    if (isEmpty(*top))
    {
        cout << "Stack Underflow";
        return -1;
    }
    else
    {
        Node *temp = *top;
        *top = (*top)->next;
        int data = temp->data;
        delete temp;
        return data;
    }
}

int main()
{
    Node *top = NULL;
    //taking an input array for push operation
    int arr[] = {1, 3, 4, 5, 6, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        top = push(top, arr[i]);

    linkedListTraversal(top);
    cout << endl;

    int element = pop(&top);
    printf("Popped element is %d\n", element);
    linkedListTraversal(top);
    return 0;
}