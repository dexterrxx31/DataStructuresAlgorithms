#include<bits/stdc++.h>
using namespace std;

//Finding max subarray sum in given array.
//Brute Force Approch
int max_subarray(int arr[] , int n , int k)
{   int max_sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {   int current_sum = 0 ;
        for (int j = i; j < i+k && j<n; j++)
        {
            current_sum += arr[j];
        }
        max_sum = max(max_sum , current_sum);
    }
    return max_sum;
}

int main()
{   
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sub_array_size = 3;
    cout<<max_subarray(arr, n , sub_array_size);
    return 0 ;
}