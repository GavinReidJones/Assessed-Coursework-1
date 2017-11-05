// integrate_f.cpp : Defines the entry point for the console application.
//

//include statements to allow the program to access in/out fuctionality, maths functions and the vector class.
#include "stdafx.h"
#include <iostream>
#include <cmath>

//Allows the program to call functions from the standard library without referencing it.
using namespace std;
// Defines the constant pi that is used to generate the initial estimate for the root of the legendre polynomial
double const pi = atan(1) * 4;


double integrate_f(double n, double **quadrature)
{

	double dSummation = 0, dNextstep = 0, dCurrentSum = 0;

	for (int i = 1; i < n+1; i++)
	{
		dNextstep = cos(quadrature[0][i - 1] * pi)*exp(quadrature[0][i - 1] * pi) * quadrature[1][i - 1];
		dSummation = dCurrentSum + dNextstep;

		dCurrentSum = dSummation;
	}

	dCurrentSum = dCurrentSum*pi;
	return(dCurrentSum);
}