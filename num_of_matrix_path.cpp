#include<iostream>

using namespace std ;


int num_path(int rows , int columns )
{
    if(rows ==1 || columns == 1)
    {
        return 1 ;
    }
    return num_path(rows-1 , columns) + num_path(rows , columns -1 ) ;
}
int main()
{   
    int rows = 4 ;
    int columns = 5 ;
    cout<<num_path(rows, columns);
    return 0 ;
}