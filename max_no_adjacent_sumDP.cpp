#include<bits/stdc++.h>
using namespace std ;

//Recursive Approch
int rec_apr(vector<int> arr , int i , int n , int prev)
{
    if(i == n ) return 0 ; 
    int ans1 = rec_apr(arr, i + 1, n , prev) ;
    int ans2 = 0 ; 
    if(prev + 1 != i) ans2 = rec_apr(arr , i + 1 ,n , i) + arr[i] ;
    return max(ans1 , ans2) ;
}

//Memoiasation Approch
vector<int> t(7 , -1) ;
int rec_mem(vector<int> arr , int i , int n , int prev)
{
    if(i == n ) return 0 ; 
    if(t[i] !=-1) return t[i] ;
    else
    {
        int ans1 = rec_apr(arr, i + 1, n , prev) ;
        int ans2 = 0 ; 
        if(prev + 1 != i) ans2 = rec_apr(arr , i + 1 ,n , i) + arr[i] ;
        return t[i] = max(ans1 , ans2) ;
    }
}

//Bottom up Approch 
int non_adjacent_sum(vector<int> arr  ,int i  , int n )
{
    vector<int> ans (n , 0 ) ;
    ans[0] = arr[0] ;
    ans[1] = max(arr[0] , arr[1]) ;
    for(int i = 2 ; i < n ; i++) ans[i] = max( ans[i-1] , arr[i] + ans[i-2]) ;
    return ans[n-1] ;
}

int main()
{
    vector<int> arr  ={6,10,12,7,9,14};
    int i = 0 ; 
    int n = arr.size() ; 
    cout<<non_adjacent_sum(arr , i , n )<<endl ;
    cout<<rec_apr(arr , 0 , n , INT_MIN)<<endl ;
    cout<<rec_mem(arr , 0 , n , INT_MIN) ;
    return 0 ; 
}