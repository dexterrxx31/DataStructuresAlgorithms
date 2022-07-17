#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr{1, 3, -1, -3, 5, 3, 6, 7}; // input String
    int n = arr.size();                        // size of input Array
    list<int> ls;
    vector<int> ans; // vector to store answer string
    int k = 3;       // size of window

    int i, j;  // Begin and end Pointers
    i = j = 0; // Initial State of Pointers

    // Sliding window Loop
    while (j < n)
    {
        // Initial Calculation Step
        while (arr[j] > ls.back() && ls.size() > 0)
            ls.pop_back();

        ls.push_back(arr[j]);
        // if Window size didn't hit window size
        if (j - i + 1 < k)
            j++;
        else
        {
            ans.push_back(ls.front());
            if (arr[i] == ls.front())
                ls.pop_front();

            i++;
            j++;
        }
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

vector<int> fxn(vector<int> arr, int n, int k)
{
    vector<int> answer;
    list<int> ls;
    int i = 0, j = 0;

    while (j < n)
    {
        while (arr[j] > ls.front() && ls.size() > 0)
            ls.pop_back();

        ls.push_back(arr[j]);

        if (j - i + 1 < k)
            j++;
        else
        {
            answer.push_back(ls.front());
            if (arr[i] == ls.front())
                ls.pop_front();
            i++;
            j++;
        }
    }
    return answer;
}

int main()
{
    vector<int> arr{1, 3, -1, -3, 5, 3, 6, 7}; // input String
    int n = arr.size();                        // size of input Array
    int k = 3;                                 // size of window
    vector<int> ans = fxn(arr, n, k);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}
*/