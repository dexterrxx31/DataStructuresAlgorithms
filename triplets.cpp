#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

//Line 1 -- Array of int
//Line 2 -- Targeted sum of triplets

vector<vector<int>> pairs(vector<int> arr, int target_sum)
{
    vector<vector<int>> result;
    for (int i = 0; i <= arr.size() - 3; i++)
    {
        int left_pointer = i + 1;
        int right_pointer = arr.size() - 1;
        while (left_pointer < right_pointer)
        {   int current_sum = arr[i];
            current_sum+=arr[left_pointer];
            current_sum+=arr[right_pointer];
            if (current_sum== target_sum)
            {
                result.push_back({arr[i],arr[left_pointer],arr[right_pointer]});
                right_pointer--;
                left_pointer++;
            }
            if (current_sum > target_sum)
            {
                right_pointer--;
            }
            else
            {
                left_pointer++;
            }
        }
    }
    return result ;
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
    for (int i = 0; i < arr.size() ; i++)
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
    vector<vector <int>> result = pairs(arr, target_sum);
    cout<<result.size();
    cout<<endl;
    vector_traversal_2d(result);
    return 0;
}