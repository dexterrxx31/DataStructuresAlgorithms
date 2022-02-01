#include <bits/stdc++.h>
using namespace std;

void min_height(int arr[], int size, int k)
{
    sort(arr, arr + size);
    int diff = arr[size - 1] - arr[0];
    int mn, mx;
    for (int i = 1; i < size; i++)
    {   
        if(arr[i] - k <0 ) continue ;
        mx = max(arr[size - 1] - k, arr[i - 1] + k);
        mn = min(arr[0] + k, arr[i] - k);
        diff = min(diff, mx - mn);
    }
    
    cout << diff;
}

int main()
{
    int arr[] = {1, 5, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    min_height(arr, size, k);
    return 0;
}