#include <iostream>
#include <vector>
using namespace std;

int partition(int arr[], int start, int end)
{   int pivot_element_location = start ;
    while (start < end)
    {
        for (int i = start; i < 9; i++)
        {
            if (arr[i] > arr[pivot_element_location])
            {
                start = i;
                break;
            }
        }
        for (int j = end; j > 0; j--)
        {
            if (arr[j] < arr[pivot_element_location])
            {
                end = j;
                break;
            }
        }
        if (start < end)
        {
            int temp_1 = arr[start];
            arr[start] = arr[end];
            arr[end] = temp_1;
        }
    }

    int temp_2 = arr[pivot_element_location];
    arr[pivot_element_location] = arr[end];
    arr[end] = temp_2;
    return end ;
}
void QuickSort(int arr[], int lb, int ub)
{   
    int location;
    if (lb < ub)
    {
        location = partition(arr, lb, ub);
        QuickSort(arr, location + 1, ub);
        QuickSort(arr, lb, location - 1);
    }
}

int main()
{
    int arr[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
    int start, end;
    start = 0;
    end = 9 ;
    QuickSort(arr, start , end );

    //displaying Sorted array
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << "||";
    }

    return 0;
}
