// Problem URL https://www.spoj.com/problems/EXPEDI/

/*
Input
The first line of the input contains an integer t representing the number of test cases. Then t test cases follow. Each test case has the follwing form:

Line 1: A single integer, N
Lines 2..N+1: Each line contains two space-separated integers describing a fuel stop: The first integer is the distance from the town to the stop; the second is the amount of fuel available at that stop.
Line N+2: Two space-separated integers, L and P
Output
For each test case, output a single integer giving the minimum number of fuel stops necessary to reach the town. If it is not possible to reach the town, output -1.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }

        int l, p;
        cin >> l >> p;

        for (int i = 0; i < n; i++)
            a[i].first = l - a[i].first;

        sort(a.begin(), a.end());
        int ans = 0;
        int curr = p;

        priority_queue<int, vector<int>> pq;
        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (curr >= l)
                break;
            while (curr < a[i].first)
            {
                if (pq.empty())
                {
                    flag = 1;
                    break;
                }
                ans++;
                curr += pq.top();
                pq.pop();
            }
            if (flag)
                break;
            pq.push(a[i].second);
        }
        if (flag)
        {
            cout << "-1" << endl;
            continue;
        }

        while (!pq.empty() && curr < l)
        {
            curr += pq.top();
            pq.pop();
            ans++;
        }

        if (curr < l)
        {
            cout << "-1" << endl;
            continue;
        }
        cout << ans << endl;
    }

    return 0;
}