/*********************************************************************
** Program Filename: assignment1.cpp
** Author: Blake Schafer
** Date: 4-7-2021
** Description: Calulating gross income, taxes, and remaining after taxes of a Car salesman
** Input: monthly salary, number of months worked, cost of car, number of cars sold, number of misconducts, tax year and state
** Output: gross income, tax, remaining after tax
*********************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){

srand(time(NULL));

float month_sal; //float allows for decimal value
cout << "What is your monthly salary? "; //user input montly salary
cin >> month_sal; //read user input

int months;
cout << "How many months do you work in a year? "; //user input months worked in a year 
cin >> months;

int annual_sal = month_sal * months; //calculating annual salary

int cars_sold;
cout << "How many cars have you sold? "; //user input cars sold
cin >> cars_sold;

float car_cost;
cout << "What is the cost of a car? "; //input cost of a car
cin >> car_cost;

int rand_num = rand() % (10 - 5 + 1) + 5; //genrating random price 5-10% above car price
int average_cost = car_cost + (car_cost * rand_num); //generating average cost of car
int profit = (((average_cost - car_cost) * 2) / 100.0) * cars_sold; //calculating profit

int misconducts;
cout << "How many misconducts were observed? "; //user input misconducts observed
cin >> misconducts;

int deduction;
if (misconducts == 0){
	deduction = 0; //if no misconducts were observed, price of deduction is zero
}
else{
	deduction = 100 * pow ( 2, misconducts - 1); //calculate amount of deductions based on misconducts observed 
}

int gross_income = annual_sal + (0.02 * profit) - deduction; //calculate gross income

int tax_year;
cout << "What tax year are you in?(17 or 18): "; //user input tax year
cin >> tax_year;

int state;
cout << "What state are you located in?(a=1, b=2, or c=3): "; //user input tax state
cin >> state;

int tax;
if (tax_year == 17){ //tax year is 2017
	if (state == 1){
		tax = (gross_income * 6) / 100.0;//6% of gross income
	}
	else if (state == 2){
		if (gross_income <=2000){
			tax = 0;
		}
		else if (gross_income > 2000 and gross_income <= 10000){
			tax = 100;
		}
		else{
			tax = ((gross_income * 10) / 100.0) +100;
		}
	}
	else{
		if (gross_income <=3500){
			tax = (gross_income * 5) / 100.0;
		}
		else if (gross_income > 3500 and gross_income <=9000){
			tax = ((gross_income * 7) / 100.0) + 175;
		}
		else if (gross_income > 9000 and gross_income <=125000){
			tax = ((gross_income * 9) /100.0) + 560;
		}
		else{
			tax = ((gross_income * 9.9) /100.0) + 11000;
		}
	}
}
if (tax_year == 18){ //tax year is 2018
	if (state == 1){
		tax = (gross_income * 8) / 100.0;
	}
	else if (state == 2){
		if (gross_income <= 2500){
			tax = 0;
		}
		else if (gross_income >2500 and gross_income <= 10000){
			tax = 115;
		}
		else{
			tax = ((gross_income * 10.5) / 100.0) + 115;
		}
	}
	else{
		if (gross_income <=3450){
			tax = (gross_income * 5) / 100.0;
		}
		else if (gross_income >3450 and gross_income <= 8700){
			tax = ((gross_income * 7) / 100.0) + 172.5;
		}
		else if (gross_income > 8700 and gross_income <= 125000){
			tax = ((gross_income * 9) / 100.0) + 540;
		}
		else{
			tax = ((gross_income * 9.9)/ 100.0) + 11007;
		}
	}
}

cout << "Your gross income is: $" << gross_income <<endl; //output gross income
cout << "The tax you need to pay is: $" << tax << endl; //output tax

int remaining = gross_income - tax; //calculate remaining 
cout << "Your income after tax is: $" << remaining << endl; //output remaining

	return 0;
}