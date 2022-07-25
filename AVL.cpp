#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    int height;
};

int get_height(Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

Node *create_node(int e)
{
    Node *node = new Node;
    node->data = e;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int get_bf(Node *node)
{
    if (node == NULL)
        return 0;

    return get_height(node->left) - get_height(node->right);
}

Node *right_rotation(Node *y)
{
    Node *x = y->left;
    Node *t1 = x->right;

    x->right = y;
    y->left = t1;

    y->height = max(get_height(y->right), get_height(y->left)) + 1;
    x->height = max(get_height(x->right), get_height(x->left)) + 1;

    return x;
}

Node *left_rotation(Node *x)
{
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    y->height = max(get_height(y->right), get_height(y->left)) + 1;
    x->height = max(get_height(x->right), get_height(x->left)) + 1;

    return y;
}

Node *insert_BST(Node *root, int e)
{
    if (root == NULL)
        return create_node(e);

    if (e > root->data)
        root->right = insert_BST(root->right, e);
    else if (e < root->data)
        root->left = insert_BST(root->left, e);

    root->height = 1 + max(get_height(root->right), get_height(root->left));
    int bf = get_bf(root);

    // left left case
    if (bf > 1 and e < root->left->data)
        return right_rotation(root);

    // right right case
    if (bf < -1 and e > root->right->data)
        return left_rotation(root);
    // right left  case
    if (bf < -1 and e < root->right->data)
    {
        root->right = right_rotation(root->right);
        return left_rotation(root);
    }
    // left right case
    if (bf > 1 and e > root->left->data)
    {
        root->left = left_rotation(root->left);
        return right_rotation(root);
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

int main()
{
    Node *root = NULL;
    root = insert_BST(root, 1);
    root = insert_BST(root, 2);
    root = insert_BST(root, 5);
    root = insert_BST(root, 3);
    root = insert_BST(root, 4);
    root = insert_BST(root, 6);

    inorder_traversal(root);
    return 0;
}