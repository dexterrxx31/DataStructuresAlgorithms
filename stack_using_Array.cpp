#include <iostream>
#include <stdlib.h> //used for Malloc
using namespace std;

class stack
{
public:
    int size;
    int top;
    int *arr;
};

int IsEmpty(class stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int IsFull(class stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(class stack *s, int value)
{
    if (IsFull(s))
    {
        cout << "Stack overflow" << endl;
        return -1;
    }
    else
    {
        s->top = s->top + 1;
        s->arr[s->top] = value;
        return 0;
    }
}
int pop(class stack *s)
{
    if (IsEmpty(s))
    {
        cout << "Stack underflow" << endl;
        return -1;
    }
    else
    {
        int value = s->arr[s->top];
        s->top = s->top - 1;
        return value;
    }
}

int peek(class stack *ptr, int position)
{
    int ArrayIndex = ptr->top - position + 1;
    if (ArrayIndex < 0)
    {
        cout << "Not a valid position for the stack \n";
        return -1;
    }
    else
    {
        return ptr->arr[ArrayIndex];
    }
}
int stackTop(class stack *ptr)
{
    return ptr->arr[ptr->top];
}
int staclBottom(class stack *ptr)
{
    return ptr->arr[0];
}
int main()
{ //Declaration of a Stack of array without using pointers.
    // class stack s ;
    // s.size = 80 ;
    // s.top = -1 ;
    // s.arr = (int *)malloc(size * sizeof(int));

    //Declaration of a Stack of array using pointers.
    class stack *s;
    s = (class stack *)malloc(sizeof(class stack));
    s->size = 50;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    //pushing some elements in stack
    push(s, 21);
    push(s, 23);
    push(s, 99);
    push(s, 75);
    push(s, 3);
    push(s, 64);
    push(s, 57);
    push(s, 46);
    push(s, 89);
    push(s, 6);
    push(s, 5);
    push(s, 75);

    //testing peek function
    for (int j = 1; j <= s->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(s, j));
    }
}