#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;

    int node;
    int i = 1;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    cout << i;
    visited[i] = 1;
    q.push(i);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 and visited[j] == 0)
            {
                cout << j;
                visited[j] = 1;
                q.push(j);
            }
        }
    }
    return 0;
}