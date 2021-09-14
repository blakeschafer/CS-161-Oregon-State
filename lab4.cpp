#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
using std::cout;
using std::endl;

/********************************************************************
** Function: a_to_i
** Description: turns a character into a decimal value
** Parameters: char character
** Pre-Conditions: the input is a character
** Post-Conditions: returned the decimal value of the character
********************************************************************/
int a_to_i(char input_cha)
{
    int itoa = (int)input_cha;
    cout << input_cha << " = " << itoa << "\nin computer language :P" << endl;
}

/********************************************************************
** Function: i_to_a
** Description: turns a decimal value into a character value
** Parameters: int decimal
** Pre-Conditions: the input is an integer 
** Post-Conditions: returned the character which represents the
decimal value
********************************************************************/  
char i_to_a(int input_int)
{
    char atoi = (char)input_int;
    cout << input_int << " = " << atoi << "\nit's called ascii code!" << endl;
}

int main()
{
    char input_cha;
    int input_int;

    cout << "Enter a character: " << endl;
    cin >> input_cha;
    cout << "Enter a number: " << endl;
    cin >> input_int;     

    cout << a_to_i(input_cha);
    cout << i_to_a(input_int);

    return 0;
}