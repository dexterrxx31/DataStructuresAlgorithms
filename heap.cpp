#include <iostream>
using namespace std;

//Swap elements in an array by index
void swap(int arr[], int n, int m)
{
    int temp;
    temp = arr[n];
    arr[n] = arr[m];
    arr[m] = temp;
}

// void heapify(int arr[] , int size , int i )
// {
//     int parent =( i - 1 ) / 2; 
//     if (arr[parent] > 0)
//     {
//         if(arr[i] > arr[parent])
//         {
//             swap(arr,i,parent);
//             heapify(arr , size , parent);
//         }
//     }
// }


void insert_element(int A[] , int n )
{
    int i = n , temp;
    temp = A[i];

    while (i>1 && temp>A[i/2])
    {
        A[i] = A[i/2];
        i = i / 2 ;
    }
    A[i] = temp ;
}

int delete_element(int A[] , int n )
{
    int i , j ,deleted_element ;

    //Swaping Root element and last leaf
    deleted_element = A[1];
    swap(A , 1 , n );

    //setting parent and child 
    i = 1 ; j = i*2;

    while(j < n-1 )
    {
        if(A[j+1] > A[j])
            j++;
        if(A[i] <A[j])
        {   
            //Swap parent and Child
            swap(A , i , j );
    
            //Updating child element as parent and  initialing j to its child
            i = j ;
            j = 2*j ;
        }
        else
            break;      // If parent is greater than child then its time to stop the loop
    }
    //returning the deleted value 
    return deleted_element;
}

void heap_sort(int arr[] , int n )
{
    for (int i = n; i > 1; i--)
    {
        delete_element(arr , i );
    }
}
int main()
{
    //An Array forming Max Heap
    int H[] = {0,10,20,30,25,5,40,35}; 

    for(int i = 2; i<=7 ; i++)
        insert_element(H,i);

    //cout<<delete_element(H,7)<<endl;
    heap_sort(H , 7);
    for (int j = 0; j <= 7; j++)
        cout<<H[j]<<" ";
    
    
    return 0;
}