#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = 0, j = 0;
    vector<int> ans;

    while (i < m and j < n)
    {
        if (nums1[i] < nums2[j])
        {
            ans.push_back(nums1[i++]);
            //i++;
        }
        else if (nums1[i] >= nums2[j])
        {
            ans.push_back(nums2[j++]);
            //j++;
        }
    }
    while (i < m)
    {
        ans.push_back(nums1[i++]);
        //i++;
    }
    while (j < n)
    {
        ans.push_back(nums2[j++]);
        //j++;
    }
    nums1 = ans;
    for(auto x : nums1)
        cout<<x<<" ";
}

int main()
{
    vector<int> n = {2, 3};
    vector<int> m = {0};
    merge(n, 2, m, 0);
    return 0;
}