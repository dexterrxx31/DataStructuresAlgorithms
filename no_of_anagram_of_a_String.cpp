#include <bits/stdc++.h>
using namespace std;

int main()
{
    string arr_in = "forfoforfro"; // input String
    int n = arr_in.size();         // size of input String
    string arr_ptr = "for";        // Pattern String
    int k = arr_ptr.size();        // size of window

    unordered_map<char, int> mp;
    // frequency of each element in Pattern String
    for (int i = 0; i < k; i++)
        mp[arr_ptr[i]]++;

    // Frequency of each letter in Patter String
    unordered_map<char, int>::iterator it; // Initialting an iterator of map top display map
    for (it = mp.begin(); it != mp.end(); it++)
        cout << it->first << "->" << it->second << endl;

    int i, j;                // Begin and end Pointers
    i = j = 0;               // Initial State of Pointers
    int counter = mp.size(); // Number of distict letters in Pattern String
    int ans = 0;
    // Sliding window Loop
    while (j < n)
    {
        // Initial Calculation Step
        if (mp.find(arr_in[j]) != mp.end())
        {
            mp[arr_in[j]]--;
            if (mp[arr_in[j]] == 0)
                counter--;
        }
        // if Window size didn't hit window size
        if (j - i + 1 < k)
            j++;

        else
        {
            if (counter == 0)
                ans++;
            if (mp.find(arr_in[i]) != mp.end())
            {
                mp[arr_in[i]]++;
                if (mp[arr_in[i]] == 1)
                    counter++;
            }
            i++;
            j++;
        }
    }
    cout << ans;
    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

int fxn(string str, string ptt, int n, int k)
{
    unordered_map<char, int> mp;

    for (int i = 0; i < k; i++)
    {
        mp[ptt[i]]++;
    }
    unordered_map<char, int>::iterator it;

    for (it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << "->" << it->second << endl;
    }

    int i = 0, j = 0;
    int counter = mp.size();
    int answer = 0;

    while (j < n)
    {
        // initial calculation step
        if (mp.find(str[j]) != mp.end())
        {
            mp[str[j]]--;
            if (mp[str[j]] == 0)
                counter--;
        }

        if (j - i + 1 < k)
        {
            j++;
        }

        else
        {
            if(counter == 0 )
                answer++;
            if(mp.find(str[j]) != mp.end())
            {
                mp[str[i]]++;
                if(mp[str[i]] == 1)
                    counter++;
            }
            i++;
            j++;
        }
    }
    return answer ;
}

int main()
{
    string arr_in = "forfoforfro"; // input String
    int n = arr_in.size();         // size of input String
    string arr_ptr = "for";        // Pattern String
    int k = arr_ptr.size();        // size of window
    cout<<fxn(arr_in , arr_ptr , n , k );
    return 0;
}
*/