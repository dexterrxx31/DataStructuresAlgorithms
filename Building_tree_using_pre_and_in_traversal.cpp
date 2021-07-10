#include<iostream>
using namespace std ;

//Body of Node

struct Node
{
    int data ;
    struct Node* left  ;
    struct Node* right ;

    Node(int val)
    {
        data = val ; 
        left = NULL ;
        right = NULL ;
    }
};

int search(int inorder[] , int start ,int end ,int current)
{
    for(int i = start ; i <=end ; i++)
    {
        if (inorder[i] == current)
        {
            return i ; 
        }
    }
    return -1 ; 
}

void inorder_traversal ( Node* root )
{   
    if(root == NULL)
    {
        return ;
    }
    inorder_traversal(root->left) ;
    cout<<root->data<<" " ;
    inorder_traversal(root->right) ;
}
struct Node* Build_tree(int preorder[] , int  inorder[] , int start ,int end )
{
    static int index = 0 ;
    if(start > end)
    {   
        return NULL ;
    } 
    int current = preorder[index] ;
    index++ ;
    Node* node = new Node(current) ; 
    if(start == end)
    {
        return node ;
    }
    int pos = search(inorder , start , end , current ) ;
    node->left = Build_tree(preorder , inorder , start , pos -1 ) ;
    node->right = Build_tree(preorder , inorder , pos + 1 , end) ;
    return node ; 
}
int main()
{
    int preorder[] = {1,2,4,3,5}; 
    int inorder[] = {4,2,1,5,3};
    struct Node* root = Build_tree(preorder , inorder , 0 , 4);
    inorder_traversal(root); 
    return 0 ; 
}
