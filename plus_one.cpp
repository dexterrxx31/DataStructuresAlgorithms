#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> digits = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0} , ans ;
    bool carry = true;
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        if (carry)
        {
            if (digits[i] + 1 > 9)
            {
                ans.push_back(0);
                carry = true;
            }
            else
            {
                ans.push_back(digits[i] + 1);
                carry = false;
            }
        }
        else
        {
            ans.push_back(digits[i]);
        }
    }
    if (carry) ans.push_back(1);
    
    reverse(ans.begin(), ans.end());
    for (auto x : ans) cout << x << " ";
}