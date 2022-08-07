#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    int j = nums.size() - 1 , i = 0 ;
    vector<int> ans;
    while (j >= i)
    {
        while (abs(nums[i]) >= abs(nums[j]) && i != j) ans.push_back(abs(nums[i++]));
        while (abs(nums[j]) > abs(nums[i])) ans.push_back(abs(nums[j--]));
        if (i == j)
        {
            ans.push_back(abs(nums[i++]));
            break;
        }
    }
    reverse(ans.begin() , ans.end());
    return ans;
}
int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};
    nums = sortedSquares(nums);
    for (auto x : nums)
        cout << x << " ";
    return 0;
}