#include <iostream>
#include <string.h>

using namespace std;

class Node
{
public:
    char data;
    class Node *next;
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
    char const *arr = "1(3+2)(+67+)";

    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == '(' || ')')
        {
            if (arr[i] == '(')
            {
                top = push(top, arr[i]);
                Traversal(top);
            }
            else
            {
                if (isEmpty(top))
                {
                    cout << "Parenthesis Mismatch";
                    break;
                }
                pop(top);
                Traversal(top);
            }
        }
    }
    Traversal(top);
    if (top == NULL)
    {
        cout << "Parenthesis Matched";
    }
    return 0;
}