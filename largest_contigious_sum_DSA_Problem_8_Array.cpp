//Largest sum of contigious part of an array

#include <bits/stdc++.h>
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

void largest_subarray_sum(int arr[], int size)
{
    int sum = 0;
    int sum2 = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            for (int k = i; k <= j; k++)
                sum = sum + arr[k];
            if (sum > sum2)
                sum2 = sum;
            sum = 0;
        }
    }
    cout << sum2;
}

int main()
{
    int arr[] = {-1, 4, 7, 2};
    int start, end;
    int size = sizeof(arr) / sizeof(arr[0]);
    //printing_subarray(arr ,size);
    largest_subarray_sum(arr, size);
    return 0;
}