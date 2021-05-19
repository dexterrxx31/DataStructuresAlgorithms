/* Every node has atmost degree 2 is called binary tree
if tree has n nodes then it will have n-1 edges
Degree of node: No of direct children.
Degree of tree : highest degree of a node among all the nodes present in the tree.
Binary tree : Tree of degree two.
*/
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    class Node *left;
    class Node *right;
};

class Node *create_Node(int data)
{
    class Node *newNode = (class Node *)malloc(sizeof(class Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
/*                  1       (ROOT)
                2       3   
              left    right

Three types of Traversal in Binary Tress .
    PreOrder     - Root/Left/Right
    postOrder    - Left/Right/Root
    inOrder      - left/Root/Right

*/

void preOrder(class Node *ptr)
{
    if (ptr != NULL)
    {
        cout << ptr->data << "||";
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}

void postOrder(class Node *ptr)
{
    if (ptr != NULL)
    {
        postOrder(ptr->left);
        postOrder(ptr->right);
        cout << ptr->data << "||";
    }
}

int isBST(class Node *ptr)
{
    static class Node *previous_node = NULL;

    if (ptr != NULL)
    {
        if(!isBST(ptr->left))
        {
            return 0 ;
        }
        if(previous_node != NULL && ptr->data <= previous_node->data)
        {
            return 0 ;
        }
        previous_node = ptr;
        return isBST(ptr ->right);
    }
    else
    {
        return 1;
    }
}
/*  
For Binary Search Trees inOrder Traversal gives ascending order of elements.
therefore we can check this using function of inOrder Traversal with some modification
*/

int main()
{
    class Node *p = create_Node(1);
    class Node *p1 = create_Node(2);
    class Node *p2 = create_Node(3);
    class Node *p3 = create_Node(4);
    class Node *p4 = create_Node(5);
    class Node *p5 = create_Node(6);
    class Node *p6 = create_Node(7);
    //Linking Nodes to form a tree

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    // preOrder(p);
    // cout << endl;
    // postOrder(p);
    // cout << endl;
    // inOrder(p);
    if(isBST(p))
    {
        cout<<"Given Tree is Binary Search Tree.";
    }
    else
    {
        cout<<"Given Tree is not Binary Search Tree.";
    }
    return 0;
}