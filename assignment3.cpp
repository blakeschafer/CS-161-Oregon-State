/******************************************************************
** Program: assignment2.cpp
** Author: Blake Schafer
** Date: 02/07/2021 
** Description: Error Handling and Helper Function Library 
** Input: This program only takes a few user inputs, only from the get_int function.
** Output: This program has various outputs ranging from bool, int and strings.
*******************************************************************/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
using std::cout;
using std::endl;
 
/******************************************************************
* ** Function: check_range()
** Description: Indicates if the provided number is in the specified range
** Parameters: int lower_bound, int upper_bound, int test_value
** Pre-conditions: take three int parameters
** Post-conditions: returns a value to tell if test_value is in boundaries
*******************************************************************/
bool check_range(int lower_bound, int upper_bound, int test_value)
{
    return (lower_bound <= test_value && test_value <= upper_bound);
}

/******************************************************************
* ** Function: is_capital()
** Description: Indicates if the provided letter is a capital or not
** Parameters: char letter
** Pre-conditions: takes a character letter as a parameter
** Post-conditions: returns true if its a capital letter else false
*******************************************************************/
bool is_capital(char letter) 
{ 
    if (letter >= 'A' && letter <= 'Z') 
        return 1;
    else
        return 0;               
}

/******************************************************************
* ** Function: is_even()
** Description: Indicates if the provided number is even or not
** Parameters: int num
** Pre-conditions: take in a integer 
** Post-conditions: return true if the number is even else false
*******************************************************************/
bool is_even(int num)
{
    num = num %2;
    if (num == 0)
        return 1;
    else
        return 0;
}

/******************************************************************
* ** Function: is_odd()
** Description: Indicates if the provided number is odd
** Parameters: int num
** Pre-conditions: take in integer number
** Post-conditions: return true if number is odd else false
*******************************************************************/
bool is_odd(int num)
{
    num = num %2;
    if (num == 1)
        return 1;
    else
        return 0;
}

/******************************************************************
* ** Function: equality_test()
** Description: tests two values agaisnt eachother
** Parameters: int num1, int num2
** Pre-conditions: take in two integer values
** Post-conditions: returns a value based on whether the values are equal or gretaer than/ less than eachother
*******************************************************************/
int equality_test(int num1, int num2)
{
    if (num1 < num2)
        return -1;
    else if (num1 == num2)
        return 0;
    else if (num1 > num2)
        return 1;
}

/******************************************************************
* ** Function: float_is_equal()
** Description: tests two values agaisnt eachother to se if they are within a sepcified range
** Parameters: float num1, float num2, float precision
** Pre-conditions: takes in three float parameters
** Post-conditions: returns true of the values are within the range, false if they are not in the specified range
*******************************************************************/
bool float_is_equal(float num1, float num2, float precision)
{
    if (abs (num1 - num2) <= precision)
        return 1;
    else
        return 0;
}

/******************************************************************
* ** Function: is_int()
** Description: Indicates if a given string is an integer
** Parameters: string num
** Pre-conditions: takes in a string as a parameter
** Post-conditions: returns true if the string is an integer, else false
*******************************************************************/
bool is_int(string num)
{
    for (int i = 0; i < num.length(); i++)
        if ((num.at(i) >= '0' && num.at(i) <= '9'))
            return 1;
        else if(num.at(0) == '-')
            return 1;
    return 0;
}

/******************************************************************
* ** Function: numbers_present()
** Description: Indicates if the provided string contains numbers or not
** Parameters: string sentencce
** Pre-conditions: take a string as a parameter
** Post-conditions: returns true if the string contains numbers, else false
*******************************************************************/
bool numbers_present(string sentence)
{
    for (int i = 0; i < sentence.length(); i++){
        if(sentence.at(i) >= '0' && sentence.at(i) <= '9') 
            return 1;
    }
    return 0;
}

/******************************************************************
* ** Function: letters_presents()
** Description: Indicates if the provided string contains letters or not
** Parameters: string sentence
** Pre-conditions: takes a string as a parameter 
** Post-conditions: return true if the string contains letters else false
*******************************************************************/
bool letters_present(string sentence)
{
    for (int i = 0; i < sentence.length(); i++)
        if (sentence.at(i) >= 'a' && sentence.at(i) <= 'z' || sentence.at(i) >= 'A' && sentence.at(i) <= 'Z')
            return 1;
    return 0;
}

/******************************************************************
* ** Function: 
** Parameters: string sentence, string sub_string
** Pre-conditions: takes in two strings, the sentecne action: contains_sub_string()
** Description: Indicates if substring exists in sentencend sub_string 
** Post-conditions: return a true if the sub_string exists in the provided sentence, else false
*******************************************************************/
bool contains_sub_string(string sentence, string sub_string)
{
for (int i = 0; i < sentence.length(); i++)
    for(int e = 0; e < sub_string.length(); e++)
        if (sentence[i] == sub_string[e])
            return 1;
return 0;
}


/******************************************************************
* ** Function: word_count()
** Description: Returns the number of words in a provided sentence 
** Parameters: string sentence 
** Pre-conditions: takes in a string as a parameter
** Post-conditions: returns a integer of amount of words in the string
*******************************************************************/
int word_count(string sentence)
{
int i, count = 1;
    for(i = 0; sentence[i] != '\0'; ++i){
        if(sentence[i] ==' ' || sentence[i] == '\n' || sentence[i] == '\0')
            count++;
    }
return count;
}

/******************************************************************
* ** Function: to_upper()
** Description: Turns all the letters in the string to uppercase letters, excludes non letters
** Parameters: string sentence
** Pre-conditions: takes in a string
** Post-conditions: prints out the string in all capital letters
*******************************************************************/
string to_upper(string sentence)
{
for(int i = 0; i < sentence.length(); i++){
        if (sentence[i] >= 'a' && sentence[i] <= 'z'){
            sentence[i] = sentence[i] - 'a'+'A';
        }
    }
return sentence;
}

/******************************************************************
* ** Function: to_lower()
** Description: Turns all the letters in the string to lowercase letters, excludes non letter values
** Parameters: string sentence
** Pre-conditions: takes in a string
** Post-conditions: prints out the string in all lower case letters
*******************************************************************/
string to_lower(string sentence)
{
for(int i = 0; i < sentence.length(); i++){
        if (sentence[i] >= 'A' && sentence[i] <= 'Z'){
            sentence[i] = sentence[i] - 'A'+'a';
        }
    }
return sentence;
}

/******************************************************************
* ** Function: get_int()
** Description: Takes a prompt from the user as a string literal, checks if input is a valid integer, returns the provided integer
** Parameters: string prompt
** Pre-conditions: takes in a prompt from the user
** Post-conditions: returns provided integer from the user if there is one in the prompt
*******************************************************************/
int get_int(string prompt)
{
    int x = 0;
    bool cont = true;
    while(cont == true){
        cont = is_int(prompt);
            for(int i = 0; i < prompt.length(); i++)
                x = (x * 10) + (prompt[i] - 48);
                return x;
    }

}

int main()
{
    //check_range()
    cout << "\nTesting check_range(\"10, 100, 30\")...\n";
    cout << "Expected: 1";
    cout << "\tActual: " << check_range(10, 100, 30);
    (check_range(10, 100, 30)==1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";
    
    cout << "\nTesting check_range(\"10, 100, 5\")...\n";
    cout << "Expected: 0";
    cout << "\tActual: " << check_range(10, 100, 5);
    (check_range(10, 100, 5)==0)? cout << "\tPASSED\n" : cout << "\tFAILED\n"; 

    //is_capital()
    cout << "\nTesting is_capital(\"L\")...\n";
    cout << "Expected: 1";
    cout << "\tActual: " << is_capital('L');
    (is_capital('L')==1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    cout << "\nTesting is_capital(\"l\")...\n";
    cout << "Expected: 0";
    cout << "\tActual: " << is_capital('l');
    (is_capital('l')== 0)? cout << "\tPASSED\n" : cout << "\tFAILED\n"; 

    //is_even()
    cout << "\nTesting is_even(\"2\")...\n";
    cout << "Expected: 1";
    cout << "\tActual: " << is_even(2);
    (is_even(2)==1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    cout << "\nTesting is_even(\"3\")...\n";
    cout << "Expected: 0";
    cout << "\tActual: " << is_even(3);
    (is_even(3)==0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    //is_odd()
    cout << "\nTesting is_odd(\"5\")...\n";
    cout << "Expected: 1";
    cout << "\tActual: " << is_odd(5);
    (is_odd(5)==1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    cout << "\nTesting is_odd(\"4\")...\n";
    cout << "Expected: 0";
    cout << "\tActual: " << is_odd(4);
    (is_odd(4)==0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    //equality_test()
    cout << "\nTesting equality_test(\"15, 20\")...\n";
    cout << "Expected: -1";
    cout << "\tActual: " << equality_test(15, 20);
    (equality_test(15, 20)==-1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    cout << "\nTesting equality_test(\"15, 15\")...\n";
    cout << "Expected: 0";
    cout << "\tActual: " << equality_test(15, 15);
    (equality_test(15, 15)== 0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    cout << "\nTesting equality_test(\"15, 10\")...\n";
    cout << "Expected: 1";
    cout << "\tActual: " << equality_test(15, 10);
    (equality_test(15, 10)== 1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    //float_is_equal()
    cout << "\nTesting float_is_equal(\"2, 1.5, 0.5\")...\n";
    cout << "Expected: 1";
    cout << "\tActual: " << float_is_equal(2, 1.5, 0.5);
    (float_is_equal(2, 1.5, 0.5)== 1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    cout << "\nTesting float_is_equal(\"2, 1.5, 0.2\")...\n";
    cout << "Expected: 0";
    cout << "\tActual: " << float_is_equal(2, 1.5, 0.2);
    (float_is_equal(2, 1.5, 0.2)== 0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    //is_int()
    cout << "\nTesting is_int(\"54\")...\n";
    cout << "Expected: 1";
    cout << "\tActual: " << is_int("54");
    (is_int("54")== 1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    cout << "\nTesting is_int(\"hello\")...\n";
    cout << "Expected: 0";
    cout << "\tActual: " << is_int("hello");
    (is_int("hello")== 0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    //numbers_present()
    cout << "\nTesting numbers_present(\"I have 2 dogs.\")...\n";
    cout << "Expected: 1";
    cout << "\tActual: " << numbers_present("I have 2 dogs.");
    (numbers_present("I have 2 dogs.")== 1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    cout << "\nTesting numbers_present(\"I have two dogs.\")...\n";
    cout << "Expected: 0";
    cout << "\tActual: " << numbers_present("I have two dogs.");
    (numbers_present("I have two dogs.")== 0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    //letters_present()
    cout << "\nTesting letters_present(\"I have two dogs.\")...\n";
    cout << "Expected: 1";
    cout << "\tActual: " << letters_present("I have two dogs.");
    (letters_present("I have two dogs.")== 1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    cout << "\nTesting letters_present(\"90/.345\")...\n";
    cout << "Expected: 0";
    cout << "\tActual: " << letters_present("90/.345");
    (letters_present("90/.345")== 0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    //contains_sub_string()
    cout << "\ncontains_sub_string(\"Hello World\", \"World\")...\n";
    cout << "Expected: 1";
    cout << "\tActual: " << contains_sub_string("Hello World", "World");
    (contains_sub_string("Hello World", "World")== 1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    cout << "\ncontains_sub_string(\"Hello World\", \"abc\")...\n";
    cout << "Expected: 0";
    cout << "\tActual: " << contains_sub_string("Hello World", "abc");
    (contains_sub_string("Hello World", "abc")== 0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";
    
    //word_count()
    cout << "\nTesting word_count(\"I have two dogs.\")...\n";
    cout << "Expected: 4";
    cout << "\tActual: " << word_count("I have two dogs.");
    (word_count("I have two dogs.")== 4)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    //to_upper()
    cout << "\nTesting to_upper(\"I have two dogs.\")...\n";
    cout << "Expected: I HAVE TWO DOGS.";
    cout << "\tActual: " << to_upper("I have two dogs.");
    (to_upper("I have two dogs.")== "I HAVE TWO DOGS.")? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    //to_lower()
    cout << "\nTesting to_lower(\"I HAVE TWO DOGS.\")...\n";
    cout << "Expected: i have two dogs.";
    cout << "\tActual: " << to_lower("I HAVE TWO DOGS.");
    (to_lower("I HAVE TWO DOGS.")== "i have two dogs.")? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    //get_int()
    string input;
    cout << "\nEnter an integer as string literal: " <<endl;
    cin >> input;
    cout << "Expected: " << input;
    cout << "\tActual: " << get_int(input) << endl;

    return 0;
}
