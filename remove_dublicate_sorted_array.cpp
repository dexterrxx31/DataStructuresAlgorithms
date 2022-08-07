#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int j = 0, i = 0, n = nums.size();
    if (n <= 1)
        return n;
    while (j < n - 1)
    {
        while (nums[j] == nums[i] and j < n - 1)
            j++;
        if (nums[i] != nums[j] and j < n)
            nums[++i] = nums[j];
    }
    return i + 1;
}

int main()
{
    vector<int> nums = {1, 1};
    cout << removeDuplicates(nums);
    return 0;
}