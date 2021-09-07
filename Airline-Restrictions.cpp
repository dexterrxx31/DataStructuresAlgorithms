// Codechef Septempter Long  Challenge DIV 3
// Airline Restrictions
#include<iostream>
using namespace std;

int main()
{
    int num_of_test_cases ;
    cin>>num_of_test_cases;
    int arr[5];
    for (int i = 0; i < num_of_test_cases; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin>>arr[j];
        }
        int A , B , C , D , E ;
        A = arr[0];
        B = arr[1];
        C = arr[2];
        D = arr[3];
        E = arr[4];
        (A + B <= D && C <=E) || (A + C <=D && B <= E) || (B + C <= D && A <= E) ? cout<<"yes" : cout<<"no" ;
    }

    return 0 ; 
}