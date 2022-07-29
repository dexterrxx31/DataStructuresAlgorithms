#include <bits/stdc++.h>
using namespace std;

vector<int> peakArray(vector<int> a)
{

    int index = 0;
    int max = INT_MIN;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > max)
        {
            index = i;
            max = a[i];
        }
    }
    cout << "max :" << max << endl
         << "index:" << index << endl;
    vector<int> right, left;
    for (int i = 0; i < index; i++)
    {
        left.push_back(a[i]);
    }
    for (int i = index + 1; i < a.size(); i++)
    {
        right.push_back(a[i]);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end(), greater<int>());

    vector<int> ans;
    for (int i = 0; i < left.size(); i++)
    {
        ans.push_back(left[i]);
    }
    ans.push_back(max);
    for (int i = 0; i < right.size(); i++)
    {
        ans.push_back(right[i]);
    }
    return ans;
}

int main()
{
    vector<int> inp = {2, 4, 6, 8, 1, 5, 7};
    inp = peakArray(inp);
    for (int i = 0; i < inp.size(); i++)
    {
        cout << inp[i] << " ";
    }
    return 0;
}