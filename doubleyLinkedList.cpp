#include<iostream>
using namespace std ;

class Node{
    public:
    int data;
    class Node * next;
    class Node * previous;
};

void traversal(class Node * headOrPrevious)
{   
    if (headOrPrevious->next == NULL)
    {   while(headOrPrevious != NULL)
        {
         
            cout<<headOrPrevious->data<<"|";
            headOrPrevious = headOrPrevious ->previous ;
        }
    }
    else 
    {
        while(headOrPrevious != NULL)
        {   cout<<headOrPrevious->data<<"|";
            headOrPrevious = headOrPrevious ->next ;
        }
    }
}
int main()
{   
    class Node * head; 
    class Node * first; 
    class Node * second; 
    class Node * third; 
    class Node * forth;

    head = new  Node ;
    first = new  Node ;
    second =new  Node ; 
    third =new  Node ;
    forth = new  Node ;

    head->next = first ;
    head->previous = NULL;

    first->next = second ;
    first->previous = head;
    
    second->next = third ;
    second->previous = first;

    third->next = forth ;
    third->previous = second;

    forth->next = NULL;
    forth->previous = third;
    head->data = 1;
    first->data = 2;
    second->data = 3;
    third->data = 4;
    forth->data = 5;
    traversal(head);
    cout<<endl;
    traversal(forth);
    return 0;
}