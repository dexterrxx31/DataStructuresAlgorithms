//Sorting An array of 0 1 2 without using any sorting Algorithm 

#include <bits/stdc++.h>
using namespace std;

//Using STL Multiset
void multiset_method(int arr[] , int size)
{
    multiset<int> s( arr , arr + size); 
    for(auto i : s)
    {
        cout<<i <<" ";
    }
}

int main()
{
    int arr[] = {1,2,0,0,0,2,2,1,1,0};
    int size = sizeof(arr) / sizeof(arr[0]);
    multiset_method(arr,size);
    return 0 ;
}