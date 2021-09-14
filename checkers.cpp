/******************************************************************
** Program: checkers.cpp
** Author: Blake Schafer
** Date: 06/3/2021 
** Description: two player game of checkers 
** Input: This program takes various inputs, such as size of board, where you want to move the piece, and play again
** Output: This program outputs the checkers board with the pieces, and updates with each move
*******************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;
//move diagonal right up function
//move diagonal left up function
//move diagnol right down function
//move diagnol left down function
//king space function move any diagnol direction 
//print board function, print after each move 
//declare winner function
//extra credit: A.I. player funtion
//2d arrays on the heap
/******************************************************************
** Function: init_board()
** Description: intializes the game board and puts in on the heap
** Parameters: takes in two ints of rows and columns on the game board 
** Pre-conditions: takes in user inputted size of board
** Post-conditions: intializes the board of given size
*******************************************************************/
char** init_board(int rows, int cols)
{
    char **board;
    //allocate
    board = new char*[rows];
    for(int i = 0; i < rows; i++){
        board[i] = new char[cols];
        for(int j = 0; j < cols; j++){
            board[i][j] = ' ';
        }
    }
    return board;
}
/******************************************************************
** Function: printBoard()
** Description: Prints out the game board
** Parameters: takes in the pointer variable to the initialized game board, and two ints rows and cols
** Pre-conditions: intialized game board
** Post-conditions: returns game board to the console
*******************************************************************/
void printBoard(int rows, int cols, char** board)
{

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << board[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "___________" << endl;

    //black and white
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {       
            if (i % 2 == 0 && j % 2 == 0)
                cout << "|\033[30;47m " << board[i][j] << " ";
            else if (i % 2 == 1 && j % 2 == 1)
                cout << "|\033[30;47m " << board[i][j] << " ";
            else
                cout << "|\033[0m " << board[i][j] << " ";
                cout << "\033[0m";
        }
        cout << endl;
    }
}


int main(int argc, char** argv)
{
    int cols = 3;
    int rows = atoi(argv[1]);
    char **board;
    init_board(rows, cols);
    printBoard(rows, cols, board);
/*
    if (argc > 2){
        cout << "Too many arguments! " << endl;
        return 0;
    }

    if (rows > 12){
        cout << "Too big" << endl;
        cin >> rows;
    }


 
    cout << arr[cols][rows] << endl;
    //delete
    for (int i = 0; i < rows; i++){
        delete [] arr[i];
        arr[i] = NULL;
    }
    delete [] arr;
    arr = NULL;
*/
return 0;
}