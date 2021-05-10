#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    class Node *next;
};
class Node *top = NULL;
int isEmpty(class Node *ptr)
{
    if (ptr == NULL)
    {
        //cout<<"Stack is Full";
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(class Node *ptr)
{
    class Node *newNode = (class Node *)malloc(sizeof(class Node));
    if (newNode == NULL)
    {
        //cout<<"Stack is Full";
        return 1;
    }
    else
    {
        return 0;
    }
}
class Node *push(class Node *ptr, int value)
{
    if (isFull(ptr))
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        class Node *newNode = (class Node *)malloc(sizeof(class Node));
        newNode->data = value;
        newNode->next = ptr;
        ptr = newNode;
        return ;
    }
}
void linkedListTraversal(class Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
void peek(class Node* ptr , int position)
{   int counter = 1 ;
    while(ptr != NULL)
    {   
        if (counter == position)
        {
            cout<<"Element is :"<<ptr->data<<endl;
            break ;
        }
        counter++ ;
        ptr = ptr->next;

    }
}
void top_of_stack(class Node* ptr)
{
    cout<<"Top element is :"<<ptr->data<<endl;
}
void bottom_of_stack(class Node* ptr)
{
    while (ptr != NULL)
    {
        if (ptr->next == NULL)
        {
            cout<<"Bottom element is :"<<ptr->data<<endl;
        }
        ptr = ptr->next;
        
    }
    
}
int pop(class Node *tp)
{
    if (isEmpty(tp))
    {
        cout << "Stack Underflow";
        return -1;
    }
    else
    {
        class Node* temp = tp;
        top = (tp)->next;
        int data = temp->data;
        free(temp);
        return data;
    }
}
int main()
{
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);

    // linkedListTraversal(top);
    // int element = pop(top);
    // printf("Popped element is %d\n", element);
    // linkedListTraversal(top);
    
    peek(top , 2);
    //top_of_stack(top);
    //bottom_of_stack(top);
    return 0;
}