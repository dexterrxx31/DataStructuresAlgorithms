#include<bits/stdc++.h>
using namespace std ;

int solution(int move)
{
    int rem = 0  ;
    if(move % 5 >= 1) rem = 1 ;
    return move/5 + rem;
}
int main()
{   
    int testcases ; cin>>testcases ;
    int move ;
    for(int i = 1 ; i <= testcases ; i++)
    {
        cin>>move ;
        cout<<"Case #"<<i<<": "<<solution(move)<<endl;
    }
    return 0 ; 
}