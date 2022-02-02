#include<bits/stdc++.h>
using namespace std;

int dublicate_sort(int arr[] , int n)
{
    sort(arr , arr + n);
    for (int i = 0; i < n - 1; i++)
    {
        if(arr[i] == arr[i+1])
            cout<<arr[i];
    }
}

int main()
{   
    int arr[] = {1,3,4,2,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    //cout<<binary_search(arr , 1 , 0  , 4);
    //cout<<dublicate(arr ,n);
    dublicate_sort(arr , n);
    return 0 ;
}