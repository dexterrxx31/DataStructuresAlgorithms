#include <iostream>
using namespace std;

int binarySearch(int arr[], int leftIndex, int rightIndex, int searchElement)
{
    if (rightIndex > 1)
    {
        int midIndex = (leftIndex + rightIndex -1) / 2;
        if (arr[midIndex] == searchElement)
        {
            return midIndex ;
        }
        if (arr[midIndex] < searchElement)
        {
            return binarySearch(arr,midIndex + 1 ,rightIndex , searchElement);
        }
        if (arr[midIndex] >searchElement)
            return binarySearch(arr,leftIndex ,midIndex -1, searchElement);
    
    }
    return -1;
}
    int main()
    {
        int arr[7] = {23, 67, 90, 92, 100, 784, 800}, left, right, searchElement;
        left = 0;
        right = sizeof(arr) / sizeof(arr[0]);
        searchElement = 23;
        int position = binarySearch(arr, left, right, searchElement);
        if (position == -1){
            cout<<"Sorry Element is not present in array"<<endl;
        }
        else
            cout<<"Element is present in index "<<position;
        return 0;
    }