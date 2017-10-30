// q1b.cpp : Defines the entry point for the console application.
//
// Program written by Gavin Reid-Jones for Assesed Course Work 1 last edited 30/10/17


//include statements to allow the program to access in/out fuctionality, maths functions and the vector class.
#include "stdafx.h"
#include <iostream>
#include <cmath>


//Allows the program to call functions from the standard library without referencing it.
using namespace std;

double diff_legendre(double n, double x);

int main()
{
	//values that the Legendre function uses to calculate the result
	double dXval = 0.3;
	int iNval = 2;
	double dResult;

	//Calling the Legendre function
	dResult = diff_legendre(iNval, dXval);

	cout << "The Differentiated Legendre Polynomial is : " << dResult << "\n";
	return 0;
}
