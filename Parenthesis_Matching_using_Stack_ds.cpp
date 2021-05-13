#include <iostream>
#include <string.h>

using namespace std;

class Node
{
public:
    int size ;
    int top ;
    class *arr;
};

class Node *top = NULL;
//(class Node *)malloc(sizeof(class Node));
int isEmpty(class Node *ptr)
{
    if (ptr == NULL)
        return 1;
    else
        return 0;
}

class Node *push(class Node *ptr, char value)
{
    class Node *temp = (class Node *)malloc(sizeof(class Node));
    temp->data = value;
    temp->next = ptr;
    ptr = temp;
    return ptr;
}

void pop(class Node *ptr)
{
    class Node *temp = ptr;
    top = (ptr)->next;
    free(temp);
}

void Traversal(class Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}
int main()
{
   char * expression = "((1+2)(*---$$)))";

   
    return 0;
}