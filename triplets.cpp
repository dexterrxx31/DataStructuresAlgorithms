#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

//Line 1 -- Array of int
//Line 2 -- Targeted sum

int binary_search(vector<int> arr, int element)
{
    int begin = 0;
    int end = arr.size();
    while (begin <= end)
    {
        int mid = begin + (end - begin) / 2;
        if (arr[mid] == element)
        {
            return 1;
        }
        if (arr[mid] < element)
        {
            begin = mid + 1;
        }

        if (arr[mid] > element)

        {
            end = mid - 1;
        }
    }
    return 0;
}

vector<int> pairs(vector<int> arr, int target_sum)
{
    vector<int> result;
    for (int i = 0; i < arr.size(); i++)
    {
        int required_number = target_sum - arr[i];
        if (arr[i] == required_number)
        {
            continue;
        }
        if (binary_search(arr, required_number) == 1)
        {
            result.push_back(arr[i]);
            result.push_back(required_number);
            return result;
        }
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