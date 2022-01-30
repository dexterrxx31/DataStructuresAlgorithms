#include <iostream>
using namespace std;

//Pair Structure
struct Pair
{
    int max;
    int min;
};

// Simple Linear Search Method
Pair max_min_linear_search(int arr[], int size)
{
    struct Pair result;
    if (arr[0] > arr[1])
    {
        result.max = arr[0];
        result.min = arr[1];
    }
    else
    {
        result.max = arr[1];
        result.min = arr[0];
    }

    for (int i = 2; i < size; i++)
    {
        if (arr[i] > result.max)
        {
            result.max = arr[i];
        }
        if (arr[i] < result.min)
        {
            result.min = arr[i];
        }
    }
    return result;
}

//Tournament Approch
Pair max_min_tournament(int arr[], int low, int high)
{
    struct Pair result, mml, mmr;
    int mid;

    //if size = 1 then both max and min will be same number that is index 1 element
    if (low == high)
    {
        result.max = arr[0];
        result.min = arr[0];
        return result;
    }

    //if size = 2 then there will be comparision between first and second index element
    if (high == low + 1)
    {
        if (arr[low] > arr[high])
        {
            result.max = arr[low];
            result.min = arr[high];
        }
        else
        {
            result.max = arr[high];
            result.min = arr[low];
        }
        return result;
    }

    //Splitting task in two halfs and operating function
    mid = (low + high) / 2;
    mml = max_min_tournament(arr, low, mid);
    mmr = max_min_tournament(arr, mid + 1, high);

    // Compare between max and min elements of both the halfs
    if (mml.min < mmr.min)
        result.min = mml.min;
    else
        result.min = mmr.min;

    if (mml.max > mmr.max)
        result.max = mml.max;
    else
        result.max = mmr.max;

    return result;
}

//Compare in pairs
struct Pair comp_pair(int arr[], int n)
{
    struct Pair minmax;
    int i;

    //if n is even compare between first and second element
    if (n % 2 == 0)
    {
        if (arr[0] > arr[1])
        {
            minmax.max = arr[0];
            minmax.min = arr[1];
        }
        else
        {
            minmax.max = arr[1];
            minmax.min = arr[0];
        }

        i = 2;
    }
    //if n is odd then max and min is first element it self
    else
    {
        minmax.max = arr[0];
        minmax.min = arr[0];

        i = 1;
    }

    //Compare between pairs
    while (i < n - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            if (arr[i] > minmax.max)
            {
                minmax.max = arr[i];
            }

            if (arr[i + 1] < minmax.min)
            {
                minmax.min = arr[i + 1];
            }
        }
        else
        {
            if (arr[i + 1] > minmax.max)
            {
                minmax.max = arr[i + 1];
            }
            if (arr[i] < minmax.min)
            {
                minmax.min = arr[i];
            }
        }

        i += 2;
    }
    return minmax;
}

//Driver program
int main()
{
    int arr[] = {2, 1, 0, 67, -99, 8, 5, 7, 8, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct Pair result = comp_pair(arr, size);
    cout << "Max number is :" << result.max << endl;
    cout << "Min number is :" << result.min << endl;
    return 0;
}