/******************************************************************
** Program: textsurgeon.cpp
** Author: Blake Schafer
** Date: 05/22/2021 
** Description: Performing differnt operations on a string of text 
** Input: This program takes various inputs, one original string or text, then what the user wants to do with that text, then for each function takes in various inputs
** Output: This program has various outputs depending on what the user wants to do with the string of text
*******************************************************************/
#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
using namespace std;

/******************************************************************
** Function: letter_swap()
** Description: Takes in two chars and switches the user inputted string with replacing the first char with the second char in the string
** Parameters: takes in char input of length of user input
** Pre-conditions: takes in user inputted string
** Post-conditions: returns the user string with two user inputted characters swapped
*******************************************************************/
void letter_swap(char *sen)
{
    char a, b; //intialize two characters

    cout << "Enter a character you want to replace: " << endl; //input for first char
    cin >> a;

    cout << "Enter a character you want to replace it with: " << endl; //input for second char
    cin >> b;
    
    for(int i = 0; i < strlen(sen); i++){ //iterate through the length of the string
        if(sen[i] == a){ //if input at index i is equal to first character
            sen[i] = b; //then replace it with the second character
        }
    }
    cout << "Letter Swapped String: " << sen << endl; //cout swapped sentence 

}

/******************************************************************
** Function: reverse()
** Description: returns the user inputted string but reversed
** Parameters: takes in char input of length of user input
** Pre-conditions: takes in user inputted string
** Post-conditions: returns the user string but in reversed and saved to a c-style string allocated on the heap
*******************************************************************/
void reverse(char *sen)
{
    char *reverse_string = new char[strlen(sen) + 1]; //create a copy of string input and put it on the heap
    int j = 0;
    for (int i = strlen(sen) - 1; i >= 0; i--){ //iterate throught the length of the input
        reverse_string[j] = sen[i]; //position of reversed string at j equals position of input i
        j++; //increase the index of j, while in the for loop the position of i decreases
    }
    cout << "Reversed string: " << reverse_string << endl; //cout reversed string
    delete [] reverse_string; //clear the memory for reverse_string off the heap
}

/******************************************************************
** Function: word_count()
** Description: Returns number of times string is found in sentence
** Parameters: orignal sentence and strin search
** Pre-conditions: takes in user inputted string and another string called search
** Post-conditions: returns the count of the word to look for
*******************************************************************/
int word_count(char *sen, string search)
{
    int count = 0;
    int win = 0;
    //window search alogirthm
    for(int j = 0; j < strlen(sen); j++){
        if(win == search.length()){
            count += 1;
            win = 0;
        }
        if(sen[j] == search[win]){
            win++;
        }
    }
    return count;
}

/******************************************************************
** Function: word_frequency()
** Description: Indicates the amount of times a word appears in the string of text
** Parameters: takes in char input of length of user input
** Pre-conditions: takes in user inputted string
** Post-conditions: returns the user inputted words they want to search for and the amount of times they appear in the string
*******************************************************************/
void word_frequency(char *sen)
{
    
    int n;
   
    cout << "How many words do you want to search for?: " << endl; //ask user for n words
    cin >> n;
    string *words_array = new string[n]; //make array of n words on the heap

    for(int i = 0; i < n; i++){
        cin.ignore();
        cout << "Enter " << n << " words to search for: ";
        cin >> words_array[i];
    }
    
    for(int i = 0; i < n; i++){
        cout << words_array[i] << ":" << word_count(sen, words_array[i]) << endl; //call word_count function eith original string and words_array for parameters which will return word count
    }

    delete [] words_array; //deallocate memory
}
//

int main()
{
    int again;
    int operation = 0;
    char sen[1024]; //char* 0-1023
    sen[1023] = '\0';

    cout << "Enter a string: " <<endl;
    cin.getline(sen, 1023, '\n');
    if (cin.fail())
    {
        cin.ignore(256, '\n'); //get rid of everything leftover
        cin.clear(); //reset the failbit for the next cin
    }

    do{
        cout << "What operation would you like to perform on your string?\n 1 for letter swap \n 2 for reversing the string\n 3 for word frequency" << endl;
        cin >> operation;

        if (operation == 1){
            letter_swap(sen);
        }

        else if (operation == 2){
            reverse(sen);
        }

        else if(operation == 3){
            word_frequency(sen);
        }
 
        cout << "Perform another operation?(yes=1, no=0)" << endl;
        cin >> again;
    }while(again == 1);

    if (again == 0){
        cout <<"Thanks for playing!:)" << endl;
    }

    return 0;
}