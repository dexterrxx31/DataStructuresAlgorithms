#include <bits/stdc++.h>
using namespace std;

int binary(vector<int> arr , int l , int r , int ele)
{
    int  mid ;

    while(l <= r)
    {   
        mid = (l+r) >> 1 ;
        if(arr[mid] == ele) return mid ;
        else if(arr[mid] < ele) l = mid + 1;
        else r = mid - 1 ;
    }
    return -1 ;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int target; cin >> target;
    vector<int> arr; int ele;
    while (cin >> ele) arr.push_back(ele);
    
    cout<<binary(arr , 0 , 7 , target);
    return 0;
}
