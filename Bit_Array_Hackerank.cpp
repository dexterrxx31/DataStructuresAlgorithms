#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long n, s, p, q, i, cr, prev, k = 0, po = 1 << 31;
    cin >> n >> s >> p >> q;
    unsigned long long arr[n];
    prev = s % po;

    for (i = 0; i < n; i++)
    {
        cr = (prev * p + q) % po;
        if (cr != prev)
            k++;
    }

    cout << k;
}
