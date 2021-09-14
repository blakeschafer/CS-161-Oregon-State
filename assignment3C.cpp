/******************************************************************
** Program: assignment3C.cpp
** Author: Blake Schafer
** Date: 02/28/2021 
** Description: Number Pattern Printing
** Input: This program asks for the number of rows the user wants and if it wants to do another pattern
** Output: This program outputs a repeting number pattern that forms a diamond, based on the users input.
*******************************************************************/
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
int run;
//do while loop to do another conversion
do{
   int rows=0;
   printf("How many numbers of rows do you want? = ");
   scanf("%d",&rows);
   int k=rows/2; //it stores the number i.e, half of the number of rows
   for(int i=1;i<=k+1;i++)
   {
       for(int j=1;j<=k-(i-1);j++)
       {
           printf(" ");
       }
       for(int j=1;j<=(2*i)-1 ;j++)
       {
           printf("%d",j );
       }
       printf("\n");
   }
   for(int i=k;i>=1;i--)
   {
       for(int j=1;j<=k-(i-1);j++)
       {
           printf(" ");
       }
       for(int j=1;j<=(2*i)-1 ;j++)
       {
           printf("%d",j );
       }
       printf("\n");
   }
    cout<< "\nDo you want to do another conversion?(0=no, 1=yes): ";
    cin >> run;
}

while(run == 1);

    return 0;
}