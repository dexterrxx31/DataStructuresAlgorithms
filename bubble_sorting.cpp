#include <iostream>
using namespace std;

int main()
{
    int arr[] = {34, 1, 78, 3, 89};
    int n = 5;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            //swaping
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    //displaying Sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "||";
    }

    return 0;
}
