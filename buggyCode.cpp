/*
  2 THERE ARE BUGS IN THE FOLLOWING CODE.
  3 */
  4 #include <iostream>
  5 #include <cmath>
  6 using namespace std;
  7 int main(){
  8 
  9         int x=3, y;
 10         char myAnswer;
 11         int num;
 12         bool again;
 13         int fact;
 14         y = x;
 15         cout << "y is set to: " << y << endl;
 16 
 17         cout << "Please input a number: ";
 18         cin >> y;
 19         again = true;
 20         while(again == true){
 21                 if(x > y){
 22                         cout << "X is greater than Y\n";
 23                         cout <<" would you like to input another number?" << endl;
 24                         cin >> again;
 25                 }
 26                 else if(x==y){
 27                         cout << "X is equal to Y" << endl;
 28                         cout << "Would you like to input another number?"<< endl;
 29                         cin >> again;
 30                 }
 31                 else{
 32                         cout << "X is less than Y" << endl;
 33                         cout << "would you like to input another number?" << endl;
 34                         cin >> again;
 35                 }
 36                 //hint: what about equal logic?
 37         }
 38         for(x = 0; x < 10; x++){
 39                 cout << x << endl;
 40         }
 41         cout << "What number would you like to find the factorial for? " << endl;
 42         cin >> num;
 43         for(x=num; x < 10; x--){
 44                 fact = num *= x;                //hint: is this factorial correct?
 45         }
 46         cout << fact << endl;
 47         cout << "Are you enjoying cs161? (y or n) " << endl;
 48         cin >> myAnswer;
 49 
 50         if(myAnswer == y){
 51                 cout << "YAY" << endl;
 52         }
 53         else{
 54                 cout << "YOU WILL SOON!" << endl;
 55         }
 56         return 0;
    }
