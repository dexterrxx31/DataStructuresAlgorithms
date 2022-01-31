//Sorting An array of 0 1 2 without using any sorting Algorithm 

#include <bits/stdc++.h>
using namespace std;

//Swap elements in an array by index
void swap(int arr[], int n, int m)
{
    int temp;
    temp = arr[n];
    arr[n] = arr[m];
    arr[m] = temp;
}

//Using STL Multiset
void multiset_method(int arr[] , int size)
{
    multiset<int> s( arr , arr + size); 
    for(auto i : s)
    {
        cout<<i <<" ";
    }
}

void dnf_sort(int arr[] , int  size)
{
    int lo = 0 ;
    int mid = 0 ;
    int hi = size - 1 ;

    while(mid <= hi )
    {
        if(arr[mid] == 0)
        {
            swap(arr , mid ,lo);
            mid++;
            lo++;
        }
        else if(arr[mid] ==1)
        {
            mid++;
        }
        else
        {   
            swap(arr , mid , hi);
            hi--;
        }
        
    }
}
int main()
{
    int arr[] = {1,2,0,0,0,2,2,1,1,0};
    int size = sizeof(arr) / sizeof(arr[0]);
    //multiset_method(arr,size);
    dnf_sort(arr,size);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i] <<" ";
    }
    
    return 0 ;
}