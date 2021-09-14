#include <iostream>
#include <sys/time.h>
using namespace std;
using std::cout;
using std::endl;

int fib_iter(int n)
{
    int a = 0, b = 1, c, i; 
    if (n==0)
        return a;
    for(i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return 0;
}

int fib_recurse(int n){
    if (n<=1)
        return n;
    return fib_recurse(n-1) + fib_recurse(n-2);
}

int main(){

int n;
cout <<"Enter an integer: " << endl;
cin>>n;
/*
typedef struct timeval time;
time stop, start;

gettimeofday(&start, NULL);
*/
cout << fib_iter(n) <<endl;
/*
gettimeofday(&stop, NULL);

if(stop.tv_sec > start.tv_sec)
    cout << "Seconds: " << stop.tv_sec-start.tv_sec <<endl;
else
    cout << "Micro: " << stop.tv_sec-start.tv_sec <<endl;


gettimeofday(&start, NULL);
*/
cout << fib_recurse(n) << endl;
cout << n << endl;
/*
gettimeofday(&stop, NULL);

if(stop.tv_sec > start.tv_sec)
    cout << "Seconds: " << stop.tv_sec-start.tv_sec << endl;
else
    cout << "Micro: " << stop.tv_sec-start.tv_sec << endl;
*/
    return 0;
}