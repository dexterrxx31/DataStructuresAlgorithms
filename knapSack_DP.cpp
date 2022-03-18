#include <bits/stdc++.h>
using namespace std;

// Recursive Approch
int KnapSack_REC(int weight[], int profit[], int W, int n)
{
    if (W == 0 || n == 0)
    {
        return 0;
    }
    if (weight[n - 1] <= W)
    {
        return max(profit[n - 1] + KnapSack_REC(weight, profit, W - weight[n - 1], n - 1), KnapSack_REC(weight, profit, W, n - 1));
    }
    else if (weight[n - 1] > W)
    {
        return KnapSack_REC(weight, profit, W, n - 1);
    }
}

// Memoization
vector<vector<int>> t(100, vector<int>(100, -1));

int KnapSack_DP(int weight[], int profit[], int W, int n)
{
    if (W == 0 || n == 0)
    {
        return 0;
    }
    if (t[n][W] != -1)
    {
        return t[n][W];
    }
    if (weight[n - 1] <= W)
    {
        return t[n][W] = max(profit[n - 1] + KnapSack_DP(weight, profit, W - weight[n - 1], n - 1), KnapSack_DP(weight, profit, W, n - 1));
    }
    else if (weight[n - 1] > W)
    {
        return t[n][W] = KnapSack_DP(weight, profit, W, n - 1);
    }
}

// Top Down Approch
int KnapSack_DP2(int weight[], int profit[], int W, int n)
{
    int tt[n + 1][W + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                tt[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (weight[i - 1] <= W)
            {
                tt[i][j] = max(profit[i - 1] + tt[i - 1][j - weight[i - 1]], tt[i - 1][j]);
            }
            else if (weight[i - 1] > W)
            {
                tt[i][j] = tt[i - 1][j];
            }
        }
    }

    return tt[n][W];
}

int main()
{
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    int n = 3;
    cout << KnapSack_DP2(weight, profit, W, n);
    return 0;
}