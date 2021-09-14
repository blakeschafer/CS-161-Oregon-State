#include <iostream>
#include <string>
using namespace std;
/******************************************************************
** Program: string get_sentence
** Pre-conditions: call the function in a main function
** Post-conditions: have a variable where a value is to be catched when it is returned from a get_sentnece() method
*******************************************************************/
string get_sentence()
{
    string sent;
    cout << "Enter a sentence: " << endl;
    getline(cin, sent);
    return sent;
}
/******************************************************************
** Program: void get_sentence
** Pre-conditions: we have to declare a string variable and it is to be passed to the formal argument as an address
** Post-conditions: N/A because there is no task to do after completion
*******************************************************************/
void get_sentence(string &s) //when you do not have the amperand there, it does not cout the sentence, ampersand points to the address of the variable
{
    cout << "Enter another sentence: " << endl;
    getline(cin, s);
}

void swap_sentence(string sen1, string sen2)
{
    sen1.swap(sen2);
    cout << "In swap function ..."<< endl;
    cout << "sen1: " << sen1 << endl;
    cout << "sen2: " << sen2 << endl;
}

int main() 
{ 
    string sen1, sen2, sentence, sentence2;
    /* 
    cout << "Enter sentence 1: "; 
    getline (cin, sen1); 
    cout << "Enter sentence 2: "; 
    getline (cin, sen2); 
    swap_sentence(sen1, sen2); 
    cout << "In main function ..." << endl; 
    cout << "sentence 1: " << sen1 << endl; 
    cout << "sentence 2: " << sen2 << endl;
    */
    sentence = get_sentence();
    cout << sentence << endl;

    get_sentence(sentence2);
    cout << sentence2 << endl;
    return 0;
}