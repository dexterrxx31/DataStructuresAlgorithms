#include <bits/stdc++.h>
using namespace std;

vector<int> two_sum(vector<int> arr, int target)
{
    vector<int> ans;
    int n = arr.size();

    int i = 0, j = 0;

    int sum = 0 ;

    while (j < n)
    {
        if (sum < target)
        {
            sum = sum + arr[j];
            j++;
        }
        else if (sum == target)
        {
            break;
        }
        if (sum > target)
        {
            while (sum > target)
            {
                sum = sum - arr[i];
                i++;
            }
            if (sum == target)
            {
                break;
            }
        }
    }

    for (i  ; i < j; i++)
    {
        ans.push_back(i);
    }
    return ans;
}

int main()
{
    vector<int> arr = {3,3};
    int target = 6;
    vector<int> ans = two_sum(arr, target);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}