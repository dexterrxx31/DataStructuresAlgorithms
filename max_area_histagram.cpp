#include <bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerRight(vector<int> arr)
{
    stack<pair<int, int>> st;
    vector<int> result;
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (!st.empty())
        {
            while (!st.empty() && st.top().first >= arr[i])
            {
                st.pop();
            }
        }
        st.empty() ? result.push_back(-1) : result.push_back(st.top().second);
        st.push({arr[i], i});
    }
    reverse(result.begin(), result.end());
    return result;
}

vector<int> nearestSmallerLeft(vector<int> arr)
{
    stack<pair<int, int>> st;
    vector<int> result;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (!st.empty())
        {
            while (!st.empty() && st.top().first >= arr[i])
            {
                st.pop();
            }
        }
        st.empty() ? result.push_back(-1) : result.push_back(st.top().second);
        st.push({arr[i], i});
    }

    return result;
}

int maxAreaHistogram(vector<int> arr)
{
    int maxArea = 0;
    // We need to find smaller to left and greater to right
    vector<int> rt_small = nearestSmallerRight(arr);
    vector<int> lf_small = nearestSmallerLeft(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        int width = rt_small[i] - lf_small[i] - 1;
        int area = arr[i] * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}
int main()
{
    vector<int> arr{6, 2, 5, 4, 5, 1, 6};
    cout<<maxAreaHistogram(arr);
    return 0;
}