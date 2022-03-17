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
            while (!st.empty() && st.top().first > arr[i])
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
            while (!st.empty() && st.top().first > arr[i])
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
        int area = abs( arr[i] * width );
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int maxAreaBinaryMatrix(vector<vector<int>> arr)
{
    vector<int> temp  = arr[0];
    int result = maxAreaHistogram(temp);
    for(int i = 1 ; i < arr[0].size() ; i++)
    {
        for (int  j = 0; j < arr[0].size(); j++)
        {
            if(arr[i][j] != 0 )
            {
                temp[j] = temp[j] + arr[i][j];
            }
            else if(arr[i][j] == 0)
            {
                temp[j] = 0 ;
            }
        }
        for (int k = 0; k < temp.size(); k++)
        {
            cout<<temp[k]<<" ";
        }
        cout<<endl;
        result = max(result ,maxAreaHistogram(temp));
        
    }
    cout<<endl;
    return result ;
}

int main()
{
    vector<vector<int>> arr{
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}};
    cout<<maxAreaBinaryMatrix(arr);
    return 0;
}