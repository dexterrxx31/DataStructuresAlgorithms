#include<iostream>
using namespace std ;

class Node{
    public:
    int data;
    class Node * next ;
};
// we can usee (*pointer).its_members
//in place of pointer->its_members
void traversalOfElements(class Node * address)
{
    while(address != NULL)
    {
        cout<<(*address).data <<"|";
        address = address ->next;
    }
}
int main()
{      
    class Node * head ;
    class Node * second ;
    class Node * third ;

    head = new Node ;
    second = new Node ;
    third = new Node ;

    head->data = 7 ;
    head->next = second;

    
    second->data = 8 ;
    second->next = third;

    
    third->data = 9 ;
    third->next = NULL;
    traversalOfElements(head);
    return 0 ;
}