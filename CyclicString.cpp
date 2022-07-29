#include <bits/stdc++.h>
using namespace std;

int cyclicString(string a, string b)
{
    int operation;
    for (int i = 0; i < a.size(); i++)
    {
        operation = abs(b[i] - a[i]);
        if (operation % 2 == 1)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    string a = "uv";
    string b = "jg";
    cout << cyclicString(a, b);
    return 0;
}