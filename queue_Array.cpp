#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(Queue *ptr)
{
    if (ptr->rear == ptr->size - 1)
        return 1;
    else
        return 0;
}

int isEmpty(Queue *ptr)
{
    if (ptr->front == ptr->rear)
        return 1;
    else
        return 0;
}

void enqueue(Queue *ptr, int val)
{
    if (isFull(ptr))
        cout << "Queue is Full" << endl;
    else
    {
        ptr->rear++;
        ptr->arr[ptr->rear] = val;
    }
}

int dequeue(Queue *ptr)
{
    if (isEmpty(ptr))
        cout << "Queue is Empty" << endl;
    else
    {
        ptr->front++;
        int deleted_item = ptr->arr[ptr->front];
        ptr->arr[ptr->front] = 0;
        return deleted_item;
    }
}

void traversal(Queue *ptr)
{
    for (int i = 0; i < ptr->size; i++)
    {
        cout << ptr->arr[i] << " ";
    }
}

int main()
{
    Queue *st = new Queue;
    st->size = 20;
    st->front = -1;
    st->rear = -1;
    st->arr = new int[st->size];

    int input_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(input_arr) / sizeof(input_arr[0]);

    for (int i = 0; i < n; i++)
    {
        enqueue(st, input_arr[i]);
    }

    traversal(st);
    cout << endl
         << dequeue(st) << endl;
    traversal(st);
    return 0;
}