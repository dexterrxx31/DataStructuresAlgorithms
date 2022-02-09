#include <bits/stdc++.h>
using namespace std;

// brute force Approch
int max_profit(int arr[], int n)
{
    int min_diff = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] - arr[i] > min_diff)
                min_diff = arr[j] - arr[i];
        }
    }
    if (min_diff < 0)
        min_diff = 0;
    return min_diff;
}

int main()
{
    int arr[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << max_profit(arr, n);
    return 0;
}