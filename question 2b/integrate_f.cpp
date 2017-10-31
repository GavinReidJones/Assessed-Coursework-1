// integrate_f.cpp : Defines the entry point for the console application.
//

//include statements to allow the program to access in/out fuctionality, maths functions and the vector class.
#include "stdafx.h"
#include <iostream>
#include <cmath>

//Allows the program to call functions from the standard library without referencing it.
using namespace std;
// Defines the constant pi that is used to generate the initial estimate for the root of the legendre polynomial
double const pi = atan(1)*4;

double integrate_f(double n, double **quadrature)
{
	// boolean variable to check whether the newton method has produced an accurate enough solution
	bool accurate = false;
	//variables to store the estimates for the root of the legendre polynomial
	double xn1 = 0, xn;

	//loop used to set an accurate value for each value of the quadrature
	for (int i = 1; i<n + 1; i++)
	{
		//initial guess for xn
		xn = -cos(((2 * i - 1) / (2 * n))*pi);
		
		//set that the guess has not met the accuracy threshhold
		accurate = false;
		//the loop used to implement newton iteration to find the root
		while (accurate == false)
		{
			//implements the newton method to find a better approximation to the solution
			xn1 = xn - ((cos(xn)*exp(xn)) / (exp(xn)*(cos(xn)-sin(xn))));
			//checks whether the new approximation is accurate enough
			if (abs(xn1 - xn) < pow(10, -15))
			{
				accurate = true;
			}
			//sets the new value of xn to the old variable to allow it to be computed again without recursion.
			xn = xn1;
		}

		if (xn > pi)
		{
			xn = xn - 2 * pi;
		}
		else if (xn < -pi)
		{
			xn = xn + 2 * pi;
		}
		double fx1 = exp(xn)*(cos(xn) - sin(xn));

		//calculates the weight of each point in the quadrature
 		double w =  2 / ((1 - pow(xn, 2))*pow(fx1, 2));

		//stores the values calculated by the program to the appropriate location in the array
		quadrature[0][i - 1] = xn;
		quadrature[1][i - 1] = w;
	}
	double dCurrentSum=0, dSum = 0;

	for (int i = 1; i < n + 1; i++)
	{
		dSum = dCurrentSum + cos(quadrature[0][i - 1]*pi)*exp(quadrature[0][i - 1]*pi) * quadrature[1][i - 1];

		dCurrentSum = dSum;
	}

	dCurrentSum = dCurrentSum*pi;
	return(dCurrentSum);
}