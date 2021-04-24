#include <iostream>
using namespace std ;
int func(int *arr)
{   arr[2] = 0 ;
    return 0 ;
}
int disp(int *arr){
    for(int i =0 ;i<=sizeof(arr)+1;i++){
        cout<<arr[i]<<"*";
    }
}
int main()
{
    int arr [] = {1,2,3,4,45,67};
    func(arr);
    disp(arr);
    return 0;
}
