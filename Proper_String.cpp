#include <bits/stdc++.h>
using namespace std;

bool isProper(string &s)
{
    set<char> vowel = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 1; i < s.size(); i++)
        if (vowel.find(s[i - 1]) != vowel.end() and vowel.find(s[i]) != vowel.end() || vowel.find(s[i - 1]) == vowel.end() and vowel.find(s[i]) == vowel.end())
            return false;

    return true;
}

int main()
{
    string s  = "usekeronewusize" ;

    if(isProper(s))
        cout<<"Yes" ;
    else
        cout<<"No" ;

    return 0;
}