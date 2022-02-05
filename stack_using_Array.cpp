#include <bits/stdc++.h>
using namespace std;

struct stk
{
public:
    int size;
    int top;
    int *arr;
};

int IsEmpty(stk *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

int IsFull(stk *ptr)
{
    if (ptr->top == ptr->size)
        return 1;
    else
        return 0;
}

void push(stk *ptr, int value)
{
    if (IsFull(ptr))
    {
        cout << "Stack overflow" << endl;
        return;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int void pop(stk *ptr)
{
    if (IsEmpty(ptr))
    {
        cout << "Stack underflow" << endl;
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int peek(class stk *ptr, int position)
{
    int ArrayIndex = ptr->top - position + 1;
    if (ArrayIndex < 0)
    {
        cout << "Not a valid position for the stk \n";
        return -1;
    }
    else
    {
        return ptr->arr[ArrayIndex];
    }
}

int stackTop(class stk *ptr)
{
    return ptr->arr[ptr->top];
}

int stackBottom(class stk *ptr)
{
    return ptr->arr[0];
}

int main()
{ //Declaration of a Stack of array without using pointers.
    // class stk s ;
    // s.size = 80 ;
    // s.top = -1 ;
    // s.arr = (int *)malloc(size * sizeof(int));

    //Declaration of a Stack of array using pointers.
    stk *s = new stk;
    //s = (class stk *)malloc(sizeof(class stk));
    s->size = 20;
    s->top = -1; //initially keeping stk top as -1
    //s->arr = (int *)malloc(s->size * sizeof(int));
    s->arr = new int[s->size];

    //taking one input arr for pushing some value
    int input_arr[] = {1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 10};
    int n = sizeof(input_arr) / sizeof(input_arr[0]); //size of input array

    for (int i = 0; i < n; i++)
    {
        push(s, input_arr[i]); //pushing values in array
    }

    printf("The top most value of this stk is %d\n", stackTop(s));
    printf("The bottom most value of this stk is %d\n", stackBottom(s));
    //testing peek function
    // for (int j = 1; j <= s->top + 1; j++)
    // {
    //     printf("The value at position %d is %d\n", j, peek(s, j));
    // }
}