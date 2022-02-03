#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void traverse_linked_list(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "||";
        head = head->next;
    }
}

void add_node_to_end(struct Node *head, int data)
{
    struct Node *node_to_be_inserted = new Node;
    node_to_be_inserted->data = data;
    node_to_be_inserted->next = NULL;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = node_to_be_inserted;
}

struct Node *add_node_to_beginning(struct Node *head, int data)
{
    struct Node *node_to_be_inserted = new Node;
    node_to_be_inserted->data = data;
    node_to_be_inserted->next = head;
    return node_to_be_inserted;
}

int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;

    head = new Node;
    first = new Node;
    second = new Node;

    head->data = 67;
    head->next = first;
    first->data = 98;
    first->next = second;
    second->data = 78;
    second->next = NULL;
    traverse_linked_list(head);

    cout << endl;
    head = add_node_to_beginning()
        traverse_linked_list(head);
    return 0;
}