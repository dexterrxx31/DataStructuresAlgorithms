#include <bits/stdc++.h>
using namespace std;

// Without stack Approch
vector<int> stockSpanProlem_1(vector<int> arr)
{
    vector<int> answer;
    int n = arr.size(); // size of array
    int i = n - 1;
    int counter;
    while (i >= 0)
    {
        counter = 0;
        int j = i - 1;
        while (arr[j] <= arr[i] && j >= 0)
        {
            counter++;
            j--;
        }
        answer.push_back(counter + 1);
        i--;
    }
    return answer;
}

// With Stack Approch
vector<int> stockSpanProlem_2(vector<int> arr)
{
    int n = arr.size();
    stack<pair<int, int>> st;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (!st.empty())
        {
            while (!st.empty() && st.top().first <= arr[i])
            {
                st.pop();
            }
        }
        st.empty() ? ans.push_back(-1) : ans.push_back(st.top().second);
        st.push({arr[i], i});
    }
    for (size_t i = 0; i < ans.size(); i++)
    {
        ans[i] = i - ans[i];
    }
    return ans;
}

int main()
{
    stack<int> st;
    vector<int> arr{100, 80, 60, 70, 60, 75, 85}; // given array
    vector<int> answer = stockSpanProlem_2(arr);
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    return 0;
}