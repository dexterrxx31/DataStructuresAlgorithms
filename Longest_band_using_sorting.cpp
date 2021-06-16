#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std ;

void vector_traversal(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "|" << arr[i] << "|";
    }
    cout << endl;
}
vector<int> length_of_bands(vector<int> arr)
{   
    vector<int> result ;
    int counter =  0 ;
    for(int i = 1 ; i <= arr.size() ; i++ )
    {   
        counter++;
        if( arr[i] - arr[i-1] != 1)
        {
            result.push_back(counter);
            counter = 0 ;
        }
        
    }
    return result ;
}
int main()
{
    vector<int> arr  = {1,9,3,0,18,5,2,4,10,7,12,6};
    sort(arr.begin() , arr.end());
    vector_traversal(arr);
    vector<int> array_of_length_of_bands = length_of_bands(arr) ;
    vector_traversal(array_of_length_of_bands) ; 
    return 0 ;
}