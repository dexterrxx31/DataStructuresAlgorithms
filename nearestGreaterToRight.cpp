// Find greatest to right of array of each element . Return -1 is no element is greater .

#include <bits/stdc++.h>
using namespace std;

// Brute force Approch O(n2)
void nextGreatestElementWithoutStack(vector<int> arr)
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

// Using Stack data structure
vector<int> NGEWithStack(vector<int> arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        if (!st.empty())
        {
            while (!st.empty() && st.top() <= arr[i])
            {
                st.pop();
            }
        }
        st.empty() ? ans.push_back(-1) : ans.push_back(st.top());
        st.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> arr{11, 13, 21, 3};
    // nextGreatestElementWithoutStack(arr);
    vector<int> answer = NGEWithStack(arr);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}