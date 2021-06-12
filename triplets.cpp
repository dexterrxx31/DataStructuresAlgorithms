#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

//Line 1 -- Array of int
//Line 2 -- Targeted sum

vector<int> pairs(vector<int> arr, int target_sum)
{
    vector<vector<int>> result;
    int left_pointer = 1;
    int right_pointer = arr.size();
    int c = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int required_sum = target_sum - arr[i];
        while (left_pointer < right_pointer)
        {
            if (arr[left_pointer] + arr[right_pointer] == required_sum)
            {
                result[c][0] = arr[i];
                result[c][1] = arr[left_pointer];
                result[c][3] = arr[right_pointer];
                right_pointer--;
                left_pointer++;
                c++;
            }
            if (arr[left_pointer] + arr[right_pointer] >= required_sum)
            {
                right_pointer--;
            }
            if (arr[left_pointer] + arr[right_pointer] >= required_sum)
            {
                left_pointer++;
            }
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
void vector_traversal_2d(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << "|" << arr[i][j] << "|";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {4, 5, 2, 7, 3, 6, 15, 9, 1, 8};
    sort(arr.begin(), arr.end());
    vector_traversal(arr);
    int target_sum = 18;
    vector<int> result = pairs(arr, target_sum);
    return 0;
}