#include <cstdlib> //srand, rand function
#include <ctime>
#include <iostream>

using namespace std;

int main(){

    int x; //varibale to hold our random integer
    srand(time(NULL));

    x = rand() % 5 + 1;
    cout << "x= " << x << endl;
    x = rand();
    cout << "x= " << x << endl;
    
    if (x == 1)
    {
            cout << "I am a 1!" << endl;
    }

    int a = 1; int b = (--a)++;

    cout << a <<endl;
    cout << b <<endl;

    float value = 100.5;
    cout << "value" <<endl;















    return 0;
}