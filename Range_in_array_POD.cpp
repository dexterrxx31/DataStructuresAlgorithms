#include <bits/stdc++.h>
using namespace std;

bool check_elements(int arr[], int n, int A, int B)
{
    set<int> s;
    for (int i = 0; i < n; i++)
        if (arr[i] >= A and arr[i] <= B)
            s.insert(arr[i]);

    if (s.size() == B - A + 1)
        return true;
    else
        return false;
}

int main()
{
    int arr[] = {1, 4, 5, 2, 7, 8, 3};
    int n = 7;
    int A = 2;
    int B = 8;

    if (check_elements(arr, n, A, B))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}