#include<iostream>
using namespace std ;

//find Euclid GDC of given numbers.
//gcd(a,b) = gcd(a-b,b) for a>b
//gcd(a,b) = gcd(b ,a%b )    till a%b != 0 
int gcd (int a , int b)
{
    return a%b == 0 ? b : gcd(b , a%b);
}
int main()
{   
    int a = 75 , b = 60 ;
    cout<<gcd(a,b);
    return 0 ;
}