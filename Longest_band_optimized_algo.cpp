#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longest_band(vector<int> arr)
{   
    unordered_set<int> s;

    for (int x : arr)
    {
        s.insert(x);
    }

    int largest_length = 1 ;

    for (auto element : s)
    {
        int parent = element - 1;

        if (s.find(parent) == s.end())
        {
            int next_number = element + 1;
            int counter = 1 ;

            while (s.find(next_number) != s.end())
            {
                next_number++;
                counter++;
            }

            if (counter > largest_length)
            {
                largest_length = counter;
            }
        }
    }

    return largest_length;
}
int main()
{
    vector<int> arr = {1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    cout << longest_band(arr);
    return 0;
}