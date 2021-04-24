#include <iostream>

using namespace std;

int evenOdd(int number)
{
    if ( number & 1 )
        cout<<"Odd Number"<<endl;
    else
        cout<<"Even Number"<<endl;

return 0;
}
int swapTwoNumbersWithoutThirdVariable(int number1 , int number2 ,int arr[2])
{   
    number1 =number1^number2;
    number2 =number1^number2;
    number1 =number1^number2;
    arr[0] = number1;
    arr[1] = number2;
    return 0;
}
int main()
{   int number1 = 60 , number2 = 40 ,arr [2];
    // //evenOdd(number);
    // cout <<(number & 1 == 0) ;
    // //cout<<c;
    cout<<number1<<"****"<<number2<<endl;
    swapTwoNumbersWithoutThirdVariable(number1,number2,arr);
    number1 = arr[0];
    number2 = arr[1];
    cout<<number1<<"****"<<number2;
    return 0;
}
