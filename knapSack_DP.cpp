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

int main()
{
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    int n = 3;
    cout << KnapSack_REC(weight, profit, W, n);
    return 0;
}