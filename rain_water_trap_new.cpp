#include <bits/stdc++.h>
using namespace std;

int max_to_left(vector<int> arr, int index)
{
    int n = arr.size();
    int mm = INT_MIN;
    for (int i = index; i >= 0; i--)
    {
        mm = max(mm, arr[i]);
    }
    return mm;
}

int max_to_right(vector<int> arr, int index)
{
    int n = arr.size();
    int mm = INT_MIN;
    for (int i = index; i < n; i++)
    {
        mm = max(mm, arr[i]);
    }

    return mm;
}

int total_water_trapped(vector<int> arr)
{
    
}
int main()
{
    vector<int> arr{3, 0, 0, 2, 0, 4};
    int n = arr.size();
    cout << max_to_left(arr, 1) << endl
         << max_to_right(arr, 1);
    return 0;
}