#include <bits/stdc++.h>
using namespace std;

int brute_force_approch(int arr[], int n)
{
    int count;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count = 1;
            }
        }
        if (count == 1)
        {
            return arr[i];
        }
    }
}

int dublicate_sort(int arr[], int n)
{
    sort(arr, arr + n);
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            return arr[i];
        }
    }
}

int main()
{
    int arr[] = {1, 3, 4, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout<<dublicate_sort(arr, n);
    // cout<<brute_force_approch(arr,n);
    return 0;
}