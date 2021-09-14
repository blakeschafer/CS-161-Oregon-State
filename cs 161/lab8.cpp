#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
using namespace std;

void get_words(){
    
    int n;
   
    cout << "How many words do you want to search for?: " << endl; //ask user for n words
    cin >> n;
    string *words_array = new string[n]; //make array of n words on the heap

    for(int i = 0; i < n; ++i){
        cout << "Enter " << n << " words to search for:" <<endl;
        getline(cin, words_array[i]);
    }
    cout << words_array[n] << endl;

    for(int i = 0; i < n; i++){
        cout << words_array[i] << endl;
    }
    delete [] words_array;
}

int main()
{

    char sen[1024]; //char* 0-1023
    sen[1023] = '\0';

    cout << "Enter a string: " <<endl;
    cin.getline(sen, 1023, '\n');
    if (cin.fail())
    {
        cin.ignore(256, '\n'); //get rid of everything leftover
        cin.clear(); //reset the failbit for the next cin
    }

    get_words();



    return 0;
}