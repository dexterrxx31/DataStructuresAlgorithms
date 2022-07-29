#include<bits/stdc++.h>
using namespace std;

int clear_last_i(int n  , int i )
{
    int mask = 1 << i  ;
    return n & mask ;
}
int clear_rang_of_bits(int n , int i , int j )
{
  int mask = (~0 << i ) | ~(~0 << j) ;
  return n & mask ;
}

//Two number N and M are given , i and j positions are given 
//put M in between i and j in N 
int set_in_between(int n , int i , int j , int m )
{
  //Will clear that part between i and j ; 
  int mask = (-1<<i) | ~(-1<<j) ;
  n = n & mask ; 
  m = m << j ; 
  return n | m  ; 
}

int num_if_set_bits_1(int n )
{
  while(n > 0 )
  {
    
  }
}
int main()
{   
    int n = 128 ;
    int i = 4 ;
    int j = 2 ;
    int m =  7 ;
    //cout<<clear_last_i(n , i ) ;
    //cout<<clear_rang_of_bits(n, i , j ) ;
    cout<<set_in_between( n , i , j , m ) ;
  return 0 ;
}