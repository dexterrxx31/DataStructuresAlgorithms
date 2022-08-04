#include<bits/stdc++.h>
using namespace std;

void movezeros(vector<int> arr)
{
    int i = 0 , j = 0 , n = arr.size();
    while(i < n - 1)
    {   
        if( j > i ){ i = j  ;}
        while(arr[i] == 0 and i < n - 1){i++;}
        if(arr[j] == 0 and j < i )
        {   
            int temp = arr[j] ;
            arr[j] = arr[i] ;
            arr[i] = temp ;
        }
        j++;
    }
    for(auto x : arr)
        cout<<x<<" ";
}

int main()
{
    vector<int> arr = {1,0} ;
    movezeros(arr);
    return 0 ; 
}
