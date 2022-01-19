#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size() ; i++)
    {
        if (nums[i - 1] == nums[i])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    vector<int> nums = {5,2,1,6,6,7,0};
    cout << containsDuplicate(nums);
    return 0;
}