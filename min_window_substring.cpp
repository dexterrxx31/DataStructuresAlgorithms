#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "ADOBECODEBANC";  // input string ;
    string pattern = "BANC";     // pattern string
    unordered_map<char, int> mp; // map to store the frequency of each char in pattern string
    int i, j, count, min_length; // declaring variables
    i = j = 0;                   // initial value of both the window pointers
    min_length = INT_MAX;        // minimum length of window
    int start, end;              // to output the substring
    // Loop to create the map of frequency of each letter in pattern string
    for (int i = 0; i < pattern.size(); i++)
        mp[pattern[i]]++;

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
            }
        }

        if (count == 0)
        {
            // Loop to reduce the window size to minimum.
            while (count == 0)
            {
                min_length = min(min_length, j - i + 1); // updating the minimum window size
                // Keeping start and end pointers to keep updated the output string at last.
                start = i;
                end = j;

                if (mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    if (mp[s[i]] > 0)
                        count++;
                }
                i++;
            }
        }
        j++;
    }

    cout << "Minimum length of window is : " << min_length << endl
         << "Substring : ";
    for (int i = start; i <= end; i++)
    {
        cout << s[i];
    }

    return 0;
}