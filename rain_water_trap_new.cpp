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
    int water = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int height_of_water = min(max_to_left(arr, i), max_to_right(arr, i));
        water += height_of_water - arr[i];
    }
    return water;
}
int main()
{
    vector<int> arr{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = arr.size();
    cout << total_water_trapped(arr);
    return 0;
}