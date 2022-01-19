#include<iostream>
#include<string>
using namespace std;

void power_set (string st , int index , string current)
{
    if(index == st.length())
    {
        cout<<current<<"||";
        return ;
    }
    power_set(st, index + 1 , current + st[index]);
    power_set(st, index + 1 , current );
}

int main()
{   
    string st = "Monday";
    int index = 0 ;
    string current = "";
    power_set(st, index , current);
    return 0 ;
}