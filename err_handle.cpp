#include <iostream>

using namespace std;


bool is_positive_int()
{

}


int main()
{
/*
    int i;
    do{
        
        if(cin.fail() == 1){
            cin.clear(); //reset failbit to zero
            cin.ignore(256, '\n'); //ingore 256 char or until newline
        }

        cout << "Enter i: ";
        cin >> i;

        cout << cin.fail() << endl;    

    }while(cin.fail() == 1);

    cout << i << endl;
*/
    string str; //declare a string
    bool bad; //create a flag to indicate good or bad data
    do {
        cout << "Enter string: ";
        getline(cin, str);

        bad = false;

        for(int i = 0; i < str.length(); i++)
        {
            if (!(str[i] >= '0' && str[i] <= '9'))
            {
                bad = true;
                break; //break out of for loop when we see a bad character
            }
        }  

    }while(bad == true);

    cout << str << endl;

    return 0;
}