// Find smallest to left of array of each element . Return -1 is no element is smaller .

#include <bits/stdc++.h>
using namespace std;

// Using Stack data structure
vector<int> NGEWithStack(vector<int> arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> ans;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!st.empty())
    //     {
    //         while (!st.empty() && st.top() >= arr[i])
    //         {
    //             st.pop();
    //         }
    //     }
    //     st.empty() ? ans.push_back(-1) : ans.push_back(st.top());
    //     st.push(arr[i]);
    // }
        for (int i = 0; i < n; i++)
    {
        if (st.size() == 0)
        {
            ans.push_back(-1);
        }
        else if (st.size() > 0 && st.top() < arr[i])
        {
            ans.push_back(st.top());
        }
        else if (st.size() > 0 && st.top() >= arr[i])
        {
            while (st.size() > 0 && st.top() >= arr[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top());
            }
        }
        st.push(arr[i]);
    }
    return ans;
}

int main()
{
    vector<int> arr{11, 13, 21, 3};
    vector<int> answer = NGEWithStack(arr);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}