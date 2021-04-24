#include <iostream>
#include <math.h>
using namespace std;

int bitcounter(int arr[] , int number)
{   int ctr = 0 ;
    while (number > 0)
    {
        if ( number & 1 == 1 )
        {
            arr[ctr]++ ;
        }
        number = number >> 1 ;
        ctr++;
    }
    return 0 ;
}
int main()
{   
    int arr[] = {0,0,0,0,0,0,0,0,0,0};
    int arr3[] = {2,2,1,5,1,1,2};
    for(int i=0;i<7 ;i++)
    {
        bitcounter(arr,arr3[i]);
    }
    for (int i =0 ; i<10 ;i++)
    {
        cout<<arr[i]<<"**";
    }
    cout<<endl;
    for (int i =0 ; i<10 ;i++)
    {
        if ( arr[i] >=3 )
        {
            arr[i] = arr[i] % 3 ;
        }
    }
      for (int i =0 ; i<10 ;i++)
    {
        cout<<arr[i]<<"**";
    }
    int binry = 0 ;
     for (int i =0 ; i<10 ;i++)
    {
        if (arr[i] ==1)
        {
            binry = binry + pow(2,i); 
        }
    }
    cout<<binry;
    // int arr1[] = {5, 6, 7, 5, 6, 7, 1, 3, 3};
    // int x = 0;
    // int length = sizeof(arr1)/sizeof(arr1[0]);
    // for (int i = 0; i < length; i++)
    // {
    //     x = arr1[i] ^ x;
    // }
    // cout << x;

    //********************************************************************************************************//

    // int arr2[] = {5, 6, 7, 2, 5, 6, 7, 9, 3, 3};
    // int y = 0;
    // int length2 = sizeof(arr2)/sizeof(arr2[0]);
    // for (int i = 0; i < length2; i++)
    // {
    //     y = arr2[i] ^ y;
    // }
    // int temp = y;
    // int temp2 = y;
    // int temp3 = y;
    // int counter = 0;
    // while (temp > 0)
    // {
    //     if (temp & 1 == 1)
    //         break;
    //     temp = temp>>1;
    //     counter++;
    // }

    // for (int j =0 ;j <length2 ; j++)
    // {
    //     if ((arr2[j]>>counter) & 1 == 1)
    //     {
    //         temp2 = arr2[j] ^ temp2 ;

    //     }
    //     else
    //     {
    //         temp3 = arr2[j] ^ temp3 ;
    //     }

    // }
    // cout<<temp2<<"***"<<temp3;

    //********************************************************************************************************//
    return 0;
}
