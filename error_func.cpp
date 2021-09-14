/******************************************************************
** Program: error_func.cpp
** Author: Blake Schafer
** Date: 05/05/2021 
** Description: Error Handling and Helper Function Library 
** Input: This program does not take in any input, all of them are hard-coded
** Output: This program has various outputs ranging from bool, int and strings.
*******************************************************************/
#include <iostream>
#include <cmath>
#include <string>
#include "helper_functions.h"
using namespace std;
using std::cout;
using std::endl;


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

    //string_to_int()

    /*swap()
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