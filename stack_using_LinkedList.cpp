#include<iostream>
using namespace std ;

class Node {
    public:
    int data;
    class Node *next ;
};
int isEmpty(class Node *ptr)
{
    if(ptr == NULL)
    {
        cout<<"Stack is Full";
        return 1;
    }else{
        return 0 ;
    }
}
int isFull(class Node *ptr)
{
    class Node *newNode = (class Node*)malloc(sizeof(class Node));
    if (newNode == NULL)
    {
        cout<<"Stack is Full";
        return 1;
    }else {
        return 0;
    }
}
void push( class Node *top , int value)
{
    class Node *newNode = (class Node *)malloc(sizeof(class Node));
    if(newNode == NULL)
    {
        cout<<"Stack Overflow";
    }else{
        newNode->next = top ;
        top = newNode ;
    }
}
int pop( class Node *top)
{  
    if(isEmpty(top)){
        cout<<"Stack Underflow";
        return -1 ;
    }else{
        class Node *temp = top ;
        top = top->next;
        int data = temp->data ;
        free(temp);
        return data ;
    }
}
int main()
{
    return 0 ;
}