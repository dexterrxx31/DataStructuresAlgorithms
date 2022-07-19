#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * left;
    Node * right;
};

Node * newNode(int data)
{
    Node * node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node * insertLevelOrder(int arr[], int i, int n)
{
    Node *root = nullptr;
    if (i < n)
    {
        root = newNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

void inorder_traversal(Node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        cout<<root->data<<" ";
        inorder_traversal(root->right);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 6, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = insertLevelOrder(arr, 0, n);
    inorder_traversal(root) ;
}