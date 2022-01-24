#include<iostream>
using namespace std;


struct Pair {
    int max ;
    int min ;
};

Pair max_min(int arr[])
{   
    struct Pair result ;
    //int size = sizeof(arr) / sizeof(arr[0]);
    if (arr[0] > arr[1])
    {
        result.max = arr[0];
        result.min = arr[1];
    }
    else
    {
        result.max = arr[1];
        result.min = arr[0];        
    }
    
    for (int i = 2 ; i < 10 ; i ++)
    {
        if(arr[i] > result.max)
        {
            result.max = arr[i];
        }
        if(arr[i] < result.min)
        {
            result.min = arr[i];
        }
    }
    return result ; 
}
int main()
{   
    int arr[] = {2,1,0,67,-99,8,5,7, 8 , 90};
    struct Pair result = max_min(arr);
    cout<<"Max number is :"<<result.max<<endl;
    cout<<"Min number is :"<<result.min<<endl;
    return 0 ; 
}