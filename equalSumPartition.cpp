#include <bits/stdc++.h>
using namespace std;

bool findPartion(int arr[], int n)
{
    int sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += arr[i];
    if (sum % 2 != 0)
        return false;
    else
    { // Taking concept of subset problem
        sum /= 2;
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
}

int main()
{
    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (findPartion(arr, n) == true)
        cout << "Can be divided into two subsets of equal sum";
    else
        cout << "Can not be divided into two subsets of equal sum";

    return 0;
}