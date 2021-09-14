#include <iostream>

using namespace std;
/*
void towers(int number_of_disks, int b[0][3], int from_col, int to_col, int spare){
    if(number_of_disks >= 1){
        towers(number_of_disks - 1, b[][], from_col, spare, to_col)
        cout << "Move disk " << number_of_disks << " from " << from_col << " to " << to_col << "." << endl;
        print_board
        towers(number_of_disks - 1, b[][], spare, to_col, from_col)
    }

}
*/
int print_board(int b[][3])
{
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            cout << b[x][y] << " ";
        }
    cout << endl;
    }
    cout << "-------" <<endl;
}

//move disk function
//void move_disk(){
    //iterate through the 2d array
    //while(index [row][col] != 0)
        //keep iterating
    //if index equals 0
        //move from col or index j to the first postion of 0
        //so we need another variable to keep track of where the empty index is
        //then set equal that index to the col went want to move from

int main()
{

    int b[3][3]=
    {
        {1, 0, 0},
        {2, 0, 0},
        {3, 0, 0}
    };
    cout << print_board(b);

    return 0;
}