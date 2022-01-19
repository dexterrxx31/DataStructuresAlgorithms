#include <bits/stdc++.h>
#include <string>
using namespace std;


void permutation_of_string(string st , int left ,int right)
{
    if( left == right )
    {
        cout<<st<<"||" ;
        return;
    }
    for (int i = left; i <= right; i++)
    {
        swap(st[left] , st[i]);
        permutation_of_string(st , left+1,right);
        swap(st[left] , st[i]);
    }
    
}
int main()
{   
    string st = "Riyan";
    int num = st.length();
    permutation_of_string(st , 0 , num-1);
    return 0; 
}