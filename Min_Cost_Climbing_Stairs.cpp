#include <bits/stdc++.h>
using namespace std;

int fxn(vector<int> arr , int n , int i ,vector<int> t)
{
    if( i >= n ) return 0 ; 
    if( t[i] != -1) return t[i] ;
    return t[i] = arr[i] + min(fxn(arr , n , i+1 ,t ) ,fxn(arr , n , i+2,t));

}
// Recursive Approch
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size() ; 
    vector<int> t(n, -1);
    return min(fxn(cost , n  , 0 , t) , fxn(cost ,n , 1 ,t)) ;
}

// int minCostClimbingStairs(vector<int> &cost)
// {
//     int n = cost.size() ; 
//     vector<int> t(n+1, -1);
//     t[0] = 0 ;
//     int ans1 = ans2 = INT_MAX ;
//     for(int i = 0 ; i < n ; i++)
//     {
//         ans1 = min(ans1 , cost[i] )
//     }
// }

int main()
{   vector<int> arr = {10,15,20} ;
    cout<<minCostClimbingStairs(arr);
    return 0;
}