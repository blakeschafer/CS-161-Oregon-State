/******************************************************************
** Program: assignment4.cpp
** Author: Blake Schafer
** Date: 03/14/2021 
** Description: Connect 4
** Input: Asks user for size of the board, and where they want to place their game piece
** Output: Displays the Connect 4 board and updates when a user places their board piece, displays who won and if you want to play again
*******************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;

// declare the functions

// to validate the user input
bool validateUserInput(string userInput);

// to get player input
int getPlayerInput(int columns);

// to get the computer input
int getComputerInput(int columns);

// to get the moves of the players'
int get_the_move(int rows, int columns, int playerTurn, int numPlayers);

// to start the game
void start_the_game(int rows, int columns, int pointsToMatch,
   int numPlayers, int player_turn, char** gameBoard);

// to validate the inputs passed at command line
bool read_validate_args(int argc);

// to initialize the board
char** initialize_board(int rows, int columns);

// to display the game board
void display_Game_Board(int rows, int columns, char** gameBoard);

// to inser the player's piece
bool insert_Player_Piece(int rows, int columns, int specific_column,
   char pieceToInsert, char** gameBoard);

// to check the winner
int checkForPlayersWin(int rows, int columns, int pointsToMatch, char** gameBoard);

// main() function
int main(int argc, char* argv[])
{
   // declare the required variables
   int rows, columns, pointsToMatch, numPlayers;
   pointsToMatch = 4;
   int player_turn = 0;
   char **gameBoard;
   char toContinue = 'n';
   char playerVsCompChoice;
   srand(time(0));

   // read_validate_args() function call
   // to check for the validation of the argc
   if (read_validate_args(argc))
   {
       // set the first argument value as numPlayers
       numPlayers = atoi(argv[1]);

       // set the second argument value as rows(number of rows)
       rows = atoi(argv[2]);

       // check whether the rows are not beyond 20 if so,
       // display the error message and prompt the user
       // for row
       while (rows > 20)
       {
           cout << "The size of the board must be positive and <= 20. \n";
           cout << "Enter the row size of the board(height): ";
           cin >> rows;
       }

       // set the third argument value as columns(number of columns)
       columns = atoi(argv[3]);

       // check whether the rows are not beyond 20 if so,
       // display the error message and prompt the user
       // for row
       while (columns > 20)
       {
           cout << "The size of the board must be positive and <= 20. \n";
           cout << "Enter the column size of the board(width): ";
           cin >> columns;
       }
   }

   // if the given arguments are incorrect, then prompt the user
   // for valid inputs
   else
   {
       cout << "Enter number of players(1 or 2): ";
       cin >> numPlayers;
       do
       {
           cout << "Enter the row size of the board(height): ";
           cin >> rows;
       } while (rows > 20);
       do
       {
           cout << "Enter the column size of the board(width): ";
           cin >> columns;
       } while (columns > 20);
   }
   // now play the game until, the user wants to quit
   do
   {
       // call the initialize_board()
       gameBoard = initialize_board(rows, columns);      
      
       // if numPlayers is 1, then prompt the user whether the
       // user wants to go first or not
       if (numPlayers == 1)      
       {
           cout << "\n\n\t\t Player Vs Computer" << endl <<endl;
          
           cout << "\nWould the player like to take the first turn? "<<endl;
           cout << "Press (Y or y) or press any key to make computer move first: ";
           cin >> playerVsCompChoice;

           // if user wants to play first then set the player_turn value
           // to 0
           if (playerVsCompChoice == 'Y' || playerVsCompChoice == 'y')
           {
               player_turn = 0;
           }
           // otherwise, set to 1
           else
           {
               player_turn = 1;
           }
       }
       else
       {
           cout << "\n\n\t\t Player Vs Player" << endl << endl;          
       }
      
       // call the function start_the_game()
       start_the_game(rows, columns, pointsToMatch, numPlayers, player_turn, gameBoard);

       // when the game finihes, prompt the user whether they want
       // to play another game
       cout << "Would like to play another game?\n";
       cout << "Press (Y or y) to continue or Press any key to quit: ";
       cin >> toContinue;
       player_turn ^= 1;
   } while (toContinue == 'y' || toContinue == 'Y');
  
   cout << "Thanks for playing..." << endl;
   system("pause");

   //Return
   return 0;
}


// read_validate_args() to validate the
// command line arguments
bool read_validate_args(int argc)
{
   // If argc is less than 4 then
   // display the appropriate message to
   // the user and return
   if (argc < 4)
   {
       //Display message
       cout << "You have entered insufficient arguments\n";
       return false;
   }

   // If argc is greater than 4 then
   // display the appropriate message to
   // the user
   if (argc > 4)
   {
       //Display message
       cout << "You have entered too many arguments\n";
       return false;
   }

   //If count is 4
   if (argc == 4)
   {
       //Return
       return true;
   }
}

// initialize_board() function to set up the board and
// initialize the board with
char** initialize_board(int rows, int columns)
{
   // declare the variable to hold the
   // gameBoard of type char array
   char **gameBoard;

   // allocate memory
   gameBoard = (char**)malloc(rows * sizeof(char *));

   // allocate the each row wise memory
   for (int i = 0; i < rows; ++i)
   {
       gameBoard[i] = (char*)malloc(columns * sizeof(char));
   }

   // loop through each row
   for (int i = 0; i < rows; ++i)
   {
       // loop through each column
       for (int j = 0; j < columns; ++j)
       {
           // set the empty character
           gameBoard[i][j] = ' ';
       }
   }

   // return the initialized game board
   return gameBoard;
}

// display_Game_Board() function, to display the initialized
// and updated game board
void display_Game_Board(int rows, int columns, char** gameBoard)
{
   // declare the iterative variables
   int i, j;
   cout << endl;

   // loop to display the column numbers
   // on the top of each column
   for (i = 0; i < columns; ++i)
   {
       cout << setw(3) << (i + 1) << " ";
   }

   cout << "\n";

   // loop to display the board
   // loop through each row
   for (i = 0; i < rows; ++i)
   {
       // loop through each column
       for (j = 0; j < columns; ++j)
       {
           // check for the row and the column
           // number if they are even display as white
           if (i % 2 == 0 && j % 2 == 0)
           {
               cout << "|\033[30;47m " << gameBoard[i][j]
                   << " " << "\033[30;0m";
           }

           // if the row and the column is odd, display
           // as white
           else if (i % 2 == 1 && j % 2 == 1)
           {
               cout << "|\033[30;47m " << gameBoard[i][j]
                   << " " << "\033[30;0m";
           }

           // othwer wise display as black
           else
               cout << "|\033[30;0m " << gameBoard[i][j] << " ";
       }

       // display new line
       cout << "\n";
   }
}

// validateUserInput() function to validate the user input
bool validateUserInput(string userInput)
{
   if (isdigit(userInput[0]))
       return true;
   return false;
}

// getPlayerInput() function to get the
// move of the player
int getPlayerInput(int columns)
{
   // declare the variable to hold user input
   int userInput;
   string userValue;

   // prompt for the column number and read the column number
   cout << "Enter a column between 1 and " << columns << " to play in: ";
   cin >> userValue;

   // loop to check the input validation
   while (!validateUserInput(userValue) || (stoi(userValue) < 1) || (stoi(userValue) > columns))
   {
       // re-prompt the user for the input
       cout << "Enter a column between 1 and " << columns << " to play in: ";
       cin >> userValue;      
   }
   userInput = stoi(userValue);

   // return the input
   return userInput;
}

// getComputerInput() function, to get the random number
// to place the computer's move
int getComputerInput(int columns)
{
   int randomValue;
   randomValue = (int)((rand() % (columns)) + 1);
   return randomValue;
}

// get_the_move() function to get either player1's or player2's or
// computer move and return the value
int get_the_move(int rows, int columns, int playerTurn, int numPlayers)
{
   cout << endl;

   // if the number of players are 2
   if (numPlayers == 2)
   {
       // if the playerTurn == 0
       if (playerTurn == 0)
       {
           // display player turns name
           cout << "Player 1's turn: " << endl;
       }
       // if the playerTurn == 1
       else
       {
           // display player turns name
           cout << "Player 2's turn: " << endl;
       }

       // return the value returned by the getPlayerInput()
       // function (column number)
       return getPlayerInput(columns) - 1;
   }

   // otherwise player for the computer or player
   // depending on the playerTurn
   else
   {
       // if playerTurn is zero, then
       // it is players turn, call the
       // getPlayerInput() function and return
       // the value
       if (playerTurn == 0)
       {
           cout << "Player's turn: " << endl;
           return getPlayerInput(columns) - 1;
       }
       // otherwise, it is computers' turn, call the
       // getComputerInput() function and return
       // the value
       else
       {
           cout << "Computer's turn: " << endl;
           return getComputerInput(columns) - 1;
       }
   }
}

// start_the_game() function, it is used to start the game
// which contains players input, update the board and display and
// check for the game winner and display, and return from the
// file.
void start_the_game(int rows, int columns, int pointsToMatch,
   int numPlayers, int player_turn, char** gameBoard)
{
   // Declare the required variables
   // to check whether the game is over or not
   bool game_over = false;

   // variable to which piece(either X or O)
   // the player must insert into the board according
   // to player's turn
   char pieceToInsert;

   int result;
   // loop until there is a winner or tie
   while (game_over == false)
   {
       // call the function display_Game_Board()
       // to print the updated board
       display_Game_Board(rows, columns, gameBoard);

       // condition to check inorder to set the
       // piece value
       if (player_turn == 0)
       {
           // set the value 'X'
           pieceToInsert = 'X';
       }

       // Otherwise
       else
       {
           // set the value 'O'
           pieceToInsert = 'O';
       }

       // loop until there is valid column to drop the
       // piece and inser the piece into the board
       while (insert_Player_Piece(rows, columns,
           get_the_move(rows, columns, player_turn, numPlayers),
           pieceToInsert, gameBoard) == false);

       // change the player's turn
       player_turn ^= 1;

       // get the result and if the return value is success, the do the process
       if ((result = checkForPlayersWin(rows, columns, pointsToMatch, gameBoard)))
       {
           // display the board
           display_Game_Board(rows, columns, gameBoard);

           // if the result is 2, that means the game is tie
           if (result == 2)
           {
               // Display message about the match tie
               cout << "It's a Tie game!" << endl;
           }

           // if the player_turn is 0, then display
           // second player information
           else if (player_turn == 0)
           {
               if (numPlayers == 1)
                   cout << "\nComputer Won!\n";
               else
                   //Display message
                   cout << "\nPlayer 2 Won!\n";
           }

           // Otherwise display the player1's information
           else
           {
               //Display message
               cout << "\nPlayer 1 Won!\n";
           }

           // Assign value
           game_over = true;
       }
   }
}

// insert_Player_Piece() function to insert the player's piece into
// the board
bool insert_Player_Piece(int rows, int columns, int specific_column,
   char pieceToInsert, char** gameBoard)
{
   // if the column at specific_column is O or X then return 0
   if (gameBoard[0][specific_column] == 'O' ||
       gameBoard[0][specific_column] == 'X')
   {
       return false;
   }

   // set the i value
   int i = rows - 1;

   // get the piece from the gameboard which is present
   // at i'th row and specific_column
   char currentPiece = gameBoard[i][specific_column];

   // loop until, the following condition fails
   while (((currentPiece == 'O') || (currentPiece == 'X')) && (i > -1))
   {
       // decrement the row value
       i--;

       // get the piece
       currentPiece = gameBoard[i][specific_column];
   }

   // now the pieceToInsert by the player into
   // the i'th row and specific_column
   gameBoard[i][specific_column] = pieceToInsert;

   // and return 1
   return true;
}

// checkForPlayersWin() function to check for the players win.
// Basing on the status of the game return the value
int checkForPlayersWin(int rows, int columns, int pointsToMatch, char** gameBoard)
{
   // declare the required variables
   int i, j, checkPoints;
   bool flagMatch;
   char pieceToInsert;

   // boolean variable to hold if the game is tie
   bool isGameTie = true;

   // loop through each column at 0'th row(first row
   for (i = 0; i < columns; i++)
   {
       // if the board contains empty space
       // then set the isGameTie to false
       if (gameBoard[0][i] == ' ')
           isGameTie = false;
   }

   // if isGameTie is true, then return 2
   if (isGameTie)
   {
       //Return
       return 2;
   }

   // loop through each row
   for (i = 0; i < rows; i++)
   {
       // loop through each column
       for (j = 0; j < columns; j++)
       {
           // get the piece from the game board
           // present at i'th row and j'th column
           pieceToInsert = gameBoard[i][j];

           // if the pieceToInsert is empty
           // then continue
           if (pieceToInsert == ' ')
           {
               //Continue
               continue;
           }

           // set the flagMatch to true
           flagMatch = true;

           // check the j'th value
           if (j <= columns - pointsToMatch)
           {
               // loop through each column
               for (checkPoints = 1; checkPoints < pointsToMatch; checkPoints++)
               {
                   // if the piece of the game board mismatches with
                   // pieceToInsert
                   if (gameBoard[i][j + checkPoints] != pieceToInsert)
                   {
                       // set the flagMatch to false
                       flagMatch = false;
                   }
               }

               // if flagMatch is true, then
               // return 1(row winner)
               if (flagMatch)
               {
                   // Return
                   return 1;
               }
           }

           // reset the flagMatch to true
           flagMatch = true;

           // for the i'th and j'th value
           if (i <= rows - pointsToMatch && j < columns)
           {
               // loop through each row
               for (checkPoints = 1; checkPoints < pointsToMatch; checkPoints++)
               {
                   // if the piece of the game board mismatches with
                   // pieceToInsert
                   if (gameBoard[i + checkPoints][j] != pieceToInsert)
                   {
                       // set the flagMatch to false
                       flagMatch = false;
                   }
               }

               // if flagMatch is true, then
               // return 1(column winner)
               if (flagMatch)
               {
                   // Return
                   return 1;
               }
           }

           // reset the flagMatch to true
           flagMatch = true;

           // check for the diagonal row and column values
           if (i >= pointsToMatch - 1 && j <= columns - pointsToMatch)
           {
               // loop to check for the diagonal wise winner
               for (checkPoints = 1; checkPoints < pointsToMatch; checkPoints++)
               {
                   // if there is a mismatch, set the flagMatch to false
                   if (gameBoard[i - checkPoints][j + checkPoints] != pieceToInsert)
                   {
                       flagMatch = false;
                   }
               }

               // if flagMatch is true, then
               // return 1(diagonal winner winner)
               if (flagMatch)
               {
                   //Return
                   return 1;
               }
           }

           // reset the flagMatch to true
           flagMatch = true;

           // check for the diagonal row and column values
           if (i <= rows - pointsToMatch && j <= columns - pointsToMatch)
           {
               // loop to check for the diagonal wise winner
               for (checkPoints = 1; checkPoints < pointsToMatch; checkPoints++)
               {
                   // if there is a mismatch, set the flagMatch to false
                   if (gameBoard[i + checkPoints][j + checkPoints] != pieceToInsert)
                   {
                       flagMatch = false;
                   }
               }

               // if flagMatch is true, then
               // return 1(diagonal winner winner)
               if (flagMatch)
               {
                   
                   return 1;
               }
           }
       }
   }

   return 0;
}
