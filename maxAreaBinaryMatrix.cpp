#include <bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerRight(vector<int> arr)
{
    int n = arr.size();
    stack<pair<int, int>> st;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.size() == 0)
        {
            ans.push_back(-1);
        }
        else if (st.size() > 0 && st.top().first < arr[i])
        {
            ans.push_back(st.top().second);
        }
        else if (st.size() > 0 && st.top().first >= arr[i])
        {
            while (st.size() > 0 && st.top().first >= arr[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top().second);
            }
        }
        st.push({arr[i], i});
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> nearestSmallerLeft(vector<int> arr)
{
    int n = arr.size();
    stack<pair<int, int>> st;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (st.size() == 0)
        {
            ans.push_back(-1);
        }
        else if (st.size() > 0 && st.top().first < arr[i])
        {
            ans.push_back(st.top().second);
        }
        else if (st.size() > 0 && st.top().first >= arr[i])
        {
            while (st.size() > 0 && st.top().first >= arr[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top().second);
            }
        }
        st.push({arr[i] , i });
    }
    return ans;
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

int maxAreaBinaryMatrix(vector<vector<int>> arr)
{
    vector<int> temp = arr[0];
    int result = maxAreaHistogram(temp);
    for (int i = 1; i < arr[0].size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] != 0)
            {
                temp[j] = temp[j] + arr[i][j];
            }
            else if (arr[i][j] == 0)
            {
                temp[j] = 0;
            }
        }
        for (int k = 0; k < temp.size(); k++)
        {
            cout << temp[k] << " ";
        }
        cout << endl;
        result = max(result, maxAreaHistogram(temp));
    }
    cout << endl;
    return result;
}

int main()
{
    vector<vector<int>> arr{
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}};
    cout << maxAreaBinaryMatrix(arr);
    return 0;
}