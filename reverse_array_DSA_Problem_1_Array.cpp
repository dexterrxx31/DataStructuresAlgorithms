#include<iostream>
#include<vector>
using namespace std;

//displaying all elements of an array
int display_array(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<"||";
    }
}

//swaping elements on array positions 
vector<int> swap(int current_position , int destination_postion , vector<int> arr)
{
    int t = arr[destination_postion];
    arr[destination_postion] = arr[current_position];
    arr[current_position] = t ;
    return arr;
}

//bruteforce method for revering an array.
//simply swaping elements from fst to last index and so on.
vector<int> reversing_array_iterative_method(vector<int> arr)
{
    int temp;

        for (int i = 0 , j = arr.size() - 1; i < arr.size()/2 ; i++ , j--)
        {
            arr = swap(i ,j , arr);
        }
    return arr ;

}

//recursive approch

void reversing_array_using_recursion(int arr[] , int start , int end)
{
    if( start >= end )
    return ;
    int temp = arr[end];
    arr[end] = arr[start];
    arr[start] = temp;
    reversing_array_using_recursion(arr,start + 1, end - 1);
}

void disp(int arr[])
{
    for(int i = 0 ; i < 7 ; i++)
    {
        cout<<arr[i]<<"||";
    }
}

int main()
{    
    vector<int> arr{0,1,2,3,4,5,6,7,8};
    int arr2[7] = {0,1,2,3,4,5,6};

    int start =  0 ;
    int end = 6;
    disp(arr2);
    // arr = reversing_array_iterative_method(arr);
    reversing_array_using_recursion(arr2 , start , end );
    cout<<"Reversed"<<endl;
    disp(arr2);
    return 0 ;
}


