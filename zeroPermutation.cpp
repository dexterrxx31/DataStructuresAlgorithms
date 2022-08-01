#include <bits/stdc++.h>
using namespace std;

vector<int> zeroPermutation( vector<int> & v) {
    set<int> s ; 
    int n = v.size() ; 
    int sum = n*(n + 1) >> 1 ;
    int sum_half = sum >> 1 ;
    int counter =  0  ;
    int n2 =  n ; 
    
    while( sum_half )
    {
        if(sum_half > n2 )
        {
            sum_half -= n2  ;
            s.insert(n2) ;
            n2-- ;
        }
        else if(sum_half <= n2)
        {
            s.insert(sum_half) ;
            sum_half = 0 ; 
        }
    }
    for(int i = 0 ; i < n ; i++)
        if(s.find(v[i]) != s.end())
            v[i] *= -1  ;  
    
    return v ; 
}


int main()
{
    vector<int> v = {1, 2, 3, 4};

    v = zeroPermutation(v);
    
    for (auto a : v)
        cout << a << " ";
    return 0;
}