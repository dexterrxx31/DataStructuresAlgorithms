// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

#include <bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int k)
{
    int count = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    for (int i = 0; i < n; i++)
        if (arr[i] == k - arr[i])
            count += (mp[arr[i]] - 1);
        else
            count += mp[k - arr[i]];

    return count;
}

int main()
{
    int arr[] = {1, 5, 7, 1};             // input array
    int n = sizeof(arr) / sizeof(arr[0]); // size of an array
    int k = 6;                            // sum we need
    cout << getPairsCount(arr, n, k);
    return 0;
}