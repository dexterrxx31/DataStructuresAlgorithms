#include <iostream>
#include <stdlib.h>

using namespace std;

class Node
{
public:
    int size;
    int top;
    char *arr;
};
int isFull(class Node *ptr)
{
    if (ptr->top == ptr->size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(class Node *ptr)
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

void push(class Node *ptr, char value)
{
    if (isFull(ptr))
    {
        cout << "Stack Overflow ! Sorry cant push further elements in Stack" << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr -> top] = value;
    }
}
char pop(class Node *ptr)
{
    if (isFull(ptr))
    {
        cout << "Stack Underflow!";
    }
    else
    {
        char element = ptr->arr[ptr->top];
        ptr->top--;
        return element;
    }
}

// void Traversal(class Node *ptr)
// {
//     while (ptr != NULL)
//     {
//         cout << ptr->data << endl;
//         ptr = ptr->next;
//     }
// }

int parenthesisMatching(char *expression)
{
    class Node *sp = (class Node *)malloc(sizeof(class Node));
    sp->size = 20;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(')
        {
            push(sp, '(');
        }
        else if (expression[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
}
int main()
{
    const char * expression = "((8)(*--$$9))";

    if (parenthesisMatching(expression))
    {
        cout << "The parenthesis is matching";
    }
    else
    {
        cout << "The parenthesis is not matching";
    }

    return 0;
}