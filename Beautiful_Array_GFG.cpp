#include <bits/stdc++.h>
using namespace std;

vector<int> makeBeautiful(vector<int> arr)
{
    /*vector<int> test = arr;
    sort(test.begin(), test.end());
    if (test[0] * test[test.size() - 1] > 0)
    {
        return arr;
    }

    else if (test[0] * test[test.size() - 1] < 0 and test.size() == 2)
    {
        return {};
    }
*/
    vector<int> ans;
    int j = 1;

    while (j <= arr.size())
    {
        if (arr[j - 1] * arr[j] < 0)
        {
            /*if (arr[j - 1] == 0 and arr[j] == 0)
            {
                ans.push_back(arr[j - 1]);
                j++;
            }*/
            // else
            //{
            j = j + 2;
            //}
        }
        else
        {
            if (arr[j - 1] != 0 and arr[j] == 0 || arr[j - 1] == 0 and arr[j] != 0)
            {
                j = j + 2;
            }
            else
            {
                ans.push_back(arr[j - 1]);
                j++;
            }
        }
    }

    /* for (int i = 0; i < ans.size(); i++)
     {
         cout << ans[i] << " ";
     }
 */
    // return makeBeautiful(ans);
    return ans;
}

int main()
{
    vector<int> arr = {-3, -1, -19, 0, 6, -13, 12};

    vector<int> ans = makeBeautiful(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}