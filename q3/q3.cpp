// q3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

//Allows the program to call functions from the standard library without referencing it.
using namespace std;

void quadrature(double n, double **quadrature);

void Integrate_h(double n, double **quadrature, double result);

int main()
{
	double dResult=0, dNval = 2;

	//pointer variable that acts as the array
	double **dQuadrature;

	//defines the first layer of the 2d array
	dQuadrature = new double*[2];
	//adds the correct number of columns to the 2d array
	for (int i = 0; i < 2; i++)
	{
		dQuadrature[i] = new double[dNval];
	}

	quadrature(dNval, dQuadrature);

	Integrate_h(dNval, dQuadrature, dResult);

	cout << dResult << '\n';
	
    return 0;
}

