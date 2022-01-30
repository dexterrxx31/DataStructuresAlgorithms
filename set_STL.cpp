#include<iostream>
#include<set>

using namespace std ;

//Balanced BST
//Sorted element
//Random access not possible
//Multiset allows dublication of elements
//multiset<int> s ;
//On using s.erase(any element that occurs multitimes)
//will result in erasing all occurance of that element
//for deletion of first occurance of any element 
//s.erase(s.find(3));
// - Insertion : O(log(n))
// - Deletion : O(log(n))
// - Lower / Upper_bound : O(log(n))
// - Printing : O(nlogn)

//Unordered Set 
//Implemented using Hashing
//Not in sorted order
//#include<unordered_set>
// - Insertion : O(1) in avg case , O(n) in worst case
// - Deletion : O(1) in avg case , O(n) in worst case

int main()
{
    set<int> s ;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);

    //printing the elements in the set

    //using foreach loop
    for(auto i : s)
        cout << i <<" ";
    cout << "\n";
    for (auto i = s.begin(); i!= s.end(); i++)
    {
        cout<< *i << " " ;
    }
    cout << "\n";
    //print in reverse 
    for(auto i = s.rbegin() ; i != s.rend() ; i++)
    {
        cout << *i <<" ";
    }
    cout << "\n";

    //size of set 
    cout << s.size();
    cout << "\n";
    //Deleting all elements of set ;
    s.clear();

    s.insert(1);
    s.insert(3);
    s.insert(5);

    cout << *s.lower_bound(2) << "\n";
    cout << *s.lower_bound(3) << "\n";
    cout << *s.upper_bound(3) << "\n";
    cout << *s.upper_bound(5) << "\n";

    //declaring set in decending order 
    set<int , greater<int>> ss;
    ss.insert(1);
    ss.insert(2);
    ss.insert(2);
    ss.insert(3);

    for(auto i : ss)
    {
        cout << i << " " ; 
    }
    cout << "\n";

    s.clear();

}