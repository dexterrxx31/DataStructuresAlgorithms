#include<iostream>
using namespace std ;
class Node{
    public:
        int data;
        class Node * next ;
};
void traversalOfElements(class Node * ptr)
{
    while(ptr != NULL)
    {
        cout<<ptr ->data <<"|";
        ptr = ptr ->next;
    }
}
void deletethisElement(class Node * ptr , int position)
{   class Node* q;
    int counter = 1;
    while ( ptr != NULL)
    {
        ptr = ptr ->next ;
        counter++;
        if(counter == position)
        {
            q = ptr ->next ;
            ptr ->next = q ->next ;
            free(q);
        }
    }
} 
int main()
{
    int position =2;
    class Node * head ;
    class Node * second ;
    class Node * third ;
    class Node * forth;
    //class Node * NewNode;
    //class Node * head2 ;
    //head2 = new Node ;
    head = new Node ;
    second = new Node ;
    third = new Node ;
    forth = new Node ;
    //NewNode = new Node ;

    head->data = 7 ;
    head->next = second;

    //head2 = head;
    second->data = 8 ;
    second->next = third;

    
    third->data = 9 ;
    third->next = forth;

      
    forth->data = 10 ;
    forth->next = NULL;
    
    //NewNode->data = 78;
    
    //traversalOfElements(head);
    //cout<<endl;
    //insertionInBegining(NewNode,head);
    //head = NewNode ;
    //traversalOfElements(head);
    //insertionInEnd(NewNode,head);
    
    //traversalOfElements(head);
    //insertionInBetween(NewNode,head,position);
    deletethisElement(head , position);
    traversalOfElements(head);
    return 0 ;
}