#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int i = 0, j = 0, total_profit = 0, current_profit = 0;
    while (j < prices.size() - 1)
    {
        if (i == j)
            j++;
        if (j == prices.size() - 1)
        {
            if (prices[j] > prices[i])
            {
                total_profit += prices[j] - prices[i];
                break;
            }
            else
                break;
        }
        while (prices[j + 1] >= prices[j] and j < prices.size() - 1)
            j++;
        while (prices[i + 1] <= prices[i] and i < prices.size() - 1 and i < j)
            i++;
        current_profit = prices[j] - prices[i];
        total_profit += current_profit;
        i = j;
    }
    return total_profit;
}

int main()
{
    vector<int> arr = {7, 6, 4, 3, 1};
    cout << "Profit : " << maxProfit(arr);
    return 0;
}
