#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int size;
    int top;
    char *arr;
};

int isFull(Node *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}

int isEmpty(Node *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

void push(Node *ptr, char value)
{
    if (isFull(ptr))
        cout << "Stack Overflow !!!" << endl;
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(Node *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack Underflow!";
        return -1;
    }
    else
    {
        char element = ptr->arr[ptr->top];
        ptr->top--;
        return element;
    }
}

int matched(char a, char b)
{
    if (a == '{' && b == '}')
        return 1;
    if (a == '(' && b == ')')
        return 1;
    if (a == '[' && b == ']')
        return 1;
    return 0;
}

int parenthesisMatching(const char *expression)
{
    Node *sp = new Node;
    sp->size = 20;
    sp->top = -1;
    sp->arr = new char[sp->size];

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
            push(sp, expression[i]);
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            if (isEmpty(sp))
                return 0;
            char popped_element = pop(sp);
            if (!matched(popped_element, expression[i]))
                return 0;
        }
    }
    
    if (isEmpty(sp))
        return 1;
    else
        return 0;
}

int main()
{ // it is necessary to have const char pointer else code will not work as per as c++
    const char *expression = "((8)[{*--$$9}])";
    if (parenthesisMatching(expression))
        cout << "The parenthesis is matching";
    else
        cout << "The parenthesis is not matching";
    return 0;
}