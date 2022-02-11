#include <bits/stdc++.h>
using namespace std;

int main()
{ // solving it by Sliding window approch

    deque<int> Q;    // for storing all negative numbers
    vector<int> ans; // storing all answers

    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28}; // input Array
    int i, j, k, n;
    i = j = 0;
    k = 3;
    n = 8;

    while (j < n)
    {
        if (arr[j] < 0)
            Q.push_back(arr[j]); // inserting a negative number in Queue on every iteration
        if (j - i + 1 < k)       // Checking condition for size for window
            j++;
        else
        {
            if (Q.empty()) // Edge case when no negative number present
                ans.push_back(0);
            else
            {
                ans.push_back(Q.front()); // inserting front of Queue in Answer array as it is the only
                                          // negative number we have in window
                if (arr[i] == Q.front())  // for Sliding window we need to get rid of previous data
                    Q.pop_front();
            }
            i++, j++; // Sliding window
        }
    }

    // printing Answer vector
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}