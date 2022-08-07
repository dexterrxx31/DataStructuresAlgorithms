#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
{
    vector<vector<int>> ans;
    map<int, int> freq;
    for (int i = 0; i < items1.size(); i++)
    {
        freq[items1[i][0]] = items1[i][1];
    }

    for (int i = 0; i < items2.size(); i++)
    {
        freq[items2[i][0]] += items2[i][1];
    }

    map<int, int>::iterator it;

    for (it = freq.begin(); it != freq.end(); it++)
    {
        ans.push_back({it->first, it->second});
    }

    // using foreach loop :
    //  for (auto val : items1)
    //      freq[val[0]] = val[1];
    //  for (auto val : items2)
    //      freq[val[0]] += val[1];
    //  for (auto [x, y] : freq)
    //      ans.push_back({x, y});
    return ans;
}
int main()
{
    vector<vector<int>> arr1 = {{1, 1}, {4, 5}, {3, 8}};
    vector<vector<int>> arr2 = {{3, 1}, {1, 5}};
    vector<vector<int>> ans = mergeSimilarItems(arr1, arr2);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << "->" << ans[i][1] << endl;
    }
    return 0;
}