#include <iostream>
#include <vector>
using namespace std;
//Interview Bit
//https://www.interviewbit.com/problems/arraybug/
vector<int> rotateArray(vector<int> &A, int B)
{
    vector<int> ret;
    if (B > A.size())
    {
        B = B % A.size();
    }
    for (int i = B; i < A.size(); i++)
    {
        ret.push_back(A[i]);
    }
    for (int j = 0; j < B; j++)
    {
        ret.push_back(A[j]);
    }
    return ret;
}

int main()
{
    vector<int> A;
    int B = 10;
    for (int i = 0; i < 6; i++)
    {
        A.push_back(i);
    }

    for (int j = 0; j < A.size(); j++)
    {
        cout << A[j] << "|";
    }
    cout << endl;
    vector<int> C = rotateArray(A, B);

    for (int j = 0; j < C.size(); j++)
    {
        cout << C[j] << "|";
    }

    return 0;
}
