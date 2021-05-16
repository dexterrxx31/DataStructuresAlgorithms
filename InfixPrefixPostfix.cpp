/*
Infix :- Operator is in between Oprands.
example :-    a        +          b 
          <Oprand> <Operator> <Oprand>
Prefix :- Operator comes before Oprands.
example :-    +        a          b 
          <Oprand> <Operator> <Oprand>
Postfix :- Operator comes after Oprands.
example :-    a        b         + 
          <Oprand> <Operator> <Oprand>
*/

#include <iostream>
#include <string.h>
using namespace std;

class stack
{
public:
    int top;
    int size;
    char *arr;
};

int isEmpty(class stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(class stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(class stack *sp, char element)
{
    if (isFull(sp))
    {
        cout<<"Stack OverFlow"<<endl;
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = element;
    }
}

char pop(class stack* sp)
{
    if (isEmpty(sp))
    {
        cout << "Stack UnderFlow" << endl;
        return -1;
    }
    else
    {
        char popped_element = sp->arr[sp->top];
        sp->top--;
        return popped_element;
    }
}

char stack_top(class stack* sp)
{
    return sp->arr[sp->top];
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}

const char *infix_to_postfix(const char *expression)
{
    class stack *sp = (class stack *)malloc(sizeof(class stack));
    sp->top = -1;
    sp->size = 10;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *pos = (char *)malloc((strlen(expression) + 1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (expression[i] != '\0')
    {
        if (!isOperator(expression[i]))
        {
            pos[j] = expression[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(expression[i]) > precedence(stack_top(sp)))
            {
                push(sp, expression[i]);
                i++;
            }
            else
            {
                pos[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        pos[j] = pop(sp);
        j++;
    }
    pos[j] = '\0';
    return pos;
}
int main()
{
    const char *expression = "x-y/z-k*d";
    const char *postfix = infix_to_postfix(expression);
    cout << "Infix : " << expression << endl;
    cout << "Postfix : " << postfix << endl;
    return 0;
}
