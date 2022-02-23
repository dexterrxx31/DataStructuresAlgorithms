// Find greatest to right of array of each element . Return -1 is no element is greater .

#include <bits/stdc++.h>
using namespace std;

// Brute force Approch O(n2)
void nextGreatestElement(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                flag = false;
                cout << arr[i] << "::" << arr[j] << endl;
                break;
            }
        }
        if (flag)
        {
            cout << arr[i] << "::" << -1 << endl;
        }
    }
}

int main()
{
    vector<int> arr{11, 13, 21, 3};
    nextGreatestElement(arr);
    return 0;
}