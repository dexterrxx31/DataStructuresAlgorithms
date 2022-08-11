#include <bits/stdc++.h>
using namespace std;

//Recursion
int fxn(vector<int> arr, int n, int i)
{
    if (i == n - 1) return 0;
    if (i >= n) return INT_MAX;
    int ans = INT_MAX;

    for (int j = 1; j <= arr[i]; j++)
    {
        int jump = i + j;
        int current_jump = fxn(arr, n, jump);
        if (current_jump != INT_MAX) ans = min(ans, current_jump + 1);
    }
    return ans;
}

//Top Down
vector<int> t(13 , 0 ) ;
int fxn(vector<int> arr, int n, int i)
{
    if (i == n - 1) return 0;
    if (i >= n) return INT_MAX;
    if(t[i] != 0) return t[i] ;
    int ans = INT_MAX;
    for (int j = 1; j <= arr[i]; j++)
    {
        int jump = i + j;
        int current_jump = fxn(arr, n, jump);
        if (current_jump != INT_MAX) ans = min(ans, current_jump + 1);
    }
    return t[i] = ans;
}

int main()
{
    cout << fxn({3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 2, 5}, 12, 0);
    return 0;
}