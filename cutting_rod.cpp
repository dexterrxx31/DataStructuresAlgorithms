#include <bits/stdc++.h>
using namespace std;

// Recursion Approch
int rod(vector<int> prices, int n)
{
    if (n <= 0) return 0;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int cut = i + 1;
        int current_ans = prices[i] + rod(prices, n - cut);
        ans = max(ans, current_ans);
    }
    return ans;
}

int main()
{
    cout << rod({3, 5, 8, 9, 10, 17, 17, 20}, 8);
    return 0;
}