#include <bits/stdc++.h>
using namespace std;

vector<int> max_right(vector<int> arr)
{
    int n = arr.size();
    stack<int> s;
    vector<int> v;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            v.push_back(arr[i]);
            s.push(arr[i]);
            continue;
        }
        else if (s.size() > 0 && s.top() >= arr[i])
        {
            v.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() <= arr[i])
        {
            s.push(arr[i]);
            v.push_back(s.top());
        }
    }
    reverse(v.begin(), v.end());
    return v;
}

vector<int> max_left(vector<int> arr)
{
    int n = arr.size();
    stack<int> s;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            v.push_back(arr[i]);
            s.push(arr[i]);
            continue;
        }
        else if (s.size() > 0 && s.top() >= arr[i])
        {
            v.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() <= arr[i])
        {
            s.push(arr[i]);
            v.push_back(s.top());
        }
    }
    return v;
}

int total_water_trapped(vector<int> arr)
{
    int water = 0;
    vector<int> rt = max_right(arr);
    vector<int> lft = max_left(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        int height_of_water = min(rt[i], lft[i]);
        water += height_of_water - arr[i];
    }
    return water;
}

int main()
{
    vector<int> arr{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // vector<int> arr{3,0,2,0,4};
    cout << total_water_trapped(arr);
    return 0;
}