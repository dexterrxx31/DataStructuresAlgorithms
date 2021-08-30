#include <iostream>
using namespace std;

int main()
{
    int arr[] = {34, 1, 78, 3, 89};
    int n = 5;
    int temp ;
    int j;
    for (int i = 1; i < n - 1; i++)
    {   
        temp = arr[i] ;
        j = i - 1 ;
        while ( j >=0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    //displaying Sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "||";
    }

    return 0;
}
