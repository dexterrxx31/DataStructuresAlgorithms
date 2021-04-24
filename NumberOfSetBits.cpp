#include <iostream>
using namespace std ;

int main()
{
    int number =  10; // binary of 10 is .....000001010
    //Logic 1
    // int counter1=0;
    // while(number>0)
    // {
    //     if( number & 1 == 1)
    //     {
    //         counter1++;
            
    //     }
    //     number = number>>1;
    // }
    // cout<<"Number if set bits are : "<<counter1;
    //........................................................................................................//
    //Logic 2
    // int counter = 0;
    // while (number >0 )
    // {
    //     number = number & (number-1);
    //     counter++;
    // }
    // cout<<"Number if set bits are : "<<counter;
    return 0 ;
}