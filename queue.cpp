#include <bits/stdc++.h>
using namespace std;

struct queue
{
    int size;
    int front;
    int rear;
    int arr *
};

int isFull(queue *ptr)
{
    if (ptr > rear == ptr->size - 1)
        return 1;
    else
        return 0;
}

int isEmpty(queue *ptr)
{
    if (ptr->front == ptr->rear)
        return 1;
    else
        return 0;
}

void enqueue(queue *ptr, int val)
{   
    if(isFull)
        cout<<"Queue is Full"<<endl;
    else
    {
        ptr->rear++;
        ptr->arr[rear] = val;
    }
}

int main()
{
    queue *st = new queue;
    st->size = 20;
    st->front = -1;
    st->rear = -1;
    st->arr = new int[st->size];

    int input_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(input_arr) / sizeof(input_arr[0]);
    for (int i = 0; i < n; i++)
    {
        push(st, input_arr[i]);
    }

    return 0;
}