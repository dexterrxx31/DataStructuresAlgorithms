#include<iostream>
using namespace std ;

class Node{
    public:
    int data;
    class Node * next;
};
void traversalOfElements(class Node * ptr)
{   class Node * head = ptr;
    while(1)
    {   if(ptr->next == head)
            break;
        ptr = ptr->next;
        cout<<ptr->data<<"||";
    }
}

void insertionOfElement(class Node * ptr , class Node * NewNode , int position)
{
    class Node * p = ptr;
    int counter = 0;
    while( counter != position )
    {
        p = p->next ;
        counter++;
    }
    NewNode->next = p->next;
    p->next = NewNode;
}

void deletionOfElement(class Node * ptr , int positon)
{

}
int main()
{   
    int position =2 , dataOfNewElement = 67;
    class Node * head ;
    class Node * second ;
    class Node * third ;
    class Node * forth;
    class Node * newNode;

    head = new Node ;
    second = new Node ;
    third = new Node ;
    forth = new Node ;
    newNode = new Node ;
    newNode ->data = dataOfNewElement;

    head->data = 7 ;
    head->next = second;

    
    second->data = 8 ;
    second->next = third;

    
    third->data = 9 ;
    third->next = forth;

      
    forth->data = 10 ;
    forth->next = head;
    
    insertionOfElement(head,newNode,position);
    traversalOfElements(head);
    return 0 ;
}