#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    class Node *next;
};
/*
We can use structure too
struct Node 
{
    int data;
    Node* next;
}
*/

// we can use (*pointer).its_members
//in place of pointer->its_members

void traversalOfElements(Node *head)
{
    while (head!= NULL)   // head  head != 0
    {
        cout << (*head).data << " ";
        head = head -> next;
        //head = head->next ;
    }
}

void recursive_display(Node * head)
{
    if(head)
    {
        cout<<(*head).data<<" " ;
        recursive_display((*head).next);
    }
}

//(*head).data works same as head->data

//display Linked list reverse order
void recursive_display_reverse(Node * head)
{
    if(head)
    {
        recursive_display_reverse((*head).next);
        cout<<(*head).data<<" " ;
    }
}

//counting no of nodes in linked list
int count_nodes(Node * head)
{
    int count  = 0 ;
    while (head)
    {
        count++;
        head = head->next ;
    }
    return count ;
}

//counting no of nodes in linked list
int count_nodes_recursive(Node * head)
{
    if(!head)
    {
        return 0 ;
    }
    else{
        return count_nodes_recursive(head->next) + 1 ;
    }

}

int greatest_number(Node * head)
{
    int max_ = INT_MIN ;
    while (head)
    {
        max_  = max(max_ , head->data);
        head = head->next ;
    }
    return max_;
}

int greatest_number_recursive(Node * head)
{
    if(!head)
        return INT_MIN;
    return max(greatest_number_recursive(head->next) , head->data);
}

void insert_ele_at_end(int ele, class Node *head)
{
    class Node *newNode = new Node;
    (*newNode).data = ele;
    newNode->next = NULL;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = newNode;
}

Node *insert_ele_at_begining(int ele, Node *head)
{
    Node *newNode = new Node;
    (*newNode).data = ele;
    newNode->next = head;
    head = newNode;
    return head;
}

class Node *delete_ele_beg(class Node *head)
{
    class Node *newNode = new Node;
    newNode = head;
    head = head->next;
    delete newNode;
    return head;
}

void delete_ele_end(class Node *head)
{
    class Node *newNode = new Node;
    while ((*head).next->next != NULL)
    {
        head = head->next;
    }

    newNode = head->next;
    head->next = NULL;
    delete newNode;
}

void delete_any_ele_data(class Node *head, int ele)
{
    class Node *newNode = new Node;
    while (head->data == ele)
    {
        head = head->next;
    }

    newNode = head->next;
    head->next = newNode->next;
    newNode->next = NULL;
    delete newNode;
}

int main()
{
    Node *head = new Node;  //head Node pointer of linked list 
    head->data = 0;
    head->next = NULL;
    int arr[] = {1,2,3,4,5,6,7,8,9};    //taking array for input in linked list 
    int n = sizeof(arr) /sizeof(arr[0]);    //size of array

    for (int i = 0; i < n; i++)
    {
        head = insert_ele_at_begining(arr[i], head);
    }

    //recursive_display(head);
    //recursive_display_reverse(head);
    //cout<<count_nodes(head);
    //cout<<count_nodes_recursive(head);
    //cout<<greatest_number(head);
    cout<<greatest_number_recursive(head);
    return 0;
}