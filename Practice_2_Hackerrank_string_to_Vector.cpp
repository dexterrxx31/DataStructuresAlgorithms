#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts_without_stringstream_class(string str)
{
    // Complete this function
    vector<int> ret;
    int element = 0 ;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ',')
        {   
            element = element * 10  + int(str[i] - '0') ;
        }
        else{
          
            ret.push_back(element);
            element = 0 ;
            
        }
          
    }
    ret.push_back(element);
    return ret;
}

vector<int> parseInts_with_stringstream_class(string str)
{
    // Complete this function
    vector<int> ret;
    stringstream ss (str);
    char ch ;
    int temp ;
    int no_of_commas = 0;
    for(int i = 0 ; i < str.size() ; i++)
    {
        if(str[i] == ',')
        {
            no_of_commas++;
        }
    }
    for(int j = 0 ; j <= no_of_commas ; j++)
    {
        ss>>temp>>ch;
        ret.push_back(temp);
    }

    return ret;
}

int main()
{
    string str;
    cin >> str;
    vector<int> integers = parseInts_with_stringstream_class(str);
    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << "\n";
    }

    return 0;
}