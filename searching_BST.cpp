#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *insertLevelOrder(int arr[], int i, int n)
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
        cout << root->data << " ";
        inorder_traversal(root->right);
    }
}

void search_bst(Node *node, int e)
{

    if (node != nullptr)
    {
        if (node->data == e)
        {
            cout << "found";
            return;
        }
        if (node->data > e)
        {
            return search_bst(node->left, e);
        }
        else
        {
            return search_bst(node->right, e);
        }
    }
    else
    {
        cout << "Element is not present in tree.";
    }
}

int main()
{
    int arr[] = {30, 20, 40, 10, 25, 35, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = insertLevelOrder(arr, 0, n);
    // inorder_traversal(root);
    search_bst(root, 1);
    return 0;
}