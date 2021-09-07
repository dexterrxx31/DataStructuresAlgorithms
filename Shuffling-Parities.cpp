// Codechef Septempter Long  Challenge DIV 3
// Shuffling Parties
#include<iostream>
using namespace std;

int main()
{
    int num_of_test_cases ;
    cin>>num_of_test_cases;
    for (int i = 0; i < num_of_test_cases; i++)
    {   int N ; 
        cin>>N;
        int arr[N];
        for (int j = 0; j < N ; j++)
        {
            cin>>arr[j];
        }
        int even = 0 ;
        int odd = 0 ; 
        for (int k = 0; k < N; k++)
        {   
            arr[k] & 1 ? odd++ : even++; 
        }
        if (N & 1)
        {
            even > odd ? cout<< (N/2) + 1 + odd<<endl : cout<< (N/2) + even;
        }
        else{
            even >= odd ? cout<< (N/2) + odd <<endl : cout<<even+(N/2)<<endl ;
        }       
    }
    
    return 0 ; 
}