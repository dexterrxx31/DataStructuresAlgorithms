//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

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

// Optimal Approch O(n)
int max_profit__(int prices[], int n)
{
    int max_profit = INT_MIN;
    int buy_day = INT_MAX;
    int sold_that_day = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (prices[i] < buy_day)
            buy_day = prices[i];

        // profit if sold that day
        sold_that_day = prices[i] - buy_day;

        if (sold_that_day > max_profit)
        {
            max_profit = sold_that_day;
        }
    }
    if (max_profit < 0)
        return 0;
    else
        return max_profit;
}

int main()
{
    int arr[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << max_profit__(arr, n);
    return 0;
}