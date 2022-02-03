#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    class Node *next;
};
// we can usee (*pointer).its_members
//in place of pointer->its_members
void traversalOfElements(class Node *head)
{
    while (head != NULL)
    {
        cout << (*head).data << "|";
        head = (*head).next;
        //head = head->next ;
    }
}

void insert_ele_at_end(int ele ,class Node* head)
{
    class Node *newNode = new Node ;
    (*newNode).data = ele ;
    newNode->next = NULL;
    while(head->next != NULL)
    {
        head = head->next; 
    }
    head->next = newNode ;
}

class Node* insert_ele_at_begining(int ele ,class Node* head)
{
    class Node *newNode = new Node ;
    (*newNode).data = ele ;
    newNode->next = head ;
    head = newNode ;
    return head;
}

class Node* delete_ele_beg(class Node* head)
{
    class Node *newNode = new Node ;
    newNode = head ;
    head = head->next ;
    delete newNode;
    return  head ; 
}

void delete_ele_end(class Node* head)
{
    class Node *newNode = new Node ;
    //newNode = head ;
    while (head->next != NULL)
    {
        /* code */
    }
    
    delete newNode; 
}

int main()
{
    class Node *head;
    class Node *second;
    class Node *third;

    head = new Node;
    second = new Node;
    third = new Node;

    head->data = 7;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 9;
    third->next = NULL;
    traversalOfElements(head);
    // head = insert_ele_at_begining(11 , head);
    cout<<endl;
    head = delete_ele_beg(head);
    traversalOfElements(head);
    return 0;
}