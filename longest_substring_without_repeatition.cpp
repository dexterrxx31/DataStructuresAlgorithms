#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input_string = "aabacbebebe"; // input string
    int n = input_string.size();         // size of string (given)
    int unique_char = 3;                 // unique characters required in window
    unordered_map<char, int> mp;         // map data structure to keep track of unique characters
    int max_window_size = INT_MIN;       // max window varible to keep track of longest window size
    int i, j;                            // pointers to mark end and start of window
    i = j = 0;                           // intital value of pointers

    // Sliding window Loop
    while (j < n)
    {
        mp[input_string[j]]++; // increase the frequency of each element

        if (mp[input_string[j]] <= 1)
        {
            max_window_size = max(max_window_size, j - i + 1); // compare between the length previous and present
            j++;
        }
        else if (mp[input_string[j]] > 1)
        {
            while (mp[input_string[j]] > 1)
            {
                mp[input_string[i]]--;
                if (mp[input_string[i]] == 0)
                    mp.erase(input_string[i]);
                i++;
                if (mp[input_string[j]] <= 1)
                    max_window_size = max(max_window_size, j - i + 1);
            }
            j++;
        }
    }

    cout << max_window_size;
    return 0;
}