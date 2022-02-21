#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "";               // input string ;
    string pattern = "";         // pattern string
    unordered_map<char, int> mp; // map to store the frequency of each char in pattern string
    int i, j, count, min_length; // declaring variables
    i = j = 0;                   // initial value of both the window pointers
    min_length = INT_MAX;        // minimum length of window

    // Loop to create the map of frequency of each letter in pattern string
    for (int i = 0; i < s.size(); i++)
        mp[s[i]]++;

    count = mp.size(); // number of unique characters available in pattern string

    // sliding window loop
    while (j < s.length())
    {
        if (count > 0)
        {
            if (mp.find(s[j]) != mp.end())
            {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                    count--;
                j++;
            }
            else 
            {
                j++;
            }
        }
        else if (count == 0)
        {
            while(count == 0)
            {
                if(mp[s[i]] < 0)
                    mp[s[i]]++ ;
                if(mp[s[i]] == 0)
                    count++;
                i++;
            }
            min_length = min(min_length , j - i + 1);
            j++;
        }
    }
    cout<<min_length ;
    return 0;
}