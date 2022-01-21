#include <iostream>
using namespace std;

//Display function
void display_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "||" << arr[i] << "||";
    }
    cout << endl;
}
//sorting an array using bubble sort
void bubble_sort(int arr[], int size)
{
    int temp = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
        display_array(arr, 10);
    }
}

//obtimised bubble sort
void bubble_sort_obt(int arr[], int size)
{
    int temp = 0;
    bool swapped = false;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
        display_array(arr, 10);
    }
}

//recursive bubble sorting
void bubble_sort_rec(int arr[], int size)
{
    if (size == 1)
    {
        return;
    }
    int temp = 0;
    for (int j = 0; j < size - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
        }
    }
    bubble_sort_rec(arr, size - 1);
}

//sorting an array using selection sort
void selection_sort(int arr[], int size)
{
    int small;
    for (int i = 0; i < size - 1; i++)
    {
        small = i;
        for (int j = i; j < size - 1; j++)
        {
            if (arr[j + 1] < arr[small])
            {
                small = j + 1;
            }
        }
        int temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;
    }
}

//sorting an array using insertion sort
void insert_sort(int arr[], int size)
{
    int temp;
    int j;
    for (int i = 0; i <= size - 1; i++)
    {
        j = i;
        while (j > 0)
        {
            if (arr[j - 1] > arr[j])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            j--;
        }
        display_array(arr, size);
    }
}

void swap(int arr[], int n, int m)
{
    int temp = arr[m];
    arr[m] = arr[n];
    arr[n] = temp;
}
int partition(int arr[], int lower_bound, int upper_bound)
{
    int pivote = arr[lower_bound];
    int start = lower_bound;
    int end = upper_bound;
    while (start < end)
    {
        while (arr[start] <= pivote)
        {
            start++;
        }
        while (arr[end] > pivote)
        {
            end--;
        }
        if (start <= end)
        {
            swap(arr, start, end);
        }
    }
    swap(arr, lower_bound, end);
    return end;
}
//Quick Sorting
void quick_sorting(int arr[], int lower_bound, int upper_bound)
{
    if (lower_bound < upper_bound)
    {
        int loc = partition(arr, lower_bound, upper_bound);
        quick_sorting(arr, lower_bound, loc - 1);
        quick_sorting(arr, loc + 1, upper_bound);
    }
}

int brr[10];
void merge(int arr[], int lower_bound, int mid, int upper_bound)
{   
    int p = mid - lower_bound + 1 ;
    int q = upper_bound - mid ; 

    int left[p];
    int right[q];

    for (int i = 0; i < p; i++)
    {
        left[i] = arr[lower_bound + i];
    }
    for (int j = 0; j < q; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = lower_bound;

    while (i < p && j < q)
    {   
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < p)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < q)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

//Merge Sorting
void merge_sorting(int arr[], int lower_bound, int upper_bound)
{
    int mid;
    if (lower_bound < upper_bound)
    {

        mid = (lower_bound + upper_bound) / 2;
        merge_sorting(arr, lower_bound, mid);
        merge_sorting(arr, mid + 1, upper_bound);
        merge(arr, lower_bound, mid, upper_bound);
    }
}
//Redix 2 Sorting
void redix_heap(int arr[], int size)
{
}

int main()
{
    int arr[] = {0, 3, 25, 1, 99, 8, 6, 71, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    display_array(arr, size);
    //bubble_sort_rec(arr, 10);
    //selection_sort(arr,10);
    //insert_sort(arr,10);
    merge_sorting(arr, 0, 9);
    display_array(arr, size);
    return 0;
}