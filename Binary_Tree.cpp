/* Every node has atmost degree 2 is called binary tree
if tree has n nodes then it will have n-1 edges
Degree of node: No of direct children.
Degree of tree : highest degree of a node among all the nodes present in the tree.
Binary tree : Tree of degree two.
*/
#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    class Node* left ;
    class Node* right ;
};

class Node* create_Node (int data)
{
    class Node* newNode = (class Node*)malloc(sizeof(class Node));
    newNode->data = data ;
    newNode->left = NULL;
    newNode->right = NULL ;
    return newNode;
}
int main()
{   
    class Node * p = create_Node(1);
    class Node * p1 = create_Node(2);
    class Node * p2 = create_Node(3);
    //class Node * p3 = create_Node(4);
    //class Node * p4 = create_Node(5);

    //Linking Nodes to form a tree 

    p->left = p1 ;
    p->right = p2 ;
    return 0 ;
}