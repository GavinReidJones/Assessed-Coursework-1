// q1a.cpp : Defines the entry point for the console application.
//
// Program written by Gavin Reid-Jones for Assesed Course Work 1 last edited 30/10/17


//include statements to allow the program to access in/out fuctionality and maths functions.
#include "stdafx.h"
#include <iostream>
#include <cmath>


//Allows the program to call functions from the standard library without referencing it.
using namespace std;

// allows the function to be used from another .cpp file by declaring its dummy values 
double legendre(double n, double x);

int main()
{
	//values that the Legendre function uses to calculate the result
	double dXval = 0.3;
	int iNval = 2;
	double dResult;

	//Calling the Legendre function
	dResult=legendre(iNval, dXval);

	//displaying the result to the user
	cout << "The Legendre Polynomial is : " << dResult << "\n";
	return 0;
}



