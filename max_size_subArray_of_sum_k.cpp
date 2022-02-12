#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr{4, 1, 1, 1, 2, 3, 5}; // input String
    int n = arr.size();                   // size of input Array

    int k = 5; // sum
    int sum = 0;
    int max_sum = INT_MIN;
    int i, j;  // Begin and end Pointers
    i = j = 0; // Initial State of Pointers

    // Sliding window Loop
    while (j < n)
    {
        sum = sum + arr[j];
        if (sum < k)
            j++;

        else if (sum == k)
        {
            max_sum = max(max_sum, j - i + 1);
            j++;
        }
        else if (sum > k)
        {
            while (sum > k)
            {
                sum = sum - arr[i];
                i++;
                if (sum == k)
                    max_sum = max(max_sum, j - i + 1);
            }    
            j++;
        }
    }
    cout << max_sum;
}