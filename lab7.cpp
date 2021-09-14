#include <iostream>

using namespace std;

void get_string(string *str)
{
    
    cout << "Enter a string: " << endl;
    getline(cin, *str);
}




int main(){

string *str = new string;
get_string(str);
cout << str;

    return 0;
}