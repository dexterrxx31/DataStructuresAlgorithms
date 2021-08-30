#include <iostream>
using namespace std;

int main()
{
    int arr[] = {34, 1, 78, 3, 89};
    int n = 5;
    int min_pos;
    for (int i = 0; i < n - 1; i++)
    {
        min_pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_pos])
            {
                min_pos = j;
            }
        }

        //swapping
        int temp = arr[i];
        arr[i] = arr[min_pos];
        arr[min_pos] = temp;
    }

    //displaying Sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "||";
    }
    return 0;
}
