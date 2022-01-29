#include<iostream>
using namespace std;

//Pair Structure
struct Pair {
    int max ;
    int min ;
};

// Simple Linear Search Method
Pair max_min_linear_search(int arr[] , int size)
{   
    struct Pair result ;
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
    
    for (int i = 2 ; i < size ; i ++)
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

//Tournament Approch
Pair max_min_tournament(int arr[] , int low , int high)
{   
    struct Pair result , mml , mmr ;
    int mid ;

    if(low == high )
    {
        result.max = arr[0];
        result.min = arr[0];
        return result;
    }

    if (high == low + 1)
    {
        if (arr[low] > arr[high])
        {
            result.max = arr[low];
            result.min = arr[high];
        }
        else
        {
            result.max = arr[high];
            result.min = arr[low];
        }
        return result;
    }
    
    mid = (low + high) / 2 ;
    mml = max_min_tournament(arr , low , mid);
    mmr = max_min_tournament(arr , mid+1 , high);
    
    if (mml.min < mmr.min)
        result.min = mml.min;
    else
        result.min = mmr.min;    
     
    if (mml.max > mmr.max)
        result.max = mml.max;
    else
        result.max = mmr.max;  

    return result ; 
}



//Driver program
int main()
{   
    int arr[] = {2,1,0,67,-99,8,5,7, 8 , 90};
    int size = sizeof(arr)/sizeof(arr[0]);
    //cout<<"::"<<size<<"::"<<endl;
    struct Pair result = max_min_tournament(arr , 0 , size - 1 );
    cout<<"Max number is :"<<result.max<<endl;
    cout<<"Min number is :"<<result.min<<endl;
    return 0 ; 
}