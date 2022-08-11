#include<bits/stdc++.h>
using namespace std ;

//Top Down Approch
vector<vector<int>> t(9 , vector<int>(9 , -1)) ;

int rod(int W ,int n , vector<int> prices , vector<int> length )
{
    if(n == 0 || W == 0 ) return 0 ; 

    if(t[n][W] != -1) return t[n][W] ;

    if(length[n - 1 ] <= W)
    return t[n][W] = max(prices[n-1] + rod(W-length[n-1] , n-1 , prices , length) , rod(W , n-1 , prices , length));
    else if(length[n-1] > W)
    return  t[n][W] = rod(W , n-1 , prices , length);
    return -1 ;
}

int main()
{   
    cout<<rod(8 , 8 , {6,5,8,9,10,17,17,20} ,{1,2,3,4,5,6,7,8});
    return 0 ; 
}