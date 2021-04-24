#include <iostream>
using namespace std;

int main()
{
    int a = 37; // binary form of 37 is 100101
        // we will try to find if bit 3 is 0 or 1
    int c = a & (1 << 3) ; 
    if (c > 0)
        cout<<"Bit is 1";
    else cout << "Bit is 0";
    return 0;
}