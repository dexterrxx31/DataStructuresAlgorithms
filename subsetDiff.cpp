#include<bits/stdc++.h>
using namespace std;

int CountSubsetSum(int arr[], int sum, int n)
{
    int t[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
        t[i][0] = 1;

    for (int i = 1; i < sum + 1; i++)
        t[0][i] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            else if (arr[i - 1] > j)
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}

int subsetDiff(int arr[] , int n  , int diff)
{   int sum = 0 ; 
    for (size_t i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    int req_sum = ( sum + diff )/2 ;
    return CountSubsetSum(arr , req_sum , n );
    
}

int main()
{
    int arr[] = {1,1,2,3};
    int n  = sizeof(arr)/sizeof(arr[0]);
    int diff = 1 ;
    cout<<subsetDiff(arr , n , diff) ;
    return 0 ;
}