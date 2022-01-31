#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int n, int m)
{
    int temp;
    temp = arr[n];
    arr[n] = arr[m];
    arr[m] = temp;
}

void rotate_array(int arr[] , int size)
{
    int last_element = arr[size -1] , temp;
    for(int i = size - 1 ;i > 0 ;i--)
    {
        arr[i] = arr [i - 1];
    }
    arr[0] = last_element ;
}

int main()
{
    int b[] = {6, 7, 8, 1, 3, 4};
    int m = sizeof(b) / sizeof(b[0]);
    rotate_array(b,m);
    for (int i = 0; i < m; i++)
    {
        cout<<b[i]<<" ";
    }
    
    return 0;
}