#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <unordered_set>
using namespace std;

//Line 1 -- Array of int
//Line 2 -- Targeted sum

vector<int> pairs(vector<int> arr, int target_sum)
{
    vector<int> result;
    unordered_set<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        int required_number = target_sum - arr[i];
        if (s.find(required_number) != s.end())
        {
            result.push_back(arr[i]);
            result.push_back(required_number);
            return result;
        }
        s.insert(arr[i]);
    }
}
void vector_traversal(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "|" << arr[i] << "|";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {10, 5, 2, 3, -6, 9, 11};
    sort(arr.begin(), arr.end());
    vector_traversal(arr);
    int target_sum = 4;
    vector<int> result = pairs(arr, target_sum);
    cout << result[0] << "||" << result[1];
    return 0;
}