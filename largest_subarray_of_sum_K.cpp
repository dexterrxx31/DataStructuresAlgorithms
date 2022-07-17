#include<bits/stdc++.h>
using namespace std ;

int longest_subarray_sum(int arr[] , int n , int k )
{   
    int mx = 0 ; 
    int sum = 0 ; 
    int i = 0 , j = 0 ;

    while(j < n)
    {   
        sum = sum + arr[j];

        if(sum < k)
        {
            j++;
        }
        else if ( sum == k)
        {
            mx = max(mx , j - i + 1 );
            j++;
        }
        else if( sum > k)
        {
            while(sum > k )
            {
                sum = sum  - arr[i];
                i++;
            }
            j++;
        }
    }
    return mx ; 
}

int main()
{
    int arr[] = {4,1,1,1,2,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 5 ;                 //required sum
    cout<<longest_subarray_sum(arr , n , k );
    return 0 ; 
}