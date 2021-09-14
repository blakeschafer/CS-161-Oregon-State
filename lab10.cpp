#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;


bool fun(int array[][3], int size){

    int sum = 0, sum2 = 0;
    for(int i = 0; i<3; i++)
        sum = sum + array[i][j];

    for (int i = 0; i<3; i++)
        sum2 = sum2 + array[i][j];

    if(sum != sum2)
        return false;

    for(int i = 0; i<3; i++){
        
        int rowSum = 0;
        for(int j = 0; j<3; j++)
            rowSum += array[i][j];

        if(rowSum != sum)
            return false;
    }

    for(int i = 0; i<3; i++){

        int colSum = 0;
        for(int j = 0; j<3; j++)
            colSum += array[j][i];

        if(sum != colSum)
            return false;
    }
    return true;
}

int main(){
srand(time(NULL));
int array[][3] = {{2, 7, 6}
                  {9, 5, 1}
                  {4, 3, 8}};
/*
//int a = ;
for(int i = 0; i<3; i++){
    for(int j = 0; j<3; j++){
        array[i][j] = (rand() % 9) +1;
        //a++;
    }
}

for(int i = 0; i<3; i++){
    for(int j = 0; j<3; j++){
        cout << array[i][j];
    }
    cout << "\n";
}
*/
if(fun(array))
    cout << "This is a magic square!";
else
    cout << "This is not a magic square :(";

    return 0;
}