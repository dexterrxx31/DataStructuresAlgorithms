#include <bits/stdc++.h>
using namespace std;

//Top Down Memoization

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

//Top Down Approch

vector<int> t(9 , -1) ;
int rod(vector<int> prices, int n)
{
    if (n <= 0) return 0;
    if(t[n-1] != -1) return t[n-1] ;

    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int cut = i + 1;
        int current_ans = prices[i] + rod(prices, n - cut);
        ans = max(ans, current_ans);
    }
    return t[n-1] = ans;
}

//Bottom Up Approch

int rod(vector<int> prices, int n)
{
    vector<int> t(n+1, 0);

    for (int j = 1; j <= n; j++)
    {
        int ans = INT_MIN;
        for(int i = 0 ; i < j ; i++)
        {
            int cut = i+1 ; 
            int  current_ans = prices[i] + t[j-cut] ;
            ans = max( ans , current_ans) ;
        }
        t[j] = ans ;
    }
    return t[n];
}

int main()
{
    cout << rod({3, 5, 8, 9, 10, 17, 17, 20}, 8);
    return 0;
}