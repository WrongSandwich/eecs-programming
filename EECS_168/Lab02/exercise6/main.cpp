/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 2 - Exercise 6
 * Description: This program lets the user place a food order at a taco stand and recieve a receipt.
 * Date: 01/29/2018
 * ------------------------------------------------------------------------------- */

#include <iostream>
#include <math.h>
using namespace std;

char menuInput;
char meatInput;
int numberInput;

{
	cout << "Welcome to the taco stand!\n\nPlace order::\n============\n";
	cout << "(t/T) Taco $3.50\n(s/S) Salad $4.50\n(w/W) Water $1.00\n";
	cout << "Choice: ";
	cin >> menuInput;

	//Topping options if user chooses taco.
	if (menuInput == 't' || menuInput == 'T')
	{
		cout << "\n\nMeats:\n============\n";
		cout << "(c/C) Chicken\n";
		cout << "(s/S) Steak - add $0.50\n";
		cout << "(b/B) Barbacoa - add $0.75\n";
		cout << "(z/Z) Chorizo - add $1.00\nChoice: ";
		cin >> meatInput;
		if (meatInput == 'c' || meatInput == 'C')
