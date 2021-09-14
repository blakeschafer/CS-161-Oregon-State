#include <iostream>
#include <cmath>
#include <string>
#include "helper_functions.h"
using namespace std;

/******************************************************************
** Function: check_range()
** Description: Indicates if the provided number is in the specified range
** Parameters: int lower_bound, int upper_bound, int test_value
** Pre-conditions: take three int parameters
** Post-conditions: returns a value to tell if test_value is in boundaries
*******************************************************************/
bool check_range(int lower_bound, int upper_bound, int test_value)
{
    return (lower_bound <= test_value && test_value <= upper_bound);
}

/*****************************************************************
** Function: equality_test()
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
** Function: is_int()
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
** Function: string_to_int()
** Description: Convert the given string to an integer
** Parameters: string num, int value
** Pre-conditions: takes in string
** Post-conditions: returns a integer value of the string
*******************************************************************
void string_to_int(string num, int &value)
{
    //use a_to_i ?? 
    string num;
    int value = int(num);
}
*/
/******************************************************************
** Function: swap()
** Description: Swaps num1 and num2  
** Parameters: int num1, int num2 
** Pre-conditions: takes in two integer values
** Post-conditions: returns same values just to different variables
*******************************************************************
void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
*/

/******************************************************************
** Function: word_count()
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

    //is_int()
    cout << "\nTesting is_int(\"54\")...\n";
    cout << "Expected: 1";
    cout << "\tActual: " << is_int("54");
    (is_int("54")== 1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    cout << "\nTesting is_int(\"hello\")...\n";
    cout << "Expected: 0";
    cout << "\tActual: " << is_int("hello");
    (is_int("hello")== 0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    /*string_to_int()

    swap()
    int num1 = 5, num2 = 10;
    cout << "\nswap(\"5, 10\")...\n";
    cout << "Expected: 10, 5";
    cout << "\tActual: " << swap(num1, num2);
    (num1 == 10)? cout << "\tPASSED\n" : cout << "\tFAILED\n";
    */  
    //word_count()
    cout << "\nTesting word_count(\"I have two dogs.\")...\n";
    cout << "Expected: 4";
    cout << "\tActual: " << word_count("I have two dogs.");
    (word_count("I have two dogs.")== 4)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

    return 0;
}
