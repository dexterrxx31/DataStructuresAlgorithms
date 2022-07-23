#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left ;
    Node *right;
};

Node * newNode(int data)
{
    Node * new_node = new Node ;
    new_node->data = data ;
    new_node->left = NULL ;
    new_node->right = NULL ;
    return new_node ; 
}

Node *create_BST(int arr[], int n, int i)
{
    Node *root = nullptr;

    if (i < n)
    {   
        root = newNode(arr[i]);
        root->left = create_BST(arr, n, 2 * i + 1);
        root->right = create_BST(arr, n, 2 * i + 2);
    }
    return root;
}

void inorder_traversal(Node *root)
{
    if(root != NULL)
    {
        inorder_traversal(root->left);
        cout<<root->data<<" ";
        inorder_traversal(root->right);
    }
}

//insert element in BST 
Node * insert_BST(Node * root , int e)
{   

    if(!root)
    {
        Node * node = new Node ;
        node = newNode(e);
        return node ; 
    }
        if(root->data > e)
        {
            root->left = insert_BST(root->left , e );
        }
        else if(root->data < e)
        {
            root->right = insert_BST(root->right , e);
        }
    return root ;    
}

int main()
{
    int arr[] = {30, 20, 40, 10, 25, 35, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node * root = create_BST(arr, n ,0);
    inorder_traversal(root);
    root  = insert_BST(root , 45);
    cout<<endl;
    inorder_traversal(root);
    return 0;
}