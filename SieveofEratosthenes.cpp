#include<iostream>
#include<math.h>
using namespace std ;
//find number of prime numbers between 0-20 using sieve of eratosthenes
//Time complexity : O(n*log(log(n))) 
int main()
{   bool prime[20] ;
    for(int i = 0 ;i < 20 ;i++)
    {
        prime[i] = true;
    }
    for(int j =2 ; j*j < 20 ; j++)
    {   
        for(int k = 2*j ; k < 20 ;k+=j)
        {
            prime[k] = false;
        }
    }

       for(int i = 0 ;i < 20 ;i++)
    {
        cout<<prime[i]<<"*";
    }
    return 0;
}