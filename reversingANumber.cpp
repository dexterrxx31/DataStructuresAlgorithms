#include<iostream>
using namespace std ;

int main()
{
    int number = 5678;
    int dummy = 0 ;
    while (number >0)
    {
        dummy = dummy*10 + (number%10);
        number = number/10; 
    }
    cout<<dummy;
    return 0;
}