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
struct Node* Build_tree(int postorder[] , int  inorder[] , int start ,int end )
{
    static int index = 4 ;
    if(start > end)
    {   
        return NULL ;
    } 
    int current = postorder[index] ;
    index-- ;
    Node* node = new Node(current) ; 
    if(start == end)
    {
        return node ;
    }
    int pos = search(inorder , start , end , current ) ;
    node->right = Build_tree(postorder , inorder , pos+1 , end ) ;
    node->left = Build_tree(postorder , inorder , start , pos - 1) ;
    return node ; 
}
int main()
{
    int postorder[] = {4,2,5,3,1}; 
    int inorder[] = {4,2,1,5,3};
    struct Node* root = Build_tree(postorder , inorder , 0 , 4);
    inorder_traversal(root); 
    return 0 ; 
}
