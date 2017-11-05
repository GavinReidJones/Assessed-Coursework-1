// Diff_legendre.cpp : Defines the entry point for the console application.
//
// Program written by Gavin Reid-Jones for Assesed Course Work 1 last edited 5/11/17

//include statements to allow the program to access in/out fuctionality, maths functions and the vector class.
#include "stdafx.h"
#include <iostream>
#include <cmath>


//Allows the program to call functions from the standard library without referencing it.
using namespace std;

double diff_legendre(double n, double x)
{
	// variable used to calculate the recurrance of the polynomial in place of n as it used as a parameter
	double i;
	double xn, xn1, xn2;

	//pushes the constant values of the first two steps in the reccurance to the variables.
	xn = 0;
	xn1 = 1;
	xn2 = 0;

	//Loops the reccurance calculation until it reaches n  number of reccurances.
	for (i = 2; i < n+1 ; i++)
	{
		//calculates the recursion formula for the next step in the process and then stores it in the variable
		xn2 = (((2 * i) - 1) / (i-1))*x*xn1 - (i  /( i-1))*xn;
		xn = xn1;
		xn1 = xn2;
	}

	double dResult = xn2;

	//outputs the final result of the recursion formula
	return dResult;

}