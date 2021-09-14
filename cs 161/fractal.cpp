/******************************************************************
** Program: fractal.cpp
** Author: Blake Schafer
** Date: 05/22/2021 
** Description: Prints pattern of asteriks 
** Input: This program takes two user inputs, two numbers for n and amount of columns
** Output: This program outputs the recursive pattern of stars based on user input size
*******************************************************************/
#include <iostream>
using namespace std;

/*
For this algorithm I noticed that 
N got bigger by 2 every iteration,
and Col decreased by 1 every iteration
hence n - 2, col + 1
*/

/******************************************************************
** Function: pattern()
** Description: recursvieley prints pattern of asteriks and spaces
** Parameters: integer n and integer columns
** Pre-conditions: takes two int parameters, n must be bigger than 0
** Post-conditions: returns a pattern of stars
*******************************************************************/
void pattern(int n, int col) //pattern function given in lecture demo
{
    //if there are stars to be printed
    if (n > 0){
        
        //1st recurse call
        pattern(n - 2, col + 1);

        //print offset col
        for(int i = 0; i < col; i++)
        {
            cout << " ";
        }

        //print n stars
        for (int i = 0; i < n; i++)
        {
                cout << "* ";
        }
        cout << endl;

        //2nd recurse call
        pattern(n - 2, col + 1);

    }
}

int main()
{
    int n, col;

    cout << "Enter a number greater than 0 for n: " << endl;
    cin >> n;
    cout << "Enter a number for amount of columns: " << endl;
    cin >> col;

    //call function in main
    pattern(n, col);

    return 0;
}