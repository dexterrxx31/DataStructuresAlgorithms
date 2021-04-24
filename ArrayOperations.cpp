#include<iostream>
using namespace std ;
int displayMyArray(int arr[] , int usedSize)
{
    for (int i =0 ;i <usedSize ; i++)
    {
        cout<<arr[i]<<"||";
    }
    return 0;
}
int insertInMyArray(int arr[] , int element , int position , int usedSize)
{
    for(int i = usedSize; i>0 ; i--)
    {   if ( i == position)
        {   arr[i+1] = arr[i];
            arr[i] = element;
            break;
        }
        arr[i+1] = arr[i];
    }
    return 0;
}
int deleteInMyArray(int arr[] , int element , int position , int usedSize)
{   
    for (int i = position; i < usedSize ; i ++)
    {
        arr[i] = arr [i+1];
    }
    return 0;
}


int main()
{
    int arr[50];
    int usedSize,totalSize,element = 56 , position = 2;
    totalSize = 50 ;
    usedSize = 5 ;
    for (int i = 0 ; i<usedSize ;i++)
        arr[i] = i ;
   
    insertInMyArray(arr,element,position,usedSize);

    displayMyArray(arr,usedSize+1);

    usedSize++ ;

    cout<<endl;
    deleteInMyArray(arr,element,position,usedSize);

    usedSize--;
    displayMyArray(arr,usedSize);

    return 0 ;

}