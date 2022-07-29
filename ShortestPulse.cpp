#include <bits/stdc++.h>
using namespace std;

int shortestPulse(int n, int x, vector<int> a)
{

    int psize;
    int min_size = INT_MAX;
    int ele = 0;
    int i = 0;

    while (i < n)
    {
        if (a[i] > x)
            continue;
        if (a[i] == x)
            return 1;
        psize = x / a[i];
        // cout<<psize <<" ";
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] >= a[i])
            {
                ele++;
            }
        }

        if (ele >= psize)
            min_size = min(min_size, psize);

        i++;
        ele = 0;
    }

    if (min_size == INT_MAX)
        return -1;
    else
        return min_size - 1;
}

int main()
{
    vector<int> a = {5, 7};
    cout << shortestPulse(2, 4, a);

    return 0;
}