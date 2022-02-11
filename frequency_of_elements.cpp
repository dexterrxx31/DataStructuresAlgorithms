#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 2, 2, 4, 1, 1, 7, 8, 7, 2, 9, 4, 4, 8, 8, 8, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    // map  use Red Black tree n(logn)
    // map<int,int>::iterator it ;
    // unordered map takes hashing table n(1)
    unordered_map<int, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); it++)
    {
        cout << it->first << "->" << it->second << endl;
    }

    return 0;
}