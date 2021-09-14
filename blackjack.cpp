/******************************************************************
** Program: assignment2.cpp
** Author: Blake Schafer
** Date: 04/018/2021 
** Description: Twentyone / Blackjack 
** Input: amount of players, amount of money in bank, bet amount, another card(y/n), play agian(y/n)
** Output: this program outputs the player scores, the dealers score, bank acount amount, and who won
*******************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//Black Jack

/*******************************************************************
** Function: dealer()
** Description: determines the dealers score and prints it out
** Parameters: none
** Pre-conditions: players score is  comparable to dealers score
** Post-conditions: returns the winner of the game
*******************************************************************/
int dealer()
{
    cout << "Dealers turn..." << endl;
    //rand ensures tha dealers score is in range 17-21
    int dealsc1 = (rand() % 5) + 7; //generate a random number 7-11
    cout << "The dealer gets a(n) "  << dealsc1 << ", running total is: "  << dealsc1 << endl;
    int dealsc2 = (rand() % 2) + 10; // generate either a 10 or 11
    int dealers_score = dealsc1 + dealsc2;
    cout << "The dealer chooses hit and gets a(n) "  << dealsc2 << ", running total is: "  << dealers_score << endl;
    cout << "The dealer stops.. ";
    
    //rand() % 21 + 17;
    cout << "The dealer has " << dealers_score << " points" << endl;

}
/*******************************************************************
** Function: hitme()
** Description: gives the player a random number from 1-11
** Parameters: none
** Pre-conditions: player asks for another card
** Post-conditions: players asks for another card
*******************************************************************/
int hitme()
{
    int num = rand() % 11 + 1; //genertes number 1-11 to simulate card values
    return num; //returns random number 
}
/*******************************************************************
** Function: winner()
** Description: compares the dealers score to the players score and c's out who won 
** Parameters: integer dealers_score, integer players_score 
** Pre-conditions: has to determine dealers score and players score
** Post-conditions: print message of winner.
*******************************************************************/
int winner(int dealers_score, int players_score)
{
    if (21 < dealers_score && players_score >= 21)
    {
        cout << "The dealer busts! You win!" << endl;

    }

    else if (dealers_score == players_score)
    {
        cout << "You and the dealer have the same score! It's a Tie!" << endl;
    }

    else if (dealers_score > players_score && dealers_score <= 21)
    {
        cout << "The dealer had a better hand and beat you! You lose your bet!" << endl;
    }

    else if (players_score > dealers_score && players_score <=21)
    {
        cout << "Congratulations you won!!!" << endl;
    }

    else //if (dealears_score == 21) && (player_score != 21)
    {
        cout << "Dealer won! You lose! Better luck next time." << endl;
        
    } 
}

int main()
{
    srand(time(NULL));

    int players = 0;
    int bet, ant_num, player_score, dealers_score;
    int players_score = hitme();

    do{
        cout << "How many players do you have(1-4)?: " << endl;
        cin >> players;
    }while (!(players >=1 && players <=4));

    int bank1, bank2, bank3, bank4;

    for (int i=0; i < players; i++)
    {
        cout << "Enter bank amount for player " << i+1 << ": " << endl;
        if (i == 0) //player 1
            cin >> bank1;
        else if(i == 1)
            cin >> bank2;
        else if(i == 2)
            cin >> bank3;
        else
            cin >> bank4;
    }
    
    switch (players){
        case 1: 
            cout << "Bank is equal to: " << bank1 << endl; 
            cout << "Player 1's turn..." << endl;
            cout << "\nPlayer 1, how much do you bet you can beat the dealer?: " << endl;
            cin >> bet;
            cout << "Player 1 you placed a bet amount of: " << bet << endl;
            cout << "Player 1, you got a(n) " << players_score << ", running total is " << players_score << ". Do you want another number?(0=no, 1=yes): " << endl;
            cin >> ant_num;
            while(ant_num == 1)
            {
                players_score += hitme();
                cout << "You got another number, your running total is: " << players_score << ". Another number?(0=no, 1=yes): " << endl;
                cin >> ant_num;
                if(ant_num == 0)
                {
                    cout << "Player 1, your final score is: " << players_score << endl;
                }
                else if(players_score >= 21)
                {
                    break;
                }
            }
            if (players_score > 21)
            {
                cout << "Uh oh, you went over 21 and have busted" << endl; 
                bank1 -= bet;
                break;
            }
            else if (players_score == 21)
            {
                cout << "Congrations you won!" << endl;
                bank1 += bet * 2;
                cout << "You now have " << bank1 << " dollars in your bank account" << endl;
                break;
            }
            else
                break;

        case 2:
        cout << "Bank is equal to: " << bank1 << endl; 
            cout << "Player 1's turn..." << endl;
            cout << "\nPlayer 1, how much do you bet you can beat the dealer?: " << endl;
            cin >> bet;
            cout << "Player 1 you placed a bet amount of: " << bet << endl;
            cout << "Player 1, you got a(n) " << players_score << ", running total is " << players_score << ". Do you want another number?(0=no, 1=yes): " << endl;
            cin >> ant_num;
            while(ant_num == 1)
            {
                players_score += hitme();
                cout << "You got another number, your running total is: " << players_score << ". Another number?(0=no, 1=yes): " << endl;
                cin >> ant_num;
                if(ant_num == 0)
                {
                    cout << "Player 1, your final score is: " << players_score << endl;
                }
            }
            if (players_score > 21)
            {
                cout << "Uh oh, you went over 21 and have busted" << endl; 
                bank1 -= bet;
                break;
            }
            else if (players_score == 21)
            {
                cout << "Congrations you won!" << endl;
                bank1 += bet * 2;
                cout << "You now have " << bank1 << " dollars in your bank account" << endl;
                break;
            }
            else
                break;

        case 3:
        cout << "Bank is equal to: " << bank1 << endl; 
            cout << "Player 1's turn..." << endl;
            cout << "\nPlayer 1, how much do you bet you can beat the dealer?: " << endl;
            cin >> bet;
            cout << "Player 1 you placed a bet amount of: " << bet << endl;
            cout << "Player 1, you got a(n) " << players_score << ", running total is " << players_score << ". Do you want another number?(0=no, 1=yes): " << endl;
            cin >> ant_num;
            while(ant_num == 1)
            {
                players_score += hitme();
                cout << "You got another number, your running total is: " << players_score << ". Another number?(0=no, 1=yes): " << endl;
                cin >> ant_num;
                if(ant_num == 0)
                {
                    cout << "Player 1, your final score is: " << players_score << endl;
                }
            }
            if (players_score > 21)
            {
                cout << "Uh oh, you went over 21 and have busted" << endl; 
                bank1 -= bet;
                break;
            }
            else if (players_score == 21)
            {
                cout << "Congrations you won!" << endl;
                bank1 += bet * 2;
                cout << "You now have " << bank1 << " dollars in your bank account" << endl;
                break;
            }
            else
                break;

        case 4:
        cout << "Bank is equal to: " << bank1 << endl; 
            cout << "Player 1's turn..." << endl;
            cout << "\nPlayer 1, how much do you bet you can beat the dealer?: " << endl;
            cin >> bet;
            cout << "Player 1 you placed a bet amount of: " << bet << endl;
            cout << "Player 1, you got a(n) " << players_score << ", running total is " << players_score << ". Do you want another number?(0=no, 1=yes): " << endl;
            cin >> ant_num;
            while(ant_num == 1)
            {
                players_score += hitme();
                cout << "You got another number, your running total is: " << players_score << ". Another number?(0=no, 1=yes): " << endl;
                cin >> ant_num;
                if(ant_num == 0)
                {
                    cout << "Player 1, your final score is: " << players_score << endl;
                }
            }
            if (players_score > 21)
            {
                cout << "Uh oh, you went over 21 and have busted" << endl; 
                bank1 -= bet;
                break;
            }
            else if (players_score == 21)
            {
                cout << "Congrations you won!" << endl;
                bank1 += bet * 2;
                cout << "You now have " << bank1 << " dollars in your bank account" << endl;
                break;
            }
            else
                break;
    
        default:
            cout << "Invalid Input" << endl;
    }
    
    while(players_score != 21)
    {
        cout << dealer() << endl;
        winner(dealers_score, players_score);
        break;
    }
    
    return 0;
}