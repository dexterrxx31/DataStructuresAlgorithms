#include <iostream>
#include <string>
using namespace std;

string replace_space_with_given_string(string main_string, string string_to_be_inserted)
{
    while (int(main_string.find(" ")) != -1)
    {
        int position_of_space = main_string.find(" ");
        main_string = main_string.erase(position_of_space, 1);
        main_string.insert(position_of_space, string_to_be_inserted);
    }
    return main_string;
}

int main()
{
    string main_string = "Riyan is good Boy.";
    string string_to_be_inserted = "%90";
    cout << replace_space_with_given_string(main_string, string_to_be_inserted);
    return 0;
}