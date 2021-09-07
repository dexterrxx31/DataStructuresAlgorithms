// Codechef Septempter Long  Challenge DIV 3
// Travel Pass
#include<iostream>
using namespace std;

int main()
{
    int num_of_test_cases ;
    cin>>num_of_test_cases;
    int arr[3];
    for (int i = 0; i < num_of_test_cases; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>arr[j];
        }
        char st[arr[0]];
        for (int k = 0 ; k < arr[0] ; k++)
        {
            cin>>st[k];
        }
        int inter_district = 0 ;
        int inter_state = 0 ;
        for (int l = 0; l < arr[0]; l++)
        {
            st[l] == '0' ? inter_district++:inter_state++;
        }
        cout<<inter_state*arr[2] + inter_district*arr[1] <<endl;
    }

    return 0 ; 
}