#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> &array , int start , int end , int mid)
{
    int nn = mid - start + 1 ;
    int mm = end - mid ;
    
    vector<int> temp_nn , temp_mm;

    for (int i = 0; i < nn; i++)
    {
        temp_nn[i] = array[start + i];
    }
    for (int j = 0; j < mm; j++)
    {
        temp_mm[j] = array[mid + 1 + j];
    }

    int x , y , z ;
    x = 0 ; 
    y = 0 ;
    z = start ;

  while (x < nn && y < mm) {
    if (temp_nn[x] <= temp_mm[y]) {
      array[z] = temp_nn[x];
      x++;
    } else {
      array[z] = temp_mm[y];
      y++;
    }
    z++;
  }

  while (x < nn) {
    array[z] = temp_nn[x];
    x++;
    z++;
  }

  while (y < mm) {
    array[z] = temp_mm[y];
    y++;
    z++;
  }
}
void mergeSort(vector<int> &array , int start , int end )
{
    if(start >= end)
    {
        return ;
    }
    int mid = ( start + end ) / 2;
    mergeSort(array , start , mid);
    mergeSort(array , mid+1 , end);
    return merge(array, start , end , mid);
}
int main()
{   
    vector<int> array{10,5,2,0,7,6,4};
    int start = 0 ;
    int end = array.size() - 1;
    mergeSort(array , start , end) ;
    for(int x : array)
    {
        cout<< x << ",";
    }
    cout<<endl;
    return 0 ;
}