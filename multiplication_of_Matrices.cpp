#include<iostream>
#include<vector>
using namespace std ;

int main()
{   int  martix1[3][3] , martix2[3][3] ; 
    int row1 , row2 , col1 , col2 , sequence;
    sequence = 0 ; 
    row1 = 3 ;
    col1 = 3 ;
    row2 = 3 ;
    col2 = 3 ;
    for(int i = 0 ; i < row1 ; i ++)
    {
        for(int j = 0 ; j < col1 ; j ++)
        {
            martix1[i][j] = sequence++;
        }
    }

    for(int i = 0 ; i < row1 ; i ++)
    {
        for(int j = 0 ; j < col1 ; j ++)
        {
            cout<<martix1[i][j]<<"|";
        }
        cout<<endl;
    }

    for(int i = 0 ; i < row2 ; i ++)
    {
        for(int j = 0 ; j < col2 ; j ++)
        {
            martix2[i][j] = sequence++;
        }
    }
//---------------------------------------------------------------//
    for(int i = 0 ; i < row2 ; i ++)
    {
        for(int j = 0 ; j < col2 ; j ++)
        {
            cout<<martix2[i][j]<<"|";
        }
        cout<<endl;
    }


    return 0 ;
}