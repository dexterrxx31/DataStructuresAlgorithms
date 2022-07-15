#include <bits/stdc++.h>
using namespace std;

int max_sum_subarray(int arr[], int k, int n)
{
    int current_sum = 0;
    int max_sum = INT_MIN;
    int i = 0, j = 0;

    while (j < n)
    {
        current_sum += arr[j];
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            max_sum = max(max_sum, current_sum);
            current_sum -= arr[i];
            i++;
            j++;
        }
    }
    return max_sum;
}

int main()
{
    int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << max_sum_subarray(arr, k, n);
    return 0;
}
