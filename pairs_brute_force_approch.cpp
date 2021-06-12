#include<iostream>
#include<vector>
using namespace std ;

//Line 1 -- Array of int
//Line 2 -- Targeted sum

int if_targeted_sum ( int a , int b , int target)
{
    return (a+b == target)? 1 : 0 ; 
}
vector<int> pairs(vector<int> arr , int target_sum)
{   
    vector<int> result ;
    for(int i = 0 ; i < arr.size() ; i++)
    {
        for(int j = 0 ; j < arr.size() ;j++)
        {   if( j == i )
            {
                continue ;
            }
            if(if_targeted_sum(arr[i] , arr[j] , target_sum))
            {
                result.push_back(arr[i]);
                result.push_back(arr[j]);
                return result ; 
            }
            
        }
    }
    return result ;
}
int main()
{
    vector<int> arr = {10,5,2,3,-6,9,11} ;
    int target_sum = 4 ;
    vector<int> result  = pairs(arr , target_sum) ;
    cout<<result[0]<<"||"<<result[1] ;
    return 0 ;
}