#include<iostream>
#include <bits/stdc++.h>
using namespace std;

//using set STL c++

int main()
{
    int arr[] = {2,3,0,44,-1,6,4,100,-99};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    set<int> s(arr, arr + size); //declaring set and putting array elements inside
    set<int>::iterator itr = s.begin(); // s.begin() returns a pointer to first
    advance(itr, k - 1); // itr points to kth element in set
    cout << *itr << "\n";
    return 0;
}