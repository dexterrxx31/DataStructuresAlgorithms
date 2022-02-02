//Min number of jump to get to the end of array
//Each element represent the max jump allowed

#include <bits/stdc++.h>
#include <climits>
using namespace std;

//Recursive Approch
int decide_jump(int arr[] ,int start ,  int n )
{
    if( start >= n-1 )
        return 0 ; 

    int min_jump = INT_MAX ;

    for (int i = 1  ; i <= arr[start]  && i< n ; i++)
    {
        min_jump = min (min_jump , 1 + decide_jump(arr , start + i ,n));
    }
    return min_jump;
}

int min_jump_to_end(int arr[], int n)
{
    return decide_jump(arr , 0 , n);
}


int main()
{
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << min_jump_to_end(arr, n);
    return 0;
}
