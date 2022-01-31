#include<iostream>
#include <bits/stdc++.h>
using namespace std;

//using set STL c++
void max_min_set(int arr[] , int size , int k)
{
    set<int ,greater<int> > s(arr, arr + size); //declaring set and putting array elements inside
    set<int>::iterator itr = s.begin(); // s.begin() returns a pointer to first
    advance(itr, k - 1); // itr points to kth element in set
    cout << *itr << "\n";
}

//Swap elements in an array by index
void swap(int arr[], int n, int m)
{
    int temp;
    temp = arr[n];
    arr[n] = arr[m];
    arr[m] = temp;
}

void heapify (int arr[] , int n ,int i)
{   
    int largest = i ; // Initialize largest as a root
    int left_child = 2*i  ;
    int right_child = 2*i + 1 ;

    if(left_child < n && arr[left_child] > arr[largest])
        largest = left_child ;
    
    if(right_child < n && arr[right_child] > arr[largest])
        largest = right_child ;
    
    if(largest != i)
    {
        swap(arr , i , largest);
        heapify(arr , n ,largest);
    }
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

void heap_sort(int arr[] , int n , int k)
{
    for (int i = n; i > k; i--)
    {
        delete_element(arr , i );
    }
    cout<<arr[n-k + 1];
}

int main()
{
    //int arr[] = {0,2,3,0,44,-1,6,4,100,-99};
    int arr[] = {2,3,0,44,-1,6,4,100,-99};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    // for(int i = (size-1)/2  ; i > 0 ; i--)
    //     heapify( arr , size-1 , i);

    // for(int j = 0 ; j < size ; j++)
    //     cout<<arr[j]<<" ";

    // cout<<endl;
    // heap_sort(arr , size-1 , k);
    max_min_set(arr,size,k);
  
    return 0;
}