//Move nagative Elements on one side of array
//#include<iostream>
#include <bits/stdc++.h>
using namespace std;

//Swap elements in an array by index
void swap(int arr[], int n, int m)
{
    int temp;
    temp = arr[n];
    arr[n] = arr[m];
    arr[m] = temp;
}

//taking two pointers approch for array
void move_negative_numbers_on_one_side(int arr[], int size)
{
    int lo = 0;        //for first index
    int hi = size - 1; //for last index

    while (lo < hi)
    {
        while (arr[lo] < 0 && lo < hi)
            lo++;
        while (arr[hi] >= 0 && hi > lo)
            hi--;
        swap(arr, hi, lo);
    }
}

int main()
{
    int arr[] = {-1, 0, 1, 2, -90, 3, -2, 6, 7, -4, -7};
    int size = sizeof(arr) / sizeof(arr[0]);
    move_negative_numbers_on_one_side(arr, size);

    //printing an Array elements
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}