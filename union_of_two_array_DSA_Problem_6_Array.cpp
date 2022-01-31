#include <bits/stdc++.h>
using namespace std;

void union_of_array(int a[], int n, int b[], int m)
{
    set<int> s(a, a + n);
    for (int i = 0; i < m; i++)
        s.insert(b[i]);
    cout << s.size();
}

int main()
{
    int a[] = {1, 3, 4};
    int b[] = {6, 7, 8, 1, 3, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    union_of_array(a, n, b, m);

    //This will work in main funtion but not in other
    // set<int> s(a , a+n);
    // for(auto i : b)
    //     s.insert(i);
    // cout<<s.size();

    return 0;
}