#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> mp;
    int n = nums.size(), x, y;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(target - nums[i]) != mp.end())
        {
            x = mp.find(target - nums[i])->second;
            y = i;
            break;
        }
        mp.insert({nums[i], i});
    }
    return {x, y};
}

int main()
{
    vector<int> arr = {3, 3};
    int target = 6;
    vector<int> ans = twoSum(arr, target);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}