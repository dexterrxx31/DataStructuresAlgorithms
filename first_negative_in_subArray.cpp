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

/*
#include <bits/stdc++.h>
using namespace std;

void fxn(int arr[], int k, int n)
{
    deque<int> neq;
    int i = 0, j = 0;

    while (j < n)
    {
        if (arr[j] < 0)
        {
            neq.push_back(arr[j]);
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else
        {
            if (neq.empty())
                cout << 0;
            else
            {
                cout << neq.front();

                if (neq.front() == arr[i])
                {
                    neq.pop_front();
                }
            }
            i++;
            j++;
        }
    }
}
int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int K = 3;
    int N = sizeof(arr) / sizeof(arr[0]);
    fxn(arr, K, N);
    return 0;
}
*/