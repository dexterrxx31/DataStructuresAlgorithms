#include <iostream>
#include <stdlib.h> //used for Malloc
using namespace std;

class stack
{
public:
    int size;
    int top;
    int *arr;
};

int IsEmpty(class stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int IsFull(class stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(class stack *s , int value){
    if(IsFull){
        cout<<"Stack overflow"<<endl;
        return -1;
    }else{
        s-> top++ ;
        s->arr[s->top] = value ;
        return 0; 
    }
    
}
int pop(class stack *s){
    if(IsEmpty){
        cout<<"Stack underflow"<<endl;
        return -1;
    }else{
        int value = s->arr[s->top];
        s->top = s->top - 1 ; 
        return value ;
    }
    
}
int main()
{
    // class stack s ;
    // s.size = 80 ;
    // s.top = -1 ;
    // s.arr = (int *)malloc(size * sizeof(int));

    class stack *s;
    
    s = (class stack *)malloc(sizeof(class stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    
    s->arr[0] = 40 ;
    s->top++;
    //checking is stack is empty or full 
    if (IsEmpty(s))
    {
        cout<<"The stack is empty";
    }
    else {
        cout<<"The stack is not empty";
    }
    return 0;
}