#include<iostream>
using namespace std ;

class Node {
    public:
    int data;
    class Node *next;
};

class Node * create_node (class Node * head ,int data)
{   
    class Node * new_node  = new Node ;
    new_node->data = data ;
    new_node->next = NULL ;
    head->next = new_node ;
    head = new_node ;
    return head ;  
}

void linked_list_traversal (class Node * head) 
{
    while (head != NULL)
    {
        cout<<"|"<<head->data<<"|";
        head = head->next ;
    }
}

class Node * concatenate_two_linked_list ( class Node * List_1_head ,class Node * List_2_head)
{   
    class Node * new_node = new Node ;
    new_node = List_1_head ;
    while(List_1_head->next != NULL)
    {
        List_1_head = List_1_head->next ;
    }
    List_1_head->next = List_2_head ;
    return new_node ;
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
// Creating an array of integers (11-20)
    int array_of_integer_2[10] ;
    
    for(int j = 0 ; j < 10 ; j++)
    {
        array_of_integer_2[j] = j+11 ; 
    }
    
    //Creating a head Node for your linked list 1.
    class Node * head_2 = new Node ;
    head_2->data = array_of_integer_2[0] ;
    head_2->next = NULL ;

    // Connecting more elements to linked list 1 
    class Node * new_node_2 ;
    new_node_2 = create_node(head_2 , array_of_integer_2[1]);
    for(int j = 2 ; j < 10 ; j++)
    {
        new_node_2  = create_node(new_node_2 , array_of_integer_2[j]);
    }

    //Traveral of Linked List 1
    cout<<endl;
    cout<<"List 2 --->";
    linked_list_traversal(head_2);

    class Node * new_node_head = new Node ; 
    new_node_head = concatenate_two_linked_list(head_1 , head_2) ;
    cout<<endl;
    cout<<"Concatenated List of List 1 and List 2 "<<endl;
    linked_list_traversal(new_node_head);
    return 0 ;
}