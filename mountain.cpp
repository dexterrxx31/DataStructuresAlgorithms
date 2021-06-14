#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std ;

vector<int> peaks_of_mountain(vector<int> arr)
{
    vector<int> result ;
    int i = 1 ; 
    while( i < arr.size() - 1 )
    {
        if(arr[i-1] < arr[i] && arr[i+1] < arr[i])
        {
            result.push_back(i);
        }
        i++;
    }
    return result ;
}
void vector_traversal(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "|" << arr[i] << "|";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {5,6,1,2,3,5,4,3,2,0,1,2,3,-2,4};
    vector<int> peaks = peaks_of_mountain(arr);
    vector_traversal(peaks);
    return 0 ;
}
