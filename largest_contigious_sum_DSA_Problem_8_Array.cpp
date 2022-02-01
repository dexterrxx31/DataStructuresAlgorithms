//Largest sum of contigious part of an array

#include <bits/stdc++.h>
#include <climits>
using namespace std;

//Brute Force Approch with O(n^3)
void printing_subarray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            for (int k = i; k < j; k++)
            {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}

//O(n^3)
void largest_subarray_sum(int arr[], int size)
{
    int max_sum = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum = sum + arr[k];
            max_sum = max(sum, max_sum);
        }
    }
    cout << max_sum;
}

//O(n^2)
void running_sum_approch(int arr[], int size)
{
    int max_sum = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum = sum + arr[j];
            max_sum = max(sum, max_sum);
        }
    }
    cout << max_sum;
}

//Kadane's Algorithm
void kadanes_algo(int arr[], int size)
{
    int max_sum = INT_MIN;
    int current_sum = 0;

    for (int i = 0; i < size; i++)
    {
        current_sum = current_sum + arr[i];
        if (current_sum < 0)
            current_sum = 0;
        max_sum = max(max_sum, current_sum);
    }
    cout << max_sum;
}

int main()
{
    int arr[] = {-1, 4, 7, 2};
    int start, end;
    int size = sizeof(arr) / sizeof(arr[0]);
    //printing_subarray(arr ,size);
    //largest_subarray_sum(arr, size);
    //running_sum_approch(arr , size);
    kadanes_algo(arr , size) ;
    return 0;
}