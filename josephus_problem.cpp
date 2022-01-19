#include<iostream>
using namespace std ;

int josp(int num , int steps)
{
     if ( num == 1)
     {
         return 0;
     }

     return (josp(num-1,steps) + steps)%num ;
}

int main()
{   
    int num = 5 ;
    int steps = 2 ;
    cout << josp(num,steps) ;
    return 0 ;
}