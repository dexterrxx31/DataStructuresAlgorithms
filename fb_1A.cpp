#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream infile("aa.txt");
    if (infile.is_open())
    {

        int num_of_test_cases;
        infile>>num_of_test_cases;
        int N;
        string str;
        int counter;
        for (int i = 0; i < num_of_test_cases; i++)
        {
            infile >> N;
            infile >> str;
            counter = 0;
            for (int j = 0; j < N; j++)
            {
                if ((str[j] == 'X' && str[j + 1] != 'X') || (str[j] == 'O' && str[j + 1] != 'O'))
                {
                    counter++;
                }
            }

            cout << "Case #" << i + 1 << ":" << counter - 1 << endl;
        }
    }
    return 0;
}