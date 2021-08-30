#include <iostream>
#include <vector>
using namespace std;

void swap(int *n1 , int *n2)
{
    int temp = *n1 ;
    *n1 = *n2 ;
    *n2 = temp;
}

int partition(int arr[], int start, int end)
{   
    int pivote_element_index = end - 1 ;    
    int pivote_element = arr[pivote_element_index];
    
    for(int i = start ; i < end ; i++)
    {
        if( arr[i] )
    }
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

    //QuickSort(arr, start , end );

    //displaying Sorted array
    // for (int i = 0; i < 9; i++)
    // {
    //     cout << arr[i] << "||";
    // }

    return 0;
}
