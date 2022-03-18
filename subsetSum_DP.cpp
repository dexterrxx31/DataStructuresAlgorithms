#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int sum, int n)
{
    bool t[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
        t[i][0] = true;

    for (int i = 1; i < sum + 1; i++)
        t[0][i] = false;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            else if (arr[i - 1] > j)
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}

int main()
{
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 30;
    int n = sizeof(arr) / sizeof(arr[0]);
    if (subsetSum(arr, sum, n) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";

    return 0;
}