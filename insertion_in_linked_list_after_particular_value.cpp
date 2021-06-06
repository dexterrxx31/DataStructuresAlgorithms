#include<iostream>
using namespace std ;
class Node{
    public:
        int data;
        class Node * next ;
};
void linked_list_traversal (class Node * head) 
{
    while (head != NULL)
    {
        cout<<"|"<<head->data<<"|";
        head = head->next ;
    }
}

class Node * create_node (class Node * head ,int data)
{   
    class Node * new_node  = new Node ;
    new_node->data = data ;
    new_node->next = NULL ;
    head->next = new_node ;
    head = new_node ;
    return head ;  
}

void insertionInBetween( class Node * head ,int information_P , int data_to_be_inserted)
{   class Node * new_node = new Node ;
    new_node->data = data_to_be_inserted ;
    while( head != NULL )
    {   if(head->data == information_P)
            break;
        head = head->next ;
    }
    new_node->next = head->next;
    head->next = new_node;
}

int main()
{   
    // Creating an array of integers (1-10)
    int array_of_integer_1[10] ;
    
    for(int i = 0 ; i < 10 ; i++)
    {
        array_of_integer_1[i] = i+1 ; 
    }

    //Creating a head Node for your linked list 1.
    class Node * head_1 = new Node ;
    head_1->data = array_of_integer_1[0] ;
    head_1->next = NULL ;

    // Connecting more elements to linked list 1 
    class Node * new_node_1 ;
    new_node_1 = create_node(head_1 , array_of_integer_1[1]);
    for(int i = 2 ; i < 10 ; i++)
    {
        new_node_1  = create_node(new_node_1 , array_of_integer_1[i]);
    }

    //Traveral of Linked List 1
    cout<<"List 1 --->";
    linked_list_traversal(head_1);


    //------------------------------------------------------------------------//
    int information_P = 78 ;
    int element_to_be_inserted_after = 5;
    insertionInBetween(head_1 , element_to_be_inserted_after , information_P );
    cout<<endl<<"After Insertion --->";
    linked_list_traversal(head_1);


    return 0 ;
}