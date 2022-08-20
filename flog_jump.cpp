#include <bits/stdc++.h>
#include <math.h>
using namespace std;

// Recursive Approch

int frog_jump_rec(vector<int> &arr, int i, int n)
{
    if (i == n - 1) return 0;

    int ans1 = INT_MAX, ans2 = INT_MAX;

    if (i + 1 < n) ans1 = abs(arr[i] - arr[i + 1]) + frog_jump_rec(arr, i + 1, n);
    if (i + 2 < n) ans2 = abs(arr[i] - arr[i + 2]) + frog_jump_rec(arr, i + 2, n);

    return min(ans1, ans2);
}

vector<int> t(7, -1);
int frog_jump_td(vector<int> &arr, int i, int n)
{
    if (i == n - 1) return t[i] = 0;

    if (t[i] != -1) return t[i];

    int ans1 = INT_MAX, ans2 = INT_MAX;

    if (i + 1 < n) ans1 = abs(arr[i] - arr[i + 1]) + frog_jump_td(arr, i + 1, n);
    if (i + 2 < n) ans2 = abs(arr[i] - arr[i + 2]) + frog_jump_td(arr, i + 2, n);

    return t[i] = min(ans1, ans2);
}

// Bottom up Approch DP

int frog_jump_bu(vector<int> &arr, int i, int n)
{
    vector<int> ans(n, 0);
    ans[1] = abs(arr[1] - arr[0]);

    for (int i = 2; i < n; i++) ans[i] = min(ans[i - 1] + abs(arr[i] - arr[i - 1]), ans[i - 2] + abs(arr[i] - arr[i - 2]));

    return ans[n - 1];
}

int main()
{
    vector<int> arr = {30, 10, 60, 10, 60, 50};
    // frog started jump from first index
    // We are suppose to find min cost of jump
    cout << frog_jump_rec(arr, 0, arr.size()) << endl;
    cout << frog_jump_bu(arr, 0, arr.size()) << endl;
    cout << frog_jump_td(arr, 0, arr.size());
    return 0;
}