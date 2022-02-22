#include <bits/stdc++.h>
using namespace std;

int minProduct(vector<int> arr)
{
    int negCount, minNeg, minPos, size, zeroCount, prod;
    zeroCount = 0;
    negCount = 0;
    minNeg = INT_MIN;
    minPos = INT_MAX;
    size = arr.size();
    prod = 1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            zeroCount++;
            continue;
        }

        else if (arr[i] < 0)
        {
            negCount++;
            minNeg = max(minNeg, arr[i]);
        }
        else if (arr[i] > 0)
        {
            minPos = min(minPos, arr[i]);
        }

        prod = prod * arr[i];
    }
    if (!(negCount & 1) && zeroCount == 0)
    {
        return prod / minNeg;
    }
    if ((negCount & 1) && zeroCount == 0)
    {
        return prod;
    }
    if (zeroCount == size)
    {
        return 0;
    }
    return prod;
}

int main()
{
    //vector<int> arr{-1, -1, -2, 4, 3};
    vector<int> arr{-1,0};
    cout << minProduct(arr);
    return 0;
}